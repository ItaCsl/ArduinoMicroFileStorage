import tkinter as tk
import time

def open_badbox():
    window = tk.Toplevel()
    window.title("BAD")

    label = tk.Label(window, text="BAD BAD BAD", font=("Arial Narrow",100), fg="red")
    label.pack(expand=True)

    window.protocol("WM_DELETE_WINDOW", open_multiple)

    # while True:
    #     time.sleep(0.05)
    #     label.config(fg="black")
    #     root.update()
    #     time.sleep(0.05)
    #     label.config(fg="red")
    #     root.update()

def open_multiple():
    for i in range(5):
        open_badbox()


def on_close():
    root.destroy()

root = tk.Tk()
root.withdraw()
open_badbox()
root.mainloop()
exit()