#ifndef SECTION_H
#define SECTION_H

#include "Data.h"
#include "drivers/LED_driver.h"
#include "drivers/Worker_driver.h"

class Section
{
private:
    uint8_t white_pin = 0xff;
    uint8_t fito_pin = 0xff;
    uint8_t pump_pin = 0xff;

    // виртуальная секция для общих настроек
public:
    // общие параметры для групповой работы секций
    int16_t white_bright;
    int16_t fito_bright;
    int16_t white_start;
    int16_t white_stop;
    int16_t fito_start;
    int16_t fito_stop;
    int16_t pump_work;
    int16_t pump_pause;
    int16_t white_now;
    int16_t fito_now;
    bool pump_now;

    // объекты ламп и насоса секции
    LED_driver LED_white{white_pin};
    LED_driver LED_fito{fito_pin};
    Worker_driver Pump{pump_pin};

    //конструкторы и методы
    Section() {}

    Section(uint8_t _white_pin, uint8_t _fito_pin, uint8_t _pump_pin)
    {

        white_pin = _white_pin;
        fito_pin = _fito_pin;
        pump_pin = _pump_pin;

        LED_white = LED_driver(white_pin);
        LED_fito = LED_driver(fito_pin);
        Pump = Worker_driver(pump_pin);
    }

    /// @brief Контроль работы дневного света
    /// @param work_mode Режим работы дневного света:
    ///                  0 - выключено,
    ///                  1 - индивидуальная работа
    ///                  2 - групповая работа
    ///                  3 - включено всегда
    uint8_t white_control(int work_mode, int16_t _GeneralWhite);

    /// @brief Контроль работы фито света
    /// @param work_mode Режим работы фито света:
    ///                  0 - выключено,
    ///                  1 - индивидуальная работа
    ///                  2 - групповая работа
    ///                  3 - включено всегда
    uint8_t fito_control(int work_mode, int16_t _GeneralFito);

    /// @brief Контроль работы водяного насоса
    /// @param work_mode Режим работы насоса:
    ///                  0 - выключено,
    ///                  1 - индивидуальная работа
    ///                  2 - работа от датчика влажности почвы
    ///                  3 - включено всегда
    /// @param ground_hum_min Минимальный уровень влажности (%)
    /// @param ground_hum_max Максимальный уровень влажности (%)
    void pump_control(int work_mode, int16_t ground_hum_min, int16_t ground_hum_max);

    void set_params(int16_t _white_bright,
                    int16_t _fito_bright,
                    int16_t _white_start,
                    int16_t _white_stop,
                    int16_t _fito_start,
                    int16_t _fito_stop,
                    int16_t _pump_work,
                    int16_t _pump_pause);

    void get_devices_status();
};

#endif