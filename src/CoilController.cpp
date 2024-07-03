#include "CoilController.h"
#include "Particle.h"
#include "SimulatedSensor.h"
#include "DataPoint.h"

CoilController::CoilController(const String& manufacturer, const String& deviceId)
    : manufacturer(manufacturer), deviceId(deviceId), coilStreamEnabled(false), lastDataGenerationTime(0), lastPublishTime(0) {}

void CoilController::setup() {
    Particle.function("coilControl", &CoilController::controlCoilStream, this);
}

void CoilController::loop() {
    unsigned long currentTime = millis();

    if (coilStreamEnabled) {
        if (coilStreamEnabled && currentTime - lastDataGenerationTime > dataGenerationInterval) {
            getSensorData();
            lastDataGenerationTime = currentTime;
        }

        if (currentTime - lastPublishTime > publishInterval) {
            publishData();
            lastPublishTime = currentTime;
        }
    }
}

void CoilController::getSensorData() {
    SimulatedSensor simulatedSensor;
    DataPoint dataPoint = simulatedSensor.getDataPoint();
    accumulatedData.push_back(dataPoint);
}

void CoilController::publishData() {
    // TODO: Make this more efficient by batching data points into a single Particle.publish call
    for (const auto& dataPoint : accumulatedData) {
        String lineProtocolString = String::format("coilData,manufacturer=%s,deviceId=%s value=%d %lld\n", manufacturer.c_str(), deviceId.c_str(), dataPoint.data, dataPoint.timestamp);
        Particle.publish("influx_data", lineProtocolString, PRIVATE);
    }
    accumulatedData.clear();
}

int CoilController::controlCoilStream(String command) {
    if (command == "on") {
        coilStreamEnabled = true;
        return 1;
    } else if (command == "off") {
        coilStreamEnabled = false;
        return 1;
    }
    return -1;
}
