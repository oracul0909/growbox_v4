#include "Data.h"
#include "Arduino_FreeRTOS.h"
extern Data_struct Data;
extern Settings_struct Settings;
void Task_1(void *pvParameters);
void init(){
xTaskCreate(
    Task_1
    ,  "task1"   
    ,  128  
    ,  NULL
    ,  1  
    ,  NULL );
}
void service_day_phase()
{
    if(Data.time >= Settings.time_day && Data.time < Settings.time_night)
    {
        Settings.temp_reqired = Settings.temp_inside_day;
        Settings.hum_reqired = Settings.hum_inside_day;
    }
    else
    {
        Settings.temp_reqired = Settings.temp_inside_night;
        Settings.hum_reqired = Settings.hum_inside_night;
    }
}

void service_climat_control()
{
    //code
}