#include "Climate_system.h"
#include "Data.h"

extern int16_t data[array_length];
extern int16_t InternalData[_enum_dat_internal_count+1];

void Climate_system::cool_down(uint16_t work_time, uint16_t pause_time)
{
    if(Last_operation!= cooling)
    {
        Start_delta = abs(data[temp_inside] - data[temp_outside]);
        force_operation = None;
    }
    Last_operation = cooling;
    if(Start_delta < abs(abs(data[temp_inside] - data[temp_outside])- Climate_delta_coeff)) //Если он греется сам по себе
    {
        force_operation = cooling;
    }

    if (time_new <= data[time])
    {
        timer_flag = !timer_flag;
    }
    if ((data[temp_inside] <= (data[temp_outside]+1)) || force_operation == cooling)
    {
        if (timer_flag == true)
        {
            time_new = data[time] + work_time;
            mask = (Cooler_mask | Fan_inside_mask);
        }
        else if (timer_flag == false)
        {
            time_new = data[time] + pause_time;
            mask = Fan_inside_mask;
        }
    }
    else
    {
        mask = Fan_outside_mask;
        force_operation = None;
    }
}

void Climate_system::warm_up(uint16_t work_time, uint16_t pause_time)
{
    if(Last_operation!= heating)
    {
        Start_delta = abs(data[temp_outside] - data[temp_inside]);
        force_operation = None;
    }
    Last_operation = heating;

    if(Start_delta  < abs(abs(data[temp_outside] - data[temp_inside]) - Climate_delta_coeff)) //Если он остывает сам по себе
    {
        force_operation = heating;
    }

    if (time_new <= data[time])
    {
        timer_flag = !timer_flag;
    }
    if ((data[temp_inside] >= (data[temp_outside]-1)) || force_operation == heating)
    {
        if (timer_flag == true)
        {
            time_new = data[time] + work_time;
            if((InternalData[_enum_Temp_inside_top_temp]<55) && (data[temp_inside]<55))
            mask = (Heater_mask | Fan_inside_mask);
        }
        else if (timer_flag == false)
        {
            time_new = data[time] + pause_time;
            mask = Fan_inside_mask;
        }
    }
    else
    {
        mask = Fan_outside_mask;
    }
}

void Climate_system::humidify()
{
    if (data[hum_inside] >= data[hum_outside])
    {
        mask = Humidifier_mask;
    }
    else
    {
        mask = Fan_outside_mask;
    }
    force_operation = None;
    Last_operation = None;
}

void Climate_system::drain(uint16_t freeze_time, uint16_t defrost_time)
{
    if (time_new <= data[time])
    {
        timer_flag = !timer_flag;
    }
    if (data[hum_inside] <= data[hum_outside])
    {
        /*if (timer_flag == true) {
            time_new = data[time] + freeze_time;
            mask = Cooler_mask;
        }
        else if (timer_flag == false)
        {
            time_new = data[time] + defrost_time;
            mask = Heater_mask;
        }*/
    }
    else
    {
        mask = Fan_outside_mask;
    }
    Last_operation = None;
    force_operation = None;
}

void Climate_system::mix()
{
    if (time_new <= data[time])
    {
        timer_flag = !timer_flag;
    }
    if (timer_flag == true)
    {
        time_new = data[time] + data[fan_inside_work];
        mask = (Fan_inside_mask);
    }
    else if (timer_flag == false)
    {
        time_new = data[time] + data[fan_inside_pause];
        mask = None_mask;
    }
    force_operation = None;
    Last_operation = None;
}

void Climate_system::stop()
{
    mask = None_mask;
}

void Climate_system::system_run()
{
    if ((mask & ((byte)Fan_outside_mask)) > 0)
    {
        Fan_outside.run(true);
    }
    else
    {
        Fan_outside.run(false);
    }

    if ((mask & ((byte)Fan_inside_mask)) > 0)
    {
        Fan_inside.run(true);
    }
    else
    {
        Fan_inside.run(false);
    }

    if ((mask & ((byte)Humidifier_mask)) > 0)
    {
        Humidifier.run(true);
    }
    else
    {
        Humidifier.run(false);
    }

    if ((mask & ((byte)Cooler_mask)) > 0)
    {
        Cooler.run(true);
    }
    else
    {
        Cooler.run(false);
    }

    if ((mask & ((byte)Heater_mask)) > 0)
    {
        Heater.run(true);
    }
    else
    {
        Heater.run(false);
    }
}

void Climate_system::devices_status()
{

    if ((mask & ((byte)Fan_outside_mask)) > 0)
    {
        data[fan_outside_status] = 0x01;
    }
    else
    {
        data[fan_outside_status] = 0x00;
    }

    if ((mask & ((byte)Fan_inside_mask)) > 0)
    {
        data[fan_inside_status] = 0x01;
    }
    else
    {
        data[fan_inside_status] = 0x00;
    }

    if ((mask & ((byte)Humidifier_mask)) > 0)
    {
        data[humidifier_status] = 0x01;
    }
    else
    {
        data[humidifier_status] = 0x00;
    }

    if ((mask & ((byte)Cooler_mask)) > 0)
    {
        data[cooler_status] = 0x01;
    }
    else
    {
        data[cooler_status] = 0x00;
    }

    if ((mask & ((byte)Heater_mask)) > 0)
    {
        data[heater_status] = 0x01;
    }
    else
    {
        data[heater_status] = 0x00;
    }
}