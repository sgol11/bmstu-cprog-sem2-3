from tkinter import *
import arr_processing


def main_window():

    window = Tk()
    window.title('Array processing')
    window.geometry('500x270')
    window.configure(bg='black')

    btn_bg_color = "black"
    btn_fg_color = "white"
    btn_width = 45

    Label(window, bg=btn_bg_color).pack(pady=5)

    first_array_text = Label(window, text="First array: ",
                             bg=btn_bg_color, fg=btn_fg_color)
    first_array_text.pack()
    first_array_field = Label(window, text="Empty",
                              bg=btn_bg_color, fg=btn_fg_color)
    first_array_field.pack()

    second_array_text = Label(window, text="Second array: ",
                              bg=btn_bg_color, fg=btn_fg_color)
    second_array_text.pack()
    second_array_field = Label(window, text="Empty",
                               bg=btn_bg_color, fg=btn_fg_color)
    second_array_field.pack()

    btn_fill = Button(window, text="Fill the first array with prime numbers",
                      bg=btn_bg_color, fg=btn_fg_color, width=btn_width,
                      command=lambda bg=btn_bg_color, fg=btn_fg_color, field=first_array_field:
                      input_size_window(bg, fg, field))
    btn_fill.pack(pady=5)

    btn_fill = Button(window, text="Input the first array",
                      bg=btn_bg_color, fg=btn_fg_color, width=btn_width,
                      command=lambda bg=btn_bg_color, fg=btn_fg_color, field=first_array_field:
                      input_array_window(bg, fg, field))
    btn_fill.pack(pady=5)

    btn_transfer = Button(window, text="Transfer numbers from the first array to the second\n\
(with the insertion of a given number after each even)",
                          bg=btn_bg_color, fg=btn_fg_color, width=btn_width,
                          command=lambda bg=btn_bg_color, fg=btn_fg_color, i_field=first_array_field,
                          o_field=second_array_field: input_num_window(bg, fg, i_field, o_field))
    btn_transfer.pack(pady=5)

    window.mainloop()


def input_size_window(btn_bg_color, btn_fg_color, output_field):

    input_size = Toplevel()
    input_size.geometry("300x100")
    input_size.configure(bg="black")
    input_size.title("Input size")

    Label(input_size, text="Enter the size of array:",
          bg=btn_bg_color, fg=btn_fg_color).pack(pady=5)

    entry_size = Entry(input_size, justify=RIGHT)
    entry_size.pack(pady=5)

    btn_fill = Button(input_size, text="Fill",
                      bg=btn_bg_color, fg=btn_fg_color, width=10,
                      command=lambda i_field=entry_size, o_field=output_field:
                      arr_processing.fill_arr(i_field, o_field))
    btn_fill.pack(pady=5)


def input_array_window(btn_bg_color, btn_fg_color, output_field):

    input_size = Toplevel()
    input_size.geometry("300x100")
    input_size.configure(bg="black")
    input_size.title("Input array")

    Label(input_size, text="Enter an array (the elements are separated by a space):",
          bg=btn_bg_color, fg=btn_fg_color).pack(pady=5)

    entry_arr = Entry(input_size, width=30, justify=RIGHT)
    entry_arr.pack(pady=5)

    btn_input = Button(input_size, text="Input",
                      bg=btn_bg_color, fg=btn_fg_color, width=10,
                      command=lambda i_field=entry_arr, o_field=output_field:
                      arr_processing.input_arr(i_field, o_field))
    btn_input.pack(pady=5)


def input_num_window(btn_bg_color, btn_fg_color, input_field, output_field):

    input_size = Toplevel()
    input_size.geometry("400x220")
    input_size.configure(bg="black")
    input_size.title("Input number and choose the allocation method")

    Label(input_size, text="Enter number to insert after each even in the array:",
          bg=btn_bg_color, fg=btn_fg_color).pack(pady=5)

    entry_num = Entry(input_size, justify=RIGHT)
    entry_num.pack(pady=5)

    Label(input_size, text="Choose the memory allocation method:",
          bg=btn_bg_color, fg=btn_fg_color).pack(pady=5)

    r_var = IntVar(input_size)
    r_var.set(0)
    r1 = Radiobutton(input_size,
                     text='Estimate the maximum possible size of the array\nand allocate memory with a margin',
                     variable=r_var, value=0, bg=btn_bg_color, fg=btn_fg_color)
    r1.pack()
    r2 = Radiobutton(input_size,
                     text='Firstly call the library function to find out the required array size,\n\
then allocate memory and call the function again',
                     variable=r_var, value=1, bg=btn_bg_color, fg=btn_fg_color)
    r2.pack()

    btn_transfer = Button(input_size, text="Transfer",
                          bg=btn_bg_color, fg=btn_fg_color, width=10,
                          command=lambda i_field=input_field, n_field=entry_num, o_field=output_field, m=r_var:
                          arr_processing.transfer_arr(i_field, n_field, o_field, m))
    btn_transfer.pack(pady=5)
