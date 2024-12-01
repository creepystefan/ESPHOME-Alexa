/*
 * This is a basic example on how to use Espalexa and its device declaration methods.
 */ 
#pragma once

#include "esphome/core/component.h"
#include "esphome.h"

//#ifdef ARDUINO_ARCH_ESP32
//#include <WiFi.h>
//#else
//#include <ESP8266WiFi.h>
//#endif
#include <Espalexa.h>

namespace esphome {
namespace myespalexa { 

class MYESPALEXA : public Component {
 public:

// prototypes
//boolean connectWifi();

//callback functions
void firstLightChanged(uint8_t brightness);
void secondLightChanged(uint8_t brightness);
void thirdLightChanged(uint8_t brightness);

Espalexa espalexa;

EspalexaDevice* device3; //this is optional

void setup()
{
  Serial.begin(115200);

    espalexa.addDevice("Light 1", firstLightChanged); //simplest definition, default state off
    espalexa.addDevice("Light 2", secondLightChanged, 255); //third parameter is beginning state (here fully on)
    
    device3 = new EspalexaDevice("Light 3", thirdLightChanged); //you can also create the Device objects yourself like here
    espalexa.addDevice(device3); //and then add them
    device3->setValue(128); //this allows you to e.g. update their state value at any time!

    espalexa.begin();
    
}
 
void loop()
{
   espalexa.loop();
   delay(1);
}

//our callback functions
void firstLightChanged(uint8_t brightness) {
    Serial.print("Device 1 changed to ");
    
    //do what you need to do here

    //EXAMPLE
    if (brightness) {
      Serial.print("ON, brightness ");
      Serial.println(brightness);
    }
    else  {
      Serial.println("OFF");
    }
}

void secondLightChanged(uint8_t brightness) {
  //do what you need to do here
}

void thirdLightChanged(uint8_t brightness) {
  //do what you need to do here
}
};

}  // namespace espalexa
}  // namespace esphome
