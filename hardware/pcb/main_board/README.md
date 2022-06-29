# SW-324 - Main Board
<img align="center" src="../../../doc/images/SW-324.png">

## About
This is a main board of SW-324. It supports a max of four output (stim) channels, and two AUX channels.
It provides power (+3.3V, +5V, and +9V), battery charging, low-level control of the output modules (via RP2040/Raspberry Pi Pico), and high-level control via an ESP-32.

Each of the four output channels can be potentially repurposed for other uses (since each channel is a module board). Each channel has the following connections controlled by the RP2040/Pico:
- 2x GPIO
- 1x 12-bit ADC
- 1x 12-bit DAC
- +9V 3A max (between all channels)
- +3.3V 1A max (main board total)

## Status
- [x] Create v1.0 Schematic
- [x] Route v1.0 PCB
- [x] Order v1.0 PCBs
- [ ] Review 

## Gerber & Bill of Materials (BOM)
The Gerber zip file was generated with [JLCPCB](https://jlcpcb.com/) in mind (excluding assembly).
Two BOM sources are available, the interactive HTML BOM located in `/bom` folder, and a CSV file.

### Excluded BOM Items:
- 0.1" break-away pin headers/sockets
- Misc connectors