#include "Reed_switch_driver.h"
#include "Arduino.h"

bool Reed_switch_driver::get_state()
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