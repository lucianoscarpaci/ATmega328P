#include <Arduino.h>
#include <Crypto.h>
#include <RNG.h>

void setup() {
    Serial.begin(9600);
    RNG.begin("Random Number Generator v1.0");
    RNG.setAutoSaveTime(60);
}

void loop() {
    RNG.loop();
    if (RNG.available(16)) {
        uint8_t randomData[16];
        RNG.rand(randomData, sizeof(randomData));
        Serial.print("Random Data: ");
        for (int i = 0; i < sizeof(randomData); i++) {
            Serial.print(randomData[i], HEX);
            Serial.print(" ");
        }
        Serial.println();
    }
    delay(1000);
}