from Layer import *


class Network:
    def __init__(self, shape: list[int]) -> None:
        self.shape: list[int] = shape  # example: [2, 3, 2]
        self.layers: list[Layer] = [Layer(i) for i in self.shape]

    def __getitem__(self, index: int):
        return self.layers[index]

    def __setitem__(self, index: int, value: Layer):
        self.layers[index] = value

    def __delitem__(self, index: int):
        del self.layers[index]

    def __len__(self) -> int:
        return len(self.shape)

    def __repr__(self) -> str:
        striper = ''
        for layer in self.layers:
            striper += repr(layer) + '\n'
        return striper

    @property
    def inputs(self) -> list[float]:
        return [neuron.state for neuron in self.layers[0]]

    @property
    def outputs(self) -> list[float]:
        return [neuron.state for neuron in self.layers[-1]]

    def Calculate(self, activation_func: Callable):
        for previous_layer, layer in zip(self.layers[:], self.layers[1:]):
            layer.Calculate(activation_func, previous_layer)

    def InitializeWeights(self) -> None:
        for layer, next_layer in zip(self.layers[:], self.layers[1:]):
            layer.InitializeWeights(next_layer)

    def SelectOutput(self) -> float:
        return max(self.outputs)

    def Cost(self, wanted_outputs: list[float]) -> float:
        return sum(((output - wanted_output) ** 2) * 0.5 for output, wanted_output in zip(self.outputs, wanted_outputs))

    def Backpropagation(self, wanted_outputs: list[float]) -> None:
        # cost: float = self.Cost(wanted_outputs)

        for i in reversed(range(len(self))):  # BACK-Propagation
            for j in range(len(self[i])):
                neuron = self[i][j]
                neuron.AdjustWeights(self.outputs, wanted_outputs)


class ActivationFunctions:  # Helper class
    @staticmethod
    def sigmoid(x: float):
        return 1 / (1 + np.exp(-x))

    @staticmethod
    def Relu(x: float):
        if x < 0:
            return 0
        else:
            return x

    @staticmethod
    def softMax(x: float):
        return np.exp(x) / np.sum(np.exp(x), axis=0)

    @staticmethod
    def Linear(x: float):
        return x
