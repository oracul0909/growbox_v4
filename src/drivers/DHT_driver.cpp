#include "DHT_driver.h"


int DHT_driver::get_temperature()
{
    return dht.readTemperature();
}

int DHT_driver::get_temperature(int addr)
{
    return get_temperature();
}

int DHT_driver::get_temperature_middle()
{
    return get_temperature();
}

int DHT_driver::get_temperature_delta()
{
    return get_temperature();
}

int DHT_driver::get_humidity()
{
    return dht.readHumidity();
}

int DHT_driver::get_humidity(int addr)
{
    return dht.readHumidity();
}