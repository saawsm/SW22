# SW-3240 - A modular ESP-32 e-stim device

## About
The SW-3240 is a modular e-stim unit, with the ESP-32 microcontroller at the core. It supports a max of 4 channels.

The modular output boards try to mimic the output stage of the well-known Erostec ET312 or better, the DIY reverse engineered MK-312. 
Hopefully by recreating this output stage, the same e-stim experience can be achieved as those devices.

The main board makes use of an ATmega328PB for low-level control of the output boards. The front panel contains an ESP-32 that is for higher level processing such as front panel IO, Bluetooth, or audio.

Most connections are connected directly into the microcontroller as separate signals (e.g. the microphone and stereo line-in audio, L and R channels). Allowing firmware to customize how the front I/O works.
For example instead of having a `MIC IN` you could change the functionality to act as a trigger for some action, etc.

## Structure
The project is split into multiple KiCad sub-projects:
- [Main Board](/hardware/pcb/main_board) [[Schematic](/hardware/pcb/main_board/SW-3240.pdf)] - This is the core of the project, the main control board that can support up to four output channels.
- [Front Panel](/hardware/pcb/front_panel) [[Schematic](/hardware/pcb/front_panel/SW-3240FP.pdf)] - The front panel with the ESP-32 processor.

### Modules
- [SW-32MO10](/hardware/pcb/modules/output/SW-32MO10) [[Schematic](/hardware/pcb/modules/output/SW-32MO10/SW-32MO10.pdf)] - A single isolated output module.
- [SW-32MA1](/hardware/pcb/modules/audio/SW-32MA1) [[Schematic](/hardware/pcb/modules/audio/SW-32MA1/SW-32MA1.pdf)] - A basic audio module, supports a mono microphone and stereo line-in.

More detailed information about each can be found in the project specific READMEs.

## License
This work is licensed under a Creative Commons Attribution-NonCommercial 4.0 International License, available at
[http://creativecommons.org/licenses/by-nc/4.0/](http://creativecommons.org/licenses/by-nc/4.0/).
