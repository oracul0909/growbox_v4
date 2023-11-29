#include "Services.h"

extern int16_t data[array_length];
extern int16_t InternalData[_enum_dat_internal_count+1];
// #define data(x) data[x]

CSMS_driver CSMS(CSMS_PIN);
DHT_driver DHT_inside(DHT_INSIDE_PIN);
DHT_driver DHT_outside(DHT_OUTSIDE_PIN);
DHT_driver DS(DS18B20_PIN);

Section Section_general;
Section Section_1(WHITE_PIN_1, FITO_PIN_1, PUMP_PIN_1);
Section Section_2(WHITE_PIN_2, FITO_PIN_2, PUMP_PIN_2);
Section Section_3(WHITE_PIN_3, FITO_PIN_3, PUMP_PIN_3);
Section Section_4(WHITE_PIN_4, FITO_PIN_4, PUMP_PIN_4);
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
    data[temp_outside] = DHT_outside.get_temperature_middle();
    data[hum_inside] = DS.get_humidity_middle();
    data[hum_outside] = DHT_outside.get_humidity_middle();
    data[ground_hum] = CSMS.get_moisture_middle(5);
    data[water_tank_status] = Tank.get_state();
    data[lock_status] = Lock.get_state();
    InternalData[_enum_Temp_inside_top_temp] = DHT_inside.get_temperature_middle();


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

    InternalData[_enum_Temp_inside_top_status] = DHT_inside.Status;
    InternalData[_enum_Temp_inside_botom_status] = DS.Status;
    InternalData[_enum_Temp_outside_top_status] = DHT_outside.Status;

    if(InternalData[_enum_Temp_inside_top_status]==0xff || InternalData[_enum_Temp_outside_top_status]==0xff )
    WDT_AUTORESET();
}

void service_climate_control()
{
    if (data[temp_inside] > (data[temp_required]))
    {
        Climate.cool_down(5, 3);
    }
    else
    if (data[temp_inside] < (data[temp_required]))
    {
        Climate.warm_up(5, 3);
    }
    else
    {
        if (data[hum_inside] > (data[hum_required]))
        {
            Climate.drain(3, 3);
        }
        if (data[hum_inside] < (data[hum_required]))
        {
            Climate.humidify();
        }
        if (data[hum_inside] == (data[hum_required]))
        {
           // Climate.mix();
        }
    }
    Climate.system_run();
}

void service_section_control()
{
    Section_general.set_params(data[white_bright_general],
                               data[fito_bright_general],
                               data[time_day],
                               data[time_night],
                               data[fito_start_general],
                               data[fito_stop_general],
                               data[pump_work_general],
                               data[pump_pause_general]);
    Section_1.set_params(data[white_bright_1],
                         data[fito_bright_1],
                         data[white_start_1],
                         data[white_stop_1],
                         data[fito_start_1],
                         data[fito_stop_1],
                         data[pump_work_1],
                         data[pump_pause_1]);
    Section_2.set_params(data[white_bright_2],
                         data[fito_bright_2],
                         data[white_start_2],
                         data[white_stop_2],
                         data[fito_start_2],
                         data[fito_stop_2],
                         data[pump_work_2],
                         data[pump_pause_2]);
    Section_3.set_params(data[white_bright_3],
                         data[fito_bright_3],
                         data[white_start_3],
                         data[white_stop_3],
                         data[fito_start_3],
                         data[fito_stop_3],
                         data[pump_work_3],
                         data[pump_pause_3]);
    Section_4.set_params(data[white_bright_4],
                         data[fito_bright_4],
                         data[white_start_4],
                         data[white_stop_4],
                         data[fito_start_4],
                         data[fito_stop_4],
                         data[pump_work_4],
                         data[pump_pause_4]);
    Section_general.white_control(data[white_wm_general], 100 );
    Section_general.fito_control(data[fito_wm_general], 100 );
    Section_1.white_control(data[white_wm_1], Section_general.white_now);
    Section_2.white_control(data[white_wm_2],Section_general.white_now);
    Section_3.white_control(data[white_wm_3],Section_general.white_now);
    Section_4.white_control(data[white_wm_4],Section_general.white_now);
    Section_1.fito_control(data[fito_wm_1],Section_general.fito_now);
    Section_2.fito_control(data[fito_wm_2],Section_general.fito_now);
    Section_3.fito_control(data[fito_wm_3],Section_general.fito_now);
    Section_4.fito_control(data[fito_wm_4],Section_general.fito_now);
    Section_1.pump_control(data[pump_wm_1], data[ground_hum_min_1], data[ground_hum_max_1]);
    Section_2.pump_control(data[pump_wm_2], data[ground_hum_min_2], data[ground_hum_max_2]);
    Section_3.pump_control(data[pump_wm_3], data[ground_hum_min_3], data[ground_hum_max_3]);
    Section_4.pump_control(data[pump_wm_4], data[ground_hum_min_4], data[ground_hum_max_4]);
}





void service_data_handler()
{
    static bool inited = false;
    if(!inited)
    {
        Modbus_Driver_Init();
        Nextion_driver_init();
        inited = true;    
    }

    uint8_t f_writed_data = 0x00; 

    if(Modbus_Driver_handler()==ModbusDriver_rsv_comp){f_writed_data++;}

    uint8_t f_data_enum =  Nextion_driver_receive();


    if(f_writed_data!=0x00 || ((f_data_enum!= time) & (f_data_enum !=0xff)) || data[_EEprom_save]==1)
    {
        data[_EEprom_save]=0;
        EEPROM_Save();
    }

    Nextion_driver_transmit_ring();
}




void service_init_mem()
{
  deb_print("proc->eep-0x00");
  delay(1000);
  EEPROM_status_t memStatus_t = EEPROM_Load();
    if(memStatus_t!= EEPROM_status_OK)
    {
        Nextion_driver_init();
        delay(250);
        Nextion_driver_transmit_Now("page 18");

        switch((uint8_t)memStatus_t)
        {
            case (uint8_t)EEPROM_status_ERR_CRC:
                Nextion_driver_transmit_Now("t1.txt=\"eep0x00->0x05\"");
                deb_print("ERROR");
                deb_print("eep0x00->0x05");
            break;

            case (uint8_t)EEPROM_status_MAP_INVALID:
                Nextion_driver_transmit_Now("t1.txt=\"eep0x00->0x04\"");
                deb_print("ERROR");
                deb_print("eep0x00->0x04");
                delay(5000);
                Nextion_driver_transmit_Now("t0.txt=\"proc->0x02\"");
                deb_print("proc->0x02");
                Nextion_driver_transmit_Now("t1.txt=\"eep0x02->0x00\"");
                deb_print("eep0x02->0x00");
                delay(5000);
                if(EEPROM_Remap()!=EEPROM_status_OK)
                {
                    Nextion_driver_transmit_Now("t0.txt=\"ERROR\"");
                    deb_print("ERROR");
                    Nextion_driver_transmit_Now("t1.txt=\"eep0x03->0x05\"");
                    deb_print("eep0x03->0x05");
                }
                else
                {
                    Nextion_driver_transmit_Now("t0.txt=\"Done\"");
                    deb_print("Done");
                    Nextion_driver_transmit_Now("t1.txt=\"eep0x03->0x00\"");
                    deb_print("eep0x03->0x00");
                }

            break;         

            case (uint8_t)EEPROM_status_OUT_OF_MEM:
                Nextion_driver_transmit_Now("t1.txt=\"eep0x00->0x02\"");
            break;  

            default:
                Nextion_driver_transmit_Now("t1.txt=\"eep0x00->0x01\"");
            break;       
        }

        while(true){}
    }
}


void service_wdt_ini()
{
    WDT_INI();
}


void service_wdt()
{
    WDT_RESET();
}

void TimeToReset()
{
    static int16_t last_time;
        if((last_time>60) && data[time]==0)
           WDT_AUTORESET(); 
    last_time = data[time];
}