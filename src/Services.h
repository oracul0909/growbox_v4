#ifndef SERVICES_H
#define SERVICES_H

#include "config.h"
#include "Data.h"
#include "drivers/CSMS_driver.h"
#include "drivers/DHT_driver.h"
#include "drivers/DS18b20_driver.h"
#include "drivers/Reed_switch_driver.h"
#include "Climate_system.h"
#include "Water_tank.h"
#include "Section.h"

void service_day_phase();

void service_devices_feedback();

void service_climate_control();

void service_section_control();

#endif