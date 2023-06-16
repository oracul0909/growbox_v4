#include "CSMS_driver.h"
#include "Arduino.h"

uint8_t CSMS_driver::get_moisture_middle(uint8_t tick)
{
    int sum = 0;
    int moisture_temp = 0;
    //переделать потом на нормальный фильтр(Калман или скользящее среднее)
    for (uint8_t i = 0; i < tick; i++)
    {
        sum += int(analogRead(pin));
    }
    moisture_temp = sum / tick;
    if (moisture_temp < moisture_min)
    {
        moisture_min = moisture_temp;
    }
    if (moisture_temp > moisture_max)
    {
        moisture_max = moisture_temp;
    }
    uint8_t ground_humidity = 100 - constrain(map(moisture_temp, moisture_min, moisture_max, 0, 100), 0, 100);
    return ground_humidity;
}
