import pandas as pd
import os
from sklearn.neural_network import MLPClassifier
import pickle
import settings

settings.init()


class NeuralNet:

    def __init__(self,
                 data,
                 out_path):
        self.data = data
        self.out_path = out_path

    def make_network(self):
        x = self.data.iloc[:, :-1]
        y = self.data.iloc[:, -1:]

        nn = MLPClassifier(activation="tanh",
                           solver="sgd",
                           hidden_layer_sizes=(10, 10),
                           alpha=0.0001,
                           learning_rate_init=0.01,
                           learning_rate='constant',
                           max_iter=5000,
                           batch_size=5000,
                           tol=0.00001,
                           shuffle=True,
                           verbose=True)
        nn.fit(x, y)
        pickle.dump(nn, open(self.out_path, 'wb'))


d = pd.read_csv(os.path.abspath('../data/6vR.csv'), header=None)
myNN = NeuralNet(d, os.path.abspath("../trained_networks/6vRliterally10nodes.sav"))
myNN.make_network()
