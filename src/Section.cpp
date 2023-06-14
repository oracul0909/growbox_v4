#include "Section.h"

void Section::white_control(int intencity)
{
    if (LED_white.get_work_mode() > 0)
    {
        LED_white.set_bright(intencity);
    }
    else
    {
        LED_white.set_bright(0);
    }
    LED_white.change_bright();
}

void Section::fito_control(int intencity)
{
    if (LED_fito.get_work_mode() > 0)
    {
        LED_fito.set_bright(intencity);
    }
    else
    {
        LED_fito.set_bright(0);
    }
    LED_fito.change_bright();
}

void Section::pump_control(int work, int pause, int time)
{
    if (Pump.get_work_mode() > 0)
    {
        Pump.run(work, pause, time);
    }
    else
    {
        Pump.run(0, pause, time);
    }
}

void Section::get_general()
{
    
}