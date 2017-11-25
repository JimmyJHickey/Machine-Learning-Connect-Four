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

        nn = MLPClassifier(hidden_layer_sizes=(100,), alpha=0.0001, learning_rate='constant', max_iter=5000)
        nn.fit(x, y)

        # TEST
        # x = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 1]]
        # print(nn.predict(x))

        pickle.dump(nn, open(self.out_path, 'wb'))


d = pd.read_csv(os.path.abspath('../data/jdata.csv'), header=None)
myNN = NeuralNet(d, os.path.abspath("../trained_networks/practice.sav"))
myNN.make_network()
