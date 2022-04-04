# -*- coding: utf-8 -*-
"""
Created on Mon Mar 21 20:16:26 2022

@author: lanad
"""
from datetime import datetime 
import time
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure

#import the functions file 


countdownMins=31
time1=''
#clock = tk.Label(root, font=('times', 20, 'bold'), bg='green')
#clock.pack(fill='both', expand=1)
now = datetime.now()
print(now)
initial_time = time.strftime('%H:%M:%S')
time_passed = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
time_left = [30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0]

def countdownClock():
    global countdownMins
    if countdownMins>1:
        countdownMins = countdownMins-1
        countdown.after(60000, countdownClock)
        gui.countdown.config(text='countdown: '+f"{countdownMins}")
        
    else:
        tk.messagebox.showinfo("Stand up")
        countdownMins = 31

def tick():
    global time1
    time2 = time.strftime('%H:%M:%S')
    if time2 != time1:
        time1=time2
        clock.config(text='Time: '+time2)
    clock.after(200,tick) #every 200 ms to stop it from being glitchy

def pie_chart(time_passed, time_left,i):
    chartLabels= ['time passed', 'time left']
    chartVar = [time_passed[i], time_left[i]]
    if countdownMins>0:
        fig = Figure() # create a figure object
        ax = fig.add_subplot(111) # add an Axes to the figure
        ax.pie(chartVar, radius=1, labels=chartLabels,autopct='%0.2f%%', shadow=True,)
        circle = plt.Circle( (0,0), 0.7, color='white')
        ax.add_artist(circle)
        plt.show()
        chart1 = FigureCanvasTkAgg(fig,frameChartsLT)
        chart1.get_tk_widget().grid(row=1, column=2)
