/*
A remote own-fabricated pressure sensor monitoring device
 
Author: Fahad Mirza (fahadmirza80@yahoo.com)
Last edited: May 21st , 2016

Application:
  The code collects our sensor's ambient temp and humidity from HTU21D sensor.
  Then Upload those to Microsoft server using Azure IoT Suite. 

Hardware:
  I used a Hardware module based on esp8266, The Thing Dev from Sparkfun. 
  Arduino IDE was used to code esp8266.
  It was powered from USB. HTU21D was powered from esp8266's 3.3V supply pin. 
  ESP8266's I2c was used to communicate with HTU21D.
  

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

// Please use an Arduino IDE 1.6.8 or greater

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <WiFiUdp.h>
#include <AzureIoTHub.h>
#include "remote_monitoring.h"

char ssid[] = "****";
char pass[] = "****";

WiFiClientSecure sslClient;
AzureIoTHubClient iotHubClient(sslClient);

void setup() 
{
    Serial.begin(115200);
    initWifi();
    initTime();
    iotHubClient.begin();
}

void loop() 
{
    // Run the Remote Monitoring from the Azure IoT Hub C SDK
    // You must set the device id, device key, IoT Hub name and IotHub suffix in
    // remote_monitoring.c
    remote_monitoring_run();
}



void initWifi() 
{
    // Attempt to connect to Wifi network:
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    while (WiFi.begin(ssid, pass) != WL_CONNECTED) 
    {
      // unsuccessful, retry in 4 seconds
      Serial.print("failed ... ");
      delay(4000);
      Serial.print("retrying ... ");
    }
    Serial.println("Connected to wifi");
}

void initTime() 
{  
   time_t epochTime;
   configTime(0, 0, "pool.ntp.org", "time.nist.gov");

   while (true) 
   {
       epochTime = time(NULL);

       if (epochTime == 0) 
       {
           Serial.println("Fetching NTP epoch time failed! Waiting 2 seconds to retry.");
           delay(2000);
       } 
       else 
       {
           Serial.print("Fetched NTP epoch time is: ");
           Serial.println(epochTime);
           break;
       }
   }
}
