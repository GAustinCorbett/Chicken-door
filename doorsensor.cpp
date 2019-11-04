/*
    doorsensor.cpp - constructor & methods for doorsensor.h, a library for interacting with the
    reed switch door sensors and the arduino
    Created by G. Austin Corbett gaustincorbett@gmail.com 2019
    Released under GPLv3
*/

#include "Arduino.h"
#include "doorsensor.h"

//Class constructor, sets the class input int as the input pin for the sensor
doorsensor::doorsensor(int SENSORPIN)
{
    _SENSORPIN = SENSORPIN;
    pinMode(_SENSORPIN, INPUT);
    //sets the logic trigger on arduino input pin as either 5V (high) or 3.3V (low):
    digitalWrite(_SENSORPIN, HIGH);
}

int doorsensor::getStatus()
{
   return digitalRead(_SENSORPIN); 
}
