#include <Arduino.h>
#include "drivers/DHT_driver.h"

// put function declarations here:
int myFunction(int, int);


DHT_driver DHT_11(2);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  DHT_11.get_temperature();
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}