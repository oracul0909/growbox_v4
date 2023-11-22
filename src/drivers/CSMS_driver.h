/*Capacitive Soil Moisture Sensor driver*/
#ifndef CSMS_DRIVER_H
#define CSMS_DRIVER_H
#include "arduino.h"

class CSMS_driver
{
private:
    uint8_t pin;


public:
    CSMS_driver(uint8_t _pin)
    {
        pin = _pin;
        pinMode(_pin, INPUT);
    }

    uint8_t get_moisture_middle(uint8_t tick);

    int16_t moisture_min = 5000;
    int16_t moisture_max = 0;
    uint8_t changed = 0x00;
};

#endif