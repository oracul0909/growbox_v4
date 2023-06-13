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

    //Возвращает значение температуры датчика DHT
    int8_t get_temperature(void);

    //Возвращает значение температуры датчика DHT (адрес значения не имеет)
    int8_t get_temperature(int addr);

    //Возвращает значение температуры датчика DHT
    int8_t get_temperature_middle();

    //Возвращает значение температуры датчика DHT
    int8_t get_temperature_delta();

    //Возвращает значение влажности датчика DHT
    uint8_t get_humidity(void);

    //Возвращает значение влажности датчика DHT (адрес значения не имеет)
    uint8_t get_humidity(int addr);
};

#endif