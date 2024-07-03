#ifndef COILCONTROLLER_H
#define COILCONTROLLER_H

#include "Particle.h"
#include "DataPoint.h"

class CoilController {
public:
    CoilController(const String& manufacturer, const String& deviceId);
    void setup();
    void loop();
private:
    String manufacturer;
    String deviceId;
    bool coilStreamEnabled;
    unsigned long lastDataGenerationTime;
    unsigned long lastPublishTime;
    const unsigned long dataGenerationInterval = 500;
    const unsigned long publishInterval = 5000;
    std::vector<DataPoint> accumulatedData;

    void getSensorData();
    void publishData();
    int controlCoilStream(String command);
};

#endif
