/*
   @file WDT_driver.h - Главный фаил библиотеки внешнего watchdog
   
    Реализует:
    - Запуск watch dog
    - перезапуск цикла watchdog
    - Перезапуск всей системы по watchdog

   @author DIULINI
   @date 26.06.2023
*/


#ifndef WDT_DRIVER_H
#define WDT_DRIVER_H
#include "Arduino.h"

#define _CFG_WDT_DRIVER_PORT A4


/// @brief Инициализация WDT
void WDT_INI();

/// @brief Сброс WDT,если всё нормально
void WDT_RESET();

/// @brief Перезапуск системы
void WDT_AUTORESET();




#endif