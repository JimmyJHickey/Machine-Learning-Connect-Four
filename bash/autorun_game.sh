#!/bin/bash

i=0

python3 -m compileall ../src/game.py

while [ $i -lt 1024 ]
do
	python3 ../src/game.py
	((i++))
done
