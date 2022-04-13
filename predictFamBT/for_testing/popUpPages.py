# -*- coding: utf-8 -*-
"""
Created on Tue Mar 22 20:36:42 2022

@author: lanad
"""
import tkinter as tk
from PIL import Image, ImageTk

def openBadge():
    badgePage = tk.Toplevel()
    badgePage.title("Badges")
    badgePage.geometry("200x200")
    topFrame = tk.Frame(badgePage)
    tk.Label(topFrame, text ="1/5 badges achieved:").grid(column = 0, row =1)
    #Create an object of tkinter ImageTk
    badge = Image.open("badgeIcon.jpg")
    re_badge = badge.resize((50, 50), Image.ANTIALIAS)
    new_badge = ImageTk.PhotoImage(re_badge)
    # Create a Label Widget to display the text or Image
    badgeLabel = tk.Label(badgePage, text="Stood after 30 minutes")
    badgeLabel.grid(row=1, column=2)
    badgeLabel = tk.Label(badgePage, image = new_badge)
    badgeLabel.grid(row=1, column=0)


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