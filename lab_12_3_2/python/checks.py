import interface
import tkinter.messagebox as box

def check_size(size_field):

    n = size_field.get()
    error = 0

    try:
        n = int(n)
    except:
        box.showerror('Error', "The number of elements must be an integer")
        error = 1
        n = 0

    if not error and n <= 0:
        box.showerror('Error', "The number of elements must be a positive integer")
        error = 1
        n = 0

    return error, n


def check_array(array_field):

    arr_str = array_field.get()
    error = 0
    arr = []

    try:
        arr = [int(x) for x in arr_str.split()]
    except:
        box.showerror('Error', "Array elements must be integers")
        error = 1

    return error, arr


def check_number(number_field):

    n = number_field.get()
    error = 0

    try:
        n = int(n)
    except:
        box.showerror('Error', "The number of elements must be an integer")
        error = 1
        n = 0

    return error, n
