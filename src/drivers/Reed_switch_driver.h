#ifndef REED_SWITCH_DRIVER_H
#define REED_SWITCH_DRIVER_H
#include "arduino.h"

class Reed_switch_driver
{
private:
    int pin;

public:
    Reed_switch_driver(int _pin)
    {
        pin = _pin;
        pinMode(_pin, INPUT);
    }

    bool get_state();
};

#endif