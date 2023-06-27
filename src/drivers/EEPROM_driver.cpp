#include "EEPROM_driver.h"
#include "./Data.h"
#include "./Utils/CRC_module.h"
#include "avr/eeprom.h"

extern uint16_t data[array_length];

#define _DATA_ADR data

struct Data_struct_tupe
{
uint16_t _DATA_ADR[array_length];
} Data_struct;

//Запись регистров в EEPROOM
void EEPROM_Save()
{
  memcpy(Data_struct._DATA_ADR, _DATA_ADR, sizeof(_DATA_ADR));
  _EEPROM_WriteBlock((uint8_t*)&Data_struct._DATA_ADR, int(sizeof(Data_struct.data)), 0);
}


EEPROM_status_t EEPROM_Load()
{
  EEPROM_status_t OPstatus = _EEPROM_ReadBlock((uint8_t *)&Data_struct, (int)sizeof(Data_struct), 0);
  
  if(OPstatus!=EEPROM_status_OK)
    return OPstatus;

  if(Data_struct._DATA_ADR[_crc] != CFG_EEPROOM_INIT_CRC)
    return EEPROM_status_MAP_INVALID;

  memcpy(_DATA_ADR, Data_struct._DATA_ADR, sizeof(Data_struct._DATA_ADR));
    return  EEPROM_status_OK;
}


EEPROM_status_t EEPROM_Remap()
{
  Data_struct_tupe New_Struct;
  
  memcpy(Data_struct._DATA_ADR, New_Struct._DATA_ADR, sizeof(_DATA_ADR));
  memcpy(Data_struct._DATA_ADR, _DATA_ADR, sizeof(_DATA_ADR));
  EEPROM_Save();
  
  memcpy(Data_struct._DATA_ADR, New_Struct._DATA_ADR, sizeof(_DATA_ADR));
  memcpy(Data_struct._DATA_ADR, _DATA_ADR, sizeof(_DATA_ADR));
  New_Struct._DATA_ADR[_crc] = CFG_EEPROOM_INIT_CRC;

  EEPROM_Save();
  uint8_t Uploaded_CRC = Calc_CRC_8((uint8_t *) &Data_struct.data, sizeof(Data_struct.data));
  EEPROM_Load();
  if(Uploaded_CRC != Calc_CRC_8((uint8_t *) &_DATA_ADR, sizeof(_DATA_ADR)))
  {
    return EEPROM_status_ERR_CRC;
  }
  return EEPROM_status_OK;
}



EEPROM_status_t _EEPROM_WriteBlock(uint8_t *Data, int length, int pos = 0)
{
  if(pos>CFG_EEPROM_SIZE_MAX)
    return EEPROM_status_ADDR_INVALID;
  if(pos+length> CFG_EEPROM_SIZE_MAX)
    return EEPROM_status_OUT_OF_MEM;
  eeprom_update_block((void*)&Data,  (void*)&pos, length);
  return EEPROM_status_OK;
}


EEPROM_status_t _EEPROM_ReadBlock(uint8_t *Data, int length, int pos = 0)
{
    if(pos>CFG_EEPROM_SIZE_MAX)
    return EEPROM_status_ADDR_INVALID;
  if(pos+length> CFG_EEPROM_SIZE_MAX)
    return EEPROM_status_OUT_OF_MEM;
  eeprom_read_block((void*)&Data,  (void*)&pos, length);
  return EEPROM_status_OK;
}



#if defined(_CFG_EEPROM_LOG_ENABLED)

    void _EEPROM_driver_addlog(EEPROM_status_operation_t operation, EEPROM_status_t status)
    {

    }


    EEPROM_driver_status_now_t _EEPROM_driver_readLog(uint8_t pos)
    {
      EEPROM_driver_status_now_t out;
      out.instruction = 0x01;
      return out;
    }


    EEPROM_driver_status_now_t _EEPROM_driver_readLog()
    {
      return _EEPROM_driver_readLog(-1);
    }

    uint8_t _EEPROM_driver_log_available()
    {
      return 0x00;
    }

#endif 
