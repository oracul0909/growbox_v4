#include "Nextion_driver.h"
#include "./Data.h"
#include "./Utils/CRC_module.h"


extern uint16_t data[array_length];

#define _DATA_ADR data

    uint8_t _nextion_driver_ring[] =
    {
 temp_inside,
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
    pump_1_status,
    pump_2_status,
    pump_3_status,
    pump_4_status,
    water_tank_status,
    lock_status,
    heater_status,
    cooler_status,
    humidifier_status,
    fan_inside_status,
    fan_outside_status,

    // время и временные установки
    time,
    time_day,
    time_night,
    day_phase,
    time_format,
    white_start_1,
    white_start_2,
    white_start_3,
    white_start_4,
    white_stop_1,
    white_stop_2,
    white_stop_3,
    white_stop_4,
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
    pump_pause_general,
    fan_inside_work,
    fan_inside_pause,

    // режим работы индивидуальный(work_mode)
    // 0 - принудительно остановлен
    // 1 - включен (индивидуальная схема работы)
    // 2 - включен (групповая схема работы)
    // 3 - включен постоянно
    white_wm_1,
    white_wm_2,
    white_wm_3,
    white_wm_4,
    fito_wm_1,
    fito_wm_2,
    fito_wm_3,
    fito_wm_4,

    // режим работы индивидуальный(work_mode)
    // 0 - принудительно остановлен
    // 1 - включен по времени
    // 2 - включен по датчику влажности
    // 3 - включен постоянно
    pump_wm_1,
    pump_wm_2,
    pump_wm_3,
    pump_wm_4,

    // режим работы общий
    // 0 - принудительно остановлен
    // 1 - включен по времени
    // 2 - включен всегда
    white_wm_general,
    fito_wm_general,
    pump_wm_general,

    //уровень CO2
    CO2_day,
    CO2_night,

    };






void Nextion_driver_init()
{
    _CFG_NEXTION_DRIVER_PORT.begin(_CFG_NEXTION_DRIVER_BAUD);
}

/// @brief Принятие данных с экрана
uint8_t Nextion_driver_receive()
{
    if(_CFG_NEXTION_DRIVER_PORT.available()>6)
    {
        String msg = _CFG_NEXTION_DRIVER_PORT.readStringUntil(_CFG_NEXTION_DRIVER_Base_msg_devider);

    	uint8_t count_of_operators=0;

	    char *p = (char *)msg.c_str();
        char *str;

        String messages[_CFG_NEXTION_DRIVER__MAX_OPERATORS_COUNT];

        while ((str = strtok_r(p, " *#:&", &p)) != NULL)
        {
            if(count_of_operators<_CFG_NEXTION_DRIVER__MAX_OPERATORS_COUNT)
            {
                String dat = String(str);
                dat.trim();
                messages[count_of_operators] = dat;
                count_of_operators++;
            }
        }
    
        if(count_of_operators>1)
        {
            int dest = messages[0].toInt();
            int val = messages[1].toInt();
            _DATA_ADR[dest] = val;
            return (uint8_t)dest;
        }
    }
    return 0xff;
}


uint8_t _Nextion_driver_ring_MaxCount = sizeof(_nextion_driver_ring);
/// @brief Передача соббщений по кольцу
void Nextion_driver_transmit_ring()
{
   if( _CFG_NEXTION_DRIVER_PORT.availableForWrite()<255)
   {
    static uint8_t Ring_pos = 0x00;
    _CFG_NEXTION_DRIVER_PORT.print(_CFG_NEXTION_DRIVER_Base_msg);
    _CFG_NEXTION_DRIVER_PORT.print(Ring_pos, DEC);
    _CFG_NEXTION_DRIVER_PORT.print(_CFG_NEXTION_DRIVER_Base_msg2);
    _CFG_NEXTION_DRIVER_PORT.print('=');

    switch(Ring_pos)
    {
        case temp_inside:
            _CFG_NEXTION_DRIVER_PORT.print(String((int16_t)data[_nextion_driver_ring[Ring_pos]]));
        break;

        case temp_inside_day:
            _CFG_NEXTION_DRIVER_PORT.print(String((int16_t)data[_nextion_driver_ring[Ring_pos]]));
        break;

        case temp_inside_night:
            _CFG_NEXTION_DRIVER_PORT.print(String((int16_t)data[_nextion_driver_ring[Ring_pos]]));
        break;

        case temp_required:
            _CFG_NEXTION_DRIVER_PORT.print(String((int16_t)data[_nextion_driver_ring[Ring_pos]]));
        break;

        case temp_outside:
            _CFG_NEXTION_DRIVER_PORT.print(String((int16_t)data[_nextion_driver_ring[Ring_pos]]));
        break;

        default:
            _CFG_NEXTION_DRIVER_PORT.print(String(data[_nextion_driver_ring[Ring_pos]]));
        break;
    }



    





    _NextionDriver_endOfMsg();
    Ring_pos++;
    if(Ring_pos>= _Nextion_driver_ring_MaxCount)Ring_pos=0x00;
   }
}

/// @brief Передача прямого сообщения 
/// @param msg Сообщение
void Nextion_driver_transmit_Now(String msg)
{
    _CFG_NEXTION_DRIVER_PORT.print(msg);
    _NextionDriver_endOfMsg();
}


void _NextionDriver_endOfMsg()
{
    _CFG_NEXTION_DRIVER_PORT.write(0xFF);
    _CFG_NEXTION_DRIVER_PORT.write(0xFF);
    _CFG_NEXTION_DRIVER_PORT.write(0xFF);
}
