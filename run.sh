#!/bin/bash

sudo apt install -y ustreamer
python3 -m pip install --upgrade pip
python3 -m pip install pyserial flask

python3 Control_Server.py & ustreamer --device=/dev/video1 --host=0.0.0.0 --port=8080 --desired-fps=30
