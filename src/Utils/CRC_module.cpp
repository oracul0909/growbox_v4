#include "CRC_module.h"


uint16_t Calc_CRC_16(String data)
{
  return Calc_CRC_16((uint8_t*)&data, data.length());
}


uint8_t Calc_CRC_8(String data)
{
  return Calc_CRC_8((uint8_t*)&data, data.length());
}


uint16_t Calc_CRC_16(uint8_t *buffer, int size)
{
  uint16_t crc = 0;
  for (int i = 0; i < size; i++) {
    uint8_t data = buffer[i];
    for (int j = 8; j > 0; j--) {
      crc = ((crc ^ data) & 1) ? (crc >> 1) ^ CRC_POLYNOME_16 : (crc >> 1);
      data >>= 1;
    }
  }
  return crc;
}




uint8_t Calc_CRC_8(uint8_t *buffer, int size)
{
    uint16_t crc = 0x00;
  for (int i = 0; i < size; i++) {
    uint8_t data = buffer[i];
    for (int j = 8; j > 0; j--) {
      crc = ((crc ^ data) & 1) ? (crc >> 1) ^ CRC_POLYNOME_8 : (crc >> 1);
      data >>= 1;
    }
  }
  return crc;
}





