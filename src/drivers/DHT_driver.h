#ifndef DHT_DRIVER_H
#define DHT_DRIVER_H

#include <Adafruit_Sensor.h>
#include "DHT.h"

class DHT_driver
{
private:
    uint8_t pin;
    DHT dht{pin, DHT11};
    int temperature;
    int humidity;

public:
    DHT_driver(uint8_t _pin)
    {
        pin = _pin;
        dht.begin();
    }

    int8_t get_temperature(void);
    int8_t get_temperature(int addr);
    int8_t get_temperature_middle();
    int8_t get_temperature_delta();
    uint8_t get_humidity(void);
    uint8_t get_humidity(int addr);
};

#endif