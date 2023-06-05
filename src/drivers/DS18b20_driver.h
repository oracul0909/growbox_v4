#ifndef DS18B20_DRIVER_H
#define DS18B20_DRIVER_H

#include "avr/io.h"
#include "DallasTemperature.h"

class DS18B20_driver
{
private:
    uint8_t pin;
    OneWire OneWire{pin};
    DallasTemperature ds18b20{&OneWire};
    DeviceAddress *sensorsUnique;
    uint8_t count_sensors;
    int temperature;
    int humidity;

public:
    DS18B20_driver(uint8_t _pin)
    {
        pin = _pin;
        ds18b20.begin();
        count_sensors = ds18b20.getDS18Count();
        for (int i = 0; i < count_sensors; i++)
        {
            ds18b20.getAddress(sensorsUnique[i], i);
        }
    }

    int get_temperature(void);
    int get_temperature(int addr);
    int get_temperature_middle();
    int get_temperature_delta();
    int get_humidity(void);
    int get_humidity(int addr);
};

#endif