#include "DS18B20_driver.h"

void printAddress(DeviceAddress deviceAddress)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        if (deviceAddress[i] < 16)
           Serial.print("0");
        Serial.print(deviceAddress[i], HEX);
    }
}

int8_t DS18B20_driver::get_temperature()
{
    return get_temperature(0);
}

int8_t DS18B20_driver::get_temperature(int index)
{
    ds18b20.requestTemperatures();
    return ds18b20.getTempCByIndex(index);
}

int8_t DS18B20_driver::get_temperature_middle()
{
    int sum = 0;
    uint8_t count_success_get = 0;
    ds18b20.requestTemperatures();
    for (uint8_t i = 0; i < count_sensors; i++)
    {
        if (ds18b20.getAddress(sensorsUnique[i], i))
        {
            sum += ds18b20.getTempCByIndex(i);
            count_success_get++;
        }
        else
        {
            printAddress(sensorsUnique[i]);
        }
    }
    if (count_success_get == 0)
    {
        return 0;
    }
    else
    {
        return int8_t(sum / count_sensors);
    }
}

int8_t DS18B20_driver::get_temperature_delta()
{
    int val_temp = 0;
    int min_temp = 0;
    int max_temp = 0;
    uint8_t count_success_get = 0;
    ds18b20.requestTemperatures();
    for (uint8_t i = 0; i < count_sensors; i++)
    {
        if (ds18b20.getAddress(sensorsUnique[i], i))
        {
            val_temp = ds18b20.getTempCByIndex(i);
            if (min_temp > val_temp)
            {
                min_temp = val_temp;
            }
            if (max_temp < val_temp)
            {
                max_temp = val_temp;
            }
            count_success_get++;
        }
        else
        {
            printAddress(sensorsUnique[i]);
        }
    }
    if (count_success_get == 0)
    {
        return 0;
    }
    else
    {
        return int8_t(max_temp - min_temp);
    }
}

uint8_t DS18B20_driver::get_humidity()
{
    return 0;
}

uint8_t DS18B20_driver::get_humidity(int addr)
{
    return 0;
}