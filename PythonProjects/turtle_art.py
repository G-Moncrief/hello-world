#   Simple graphic produced by Turtle 
#
#   Written for Python 2.7
#
#   Udacity's Programming Foundations with Python - Project 3

import turtle


def draw_square(some_turtle):
    for i in range (0,4):
        some_turtle.forward(100)
        some_turtle.right(90)


def draw_art():
    window = turtle.Screen()
    window.bgcolor("green")

    #leonardo goes in squares
    leonardo = turtle.Turtle()
    leonardo.shape("turtle")
    leonardo.color("blue")
    leonardo.speed(2)
    draw_square(leonardo)

    #raphael goes in circles
    raphael = turtle.Turtle()
    raphael.shape("turtle")
    raphael.color("red")
    raphael.speed(3)
    raphael.circle(100)

    #mike goes in triangles
    mike = turtle.Turtle()
    mike.shape("turtle")
    mike.color("orange")
    mike.forward(200)
    mike.left(90)
    mike.forward(200)
    mike.left(135)
    mike.forward(282.84)

    #don goes round and round in circles
    don = turtle.Turtle()
    don.shape("turtle")
    don.color("purple")
    don.speed(10)
    for angle in range (0,360, 15):
            don.seth(angle)
            don.circle(200)
    
    window.exitonclick()

draw_art()
