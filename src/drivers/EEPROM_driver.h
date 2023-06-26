/*
   @file EEPROM_driver.h - Главный фаил библиотеки работы EEPROM atmega2560
   
    Реализует:
    - Инициализация стека EEPROM
    - Чтение блоков 
    - Запись блоков
    - Создание и расчет контрольной суммы
    - Логирование результата работы

   @author DIULINI
   @date 21.06.2023
*/

#ifndef EEPROM_DRIVER_H
#define EEPROM_DRIVER_H

#include "Arduino.h"



/// @brief  Энумератор операций процедур
typedef enum
{
    _status_eeprom_operation_read,
    _status_eeprom_operation_write,
    _status_eeprom_operation_remap,
    _status_eeprom_operation_verify
}EEPROM_status_operation_t;

/// @brief Энумератор статусов процедуры
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





#define _CFG_EEPROM_LOG_ENABLED    /// @brief Закоментировать, чтобы отключить лог
#define _CFG_EEPROM_LOG_MAX_VALUES 4 ///длина кольцевого буфера логов

//тип лога данных 
#define _CFG_EEPROM_LOG_TYPE_RING
//define _CFG_EEPROM_LOG_TYPE_QUEUE 

#if defined(_CFG_EEPROM_LOG_ENABLED)
    /// @brief Структура информации о последнем результате EEprom
    typedef struct 
    {
        uint8_t instruction;
        uint8_t status;
    }EEPROM_driver_status_now_t;

    #if defined(_CFG_EEPROM_LOG_TYPE_RING)
        typedef struct 
        {
            EEPROM_driver_status_now_t log[_CFG_EEPROM_LOG_MAX_VALUES];
            uint8_t counter_of_log;
        }EEPROM_driver_status_log_t;
    #endif 

    #if defined (_CFG_EEPROM_LOG_TYPE_QUEUE)
        //Очередь позже, когда нибудь
    #endif

    #if defined(_CFG_EEPROM_LOG_TYPE_QUEUE) & defined(_CFG_EEPROM_LOG_TYPE_RING)
        #error "_CFG_EEPROM_TYPE ERROR. Не может быть двух типов лога разом"
    #endif
    
    /// @brief Добавление данных в лог  
    /// @param operation Код операции по EEPROM_status_operation_t
    /// @param status код статуса по EEPROM_status_t
    void _EEPROM_driver_addlog(EEPROM_status_operation_t operation, EEPROM_status_t status);

    /// @brief Чтение данных из лога. Базовая перегрузка
    /// @param pos 
    /// @return структура uint8_t данных статуса
    EEPROM_driver_status_now_t _EEPROM_driver_readLog(uint8_t pos);

    /// @brief Чтение последней метки
    /// @return  структура uint8_t данных статуса
    EEPROM_driver_status_now_t _EEPROM_driver_readLog();

    /// @brief доступно сообщений EEPROM 
    /// @return Кол-во доступных сообщений
    uint8_t _EEPROM_driver_log_available(); 
#endif






#endif