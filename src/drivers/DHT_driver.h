#ifndef DHT_DRIVER_H
#define DHT_DRIVER_H

#include <Adafruit_Sensor.h>
#include "DHT.h"


#define DEBUG
#if defined(DEBUG)
    #define  deb_print(x) Serial.println(x)
 #else
    #define  deb_print(x) 
 #endif


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
        deb_print("DHT11 Start");
        delay(150);
        pin = _pin;
        dht.begin();
        deb_print("DHT11 END");
    }

    //Возвращает значение температуры датчика DHT
    int8_t get_temperature(void);

    //Возвращает значение температуры датчика DHT (адрес значения не имеет)
    int8_t get_temperature(int addr);

    //Возвращает значение температуры датчика DHT
    int8_t get_temperature_middle(void);

    //Возвращает значение температуры датчика DHT
    int8_t get_temperature_delta(void);

    //Возвращает значение влажности датчика DHT
    uint8_t get_humidity(void);

    //Возвращает значение влажности датчика DHT (адрес значения не имеет)
    uint8_t get_humidity(int addr);
};

#endif