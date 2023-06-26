#include "Data.h"

uint16_t data[array_length];

uint8_t arrayOfNumbers[] = {temp_inside,
    temp_inside_day,
    temp_inside_night,
    temp_required,
    temp_outside,

    // влажность воздуха
    hum_inside,
    hum_inside_day,
    hum_inside_night,
    hum_required,
    hum_outside,

    // влажность почвы
    ground_hum,
    ground_hum_min_1,
    ground_hum_min_2,
    ground_hum_min_3,
    ground_hum_min_4,
    ground_hum_max_1,
    ground_hum_max_2,
    ground_hum_max_3,
    ground_hum_max_4,

    // интенсивносить освещения
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

    //статусы устройств (вкл.выкл)
    white_1_status,
    white_2_status,
    white_3_status,
    white_4_status,
    fito_1_status,
    fito_2_status,
    fito_3_status,
    fito_4_status,
    water_tank_status,
    pump_1_status,
    pump_2_status,
    pump_3_status,
    pump_4_status,

    // время и временные установки
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
    pump_work_1,
    pump_work_2,
    pump_work_3,
    pump_work_4,
    pump_pause_1,
    pump_pause_2,
    pump_pause_3,
    pump_pause_4,
    fito_start_general,
    fito_stop_general,
    pump_work_general,
    pump_pause_general};