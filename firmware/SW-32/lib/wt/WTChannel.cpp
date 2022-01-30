#include "WTChannel.h"

WTChannel::WTChannel(const byte pinPulseA, const byte pinPulseB, const byte pinCurrentLimit, const byte pinCurrentSense)
    : pinPulseA(pinPulseA),
      pinPulseB(pinPulseB),
      pinCurrentLimit(pinCurrentLimit),
      pinCurrentSense(pinCurrentSense),
      waveform() {
    setWaveform(1, 0, 0, 0, 1.0f);
}

bool WTChannel::init() {
    pinMode(pinPulseA, OUTPUT);
    pinMode(pinPulseB, OUTPUT);
    pinMode(pinCurrentLimit, OUTPUT);
    pinMode(pinCurrentSense, INPUT);
    return true;
}

void WTChannel::setWaveform(unsigned int frequency, unsigned int pulseWidth, unsigned int interPeriod, unsigned int level,
                            float symmetry) {
    unsigned long period = (unsigned long)(1.0f / frequency) * 1000000UL;  // microseconds

    int a1 = 0;                     // current limit - t0 - upper
    int a2 = (int)(a1 * symmetry);  // current limit - t2 - lower - symmetry [0.0 - 1.0]

    unsigned long t2 = pulseWidth * a1 / a2;

    this->waveform[0].period = pulseWidth;  // t0
    this->waveform[0].amplitude = a1;

    this->waveform[1].period = interPeriod;  // t1 - t1Limit = P - t0 - t2
    this->waveform[1].amplitude = 0;

    this->waveform[2].period = t2;  // t2
    this->waveform[2].amplitude = -a2;

    this->waveform[3].period = period - (waveform[0].period + waveform[1].period + waveform[2].period);  // t3
    this->waveform[3].amplitude = 0;
}

bool WTChannel::update(unsigned long time) {
    WaveformSegment segment = this->waveform[index];

    if (time - this->lastTime >= segment.period) {
        this->lastTime = time;

        this->index = (this->index + 1) % WAVFORM_SEGMENTS;

        // analogWrite(this->pinCurrentLimit, MAX_AMPLITUDE - abs(segment.amplitude));

        if (segment.amplitude > 0) {
            digitalWrite(this->pinPulseB, LOW);
            digitalWrite(this->pinPulseA, HIGH);

        } else if (segment.amplitude < 0) {
            digitalWrite(this->pinPulseA, LOW);
            digitalWrite(this->pinPulseB, HIGH);

        } else {
            digitalWrite(this->pinPulseA, LOW);
            digitalWrite(this->pinPulseB, LOW);
        }

        return true;
    }

    return false;
}