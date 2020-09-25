#	TAKE A BREAK 
#	Udacity's Programming Foundations with Python - Project 1
#
#	The goal of this project is to make a program that reminds user to take a break 
#	every two hours
#
#	Program written for Python 2.7.13

import time
import webbrowser

total_breaks = 3
count = 0

print ("This program started on " +time.ctime())
while (count < total_breaks):
    time.sleep(120)
    webbrowser.open("https://www.youtube.com/watch?v=DxtmQDCyLE8")
    count += 1
