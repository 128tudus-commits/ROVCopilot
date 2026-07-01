#!/bin/bash

sudo apt update
sudo apt install -y ustreamer python3-flask python3-serial

python3 Control_Server.py & ustreamer --device=/dev/video1 --host=0.0.0.0 --port=8080 --desired-fps=30
