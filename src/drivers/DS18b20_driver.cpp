#include "DS18B20_driver.h"

void printAddress(DeviceAddress deviceAddress){
  for (uint8_t i = 0; i < 8; i++){
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}

int DS18B20_driver::get_temperature()
{
    return get_temperature(0);
}

int DS18B20_driver::get_temperature(int addr)
{
    ds18b20.requestTemperatures();
    return ds18b20.getTempCByIndex(addr);
}


int DS18B20_driver::get_temperature_middle()
{
    int sum = 0;
    int middle = 0;
    uint8_t count_success_get = 0;
    ds18b20.requestTemperatures();
    for(uint8_t i = 0; i < count_sensors; i++)
    {
        if(ds18b20.getAddress(sensorsUnique[i], i))
        {
            sum += ds18b20.getTempCByIndex(i);
            count_success_get ++;
        }
        else
        {
            printAddress(sensorsUnique[i]);
        }
    }
    if(count_success_get == 0)
    {
        return 0;
    }
    else
    {
        return (sum/count_sensors);
    }
    
}


int DS18B20_driver::get_temperature_delta()
{
    int min_temp = 0;
    int max_temp = 0;
    int delta = 0;
    uint8_t count_success_get = 0;
    ds18b20.requestTemperatures();
    for(uint8_t i = 0; i < count_sensors; i++)
    {
         if(ds18b20.getAddress(sensorsUnique[i], i))
        {
            //sum += ds18b20.getTempCByIndex(i);
            count_success_get ++;
        }
        else
        {
            printAddress(sensorsUnique[i]);
        }
    }
}

int DS18B20_driver::get_humidity()
{
    return 0;
}

int DS18B20_driver::get_humidity(int addr)
{
    return 0;
}