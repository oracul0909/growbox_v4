#ifndef SERVICES_H
#define SERVICES_H

#include "Data.h"
#include "drivers/CSMS_driver.h"
#include "drivers/DHT_driver.h"
#include "drivers/DS18b20_driver.h"
#include "Section.h"

CSMS_driver CSMS(0);
DHT_driver DHT_inside(0);
DHT_driver DHT_outside(0);
DS18B20_driver DS(0);

Section Section_general;
Section Section_1(&Section_general, 0, 0, 0);
Section Section_2(&Section_general, 0, 0, 0);
Section Section_3(&Section_general, 0, 0, 0);
Section Section_4(&Section_general, 0, 0, 0);

void Task_1(void *pvParameters);
void Task_2(void *pvParameters);
void Task_3(void *pvParameters);

void tasks_init();

void service_day_phase();

void service_climat_control();

void service_light_control();

#endif