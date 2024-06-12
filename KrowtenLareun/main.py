from Network import *
import datasetGUI as gui


def main():
    network = Network([3, 4, 3])
    network.InitializeWeights()
    network.Calculate(ActivationFunctions.sigmoid)

    print(network)


if __name__ == '__main__':
    main()
