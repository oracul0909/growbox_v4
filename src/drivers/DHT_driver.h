#ifndef DHT_DRIVER_H
#define DHT_DRIVER_H

#include <Adafruit_Sensor.h>
#include "DHT.h"


//#define DEBUG3
#ifdef DEBUG3
    #define  deb3_print(x) Serial.println(x)
 #else
    #define  deb3_print(x) 
 #endif


#define _cfg_DhtDriver_count_of_update_crc 30
#define _cfg_DhtDriver_count_of_err_crc 20

class DHT_driver
{
private:
    uint8_t pin;
    DHT dht{pin, DHT11};
    int16_t temperature;
    int16_t humidity;

    //Serivis F
    uint8_t counter_of_update_crc;

    void crcCheck();
    void reInit();
    int32_t Temperature;
    int32_t HUM;


public:
    DHT_driver(uint8_t _pin)
    {
        deb3_print("DHT11 Start");
        pin = _pin;
        dht = DHT(pin, DHT11);
        dht.begin();
        deb3_print("DHT11 END");
    }

    int16_t Status = 0x00;
    //Возвращает значение температуры датчика DHT
    int16_t get_temperature(void);

    //Возвращает значение температуры датчика DHT (адрес значения не имеет)
    int16_t get_temperature(int addr);

    //Возвращает значение температуры датчика DHT
    int16_t get_temperature_middle(void);

    //Возвращает значение температуры датчика DHT
    int16_t get_temperature_delta(void);

    //Возвращает значение влажности датчика DHT
    int16_t get_humidity(void);

    //Возвращает значение влажности датчика DHT (адрес значения не имеет)
    int16_t get_humidity(int addr);

    
    int16_t get_humidity_middle();
};

#endif