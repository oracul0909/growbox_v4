#ifndef SECTION_H
#define SECTION_H

#include "Data.h"
#include "drivers/LED_driver.h"
#include "drivers/Worker_driver.h"

class Section
{
private:
    int white_pin;
    int fito_pin;
    int pump_pin;

    //виртуальная секция для общих настроек
    Section *General;

public:
    //объекты ламп и насоса секции
    LED_driver LED_white{white_pin};
    LED_driver LED_fito{fito_pin};
    Worker_driver Pump{pump_pin};

    // общие параметры для групповой работы секций
    int white_bright;
    int fito_bright;
    int fito_start;
    int fito_stop;
    int pump_work;
    int pump_pause;
    int white_now;
    int fito_now;

    Section() {}

    Section(Section *_General, int _white_pin, int _fito_pin, int _pump_pin)
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
    void pump_control(int work_mode, int ground_hum_min, int ground_hum_max);

    void set_params(int _white_bright,
                    int _fito_bright,
                    int _fito_start,
                    int _fito_stop,
                    int _pump_work,
                    int _pump_pause);

    void get_devices_status();
};

#endif