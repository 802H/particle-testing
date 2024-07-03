#include "SimulatedSensor.h"
#include "Particle.h"
#include "DataPoint.h"

DataPoint SimulatedSensor::getDataPoint() {
    DataPoint dataPoint;
    dataPoint.data = random(-100, 101);
    dataPoint.timestamp = Time.now();
    return dataPoint;
}
