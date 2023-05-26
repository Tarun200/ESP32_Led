#include "ledcontrol.h"
#include <Arduino.h>
LEDControl::LEDControl(int ledChannel,int ledPin,int frequency, int resolution){
    ledChannel_ = ledChannel;
    ledPin_ = ledPin;
    ledFrequency_ = frequency;
    ledResolution_ = resolution;
}

void LEDControl::setup(){
    ledcSetup(ledChannel_, ledFrequency_, ledResolution_);
    ledcAttachPin(ledPin_, ledChannel_);
}

void LEDControl::setBrightness(int brightness){

    ledcWrite(ledChannel_, brightness);
}

void LEDControl::setFrequency(int frequency){
    ledcSetup(ledChannel_, frequency, ledResolution_);
    ledFrequency_ = frequency;
}

void LEDControl::loop(){
    if(Serial.available()>0){
        String command = Serial.readString();
        if(command.startsWith("b")){
            int brightness = command.substring(1).toInt();
            setBrightness(brightness);
            Serial.println("Brightness changed to" + String(brightness) + "%");
        }
        else if(command.startsWith("f")){
            int frequency = command.substring(1).toInt();
            setFrequency(frequency);
            Serial.println("Frequency changed to" + String(frequency) + "Hz");
        }
    }
}
