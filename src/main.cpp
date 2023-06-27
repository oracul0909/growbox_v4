#include <Arduino.h>
#include "Services.h"
#include "Tasks.h"


void setup()
{
  Serial.begin(9600);
  Core_tasks_init();
  //Machine_tasks_init();
}

void loop()
{

}