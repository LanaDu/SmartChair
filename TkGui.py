import popUpPages
import GUIFunc as fun
from PIL import ImageTk, Image
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

origTime = round(time.time())

root = tk.Tk()
root.title('Smart Chair UI')
root.geometry('{}x{}'.format(460, 350))

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

# hello user
hello = tk.Label(top_frame, text="Hello " + " log out",
                 bg="#334BFF", fg="white", width=20, height=10)
hello.grid(row=0, column=0)

# clock
clock = tk.Label(top_frame,bg="#334BFF", fg="white", width=20, height=10)
clock.grid(row=0, column=1)

# menu
menu = tk.Label(top_frame, text="Menu", bg="#334BFF",
                fg="white", width=20, height=10)
menu.grid(row=0, column=2)

# datedisp
date = tk.Label(top_frame, bg="#334BFF", fg="white", height=10, width=20)
date.grid(row=0, column=3)

# countdown
countdown = tk.Label(top_frame,bg="#334BFF", fg="white", width=20, height=10)
countdown.grid(row=0, column=4)


def tick():
    now = datetime.now()
    timeNow = round(time.time())- origTime
    timeToGo = (30*60)-timeNow
    countdown.configure(text='Time passed: ' + f"{timeNow}")
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
    ax.pie(chartVar, startangle =90,radius=1, labels=chartLabels,
           autopct='%0.2f%%', shadow=False)
    circle = plt.Circle((0, 0), 0.7, color='white')
    ax.add_artist(circle)
    plt.show()
    chart1 = FigureCanvasTkAgg(fig, center)
    chart1.get_tk_widget().grid(row=1, column=3)

# heat map


def create_HM(dataBot,dataTop):
    #fig size is (rows, columns)
    f, ax = plt.subplots(2,1, figsize=(6, 6))
    hmTop = sb.heatmap(dataTop, cmap=ListedColormap(['green', 'orange', 'red']),ax=ax[0])
    hmTop.set_xlabel('X-Axis', fontsize=10)
    hmTop.set_ylabel('Y-Axis', fontsize=10)

    hmBot=sb.heatmap(dataBot,cmap=ListedColormap(['green', 'orange', 'red']), ax=ax[1])
    hmBot.set_xlabel('X-Axis', fontsize=10)
    hmBot.set_ylabel('Y-Axis', fontsize=10)
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
insightsLabel = tk.Button(btm_frame, image=new_insights,
                          command=popUpPages.openInsights)
insightsLabel.grid(row=3, column=2)

tick()
root.mainloop()
