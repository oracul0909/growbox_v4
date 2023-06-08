#include "Services.h"
#include "Data.h"
#include "Arduino_FreeRTOS.h"

extern Data_struct Data;
extern Settings_struct Settings;

void service_day_phase()
{
    if (Data.time >= Settings.time_day && Data.time < Settings.time_night)
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
    // code
}



void tasks_init()
{
    xTaskCreate(Task_1, "task1", 128, NULL, 1, NULL);
    xTaskCreate(Task_2, "task2", 128, NULL, 1, NULL);
}

void Task_1(void *pvParameters)
{
    (void)pvParameters;
    pinMode(LED_BUILTIN, OUTPUT);

    for (;;)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // wait for one second
        digitalWrite(LED_BUILTIN, LOW);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task_2(void *pvParameters) 
{
  (void) pvParameters;

  for (;;)
  {
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}