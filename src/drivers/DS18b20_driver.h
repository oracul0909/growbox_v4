#ifndef DS18B20_DRIVER_H
#define DS18B20_DRIVER_H

#include "DallasTemperature.h"

class DS18B20_driver
{
private:
    uint8_t pin;
    OneWire OneWire{pin};
    DallasTemperature ds18b20{&OneWire};
    DeviceAddress *sensorsUnique;
    uint8_t count_sensors;
    int temperature;
    int humidity;

public:
    DS18B20_driver(uint8_t _pin)
    {
        pin = _pin;
        ds18b20.begin();
        count_sensors = ds18b20.getDS18Count();
        for (int i = 0; i < count_sensors; i++)
        {
            ds18b20.getAddress(sensorsUnique[i], i);
        }
    }

    //Возвращает температуру датчика с 0 индексом
    int8_t get_temperature(void);

    //Возвращает температуру датчика по индексу
    int8_t get_temperature(int index);

    //Возвращает среднюю температуру всех датчиков в группе
    int8_t get_temperature_middle();

    //Возвращает разницу между максимальной и минимальной температурой всех датчиков в группе
    int8_t get_temperature_delta();

    //Возвращает 0 (DS18b20 не измеряет влажность)
    uint8_t get_humidity(void);

    //Возвращает 0 (DS18b20 не измеряет влажность)
    uint8_t get_humidity(int index);
};

#endif