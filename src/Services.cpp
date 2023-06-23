#include "Services.h"

extern uint16_t data[array_length];

// #define data(x) data[x]

CSMS_driver CSMS(CSMS_PIN);
DHT_driver DHT_inside(DHT_INSIDE_PIN);
DHT_driver DHT_outside(DHT_OUTSIDE_PIN);
DS18B20_driver DS(DS18B20_PIN);

Section Section_general;
Section Section_1(&Section_general, WHITE_PIN_1, FITO_PIN_1, PUMP_PIN_1);
Section Section_2(&Section_general, WHITE_PIN_2, FITO_PIN_2, PUMP_PIN_2);
Section Section_3(&Section_general, WHITE_PIN_3, FITO_PIN_3, PUMP_PIN_3);
Section Section_4(&Section_general, WHITE_PIN_4, FITO_PIN_4, PUMP_PIN_4);
Water_tank Tank(CONTROL_PIN, LOW_SWITCH_PIN, NORMAL_SWITCH_PIN);
Reed_switch_driver Lock(LOCK_PIN);

Climate_system Climate(HEATER_PIN, COOLER_PIN, HUMIDIFIER_PIN, FAN_INSIDE_PIN, FAN_OUTSIDE_PIN);

void service_day_phase()
{
    if (data[time] >= data[time_day] && data[time] < data[time_night])
    {
        data[day_phase] = 1;
        data[temp_required] = data[temp_inside_day];
        data[hum_required] = data[hum_inside_day];
    }
    else
    {
        data[day_phase] = 0;
        data[temp_required] = data[temp_inside_night];
        data[hum_required] = data[hum_inside_night];
    }
}

void service_sensors_run()
{
    data[temp_inside] = DS.get_temperature_middle();
    data[temp_outside] = DHT_outside.get_temperature();
    data[hum_inside] = DHT_inside.get_humidity();
    data[hum_outside] = DHT_outside.get_humidity();
    data[ground_hum] = CSMS.get_moisture_middle(5);
    data[water_tank_status] = Tank.get_state();
    data[lock_status] = Lock.get_state();
}

void service_devices_feedback()
{
    data[white_1_status] = Section_1.LED_white.get_state();
    data[white_2_status] = Section_2.LED_white.get_state();
    data[white_3_status] = Section_3.LED_white.get_state();
    data[white_4_status] = Section_4.LED_white.get_state();
    data[fito_1_status] = Section_1.LED_fito.get_state();
    data[fito_2_status] = Section_2.LED_fito.get_state();
    data[fito_3_status] = Section_3.LED_fito.get_state();
    data[fito_4_status] = Section_4.LED_fito.get_state();
    data[pump_1_status] = Section_1.Pump.get_state();
    data[pump_2_status] = Section_2.Pump.get_state();
    data[pump_3_status] = Section_3.Pump.get_state();
    data[pump_4_status] = Section_4.Pump.get_state();
    Climate.devices_status();
}

void service_climate_control()
{
    if (data[temp_inside] > (data[temp_required] + 1))
    {
        Climate.cool_down(10, 5);
    }
    else if (data[temp_inside] < (data[temp_required] - 1))
    {
        Climate.warm_up(5, 5);
    }
    else
    {
        if (data[hum_inside] > (data[hum_required] + 1))
        {
            Climate.drain(10, 5);
        }
        else if (data[hum_inside] < (data[hum_required] - 1))
        {
            Climate.humidify();
        }
        else
        {
            Climate.stop();
        }
    }
    Climate.system_run();
}

void service_section_control()
{
    Section_general.set_params(white_bright_general,
                               fito_bright_general,
                               fito_start_general,
                               fito_stop_general,
                               pump_work_general,
                               pump_pause_general);
    Section_1.set_params(white_bright_1,
                         fito_bright_1,
                         fito_start_1,
                         fito_stop_1,
                         pump_work_1,
                         pump_pause_1);
    Section_2.set_params(white_bright_2,
                         fito_bright_2,
                         fito_start_2,
                         fito_stop_2,
                         pump_work_2,
                         pump_pause_2);
    Section_3.set_params(white_bright_3,
                         fito_bright_3,
                         fito_start_3,
                         fito_stop_3,
                         pump_work_3,
                         pump_pause_3);
    Section_4.set_params(white_bright_4,
                         fito_bright_4,
                         fito_start_4,
                         fito_stop_4,
                         pump_work_4,
                         pump_pause_4);
    Section_general.white_control(data[white_wm_general]);
    Section_general.fito_control(data[fito_wm_general]);
    Section_1.white_control(data[white_wm_1]);
    Section_2.white_control(data[white_wm_2]);
    Section_3.white_control(data[white_wm_3]);
    Section_4.white_control(data[white_wm_4]);
    Section_1.fito_control(data[fito_wm_1]);
    Section_2.fito_control(data[fito_wm_2]);
    Section_3.fito_control(data[fito_wm_3]);
    Section_4.fito_control(data[fito_wm_4]);
    Section_1.pump_control(data[pump_wm_1], data[ground_hum_min_1], data[ground_hum_max_1]);
    Section_2.pump_control(data[pump_wm_2], data[ground_hum_min_2], data[ground_hum_max_2]);
    Section_3.pump_control(data[pump_wm_3], data[ground_hum_min_3], data[ground_hum_max_3]);
    Section_4.pump_control(data[pump_wm_4], data[ground_hum_min_4], data[ground_hum_max_4]);
}