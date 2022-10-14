# SW32 - A modular E-Stim

![SW32](docs/images/SW32.png)

---

*This project is a work in-progress (primarily due to part shortages). Large changes to the design might occur, without warning. Build PCBs at your own risk..*

---

## About
The SW32 is a modular E-Stim box based on the [ZC95](https://github.com/CrashOverride85/zc95) and the [WT-312](https://github.com/WendyTeslaburger/WT-312). 
It has a similar form factor and output design to the MK312-BT (which in turn is a clone of the ET-312B).

Like the ZC95, it uses two Raspberry Pi Pico microcontrollers instead of an AVR ATmega16 of the 312B, and the firmware is open source and written in C++.

Compared to the MK312-BT, it has two extra output channels, four auxiliary inputs, and four triggers. 

## Notable Features
* TTL/RS232 front panel serial selector/multiplexer (expansion board support)
* 2x TRS 3.5mm Aux channels with expansion board support (e.g. Stereo Audio + Mono Microphone)
* 2x TRS 3.5mm Trigger channels
* Output channel center-tap jumpers (ring of TRS channel outputs)
* Modular output drivers per channel (Think: Sparkfun, Adafruit, etc.)
* Individual channel sensing via quad 12-bit ADC
* 1.8" Color TFT display
* 256kb EEPROM for configuration

## Overview
The SW32 consists of following PCBs:
* Front Panel Cover - No traces, just the cosmetic front panel with text. Could be 3D printed / CNC routed.
* Front Panel - I2C based expansion board with 4x POTs with associated ADC, 1x rotary encoder, 4x tactile buttons, 1x buzzer, and 6x addressable RGB LEDs.
* Base Board - Provides system power, battery charging, expansion, front panel control, and general control.
* Driver Board - Provides low-level control over channel output modules.
* Output Modules - Generates the E-Stim for each channel. A module per channel, controlled by the driver board. 
* Expansion Module (Optional) - Allows advanced configuration of Aux channels (e.g. Audio+Microphone)

The main reason for having modular PCBs is for flexibility and long term cost saving. Most of the cost and time that is involved in the project is the firmware, case, display, controls, etc. So being able to reuse parts when changing the design (e.g. new output modules, etc) should help keep time and cost down. Having a smaller driver board allows for a cheaper solder paste stencil.

Additionally, the SW32 was designed with the front panel and display being optional accessories. Anything that can be achieved on the front panel, can be done via Bluetooth or WiFi (e.g. Pico W). The driver board was designed to work as a standalone module (Think: Sparkfun, Adafruit, etc.) using the [swx](https://github.com/saawsm/swx) driver firmware.

## PCB Build Notes
The majority of this build is SMT. I have tried to keep parts large enough (0603 and above) for manual pick and place. However, for a few components no alternative was available (e.g. Driver board DAC/ADC use TSSOP package)

Most SMD components used are available from Mouser and LCSC. Front panel components being mostly available at places that aren't LCSC (pots, encoders, audio jacks, etc).

Some components have a thermal pad that will require a reflow oven or using hot air reflow soldering.

## [Schematics](schematics/)

## [Gerbers](gerbers/)
Gerbers are created for use with JLCPCB. P&P POS files untested/missing (since I assemble the PCBs myself).

## Firmware
- [Precompiled Firmware](https://github.com/saawsm/SW32/releases/latest)

The firmware is open source and written in C++ using the pico-sdk. You can find the source code in the [swef](https://github.com/saawsm/swef) repository.

Precompiled firmware is available on the release page of this repository.

## License
This work is licensed under a Creative Commons Attribution-NonCommercial 4.0 International License, available at
[http://creativecommons.org/licenses/by-nc/4.0/](http://creativecommons.org/licenses/by-nc/4.0/).
