#include "EEPROM_driver.h"
#include "./Data.h"

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
  eeprom_write_block((void*)&Data_struct._DATA_ADR,  0, sizeof(Data_struct._DATA_ADR));
}


EEPROM_status_t EEPROM_Load()
{
  EEPROM_status_t OPstatus = _EEPROM_ReadBlock((uint8_t *)&Data_struct, sizeof(Data_struct));
  
  if(OPstatus!=EEPROM_status_OK)
    return OPstatus;

  if(Data_struct._DATA_ADR[_crc] != CFG_EEPROOM_INIT_CRC)
    return EEPROM_status_MAP_INVALID;

  memcpy(_DATA_ADR, Data_struct._DATA_ADR, sizeof(Data_struct._DATA_ADR));
    return  EEPROM_status_OK;
}


EEPROM_status_t EEPROM_Remap()
{




}



EEPROM_status_t _EEPROM_WriteBlock(uint8_t *Data, int length, int pos = 0)
{
  if(pos>CFG_EEPROM_SIZE_MAX)
    return EEPROM_status_ADDR_INVALID;
  if(pos+length> CFG_EEPROM_SIZE_MAX)
    return EEPROM_status_OUT_OF_MEM;

  eeprom_write_block((void*)&Data,  (void*)&pos, length);

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




