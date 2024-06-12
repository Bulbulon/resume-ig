from __future__ import annotations
from Neuron import *


class Layer:
    def __init__(self, width: int) -> None:
        self.neurons: np.ndarray = np.array([Neuron() for _ in range(width)])

    def __getitem__(self, index: int): return self.neurons[index]

    def __setitem__(self, index: int, value: Neuron): self.neurons[index] = value

    def __delitem__(self, index: int): del self.neurons[index]

    def __len__(self) -> int: return len(self.neurons)

    def __repr__(self) -> str:
        striper = ''
        for neuron in self.neurons:
            striper += repr(neuron) + '\n'
        return striper

    @property
    def states(self) -> list[float]: return [neuron.state for neuron in self.neurons]

    def Calculate(self, activation_func: Callable, previous_layer: Layer) -> None:
        for neuron in self.neurons:
            neuron.Calculate(activation_func, previous_layer.states)

    def InitializeWeights(self, next_layer: Layer):
        for i in range(len(next_layer)):
            next_layer[i].setWeights(np.random.random(len(self)))

