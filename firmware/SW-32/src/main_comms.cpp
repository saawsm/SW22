/**
 * The main file for the comms processor (ESP-32). Handles routines, display, Bluetooth, front panel I/O, etc.
 */
#include <Arduino.h>
#include <SPI.h>

#include <TFT_eSPI.h>


#define BAUDRATE 115200

void setup() {  //
    Serial.begin(BAUDRATE);
}

void loop() {  //
}
