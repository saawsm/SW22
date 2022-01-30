#include <Arduino.h>

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#include "WTChannel.h"

// Warning: Untested (theoretical) code!!!!

WTChannel channel1(0, 0, 0, 0);

void setup() {
    channel1.init();

    channel1.setWaveform(150, 200, 0, 500, 0.3);
}

void loop() {
    unsigned long time = micros();

    channel1.update(time);


}