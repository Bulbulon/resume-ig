from random import random
from typing import Callable

import numpy as np


class Neuron:
    __slots__ = 'state', 'bias', 'weights', 'learning_rate'

    def __init__(self, state: float = random(), bias: float = random(), learning_rate: float = 0.1) -> None:
        self.state = state
        self.bias = bias
        self.learning_rate = learning_rate

        self.weights = []

    def __repr__(self) -> str:
        return f'Neuron({self.state=:3f}, {self.bias=:3f}, {self.weights=})'

    def setWeights(self, weights: np.ndarray): self.weights = weights

    def Calculate(self, activation_func: Callable, values: list[float]) -> None:
        self.state = activation_func(self.bias + sum(weight * value for weight, value in zip(self.weights, values)))

    def AdjustWeights(self, outputs: list[float], wanted_outputs: list[float]):
        # delta rule
        for weight in self.weights:
            weight += sum((self.learning_rate * (output - wanted_output) * self.state) for output, wanted_output in zip(outputs, wanted_outputs))

        # perceptron variation
        # for weight in self.weights:
        #     weight += self.learning_rate * (wanted_outputs - outputs) * self.state
