#include "IRbreak.h"

int SENSORPIN=7;
int lastState=0;
IRbreak beam(SENSORPIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
  if (beam.getStatus() && !lastState) {
    Serial.println("Unbroken");
  }
  if (beam.getStatus() && lastState) {
    Serial.println("Broken");
  }
  lastState = beam.getStatus();
}
