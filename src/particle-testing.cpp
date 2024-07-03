#include "Particle.h"
#include "GeophoneController.h"

SerialLogHandler logHandler(LOG_LEVEL_INFO);

String manufacturer = "PigTracks";
String deviceId = System.deviceID();

GeophoneController geophoneController(manufacturer, deviceId);

void setup() {
  geophoneController.setup();
}

void loop() {
  geophoneController.loop();
}
