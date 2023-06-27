#include "Modbus_driver.h"
#include "./Data.h"
#include "./Utils/CRC_module.h"


extern uint16_t data[array_length];

#define _DATA_ADR data

Modbus slave(_CFG_MODBUS_DRIVER_ADDR,_CFG_MODBUS_DRIVER_PORT,0);



/// @brief  Инициализация драйвера
void Modbus_Driver_Init()
{
    _CFG_MODBUS_DRIVER_PORT.begin(_CFG_MODBUS_DRIVER_BAUD);
    slave.setID(_CFG_MODBUS_DRIVER_ADDR);
    slave.start();
}


/// @brief Основной обработчик modbus
/// @return Состояние приёма данных/ или только передача
_modbus_driver_handler_state_t Modbus_Driver_handler()
{
  uint8_t CRC_begin = Calc_CRC_8((uint8_t *)&_DATA_ADR, sizeof(_DATA_ADR));
  slave.poll(_DATA_ADR,array_length);

   if(CRC_begin == Calc_CRC_8((uint8_t *)&_DATA_ADR, sizeof(_DATA_ADR)))
   {
      return ModbusDriver_trnsmt_comp;
   }
   else return ModbusDriver_rsv_comp;
}
