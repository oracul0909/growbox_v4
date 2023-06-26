/*
   @file Modbus_driver.h - Главный фаил библиотеки работы Modbus RTU-ASCII
   
    Реализует:
    - Инициализация стека 
    - Чтение блоков 
    - Запись блоков
    - Создание и расчет контрольной суммы

   @author DIULINI
   @date 21.06.2023
*/


#ifndef MODBUS_DRIVER_H
#define MODBUS_DRIVER_H
#include "Arduino.h"
#include "./Utils/ModbusRtu.h"

#define _CFG_MODBUS_DRIVER_PORT Serial
#define _CFG_MODBUS_DRIVER_BAUD 9600
#define _CFG_MODBUS_DRIVER_STOPBIT SERIAL_8N1
#define _CFG_MODBUS_DRIVER_ADDR 127

typedef enum 
{
    ModbusDriver_trnsmt_comp,
    ModbusDriver_rsv_comp
}_modbus_driver_handler_state_t;


/// @brief  Инициализация драйвера
void Modbus_Driver_Init();


/// @brief Основной обработчик modbus
/// @return Состояние приёма данных/ или только передача
_modbus_driver_handler_state_t Modbus_Driver_handler();












#endif