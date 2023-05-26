#include <Arduino.h>
#include "ledcontrol.h"

LEDControl led(0, 2, 5000, 8);

void setup() {
  // put your setup code here, to run once:
  led.setup();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  led.loop();
}