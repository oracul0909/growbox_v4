#include "DHT_driver.h"


int8_t DHT_driver::get_temperature()
{
    return dht.readTemperature();
}

int8_t DHT_driver::get_temperature(int addr)
{
    return get_temperature();
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
    return uint8_t(dht.readHumidity());
}

uint8_t DHT_driver::get_humidity(int addr)
{
    return uint8_t(dht.readHumidity());
}