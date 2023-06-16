#include "Climate_system.h"
#include "Data.h"

extern uint16_t data[array_length];

void Climate_system::cool_down()
{
    if(data[temp_inside] >= data[temp_outside])
    {
        Fan_outside.stop();
        Cooler.work_on_time(10, 10, data[time]);
        Fan_inside.run();
    }
    else
    {
        Fan_outside.run();
    }
}

void Climate_system::warm_up()
{
    if(data[temp_inside] <= data[temp_outside])
    {
        Fan_outside.stop();
        Heater.work_on_time(5, 5, data[time]);
        Fan_inside.run();
    }
    else
    {
        Fan_outside.run();
    }
}

void Climate_system::humidify()
{
    if(data[hum_inside] <= data[hum_outside])
    {
        Fan_outside.stop();//code
        Humidifier.run();
    }
    else
    {
        Fan_outside.run();
    }
}

void Climate_system::drain()
{
    if(data[hum_inside] >= data[hum_outside])
    {
        Fan_outside.stop();//code
    }
    else
    {
        Fan_outside.run();
    }
}

void Climate_system::stop()
{
    Cooler.stop();
    Heater.stop();
    Fan_inside.stop();
    Fan_outside.stop();
}