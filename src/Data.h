#ifndef DATA_H
#define DATA_H

#include <Arduino.h>

enum 
{
    //температура воздуха
    temp_inside,
    temp_inside_day,
    temp_inside_night,
    temp_required,
    temp_outside,

    //влажность воздуха
    hum_inside,
    hum_inside_day,
    hum_inside_night,
    hum_required,
    hum_outside,

    //влажность почвы
    ground_hum_min,
    ground_hum_max,
    ground_hum,

    //освещенность
    section_1_white_bright,
    section_1_fito_bright,
    section_2_white_bright,
    section_2_fito_bright,
    section_3_white_bright,
    section_3_fito_bright,
    section_4_white_bright,
    section_4_fito_bright,

    //время
    time,
    time_day,
    time_night,

    //длина массива
    array_length
};

uint16_t data[array_length];


/*
struct Data_struct
{
    int temp_inside;       //температура внутри
    int hum_inside;        //влажность внутри
    int temp_outside;      //температура снаружи
    int hum_outside;       //влажность снаружи
    int light_intencity;   //освещенность
    int ground_hum;        //влажность почвы
    int lock_status;       //состояние замка блокировки
    int water_tank_status;
    int time;              //cуммарное время в минутах(для работы)
    int time_updated;      //флаг, чт0 дату/время поменяли
    int time_minute;       //минуты
    int time_hour;         //часы
    int time_date;         //число
    int time_month;        //месяц
    int time_year;         //год
};  // Data

struct Settings_struct
{
    int water_work_mode;   //принудительная остановка полива
    int fito_work_mode;    //принудительная остановка фито лампы
    int white_work_mode;   //принудительная остановка белой лампы
    int only_one_light;    //выключение белой лампы при работе фито
    int temp_inside_day;   //минимальный уровень температуры
    int temp_inside_night; //максимальный уровень температуры
    int temp_reqired;      //
    int hum_inside_day;    //минимальный уровень влажности
    int hum_inside_night;  //максимальный уровень влажности
    int hum_reqired;       //
    int ground_hum_min;    // минимальный уровень влажности почвы
    int ground_hum_max;    //максимальный уровень влажности почвы
    int time_day;          //время начала дневной фазы
    int time_night;        //время начала ночной фазы
    int fito_time_start;   //время начала работы фито лампы
    int fito_time_stop;    //время окончания работы фито лампы
    int light_intencity_border; //световой порог включения белой лампы
    int white_reqired;
    int fito_reqired;

};                              // Settings

struct Device_status_struct
{
    int water_pump_status;   //   состояние работы водяной помны
    int fito_light_status;   //   состояние работы фито света
    int white_light_status;  //   состояние работы белого света
    int fan_inside_status;   //   состояние работы внутреннего вентилятора
    int fan_outside_status;  //   состояние работы внешнего вентилятора
    int cooler_status;
    int heater_status;       //   состояние работы лампы обогрева
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
*/
#endif