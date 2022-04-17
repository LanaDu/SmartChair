from __future__ import print_function
import pandas as pd
import predictFamBT
import matlab
import popUpPages
from PIL import ImageTk
from PIL import Image
import numpy as np
from matplotlib.colors import ListedColormap
import seaborn as sb
import tkinter as tk
from numpy import random
from datetime import datetime
import time
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
import serial

global loggedIn
global uname
global oTime
global ab
#inputs=[0.62, 0.34, 3.63, 0.47, 1.73, 1.43, 1.66, 1.89, 1.6, 1.93, 1.16, 0.85, 1.08]
 #note to self: cant use from tkinter import * AND PIL

def main1():
    def read_arduino(arduino):
        arduino_bytes = arduino.readline()  # read line of arduino serial
        arduino_decode = arduino_bytes.decode()
        [s, v] = arduino_decode.split(',')  # isolate sensor name and voltage val
        v = float(v)

        return s, v

    global uname
    uname='log in please'

    global ab
    ab = 2

    root = tk.Tk()
    root.title('Smart Chair UI')
    width = root.winfo_screenwidth()
    print(width)
    height = root.winfo_screenheight()
    print(height)
    root.geometry('{}x{}'.format(width, height))


    def abort():
        global ab
        ab = 3


    # create all of the main containers
    top_frame = tk.Frame(root, bg="#334BFF", width=width, height=50, pady=3)
    center = tk.Frame(root, bg='white', width=width, height=40, padx=3, pady=3)
    btm_frame = tk.Frame(root, bg='white', width=width, height=45, pady=3)

    # layout all of the main containers
    root.grid_rowconfigure(1, weight=1)
    root.grid_columnconfigure(0, weight=1)

    top_frame.grid(row=0, sticky="ew")
    center.grid(row=1, sticky="nsew")
    btm_frame.grid(row=3, sticky="ew")


    #while loggedIn == 1:
    #    LoginButton = tk.Button(top_frame, text='login', command=Loginform)
    #    LoginButton.grid(row=0, column=0)

    # create the widgets for the top frame

    # hello user
    hello = tk.Label(top_frame,
                     bg="#334BFF", fg="white", width=35, height=5, font=10)
    hello.grid(row=0, column=0)

    # clock
    clock = tk.Label(top_frame,bg="#334BFF", fg="white", width=35, height=5, font=10)
    clock.grid(row=0, column=1)


    # datedisp
    date = tk.Label(top_frame, bg="#334BFF", fg="white", height=5, width=35, font=10)
    date.grid(row=0, column=3)

    # countdown
    countdown = tk.Label(top_frame,bg="#334BFF", fg="white", width=35, height=5, font=10)
    countdown.grid(row=0, column=4)

    # login
    loginButton = tk.Button(top_frame,bg="#334BFF", fg="white", width=15, height=5, font=10)
    loginButton.grid(row=0, column=5)
    #abort arduino
    abortButton = tk.Button(top_frame,bg="#334BFF", fg="white", width=15, height=5, font=10, command = abort, text='abort')
    abortButton.grid(row=0, column=6)
    def tick():
        now = datetime.now()
        if uname == "Tony":

            global oTime
            timeNow = round(time.time())- oTime
            timeToGo = (30*60)-timeNow
            countdown.configure(text='Time sat down: ' + f"{timeNow//60}" + " minutes and " + f"{timeNow%60}" + " seconds")
            hello.configure(text='Hello, '+ f"{uname}")
            pie_chart(timeNow, timeToGo)
            if timeNow==(30*60):
                tk.messagebox.showinfo("Stand up")

            countdown.configure(text='Time sat down: ' + f"{timeNow//60}" + " minutes and " + f"{timeNow%60}" + " seconds")
            clock.configure(text='Time: '+ f"{now:%H:%M}")
            date.configure(text='Date: ' + f"{now:%d/%m/%Y}")
            loginButton.configure(text='log out', command=logout)
            root.after(1000, tick)
        else:
            countdown.configure(text='Time sat down: 0 minutes and 0 seconds')
            clock.configure(text='Time: '+ f"{now:%H:%M}")
            date.configure(text='Date: ' + f"{now:%d/%m/%Y}")
            hello.configure(text='Please log in')
            loginButton.configure(text = 'log in', command = Loginform)
            root.after(1000,tick)
    # pie chart function

    def pie_chart(time_pass, time_lef):
        chartLabels = ['time passed', 'time left']
        chartVar = [time_pass, time_lef]

        fig = Figure()  # create a figure object
        ax = fig.add_subplot(111)  # add an Axes to the figure
        ax.pie(chartVar, startangle =90,radius=1, shadow=False, colors = ['white', 'blue'])
        circle = plt.Circle((0, 0), 0.7, color='white')
        ax.add_artist(circle)
        ax.set_title('Stand when the blue donut disappears')
        chart1 = FigureCanvasTkAgg(fig, center)
        chart1.get_tk_widget().grid(row=1, column=3)

    # heat map




    def create_HM(dataBot,dataTop):
        #fig size is (rows, columns)
        plt.close()
        f, ax = plt.subplots(2,1, figsize=(4, 4))
        TopLabels = np.array([['A1', 'A2'],['A3', 'A4']])
        hmTop = sb.heatmap(dataTop, cmap=ListedColormap(['green', 'orange', 'red']),ax=ax[0], annot= TopLabels, fmt='', yticklabels=False, xticklabels=False)
        BotLabels =np.array([['A5', 'A6', 'A7'],['A8', 'A9','A10'],['A11', 'A12','A13']])
        hmBot=sb.heatmap(dataBot, cmap=ListedColormap(['green', 'orange', 'red']), ax=ax[1], annot= BotLabels, fmt='', yticklabels=False, xticklabels=False)
        hmBot.set_xlabel('Front of Chair', fontsize=10)
        hmTop.set_ylabel('Right hand side', fontsize=10)
        return f


    def data_hm(inputs):
        #inputs=[0.62, 0.34, 3.63, 0.47, 1.73, 1.43, 1.66, 1.89, 1.6, 1.93, 1.16, 0.85, 1.08]
        dataBot = np.array([inputs[4], inputs[5], inputs[6], inputs[7], inputs[8], inputs[9], inputs[10], inputs[11], inputs[12]]).reshape(3,3)
        dataTop = np.array([inputs[0], inputs[1], inputs[2], inputs[3]]).reshape(2,2)
        print(dataTop)
        print(dataBot)
        return dataBot, dataTop


    def call_HM():
        global ab
        arduino = serial.Serial('COM5', 9600)  # open com port (com4 or com5)
        if ab == 2:
            count = 1
            #vals= random.randint(5, size=(13))
            sensors, vals = [], []
            while count < 14:
                sensor, val = read_arduino(arduino)
                print(sensor)
                print(' A' +f"{count}")
                if sensor == ' A' +f"{count}":
                    #sensor, val = read_arduino(arduino)
                    sensors.append(sensor)
                    vals.append(val)
                    count += 1
                # now have list of sensors and list of vals to put in dataframe
                # sensors13 = pd.DataFrame(list(zip(sensors, vals)), columns=['Sensor', 'Value'])
                # all_sensors = all_sensors.append(sensors13)

            my_predictFamBT = predictFamBT.initialize()

            sensorDataIn = matlab.double(vals, size=(1, 13))
            labelOut = my_predictFamBT.predictFamBT(sensorDataIn)
            print(labelOut, sep='\n')

            my_predictFamBT.terminate()
            arduino.close()

        elif ab==3: #abort
            vals = np.zeros(13)
            print(vals)
            arduino.close()

        data = data_hm(vals)
        # heat map
        dataBot = data[0]
        dataTop = data[1]
        fig_HM = create_HM(dataBot, dataTop)
        heat_map = FigureCanvasTkAgg(fig_HM, center)
        heat_map.get_tk_widget().grid(row=1, column=1)  # A tk.DrawingArea.
        heat_map.draw()
        root.after(10000, call_HM)
    call_HM()
    # Create an object of tkinter ImageTk
    # badge = Image.open("badgeIcon.jpg")
    # re_badge = badge.resize((50, 50), Image.ANTIALIAS)
    # new_badge = ImageTk.PhotoImage(re_badge)
    # # Create a Label Widget to display the text or Image
    # badgeLabel = tk.Button(center, image=new_badge,
    #                        command=popUpPages.openBadge)
    # badgeLabel.grid(row=1, column=7)
    #
    # # Create an object of tkinter Imag                                                                          eTk
    # report = Image.open("reportIcon.png")
    # re_report = report.resize((50, 50), Image.ANTIALIAS)
    # new_report = ImageTk.PhotoImage(re_report)
    # # Create a Label Widget to display the text or Image
    # reportLabel = tk.Button(center, image=new_report,
    #                         command=popUpPages.openReport)
    # reportLabel.grid(row=1, column=6)
    #
    # # Create an object of tkinter ImageTk
    # insights = Image.open("insightsIcon.png")
    # re_insights = insights.resize((50, 50), Image.ANTIALIAS)
    # new_insights = ImageTk.PhotoImage(re_insights)
    # # Create a Label Widget to display the text or Image
    # insightsLabel = tk.Button(center, image=new_insights, command=popUpPages.openInsights)
    # insightsLabel.grid(row=1, column=5)
    tick()
    root.mainloop()

def logout():
    global uname
    uname ='logged out'

# defining login function
def login():
    # getting form data
    global uname
    uname = username.get()
    pwd = password.get()
    # applying empty validation
    if uname == '' or pwd == '':
        message.set("fill the empty field!!!")

    elif uname == "Tony" and pwd == "p":
        message.set("Login success")
        global oTime
        oTime = round(time.time())
        global loggedIn


    else:
        message.set("Wrong username or password!!!")


# defining loginform function
def Loginform():
    #global login_screen
    login_screen = tk.Toplevel()
    login_screen.grab_set()
    # Setting title of screen
    login_screen.title("Login Form")
    # setting height and width of screen
    login_screen.geometry("300x250")
    # declaring variable
    global message
    global username
    global password
    username = tk.StringVar()
    password = tk.StringVar()
    message = tk.StringVar()
    # Creating layout of login form
    tk.Label(login_screen, width="300", text="Please enter details below", bg="orange", fg="white").pack()
    # Username Label
    tk.Label(login_screen, text="Username * ").place(x=20, y=40)
    # Username textbox
    tk.Entry(login_screen, textvariable=username).place(x=90, y=42)
    # Password Label
    tk.Label(login_screen, text="Password * ").place(x=20, y=80)
    # Password textbox
    tk.Entry(login_screen, textvariable=password, show="*").place(x=90, y=82)
    # Label for displaying login status[success/failed]
    tk.Label(login_screen, text="", textvariable=message).place(x=95, y=100)
    # Login button
    tk.Button(login_screen, text="Login", width=10, height=1, bg="orange", command=login).place(x=105, y=130)
    #login_screen.mainloop()

main1()
