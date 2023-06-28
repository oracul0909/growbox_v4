#ifndef REED_SWITCH_DRIVER_H
#define REED_SWITCH_DRIVER_H
#include "arduino.h"

class Reed_switch_driver
{
private:
    uint8_t pin;

public:
    Reed_switch_driver(uint8_t _pin)
    {
        pin = _pin;
        pinMode(_pin, INPUT_PULLUP);
    }

    bool get_state(void);
};

#endif