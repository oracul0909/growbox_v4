#include <Arduino.h>
#include "Services.h"
#include "Tasks.h"

void setup()
{
  Core_tasks_init();
  Machine_tasks_init();
  RunTasksMan();
}

void loop()
{

}