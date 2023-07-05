#include "DHT_driver.h"
#include "./Utils/CRC_module.h"

int16_t DHT_driver::get_temperature()
{
    #ifdef DEBUG3
        int8_t data = dht.readTemperature();
        deb3_print(String("Hum ") + String(data));
        return data;
    #else
        temperature = (int16_t)dht.readTemperature();
        crcCheck(); 
        return temperature;
    #endif
}

int16_t DHT_driver::get_temperature(int addr)
{
    #ifdef DEBUG3
        int8_t data = get_temperature();
        deb3_print(String("T ") + String(data));
        return data;
    #else
        return get_temperature();
    #endif
}

int16_t DHT_driver::get_temperature_middle()
{
    return get_temperature();
}

int16_t DHT_driver::get_temperature_delta()
{
    return get_temperature();
}

int16_t DHT_driver::get_humidity()
{
 #ifdef DEBUG3
    uint8_t data = (dht.readHumidity());
    deb3_print(String("Hum ") + String(data));
    return data;
 #else
    humidity = int16_t(dht.readHumidity());
    crcCheck();
    return humidity;
 #endif
}


int16_t DHT_driver::get_humidity(int addr)
{
 #ifdef DEBUG3
    uint8_t data = (dht.readHumidity());
    deb3_print(String("Hum ") + String(data));
    return data;
 #else
    return int16_t(dht.readHumidity());
 #endif
}

void DHT_driver::reInit()
{
    pinMode(pin, INPUT);
    dht = DHT(pin, DHT11);
    dht.begin();
}

void DHT_driver::crcCheck()
{
    static int8_t CRC = 0x00;
    static uint8_t TryOfReboot = 0x00;
    static uint8_t _err_count;

    if(counter_of_update_crc>_cfg_DhtDriver_count_of_update_crc)
    {
        int8_t CRC_now = (int8_t)temperature+(int8_t)humidity;

        if((CRC == CRC_now) &  (_err_count>_cfg_DhtDriver_count_of_err_crc))
        {
            reInit();
            TryOfReboot++;
            _err_count=0;
        }
        if(CRC != CRC_now)
        {
          _err_count = 0;  
        }
        if(TryOfReboot>5)
        {
            Status = 0xff;
        }

        CRC = CRC_now;
        counter_of_update_crc = 0;
    }
    counter_of_update_crc++;
}