#ifndef SERVICES_H
#define SERVICES_H

#include "config.h"
#include "Data.h"
#include "drivers/CSMS_driver.h"
#include "drivers/DHT_driver.h"
#include "drivers/DS18b20_driver.h"
#include "Water_tank.h"
#include "Section.h"

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

void Task_1(void *pvParameters);
void Task_2(void *pvParameters);
void Task_3(void *pvParameters);

void tasks_init();

void service_day_phase();

void service_climat_control();

void service_light_control();

#endif