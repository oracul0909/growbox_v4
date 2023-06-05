#ifndef DHT_DRIVER_H
#define DHT_DRIVER_H

#include <Adafruit_Sensor.h>
#include "DHT.h"
#include "avr/io.h"
//#include "Arduino.h"

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

    
    int get_temperature(void);
    int get_temperature(int addr);
    int get_temperature_middle();
    int get_temperature_delta();
    int get_humidity(void);
    int get_humidity(int addr);
};

#endif