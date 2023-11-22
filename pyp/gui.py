import tkinter as tk

window = tk.Tk()
window.title("My Window")
window.geometry("200x200")

label = tk.Label(text="Hello, World!")
label.pack()

window.mainloop()
