# -*- coding: utf-8 -*-
"""
Created on Tue Mar 22 20:36:42 2022

@author: lanad
"""
import tkinter as tk
from tkinter import *
from PIL import Image, ImageTk

def openBadge():
    badgePage = tk.Toplevel()
    badgePage.title("Badges")
    badgePage.geometry("200x200")
    frameBadge = tk.Frame(badgePage)
    frameBadge.pack()

    bframe= tk.Frame(badgePage)
    tframe = tk.Frame(badgePage)
    tframe.pack(side=TOP)
    bframe.pack( side = TOP)

    tk.Label(tframe, text = "Badges achieved: 1/5").pack(side = TOP)
    tk.Label(bframe, text="Stood up after 30 minutes").pack(side=TOP)
    tk.Label(bframe, text="Remained in good posture for 5 minutes").pack(side=TOP)
    tk.Label(bframe, text="Remained in good posture for 15 minutes").pack(side=TOP)
    tk.Label(bframe, text="Stood up after 30 minutes 3 times in a row").pack(side=TOP)
    tk.Label(bframe, text="Stood up after 30 minutes 6 times in a row").pack(side=TOP)
def openInsights():
    insightsPage = tk.Toplevel()
    insightsPage.title("insights")
    insightsPage.geometry("200x200")
    tk.Label(insightsPage, text ="This is insights").pack()
    
def openReport():
    reportPage = tk.Toplevel()
    reportPage.title("report")
    reportPage.geometry("200x200")
    tk.Label(reportPage, text ="This is report").pack()