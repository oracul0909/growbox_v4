#include "Tasks.h"
#include "Arduino.h"
#include "Services.h"
#include "Arduino_FreeRTOS.h"

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
        service_section_control();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // wait for one second
    }
}

void Task_2(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        int sensorValue = analogRead(A0);
        Serial.println(sensorValue);
        vTaskDelay(1); // one tick delay (15ms) in between reads for stability
    }
}