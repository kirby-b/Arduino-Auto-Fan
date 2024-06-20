# Arduino Auto Fan

Building an arduino device that turns on a fan when my room gets too hot.

## How to use

Build the device as instructed in the blueprint and instruction manual provided. Then make sure you have the .ino file running on your arduino device (upload with Arduino IDE). I used the Arduino from the Elegoo Super Starter Kit.

If you want to when the fan turns on or how fast, but change the parameters in the ino file (at the bottom) for the if that turns it on (temp/humidity threshhold) and the DIRA to any number between 1-255 (speed)

## How it works

The arduino auto fan is pretty simple and a good part is based on elegoos example projects. The DHT sensor hooks right into the arduino and you get the tempurature and humidity through the designated pin (2). It then sends that info to the fan control function that turns on the fan if it detects a certain temp/humidity.

The fan is controlled by a L293D motor controller and is powered by a breadboard power supply (make sure to push the power button) the arduino controls the motor controller that lets through power when the arduino tells it to turn on the fan.

*I cannot say I am an expert on electronics, I do this as a hobby, so if I am wrong about any of this please let me know*
