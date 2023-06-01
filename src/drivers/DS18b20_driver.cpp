#include "DS18B20_driver.h"


int DS18B20_driver::get_temperature()
{
    return get_temperature(0);
}

int DS18B20_driver::get_temperature(int addr)
{
    ds18b20.requestTemperatures();
    return ds18b20.getTempCByIndex(addr);
}