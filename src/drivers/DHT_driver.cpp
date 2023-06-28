#include "DHT_driver.h"


int8_t DHT_driver::get_temperature()
{
    #ifdef DEBUG3
        int8_t data = dht.readTemperature();
        deb3_print(String("Hum ") + String(data));
        return data;
    #else
        return dht.readTemperature();
    #endif
}

int8_t DHT_driver::get_temperature(int addr)
{
    #ifdef DEBUG3
        int8_t data = get_temperature();
        deb3_print(String("T ") + String(data));
        return data;
    #else
        return get_temperature();
    #endif
}

int8_t DHT_driver::get_temperature_middle()
{
    return get_temperature();
}

int8_t DHT_driver::get_temperature_delta()
{
    return get_temperature();
}

uint8_t DHT_driver::get_humidity()
{
 #ifdef DEBUG3
    uint8_t data = (dht.readHumidity());
    deb3_print(String("Hum ") + String(data));
    return data;
 #else
    return uint8_t(dht.readHumidity());
 #endif
}


uint8_t DHT_driver::get_humidity(int addr)
{
 #ifdef DEBUG3
    uint8_t data = (dht.readHumidity());
    deb3_print(String("Hum ") + String(data));
    return data;
 #else
    return uint8_t(dht.readHumidity());
 #endif
}