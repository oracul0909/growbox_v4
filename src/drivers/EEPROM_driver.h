/*
   @file EEPROM_driver.h - Главный фаил библиотеки работы EEPROM atmega2560
   
    Реализует:
    - Инициализация стека EEPROM
    - Чтение блоков 
    - Запись блоков
    - Создание и расчет контрольной суммы


   @author DIULINI
   @date 21.06.2023
*/



#ifndef EEPROM_DRIVER_H
#define EEPROM_DRIVER_H

#include "Arduino.h"



typedef enum 
{
   EEPROM_status_OK,    //Успех
   EEPROM_status_EROOR, //Неизвестная ошибка
   EEPROM_status_OUT_OF_MEM, //Данные выходят ENDPOUNT памяти
   EEPROM_status_ADDR_INVALID, //Не верный начальный адрес памяти
   EEPROM_status_MAP_INVALID, //Не правильная разметка памяти
   EEPROM_status_ERR_CRC //Не совпадение контрольной суммы
}EEPROM_status_t;


/// @brief  Энумератор END_POINT of memory 
typedef enum
{
    EEPROM_MODEL_1KB_max = 1023,
    EEPROM_MODEL_2KB_max = 2047,
    EEPROM_MODEL_4KB_max = 4095
};


#define CFG_EEPROOM_INIT_CRC 0xf1F1

#if  defined(__AVR_ATmega2560__)
    #define CFG_EEPROM_SIZE_MAX EEPROM_MODEL_4KB_max
#endif 

#if defined (__ATmega328__)
    #define CFG_EEPROM_SIZE_MAX EEPROM_MODEL_1KB_max
#endif


///@brief Запись данных в  EEPROM
///@return Результат проверки контрольной суммы чтения  
void EEPROM_Save();

///@brief Чтение данных из EEPROM
///@return Результат проверки контрольной суммы чтения  
EEPROM_status_t EEPROM_Load();

///@brief Перезапись разметки тома
///@return Результат проверки контрольной суммы чтения  
EEPROM_status_t EEPROM_Remap();






/// @brief 
/// @param Data Указатель на блок данных
/// @param length Длина блока данных
/// @return _Eepromm_result_t
EEPROM_status_t _EEPROM_WriteBlock(uint8_t *Data, int length, int pos);

/// @brief 
/// @param Data Указатель на блок данных
/// @param length Длина блока данных
/// @return _Eepromm_result_t
EEPROM_status_t _EEPROM_ReadBlock(uint8_t *Data, int length, int pos);











#endif