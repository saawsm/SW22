#pragma once

#include <Arduino.h>

#define WAVFORM_SEGMENTS 4

#ifndef PWM_RESOLUTION
#define PWM_RESOLUTION 16
#endif

// Maximum value the PWM can be, based on the PWM resolution.
#define PWM_MAX ((1 << PWM_RESOLUTION) - 1)

#ifndef MAX_AMPLITUDE
#define MAX_AMPLITUDE 255
#endif

struct WaveformSegment {
    unsigned long period;  // microseconds
    int amplitude;
};

class WTChannel {
   public:
    WTChannel(const byte pinPulseA, const byte pinPulseB, const byte pinCurrentLimit, const byte pinCurrentSense);

    bool init();

    bool update(unsigned long time);

   public:
    void setWaveform(unsigned int frequency, unsigned int pulseWidth, unsigned int interPeriod, unsigned int level,
                     float symmetry);

    // TODO: Sense current and calibrate.

   private:
    const byte pinPulseA;
    const byte pinPulseB;
    const byte pinCurrentLimit;
    const byte pinCurrentSense;

    WaveformSegment waveform[WAVFORM_SEGMENTS];

    unsigned long lastTime;
    unsigned int index;
};
