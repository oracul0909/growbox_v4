#include "Tasks.h"
#include "Arduino.h"
#include "Services.h"
#include "Arduino_FreeRTOS.h"


void Core_tasks_init()
{
   service_init_mem();
    xTaskCreate(Task_service_data, "Task_service_data", 1024, NULL, 1, NULL);
    xTaskCreate(Task_service_wdt, "Task_service_wdt", 64, NULL, 1, NULL);
}

void Machine_tasks_init()
{
    xTaskCreate(Task_service_day_phase, "Task_service_day_phase", 256, NULL, 1, NULL);
    xTaskCreate(Task_service_sensors, "Task_service_sensors", 512, NULL, 1, NULL);
    xTaskCreate(Task_service_devices_feedback, "Task_service_devices_feedback", 512, NULL, 1, NULL);
    xTaskCreate(Task_service_climate_control, "Task_service_climate_control", 128, NULL, 1, NULL);
    xTaskCreate(Task_service_section_control, "Task_service_section_control", 128, NULL, 1, NULL);
}


void Task_service_data(void *pvParameters)
{
    (void)pvParameters;


    for (;;)
    {
        service_data_handler();
        vTaskDelay(50 / portTICK_PERIOD_MS); 
    }
}

void Task_service_wdt(void *pvParameters)
{
    (void)pvParameters;
    for (;;)
    {
        service_wdt();
        vTaskDelay(500 / portTICK_PERIOD_MS); 
    }
}


void Task_service_day_phase(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        service_section_control();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // wait for one second
    }
}


void Task_service_sensors(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        service_sensors_run();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // one tick delay (15ms) in between reads for stability
    }
}


void Task_service_devices_feedback(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        service_devices_feedback();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // one tick delay (15ms) in between reads for stability
    }
}


void Task_service_climate_control(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        service_climate_control();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // one tick delay (15ms) in between reads for stability
    }
}


void Task_service_section_control(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        service_section_control();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // one tick delay (15ms) in between reads for stability
    }
}