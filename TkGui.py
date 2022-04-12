import popUpPages
import GUIFunc as fun
from PIL import ImageTk
from PIL import Image
from string import ascii_letters
import numpy as np
from matplotlib.colors import ListedColormap
import pandas as pd
import seaborn as sb
import tkinter as tk

from datetime import datetime
import time
import sys
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
from matplotlib.animation import FuncAnimation
global loggedIn
 #note to self: cant use from tkinter import * AND PIL

def main1():
    uname = 'test'
    root = tk.Tk()
    root.title('Smart Chair UI')
    width = root.winfo_screenwidth()
    height = root.winfo_screenheight()
    root.geometry('{}x{}'.format(width, height))

    # create all of the main containers
    top_frame = tk.Frame(root, bg='light blue', width=width, height=50, pady=3)
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

    #while loggedIn==2:
    origTime = round(time.time())

    # create the widgets for the top frame

    # hello user
    hello = tk.Label(top_frame, text="Hello " + f"{uname}",
                     bg="#334BFF", fg="white", width=50, height=10)
    hello.grid(row=0, column=0)

    # clock
    clock = tk.Label(top_frame,bg="#334BFF", fg="white", width=50, height=10)
    clock.grid(row=0, column=1)

    # menu
    menu = tk.Label(top_frame, text="Menu", bg="#334BFF",
                    fg="white", width=50, height=10)
    menu.grid(row=0, column=2)

    # datedisp
    date = tk.Label(top_frame, bg="#334BFF", fg="white", height=10, width=50)
    date.grid(row=0, column=3)

    # countdown
    countdown = tk.Label(top_frame,bg="#334BFF", fg="white", width=50, height=10)
    countdown.grid(row=0, column=4)

    def tick():
        now = datetime.now()
        timeNow = round(time.time())- origTime
        timeToGo = (30*60)-timeNow
        countdown.configure(text='Time passed: ' + f"{timeNow//60}" + " minutes and " + f"{timeNow%60}" + " seconds")
        pie_chart(timeNow, timeToGo)
        if timeNow==(30*60):
            tk.messagebox.showinfo("Stand up")


        clock.configure(text='Time: '+ f"{now:%H:%M:%S}")
        date.configure(text='Date: ' + f"{now:%d/%m/%Y}")
        root.after(1000, tick)
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
        f, ax = plt.subplots(2,1, figsize=(4, 4))
        TopLabels = np.array([['A1', 'A2'],['A3', 'A4']])
        hmTop = sb.heatmap(dataTop, cmap=ListedColormap(['green', 'orange', 'red']),ax=ax[0], annot= TopLabels, fmt='')
        BotLabels =np.array([['A5', 'A6', 'A7'],['A8', 'A9','A10'],['A11', 'A12','A13']])
        hmBot=sb.heatmap(dataBot, cmap=ListedColormap(['green', 'orange', 'red']), ax=ax[1], annot= BotLabels, fmt='')
        hmBot.set_xlabel('Front of Chair', fontsize=10)
        hmTop.set_ylabel('Right hand side', fontsize=10)
        return f


    def data_hm():
        inputs=[0.62, 0.34, 3.63, 0.47, 1.73, 1.43, 1.66, 1.89, 1.6, 1.93, 1.16, 0.85, 1.08]
        dataBot = np.array([inputs[4], inputs[5], inputs[6], inputs[7], inputs[8], inputs[9], inputs[10], inputs[11], inputs[12]]).reshape(3,3)
        dataTop = np.array([inputs[0], inputs[1], inputs[2], inputs[3]]).reshape(2,2)
        return dataBot, dataTop


    data = data_hm()
    # heat map
    dataBot = data[0]
    dataTop = data[1]
    fig_HM = create_HM(dataBot, dataTop)
    heat_map = FigureCanvasTkAgg(fig_HM, center)
    heat_map.get_tk_widget().grid(row=1, column=1)  # A tk.DrawingArea.
    heat_map.draw()

    # Create an object of tkinter ImageTk
    badge = Image.open("badgeIcon.jpg")
    re_badge = badge.resize((50, 50), Image.ANTIALIAS)
    new_badge = ImageTk.PhotoImage(re_badge)
    # Create a Label Widget to display the text or Image
    badgeLabel = tk.Button(btm_frame, image=new_badge,
                           command=popUpPages.openBadge)
    badgeLabel.grid(row=3, column=0)

    # Create an object of tkinter Imag                                                                          eTk
    report = Image.open("reportIcon.png")
    re_report = report.resize((50, 50), Image.ANTIALIAS)
    new_report = ImageTk.PhotoImage(re_report)
    # Create a Label Widget to display the text or Image
    reportLabel = tk.Button(btm_frame, image=new_report,
                            command=popUpPages.openReport)
    reportLabel.grid(row=3, column=1)

    # Create an object of tkinter ImageTk
    insights = Image.open("insightsIcon.png")
    re_insights = insights.resize((50, 50), Image.ANTIALIAS)
    new_insights = ImageTk.PhotoImage(re_insights)
    # Create a Label Widget to display the text or Image
    insightsLabel = tk.Button(btm_frame, image=new_insights, command=popUpPages.openInsights)
    insightsLabel.grid(row=3, column=2)
    tick()
    root.mainloop()



# defining login function
def login():
    # getting form data
    uname = username.get()
    pwd = password.get()
    # applying empty validation
    if uname == '' or pwd == '':
        message.set("fill the empty field!!!")

    elif uname == "Tony" and pwd == "p":
        message.set("Login success")
        global loggedIn
        loggedIn = 2
        print("hi")

    else:
        message.set("Wrong username or password!!!")


# defining loginform function
def Loginform():
    #global login_screen
    login_screen = tk.Toplevel()
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
