#include "Reed_switch_driver.h"
#include "Arduino.h"

bool Reed_switch_driver::get_state(int pin)
{
    if(digitalRead(pin))
    {
        return true;
    }
    else
    {
        return false;
    }
}