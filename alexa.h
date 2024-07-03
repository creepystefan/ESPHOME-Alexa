#include "esphome.h"
#include <weenyMo.h>
//
// This function will be called when Alexa hears "switch [on | off] 'vee three'" 
// ESP8266 builtin LED is "backwards" i.e. active LOW, hence Alexa's ON=1 needs reversing
//
    
#define BUILTIN_LED          4
//"vee three"
#define DEVICENAME           LED

weenyMo w("vee three",onVoiceCommand);

void onVoiceCommand(bool onoff){ 
  Serial.printf("onVoiceCommand %d\n",onoff);
  digitalWrite(BUILTIN_LED,!onoff);
} 
//
bool getAlexaState(){ // We need this to let Alexa know if we are on or off
  return !digitalRead(BUILTIN_LED); // Its "active low" so reverse it
}
// The only constructor: const char* name, function<void(bool)> onCommand
// choose the name wisely: Alexa has very selective hearing!
//

class MyCustomSensor : public Component, public Sensor {
 public:

void setup() override {
  Serial.begin(74880);
  pinMode(BUILTIN_LED,OUTPUT);
  digitalWrite(BUILTIN_LED,HIGH); // start OFF 
  //WiFi.begin("ssid","pass"); // replace OF COURSE
  //WiFi.waitForConnectResult();  // so much neater than those stupid loops and dots
  //w.gotIPAddress(); // ready to roll...Tell Alexa to discover devices.
}

void loop() override {}

};
