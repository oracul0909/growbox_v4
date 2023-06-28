/*
   @file EEPROM_driver.h - Главный фаил библиотеки работы Nextion
   
    Реализует:
    - Чтение данных, и помещение их в структуру
    - Запись данных из структуры в экран кольцевым буфером

   @author DIULINI
   @date 26.06.2023
*/


#ifndef NEXTION_DRIVER_H
#define NEXTION_DRIVER_H

#include "Arduino.h"


#define _CFG_NEXTION_DRIVER_PORT Serial2
#define _CFG_NEXTION_DRIVER_BAUD 115200
#define _CFG_NEXTION_DRIVER_Base_msg "page0.va"
#define _CFG_NEXTION_DRIVER_Base_msg2 ".val"
#define _CFG_NEXTION_DRIVER_Base_msg_devider '&'
#define _CFG_NEXTION_DRIVER__MAX_OPERATORS_COUNT 5


/// @brief Инициализация порта
void Nextion_driver_init();

/// @brief Принятие данных с экрана
uint8_t Nextion_driver_receive();

/// @brief Передача соббщений по кольцу
void Nextion_driver_transmit_ring();

/// @brief Передача прямого сообщения 
/// @param msg Сообщение
void Nextion_driver_transmit_Now(String msg);


void _NextionDriver_endOfMsg();






#endif