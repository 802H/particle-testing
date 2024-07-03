#include "SineSimulatedSensor.h"
#include "Particle.h"
#include "DataPoint.h"
#include <cmath>

DataPoint SineSimulatedSensor::getDataPoint() {
    unsigned long time = Time.now();

    float amplitude = 100;
    float frequency = 0.05;
    float period = 1 / frequency;

    float modulatedTime = fmod(time, period);

    float radians = modulatedTime * 2 * M_PI * frequency;

    float value = amplitude * sin(radians);

    return DataPoint{value, time};
}
