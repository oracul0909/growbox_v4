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
#include "drivers/EEPROM_driver.h"
#include "drivers/Modbus_driver.h"
#include "drivers/Nextion_driver.h"
#include "drivers/WDT_driver.h"

void service_day_phase();

void service_sensors_run();

void service_devices_feedback();

void service_climate_control();

void service_section_control();





/// @brief Сервис модуля взаимодействия с данными
void service_data_handler();

/// @brief Одноразовый набор инструкций инициализации памяти
void service_init_mem();


///
void service_wdt_ini();
/// @brief Сервис взаимодействия с wdt
void service_wdt();


void TimeToReset();
#endif