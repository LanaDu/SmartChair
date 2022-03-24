import tkinter as tk
from datetime import datetime 
import time
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
from matplotlib.animation import FuncAnimation
now = datetime.now()
import seaborn as sb
import pandas as pd
import numpy as np
from string import ascii_letters
from PIL import ImageTk, Image
import popUpPages 

def main():
    root = tk.Tk()
    root.title('Smart Chair UI')
    root.geometry('{}x{}'.format(460, 350))
    #import the functions file 
    import GUIFunc as fun
    
    # create all of the main containers
    top_frame = tk.Frame(root, bg='light blue', width=450, height=50, pady=3)
    center = tk.Frame(root, bg='white', width=450, height=40, padx=3, pady=3)
    btm_frame = tk.Frame(root, bg='white', width=450, height=45, pady=3)
    
    
    # layout all of the main containers
    root.grid_rowconfigure(1, weight=1)
    root.grid_columnconfigure(0, weight=1)
    
    top_frame.grid(row=0, sticky="ew")
    center.grid(row=1, sticky="nsew")
    btm_frame.grid(row=3, sticky="ew")
    
    # create the widgets for the top frame
    
    #hello user 
    hello = tk.Label(top_frame, text="Hello, user! \n log out", bg="#334BFF", fg="white", width =20, height = 10)
    hello.grid(row = 0, column=0)
    
    #clock
    clock = tk.Label(top_frame,bg="#334BFF", fg="white", width =20, height = 10)
    clock.grid(row = 0, column=1)
    
    #menu
    menu = tk.Label(top_frame, text="Menu", bg="#334BFF", fg="white", width =20, height = 10)
    menu.grid(row =0, column =2)
    
    #datedisp
    date = tk.Label(top_frame, text='Date: ' + f"{now:%d %B %Y}", bg="#334BFF", fg="white",  height = 10, width =20)
    date.grid(row =0, column =3)
    
    #countdown
    countdown = tk.Label(top_frame, bg="#334BFF", fg="white", width =20,  height = 10)
    countdown.grid(row =0, column =4)
    
    
    #clock function
    time1=''
    def tick(time1):
        
        time2 = time.strftime('%H:%M:%S')
        if time2 != time1:
            time1=time2
            clock.config(text='Time: '+time2)
        clock.after(200,tick) #every 200 ms to stop it from being glitchy
    
    #countdown clock function
    countdownMins=1860
    
    def countdownClock(countdownMins,time_left,time_passed):

        if countdownMins>0:
            countdownMins = countdownMins-1
            countdown.after(1000, countdownClock) #every 1000ms = 1s
            countdown.config(text='countdown: '+f"{countdownMins}")
            time_passed = time_passed+1
            time_left = time_left -1
            pie_chart(time_passed, time_left)
        else:
            tk.messagebox.showinfo("Stand up")
            countdownMins = 1860
            time_passed = -60
            time_left = 1860
            pie_chart(time_passed, time_left)
            
    #pie chart function
    time_passed = -1 #-1 to initialize
    time_left = 1801 #30 mins in seconds 
    
    def pie_chart(time_passed, time_left):
        chartLabels= ['time passed', 'time left']
        chartVar = [time_passed, time_left]
      
        fig = Figure() # create a figure object
        ax = fig.add_subplot(111) # add an Axes to the figure
        ax.pie(chartVar, radius=1, labels=chartLabels,autopct='%0.2f%%', shadow=False)
        circle = plt.Circle( (0,0), 0.7, color='white')
        ax.add_artist(circle)
        plt.show()
        chart1 = FigureCanvasTkAgg(fig,center)
        chart1.get_tk_widget().grid(row=1, column=3)
        
    #heat map
    def create_HM(data):
        
        f, ax = plt.subplots(figsize=(4,6))
        sb.heatmap(data)
       # countdown.after(1000, data_HM())
        return f
    
    def data_HM():
        data = np.random.rand(4, 6)
        return data
    
    data= data_HM()
    #heat map
    fig_HM = create_HM(data)
    heat_map =  FigureCanvasTkAgg(fig_HM, center)
    heat_map.get_tk_widget().grid(row =1, column = 1)  # A tk.DrawingArea.
    heat_map.draw()
    
    # Create an object of tkinter ImageTk
    badge = Image.open("badgeIcon.jpg")
    re_badge = badge.resize((50,50), Image.ANTIALIAS)
    new_badge= ImageTk.PhotoImage(re_badge)
    # Create a Label Widget to display the text or Image
    badgeLabel = tk.Button(btm_frame, image = new_badge, command =popUpPages.openBadge)
    badgeLabel.grid(row=3, column =0)
    
    # Create an object of tkinter ImageTk
    report = Image.open("reportIcon.png")
    re_report = report.resize((50,50), Image.ANTIALIAS)
    new_report= ImageTk.PhotoImage(re_report)
    # Create a Label Widget to display the text or Image
    reportLabel = tk.Button(btm_frame, image = new_report, command = popUpPages.openReport)
    reportLabel.grid(row=3, column =1)
    
    # Create an object of tkinter ImageTk
    insights = Image.open("insightsIcon.png")
    re_insights = insights.resize((50,50), Image.ANTIALIAS)
    new_insights= ImageTk.PhotoImage(re_insights)
    # Create a Label Widget to display the text or Image
    insightsLabel = tk.Button(btm_frame, image = new_insights, command = popUpPages.openInsights)
    insightsLabel.grid(row=3, column =2)
    
    #call functions
    countdownClock(countdownMins,time_left,time_passed)
    tick(time1)
    root.mainloop()
    
#main()