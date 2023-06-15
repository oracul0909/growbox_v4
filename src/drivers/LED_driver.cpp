#include "LED_driver.h"

void LED_driver::set_bright(uint8_t _bright_new)
{
    intencity_index_new = _bright_new/10;
}

void LED_driver::change_bright()
{
    if(intencity_index > intencity_index_new) {intencity_index--;}
    if(intencity_index < intencity_index_new) {intencity_index++;}
    set_bright(intencity_steps[intencity_index]);
}