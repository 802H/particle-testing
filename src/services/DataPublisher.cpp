#include "Particle.h"
#include "DataPublisher.h"

DataPublisher::DataPublisher(const String& manufacturer, const String& deviceId)
    : manufacturer(manufacturer), deviceId(deviceId) {}

void DataPublisher::publish(std::vector<DataPoint> accumulatedData) {
    // TODO: Make this more efficient by batching data points into a single Particle.publish call
    for (const auto& dataPoint : accumulatedData) {
        String lineProtocolString = String::format("geophoneData,manufacturer=%s,deviceId=%s value=%f %lld\n", manufacturer.c_str(), deviceId.c_str(), dataPoint.data, dataPoint.timestamp);
        Particle.publish("influx_data", lineProtocolString, PRIVATE);
    }
}
