#ifndef DATA_H
#define DATA_H

#include "Arduino.h"

struct Data_struct
{
    int temp_inside;     // 24 температура внутри
    uint8_t hum_inside;  // 25 влажность внутри
    int temp_outside;    // 26 температура снаружи
    uint8_t hum_outside; // 27 влажность снаружи
    int light_intencity; // 28 освещенность
    uint8_t ground_hum;  // 29 влажность почвы
    bool lock_status;    //   состояние замка блокировки
    int nextion_time;    //   cуммарное время в минутах(для работы)
    bool time_updated;   // 18 флаг, чт0 дату/время поменяли
    uint8_t time_minute; // 20 минуты
    uint8_t time_hour;   // 19 часы
    uint8_t time_date;   // 21 число
    uint8_t time_month;  // 22 месяц
    int time_year;       // 23 год
};                       // Data

struct Settings_struct
{
    int water_forcibly_stop;    // 7  принудительная остановка полива
    int fito_forcibly_stop;     // 12 принудительная остановка фито лампы
    int white_forcibly_stop;    // 15 принудительная остановка белой лампы
    int only_one_light;         // 13 выключение белой лампы при работе фито
    int temp_inside_day;        // 8  минимальный уровень температуры
    int temp_inside_night;      // 9  максимальный уровень температуры
    int hum_inside_day;         // 3  минимальный уровень влажности
    int hum_inside_night;       // 4  максимальный уровень влажности
    int ground_hum_min;         // 6  минимальный уровень влажности почвы
    int ground_hum_max;         // 5  максимальный уровень влажности почвы
    int day_time_start;         // 1  время начала дневной фазы
    int night_time_start;       // 2  время начала ночной фазы
    int fito_light_time_start;  // 10 время начала работы фито лампы
    int fito_light_time_stop;   // 11 время окончания работы фито лампы
    int light_intencity_border; // 14 световой порог включения белой лампы
};                              // Settings

struct Device_status_struct
{
    int water_pump_status;   //   состояние работы водяной помны
    int fito_light_status;   //   состояние работы фито света
    int white_light_status;  //   состояние работы белого света
    int fan_inside_status;   //   состояние работы внутреннего вентилятора
    int fan_outside_status;  //   состояние работы внешнего вентилятора
    int heater_lamp_status;  //   состояние работы лампы обогрева
    int overflow_led_status; //   состояние датчика перелива
    int wi_fi_status;        // 16 состояние wi-fi
    int bluetooth_status;    // 17 состояние bluetooth
};                           // Device_status

struct Main_data_struct
{
    Data_struct Data_2;
    Settings_struct Settings_2;
    Device_status_struct Device_status_2;
};

#endif