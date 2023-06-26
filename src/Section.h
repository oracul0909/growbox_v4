#ifndef SECTION_H
#define SECTION_H

#include "Data.h"
#include "drivers/LED_driver.h"
#include "drivers/Worker_driver.h"

class Section
{
private:
    uint8_t white_pin;
    uint8_t fito_pin;
    uint8_t pump_pin;

    // виртуальная секция для общих настроек
    Section *General;

public:
    // общие параметры для групповой работы секций
    uint16_t white_bright;
    uint16_t fito_bright;
    uint16_t fito_start;
    uint16_t fito_stop;
    uint16_t pump_work;
    uint16_t pump_pause;
    uint16_t white_now;
    uint16_t fito_now;
    bool pump_now;

    // объекты ламп и насоса секции
    LED_driver LED_white{white_pin};
    LED_driver LED_fito{fito_pin};
    Worker_driver Pump{pump_pin};

    //конструкторы и методы
    Section() {}

    Section(Section *_General, uint8_t _white_pin, uint8_t _fito_pin, uint8_t _pump_pin)
    {
        General = _General;
        white_pin = _white_pin;
        fito_pin = _fito_pin;
        pump_pin = _pump_pin;
    }

    /// @brief Контроль работы дневного света
    /// @param work_mode Режим работы дневного света:
    ///                  0 - выключено,
    ///                  1 - индивидуальная работа
    ///                  2 - групповая работа
    ///                  3 - включено всегда
    void white_control(int work_mode);

    /// @brief Контроль работы фито света
    /// @param work_mode Режим работы фито света:
    ///                  0 - выключено,
    ///                  1 - индивидуальная работа
    ///                  2 - групповая работа
    ///                  3 - включено всегда
    void fito_control(int work_mode);

    /// @brief Контроль работы водяного насоса
    /// @param work_mode Режим работы насоса:
    ///                  0 - выключено,
    ///                  1 - индивидуальная работа
    ///                  2 - работа от датчика влажности почвы
    ///                  3 - включено всегда
    /// @param ground_hum_min Минимальный уровень влажности (%)
    /// @param ground_hum_max Максимальный уровень влажности (%)
    void pump_control(int work_mode, uint16_t ground_hum_min, uint16_t ground_hum_max);

    void set_params(uint16_t _white_bright,
                    uint16_t _fito_bright,
                    uint16_t _fito_start,
                    uint16_t _fito_stop,
                    uint16_t _pump_work,
                    uint16_t _pump_pause);

    void get_devices_status();
};

#endif