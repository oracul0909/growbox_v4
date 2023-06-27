#include "Tasks.h"
#include "Arduino.h"
#include "Services.h"
#include "Arduino_FreeRTOS.h"


void Core_tasks_init()
{
    deb_print("Start");
   service_init_mem();
   deb_print("mem_done");
   deb_print("Start core tasks");
   // xTaskCreate(Task_service_data, "Task_service_data", 1024, NULL, 1, NULL);
  //  xTaskCreate(Task_service_wdt, "Task_service_wdt", 64, NULL, 1, NULL);
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

    deb_print("Start data task");
    for (;;)
    {
        deb_print("Run data task");
        service_data_handler();
        vTaskDelay(50 / portTICK_PERIOD_MS); 
    }
}

void Task_service_wdt(void *pvParameters)
{
    (void)pvParameters;

    deb_print("Start wdt task");
    for (;;)
    {
        deb_print("Run wdt task");
        service_wdt();
        vTaskDelay(500 / portTICK_PERIOD_MS); 
    }
}


void Task_service_day_phase(void *pvParameters)
{
    (void)pvParameters;
    deb_print("Start day task");

    for (;;)
    {
        deb_print("Run day task");
        service_section_control();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // wait for one second
    }
}


void Task_service_sensors(void *pvParameters)
{
    (void)pvParameters;
    deb_print("Start sensors task");
    for (;;)
    {
        deb_print("Run Sensor task");
        service_sensors_run();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // one tick delay (15ms) in between reads for stability
    }
}


void Task_service_devices_feedback(void *pvParameters)
{
    (void)pvParameters;

    deb_print("Start feedback task");
    for (;;)
    {
        deb_print("Run feedback task");
        service_devices_feedback();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // one tick delay (15ms) in between reads for stability
    }
}


void Task_service_climate_control(void *pvParameters)
{
    (void)pvParameters;
    deb_print("Start climate task");
    for (;;)
    {
        deb_print("Run climate task");
        service_climate_control();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // one tick delay (15ms) in between reads for stability
    }
}


void Task_service_section_control(void *pvParameters)
{
    (void)pvParameters;
    deb_print("Start section task");
    for (;;)
    {
        deb_print("Run section task");
        service_section_control();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // one tick delay (15ms) in between reads for stability
    }
}