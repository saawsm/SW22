/**
 * The main file for the main processor (Pico) that handles low-level control over the output channels.
 */
#include <hardware/adc.h>
#include <hardware/i2c.h>
#include <hardware/pio.h>
#include <hardware/pwm.h>
#include <hardware/spi.h>
#include <inttypes.h>
#include <pico/multicore.h>
#include <pico/stdlib.h>
#include <stdio.h>

int main(void) {
    stdio_init_all();

    printf("Init...\n");

    adc_init();

    return 0;
}