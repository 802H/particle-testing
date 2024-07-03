#ifndef GEOPHONECONTROLLER_H
#define GEOPHONECONTROLLER_H

#include "Particle.h"
#include "SimulatedSensor.h"

class GeophoneController {
public:
    GeophoneController(const String& manufacturer, const String& deviceId);
    void setup();
    void loop();
private:
    String manufacturer;
    String deviceId;
    bool geophoneStreamEnabled;
    unsigned long lastDataGenerationTime;
    unsigned long lastPublishTime;
    const unsigned long dataGenerationInterval = 500;
    const unsigned long publishInterval = 5000;
    std::vector<DataPoint> accumulatedData;

    void getSensorData();
    void publishData();
    int controlGeophoneStream(String command);
};

#endif
