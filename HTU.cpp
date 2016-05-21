/*
 * Author: Fahad Mirza (fahadmirza80@yahoo.com)
 * Last edited: May 21st , 2016
 * 
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * 
 * 
 *  Hardware Connections (HTU21D to Thing Dev):
 *  -VCC = 3.3V
 *  -GND = GND
 *  -SDA = PIN2
 *  -SCL = PIN14

 * Open serial monitor to see readings.Errors 998 if not sensor is detected. Error 999 if CRC is bad.
 */

#include <Arduino.h>
#include <SparkFunHTU21D.h>
#include <Wire.h>
#include "HTU.h"

#define PRINT_SERIAL  0
/*

 */
HTU21D mySensor;

// Initialize device.
void initHTU21D(void) 
{
  mySensor.begin();
}

// Read and print Temperature and Humidity data
void getSensorData(float* Temperature, float* Humidity)
{
  *Humidity    = mySensor.readHumidity();
  *Temperature = mySensor.readTemperature();

  
  // Error check and print values [if PRINT_SERIAL is 1].
  if(PRINT_SERIAL)
  {
    if ((*Humidity == (float)998) | (*Temperature == (float)998)) 
    {
      Serial.println(F("Sensor is not detected"));
    }
    else if ((*Humidity == (float)999) | (*Temperature == (float)999)) 
    {
      Serial.println(F("CRC is not right"));
    }
    else 
    {
      Serial.print("Temperature: ");
      Serial.print(*Temperature);
      Serial.println(" *C");
      Serial.print("Humidity: ");
      Serial.print(*Humidity);
      Serial.println("%");
  
    }
  }
}


