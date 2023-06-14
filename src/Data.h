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
    white_bright_1,
    white_bright_2,
    white_bright_3,
    white_bright_4,
    fito_bright_1,
    fito_bright_2,
    fito_bright_3,
    fito_bright_4,
    white_bright_general,
    fito_bright_general,

    //полив
    water_tank_status,
    pump_1_status,
    pump_2_status,
    pump_3_status,
    pump_4_status,
    
    //время
    time,
    time_day,
    time_night,
    fito_start_1,
    fito_start_2,
    fito_start_3,
    fito_start_4,
    fito_stop_1,
    fito_stop_2,
    fito_stop_3,
    fito_stop_4,
    pump_1_work,
    pump_2_work,
    pump_3_work,
    pump_4_work,
    pump_1_pause,
    pump_2_pause,
    pump_3_pause,
    pump_4_pause,
    fito_start_general,
    fito_stop_general,
    pump_work_general,
    pump_stop_general,

    //режим работы(work_mode)
    //0 - принудительно остановлен
    //1 - выключен
    //2 - включен (автоматический алгоритм)
    //3 - включен (ручной алгоритм)
    white_wm_1,
    white_wm_2,
    white_wm_3,
    white_wm_4,
    fito_wm_1,
    fito_wm_2,
    fito_wm_3,
    fito_wm_4,
    pump_wm_1,
    pump_wm_2,
    pump_wm_3,
    pump_wm_4,
    white_wm_general,
    fito_wm_general,
    pump_wm_general,


    //длина массива
    array_length
};

#endif