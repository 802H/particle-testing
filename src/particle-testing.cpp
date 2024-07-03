#include "Particle.h"
#include "GeophoneController.h"
#include "CoilController.h"

SerialLogHandler logHandler(LOG_LEVEL_INFO);

String manufacturer = "PigTracks";
String deviceId = System.deviceID();

GeophoneController geophoneController(manufacturer, deviceId);
CoilController coilController(manufacturer, deviceId);

void setup() {
  geophoneController.setup();
  coilController.setup();
}

void loop() {
  geophoneController.loop();
  coilController.loop();
}
