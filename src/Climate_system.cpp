#include "Climate_system.h"
#include "Data.h"

extern uint16_t data[array_length];

void Climate_system::cool_down(uint16_t work_time, uint16_t pause_time)
{
    if (time_new <= data[time])
    {
        timer_flag = !timer_flag;
    }
    if (data[temp_inside] >= data[temp_outside])
    {
        if (timer_flag == true)
        {
            time_new = time + work_time;
            mask = B10010;
        }
        else if (timer_flag == false)
        {
            time_new = time + pause_time;
            mask = B00010;
        }
    }
    else
    {
        mask = B00001;
    }
}

void Climate_system::warm_up(uint16_t work_time, uint16_t pause_time)
{
    if (time_new <= data[time])
    {
        timer_flag = !timer_flag;
    }
    if (data[temp_inside] <= data[temp_outside])
    {
        if (timer_flag == true)
        {
            time_new = time + work_time;
            mask = B10010;
        }
        else if (timer_flag == false)
        {
            time_new = time + pause_time;
            mask = B00010;
        }
    }
    else
    {
        mask = B00001;
    }
}

void Climate_system::humidify()
{
    if (data[hum_inside] <= data[hum_outside])
    {
        mask = B00100;
    }
    else
    {
        mask = B00001;
    }
}

void Climate_system::drain(uint16_t freeze_time, uint16_t defrost_time)
{
    if (time_new <= data[time])
    {
        timer_flag = !timer_flag;
    }
    if (data[hum_inside] >= data[hum_outside])
    {
        if (timer_flag == true)
        {
            time_new = time + freeze_time;
            mask = B01000;
        }
        else if (timer_flag == false)
        {
            time_new = time + defrost_time;
            mask = B10000;
        }
    }
    else
    {
        mask = B00001;
    }
}

void Climate_system::stop()
{
    mask = B00000;
}

void Climate_system::system_run()
{
    Fan_outside.run(mask & (1 << 0));
    Fan_inside.run(mask & (1 << 1));
    Humidifier.run(mask & (1 << 2));
    Cooler.run(mask & (1 << 3));
    Heater.run(mask & (1 << 4));
}

void Climate_system::devices_status()
{
    data[heater_status] = (mask & (1 << 4));
    data[cooler_status] = (mask & (1 << 3));
    data[humidifier_status] = (mask & (1 << 2));
    data[fan_inside_status] = (mask & (1 << 1));
    data[fan_outside_status] = (mask & (1 << 0));
}