#include "DHT_driver.h"


int DHT_driver::get_temperature()
{
    return dht.readTemperature();
}

int DHT_driver::get_temperature(int addr)
{
    return dht.readTemperature();
}


int DHT_driver::get_humidity()
{
    return dht.readHumidity();
}