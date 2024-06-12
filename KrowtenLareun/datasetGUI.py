from tkinter import *
from Network import *
from keras.datasets import mnist
from matplotlib import pyplot


def trainingWindow():
    global splitGUI, layersGUI, learnRateGUI

    train = Tk()
    train.title("training window")
    train.configure(background="gray")
    train.minsize(200, 200)
    train.maxsize(500, 500)
    train.geometry("500x500+100+100")

    splitGUI = Scale(train, from_=0, to=100, orient="horizontal", length=200)
    splitGUI.place(relx=0.5, rely=0.1, anchor=CENTER)

    splitLabel = Label(train, text="split %", background="gray", fg="black")
    splitLabel.place(relx=0.2, rely=0.1, anchor=CENTER)

    layersGUI = Text(train, height=1, width=20)
    layersGUI.place(relx=0.5, rely=0.3, anchor=CENTER)

    layerLabel = Label(train, text="layers", background="gray", fg="black")
    layerLabel.place(relx=0.2, rely=0.3, anchor=CENTER)

    learnRateGUI = Text(train, height=1, width=5)
    learnRateGUI.place(relx=0.5, rely=0.5, anchor=CENTER)

    rateLabel = Label(train, text="learn rate", background="gray", fg="black")
    rateLabel.place(relx=0.2, rely=0.5, anchor=CENTER)

    runButton = Button(train, text="run", command=run, padx=10, pady=10)
    runButton.place(relx=0.5, rely=0.7, anchor=CENTER)

    train.mainloop()


def run():
    global splitGUI, layersGUI, learnRateGUI
    split = splitGUI.get()
    layersTemp = layersGUI.get(1.0, "end-1c")
    learnRate = learnRateGUI.get(1.0, "end-1c")

    layers = []
    layers = layersTemp.split(',')


def dataSet():
    # loading
    (train_X, train_y), (test_X, test_y) = mnist.load_data()

    # shape of dataset
    print('X_train: ' + str(train_X.shape))
    print('Y_train: ' + str(train_y.shape))
    print('X_test:  ' + str(test_X.shape))
    print('Y_test:  ' + str(test_y.shape))

    # plotting
    for i in range(9):
        pyplot.subplot(330 + 1 + i)
        pyplot.imshow(train_X[i], cmap=pyplot.get_cmap('gray'))
    pyplot.show()


def graphData():
    print("graph data")


if __name__ == '__main__':
    dataSet()
