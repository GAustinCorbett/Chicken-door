/*
    doorsensor.cpp - constructor & methods for doorsensor.h, a library for interacting with the
    reed switch door sensors and the arduino.
    The reed switch should be connected with one leg going to sensor pin, and the other leg 
    going to GND.  (THIS IS VERY IMPORTANT, OTHERWISE SWITCH WILL NEVER TRIGGER.)
    Created by G. Austin Corbett gaustincorbett@gmail.com 2019
    Released under GPLv3
*/

#include "Arduino.h"
#include "doorsensor.h"

//Class constructor, sets the class input int as the input pin for the sensor
doorsensor::doorsensor(int SENSORPIN)
{
    _SENSORPIN = SENSORPIN;
    
    //This stabilizes the circuit against noise but inverts logic:
    pinMode(_SENSORPIN, INPUT_PULLUP);
 
    // Enables the internal pullup resistor to stabilize against noise. 
    digitalWrite(_SENSORPIN, HIGH);

}

int doorsensor::getStatus()
{
    if (digitalRead(_SENSORPIN))
    {
        return(0);    
    }
    else
    {
        return (1);
    } 
}
