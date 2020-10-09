#!/bin/sh
sudo rfcomm bind rfcomm0 20:16:11:14:59:88
sudo rfcomm watch rfcomm0 &
python ./getWeatherData.py > /dev/rfcomm0
sudo rfcomm release rfcomm0
sudo killall rfcomm
