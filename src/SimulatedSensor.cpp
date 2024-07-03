#include "SimulatedSensor.h"
#include "Particle.h"
#include "DataPoint.h"

DataPoint SimulatedSensor::getDataPoint() {
    return DataPoint{random(-100, 101), Time.now()};
}
