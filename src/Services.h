#ifndef SERVICES_H
#define SERVICES_H

#include "Data.h"
#include "drivers/Section.h"

Section Section_1(0, 0, 0);
Section Section_2(0, 0, 0);
Section Section_3(0, 0, 0);
Section Section_4(0, 0, 0);
Section Section_general(0, 0, 0);

void Task_1(void *pvParameters);
void Task_2(void *pvParameters);
void Task_3(void *pvParameters);

void tasks_init();

void service_day_phase();

void service_climat_control();

void service_light_control();

#endif