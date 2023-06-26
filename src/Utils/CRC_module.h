/*
   @file CRC_module.h - Модуль расчета CRC
    цифровых лабраторий Intler
    Реализует:
    - Расчитывает контрольную сумму данных в 8-16 битную сумму 
    - Динамическое изменение контрольной суммы класса
    - Сравнивает Контрольные суммы входящих данных
*/


#ifndef _CRC_MODULE_H
#define _CRC_MODULE_H

#include "Arduino.h"

#define CRC_POLYNOME_16 0x8005
#define CRC_POLYNOME_8 0x31	

/// @brief Расчет CRC для Строк
/// @param data Обьек данных 
/// @return контрольная сумма 16бит
uint16_t Calc_CRC_16(String data);

/// @brief Расчет CRC для Строк
/// @param data Обьек данных 
/// @return контрольная сумма 8бит
uint8_t Calc_CRC_8(String data);


/// @brief Расчет  CRC данных произвольного типа
/// @param data Указатель на начало данных 
/// @param length Объём данных, в байтах
/// @return контрольная сумма 16бит
uint16_t Calc_CRC_16(uint8_t *buffer, int size);


/// @brief Расчет  CRC данных произвольного типа
/// @param data Указатель на начало данных 
/// @param length Объём данных, в байтах
/// @return контрольная сумма 8бит
uint8_t Calc_CRC_8(uint8_t *buffer, int size);












#endif