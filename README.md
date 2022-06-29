# SW-324 - A modular ESP-32 e-stim device

## About
The SW-324 is a modular e-stim unit, with the ESP-32 microcontroller at the core. It supports a max of four output (stim) channels, and two AUX channels.
Modular output boards try to mimic the output stage of the well-known Erostec ET312 or better, the DIY reverse engineered MK-312.

The main board makes use of a Raspberry Pi Pico for low-level control of the output boards and routine generation. An ESP-32 takes care of the higher-level processing such as wireless communications, display, and user controls.

Most connections are connected directly into the microcontroller as separate signals. Allowing the firmware to customize how the board functions.
For example, the AUX channels with the help of a plug-in module could accept line/microphone input, or an output channel could be rewired to handle TTL RS-232, etc.

Additionally, the SW-324 was designed with the front panel/display being optional accessories. Anything that can be achieved on the front panel, can be done via Bluetooth.

## Structure
The project is split into multiple KiCad sub-projects:
- [Main Board](/hardware/pcb/main_board) [[Schematic](/hardware/pcb/main_board/SW-324.pdf)] - This is the core of the project, the main control board that can support up to four output channels.
- [Front Panel](/hardware/pcb/front_panel) [[Schematic](/hardware/pcb/front_panel/SW-324FP.pdf)] - A front panel board that uses the expansion connector found on the main board.

### Modules
- [SW-32MO10](/hardware/pcb/modules/output/SW-32MO10) [[Schematic](/hardware/pcb/modules/output/SW-32MO10/SW-32MO10.pdf)] - A single isolated output module.
- [SW-32MA1](/hardware/pcb/modules/audio/SW-32MA1) [[Schematic](/hardware/pcb/modules/audio/SW-32MA1/SW-32MA1.pdf)] - A basic audio module, supports a mono microphone and stereo line-in.

More detailed information about each can be found in the project specific READMEs.

## License
This work is licensed under a Creative Commons Attribution-NonCommercial 4.0 International License, available at
[http://creativecommons.org/licenses/by-nc/4.0/](http://creativecommons.org/licenses/by-nc/4.0/).
