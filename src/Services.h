#ifndef SERVICES_H
#define SERVICES_H

#include "Data.h"
#include "Section.h"

Section Section_general(0, 0, 0);
Section Section_1(&Section_general, 0, 0, 0);
Section Section_2(&Section_general, 0, 0, 0);
Section Section_3(&Section_general, 0, 0, 0);
Section Section_4(&Section_general, 0, 0, 0);

void Task_1(void *pvParameters);
void Task_2(void *pvParameters);

void tasks_init();

void service_day_phase();

void service_climat_control();

void service_light_control();

#endif