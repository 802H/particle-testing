#include "WhiteNoiseSimulatedSensor.h"
#include "Particle.h"
#include "DataPoint.h"
#include <random>

DataPoint WhiteNoiseSimulatedSensor::getDataPoint() {
    unsigned long time = Time.now();

    // Define the range for the white noise amplitude
    float minAmplitude = -50;
    float maxAmplitude = 50;

    // Static to maintain state across calls
    static std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(minAmplitude, maxAmplitude);

    // Generate a random value within the specified range
    float value = distribution(generator);

    return DataPoint{value, time};
}
