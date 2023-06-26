#include "Section.h"

extern uint16_t data[array_length];

void Section::white_control(int work_mode)
{
    switch (work_mode)
    {
    case 0:
        white_now = 0;
        break;
    case 1:
        if (data[time] >= data[time_day] && data[time] < data[time_night])
        {
            white_now = white_bright;
        }
        else
        {
            white_now = 0;
        }
        break;
    case 2:
        white_now = General->white_now;
        break;
    case 3:
        white_now = white_bright;
        break;
    }
    LED_white.set_bright(white_now);
    LED_white.change_bright();
}

void Section::fito_control(int work_mode)
{
    switch (work_mode)
    {
    case 0:
        LED_fito.set_bright(0);
        fito_now = 0;
        break;
    case 1:
        if (data[time] >= fito_start && data[time] < fito_stop)
        {
            fito_now = fito_bright;
        }
        else
        {
            fito_now = 0;
        }
        break;
    case 2:
        fito_now = General->fito_bright;
        break;
    case 3:
        fito_now = fito_bright;
        break;
    }
    LED_fito.set_bright(fito_now);
    LED_fito.change_bright();
}

void Section::pump_control(int work_mode, uint16_t ground_hum_min, uint16_t ground_hum_max)
{
    bool pump_flag;
    if (data[water_tank_status] > 1)
    {
        switch (work_mode)
        {
        case 0:
            pump_flag = false;
            break;
        case 1:
            Pump.work_on_time(pump_work, pump_pause, data[time]);
            break;
        case 2:
            if (data[ground_hum] >= ground_hum_max)
            {
                pump_flag = false;
            }
            else if (data[ground_hum] < ground_hum_min)
            {
                pump_flag = true;
            }
            break;
        case 3:
            pump_flag = true;
            break;
        }
    }
    else
    {
        pump_flag = false;
    }
    Pump.run(pump_flag);
}

void Section::set_params(uint16_t _white_bright,
                         uint16_t _fito_bright,
                         uint16_t _fito_start,
                         uint16_t _fito_stop,
                         uint16_t _pump_work,
                         uint16_t _pump_pause)
{
    white_bright = _white_bright;
    fito_bright = _fito_bright;
    fito_start = _fito_start;
    fito_stop = _fito_stop;
    pump_work = _pump_work;
    pump_pause = _pump_pause;
}