#include "Arduino.h"
#include "IRbreak.h"

IRbreak::IRbreak(int SENSORPIN)
{
    pinMode(SENSORPIN, INPUT);
    digitalWrite(SENSORPIN, HIGH); 
    _SENSORPIN=SENSORPIN;
    int sensorstate;
}

int IRbreak::getStatus()
{
    return(digitalRead(_SENSORPIN));
}
