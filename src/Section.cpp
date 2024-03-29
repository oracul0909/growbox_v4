#include "Section.h"

extern int16_t data[array_length];

uint8_t Section::white_control(int work_mode, int16_t _GeneralWhite)
{
    switch (work_mode)
    {
    case 0: // выкл
        LED_white.set_bright(0);
        white_now = 0;
        break;
    case 3: // вкл всегда
        white_now = white_bright;
    break;
    case 1: // индивидуально
        if ((data[time] >= white_start) & (data[time] < white_stop))
        {
            white_now = white_bright;
        }
        else
        {
            white_now = 0;
        }
        break;
    case 2: // по общему
        white_now = _GeneralWhite;
        break;
    }
    if(white_pin != 0xff)
    {
        LED_white.set_bright(white_now);
        LED_white.change_bright();
    }

    return white_now;
}

uint8_t Section::fito_control(int work_mode, int16_t _GeneralFito)
{
    switch (work_mode)
    {
    case 0: // выкл
        LED_fito.set_bright(0);
        fito_now = 0;
        break;

    case 3: // вкл всегда
        fito_now = fito_bright;
    break;
    case 1: // индивидуально
        if ((data[time] >= fito_start) & (data[time] < fito_stop))
        {
            fito_now = fito_bright;
        }
        else
        {
            fito_now = 0;
        }
        break;
    case 2: // по общему
        fito_now = _GeneralFito;
        break;

    }
    if(fito_pin != 0xff)
    {
        LED_fito.set_bright(fito_now);
        LED_fito.change_bright();
    }
    return fito_now;
}

void Section::pump_control(int work_mode, int16_t ground_hum_min, int16_t ground_hum_max)
{
    if (data[water_tank_status] > 1)
    {
        switch (work_mode)
        {
        case 0: // выкл
            Pump.run(false);
            break;
        case 1: // по времени
            Pump.work_on_time(pump_work, pump_pause, data[time]);
            break;
        case 2: // по датчику
            if (data[ground_hum] >= ground_hum_max)
            {
                Pump.run(false);
            }
            else if (data[ground_hum] < ground_hum_min)
            {
                Pump.run(true);
            }
            break;
        case 3: // вкл всегда
            Pump.run(true);
            break;
        }
    }
    else
    {
        Pump.run(false);
    }
}

void Section::set_params(int16_t _white_bright,
                         int16_t _fito_bright,
                         int16_t _white_start,
                         int16_t _white_stop,
                         int16_t _fito_start,
                         int16_t _fito_stop,
                         int16_t _pump_work,
                         int16_t _pump_pause)
{
    white_bright = _white_bright;
    fito_bright = _fito_bright;
    white_start = _white_start;
    white_stop = _white_stop;
    fito_start = _fito_start;
    fito_stop = _fito_stop;
    pump_work = _pump_work;
    pump_pause = _pump_pause;
}