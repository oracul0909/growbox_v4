#ifndef LIGHT_DRIVER_H
#define LIGHT_DRIVER_H

#include "Arduino.h"

class Light_driver
{
private:
    int pin;
    uint8_t bright;
    uint8_t work_mode;

public:
    Light_driver(int _pin)
    {
        pin = _pin;
    }

    //Устанавливает уровень яркость в процентах
    void set_brightness(uint8_t _bright);

    void change_brightness();

    //Устанавливает режим работы лампы
    void set_work_mode(uint8_t _work_mode);
};

#endif