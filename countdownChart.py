import tkinter as tk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure

root = tk.Tk()
frameChartsLT = tk.Frame(root)
frameChartsLT.pack()

def pie_chart():
    stockListExp = ['AMZN' , 'AAPL', 'JETS', 'CCL', 'NCLH']
    stockSplitExp = [15,25,40,10,10]
    
    fig = Figure() # create a figure object
    ax = fig.add_subplot(111) # add an Axes to the figure
    
    ax.pie(stockSplitExp, radius=1, labels=stockListExp,autopct='%0.2f%%', shadow=True,)
    circle = plt.Circle( (0,0), 0.7, color='white')
    ax.add_artist(circle)
    plt.show()
    chart1 = FigureCanvasTkAgg(fig,frameChartsLT)
    chart1.get_tk_widget().pack()

pie_chart()
root.mainloop()