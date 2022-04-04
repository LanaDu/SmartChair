# -*- coding: utf-8 -*-
"""
Created on Tue Mar 22 20:36:42 2022

@author: lanad
"""
import tkinter as tk

def openBadge():
    badgePage = tk.Toplevel()
    badgePage.title("Badges")
    badgePage.geometry("200x200")
    tk.Label(badgePage, text ="This is badges").pack()

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