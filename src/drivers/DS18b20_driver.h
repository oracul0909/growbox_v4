#ifndef DS18B20_DRIVER_H
#define DS18B20_DRIVER_H

#include "DallasTemperature.h"
#include "Arduino.h"

class DS18B20_driver
{
private:
    uint8_t pin;
    OneWire OneWire{pin};
    DallasTemperature ds18b20{&OneWire};
    int temperature;
    int humidity;

public:
    DS18B20_driver(uint8_t _pin)
    {
        pin = _pin;
        ds18b20.begin();
    }

    int get_temperature(void);
    int get_temperature(int addr);
    int get_humidity(void);
    int get_humidity(int addr);
};

#endif