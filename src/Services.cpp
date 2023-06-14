#include "Services.h"
#include "Arduino_FreeRTOS.h"

extern uint16_t data[array_length];

//#define data(x) data[x]

void service_day_phase()
{
    if (data[time] >= data[time_day] && data[time] < data[time_night])
    {
        data[temp_required] = data[temp_inside_day];
        data[hum_required] = data[hum_inside_day];
    }
    else
    {
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
}

void service_workers_mode()
{
    //code
}

void service_climat_control()
{
    //code
}

void service_section_control()
{
    Section_1.white_control(data[white_bright_1]);
    Section_2.white_control(data[white_bright_2]);
    Section_3.white_control(data[white_bright_3]);
    Section_4.white_control(data[white_bright_4]);
    Section_1.fito_control(data[fito_bright_1]);
    Section_2.fito_control(data[fito_bright_2]);
    Section_3.fito_control(data[fito_bright_3]);
    Section_4.fito_control(data[fito_bright_4]);
    Section_1.pump_control(data[pump_1_work], data[pump_1_pause], data[time]);
    Section_2.pump_control(data[pump_2_work], data[pump_2_pause], data[time]);
    Section_3.pump_control(data[pump_3_work], data[pump_3_pause], data[time]);
    Section_4.pump_control(data[pump_4_work], data[pump_4_pause], data[time]);
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
        service_section_control();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // wait for one second
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