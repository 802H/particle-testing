#include "RandomSimulatedSensor.h"
#include "Particle.h"
#include "DataPoint.h"

DataPoint RandomSimulatedSensor::getDataPoint() {
    int randomNumber = random(-100, 101);
    
    float randomFloat = static_cast<float>(randomNumber);
    
    return DataPoint{randomFloat, Time.now()};
}
