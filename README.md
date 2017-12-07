# Computers *Attempting* to Kick Human Butt at Connect 4

## About

This is the final project for CS 467: Machine Learning by [JimmyJHickey](https://github.com/JimmyJHickey) and [BAndrewss](https://github.com/bandrewss).

We created a Connect 4 game. There are four different types of players that can participate: Human, Random, and Minimax and Neural Network players to play it.

## Starting the Game

* Have Python 3 installed.

* Navigate to the /src directory in a terminal or cmd.

* Run the game.py file with 2 arguments.

  * `python3 game.py *arg1 arg2*`

* These arguments specify which type of player will be player 1 and 2 respectively. These are the options:
  * `human` - a human player
  * `random` - a random player
  * `mini_easy` - a minimax player of depth 3
  * `mini_medium` - a minimax player of depth 5
  * `mini_hard` - a minimax player of depth 6
  * `net_random` - neural network player trained against random data
  * `net_easy` - neural network player consisting of one layer of 4 nodes
  * `net_medium` - neural network player consisting of 100 | 100 nodes
  * `net_hard` - neural network player consisting of 1000 | 1000 nodes

---

## About the project

#### The Python Files
* `game.py` contains the game and game board logic.
* `players.py` contains all of the different player base logic.
* `supervised_net.py` contains all of the neural network training logic.
* `minimax.py` contains all of the minimax logic.
* `settings.py` contains all of the shared data for players and game.

#### The Data
All of the data that was used to train neural networks is stored in /data.

All of the trained neural network data is stored in /trained_networks.

#### Reports
Both the proposal and final paper were written in LaTeX. The TeX and the PDFs that were created are in /Reports.

The Jupyter Notebook used for the presentation is in /src so it works correctly with our Python.
It is best viewed on the [Github](https://github.com/JimmyJHickey/Machine-Learning-Connect-Four/blob/master/src/Presentation.ipynb).
(www.github.com/JimmyJHickey/Machine-Learning-Connect-Four)
