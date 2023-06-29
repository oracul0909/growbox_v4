#include "LED_driver.h"

void LED_driver::set_bright(uint8_t _bright_new)
{
    intencity_index_new = _bright_new/10;
    
}

void LED_driver::change_bright()
{
    if(intencity_index > intencity_index_new) {intencity_index--;}
    else if(intencity_index < intencity_index_new) {intencity_index++;}
    analogWrite(pin,intencity_steps[intencity_index]);
}


bool LED_driver::get_state()
{
    if(intencity_index > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}