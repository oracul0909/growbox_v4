#ifndef TASKS_H
#define TASKS_H


/*
    * Task Init's
*/

/// @brief 
void Core_tasks_init();

/// @brief 
void Machine_tasks_init();



/*
    * Core Tasks
*/

/// @brief
void Task_service_data(void *pvParameters);

/// @brief 
void Task_service_wdt(void *pvParameters);


/*
    * Machine Tasks
*/

void Task_service_day_phase(void *pvParameters);

void Task_service_sensors(void *pvParameters);

void Task_service_devices_feedback(void *pvParameters);

void Task_service_climate_control(void *pvParameters);

void Task_service_section_control(void *pvParameters);






#endif
