#include "GeophoneController.h"
#include "Particle.h"
#include "sensors/GeophoneSensor.h"
#include "services/DataPublisher.h"
#include "DataPoint.h"

GeophoneController::GeophoneController(const String& manufacturer, const String& deviceId)
    : manufacturer(manufacturer), deviceId(deviceId), geophoneStreamEnabled(false), lastDataGenerationTime(0), lastPublishTime(0) {}

void GeophoneController::setup() {
    Particle.function("geophoneControl", &GeophoneController::controlGeophoneStream, this);
}

void GeophoneController::loop() {
    unsigned long currentTime = millis();

    if (geophoneStreamEnabled) {
        if (currentTime - lastDataGenerationTime > dataGenerationInterval) {
            getSensorData();
            lastDataGenerationTime = currentTime;
        }

        if (currentTime - lastPublishTime > publishInterval) {
            publishData();
            lastPublishTime = currentTime;
        }
    }
}

void GeophoneController::getSensorData() {
    GeophoneSensor sensor;
    DataPoint dataPoint = sensor.getDataPoint();
    accumulatedData.push_back(dataPoint);
}

void GeophoneController::publishData() {
    DataPublisher dataPublisher = DataPublisher(manufacturer, deviceId);
    dataPublisher.publish(accumulatedData);
    accumulatedData.clear();
}

int GeophoneController::controlGeophoneStream(String command) {
    if (command == "on") {
        geophoneStreamEnabled = true;
        return 1;
    } else if (command == "off") {
        geophoneStreamEnabled = false;
        return 1;
    }
    return -1;
}
