#include <Arduino.h>
#include "drivers/DHT_driver.h"
#include "drivers/DS18b20_driver.h"
#include "drivers/CSMS_driver.h"

DHT_driver DHT_11(2);
DS18B20_driver DS18b20(3);
CSMS_driver Ground_sensor(A1);

void setup()
{
}

void loop()
{
  Serial.println(DHT_11.get_temperature());
  Serial.println(DS18b20.get_temperature());
  Serial.println(Ground_sensor.get_moisture_middle(5));
  delay(1000);
}