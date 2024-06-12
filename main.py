from tkinter import *
from tkinter import filedialog
from moviepy.editor import *

fileName = ""


def gui():
    window = Tk()
    window.minsize(800, 600)

    global fileName, fileLabel

    # cut button
    cut_button = Button(window, text="cut", command=cut, padx=50, pady=30)
    cut_button.place(relx=0.5, rely=0.7, anchor=CENTER)

    # browse button
    browse_button = Button(window, text="browse", command=browse, padx=50, pady=30)
    browse_button.place(relx=0.5, rely=0.2, anchor=CENTER)

    # upload button
    upload_button = Button(window, text="upload", command=upload, padx=50, pady=30)
    upload_button.place(relx=0.3, rely=0.5, anchor=CENTER)

    # file name label
    fileLabel = Label(text=fileName)
    fileLabel.place(relx=0.5, rely=0.5, anchor=CENTER)

    window.mainloop()


def cut():
    global fileName
    clip = VideoFileClip(fileName)
    duration = clip.duration
    minutes = round(duration / 60) - 1
    for i in range(minutes - 1):
        clip1 = clip.subclip((i, 0), (i, 57)).resize((608, 1080))
        clip1.write_videofile(
            r'C:\Users\rafae\OneDrive\Рабочий стол\important shit\breaking bad' + str(i) + '#shorts' + '.mp4',
            codec='libx264')


def browse():
    global fileName, fileLabel
    browsed_name = filedialog.askopenfilename()
    fileName = browsed_name
    fileLabel.config(text=fileName)


def upload():
    print("a")


if __name__ == '__main__':
    gui()
