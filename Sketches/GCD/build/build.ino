#include <Arduino.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void setup() {
    Serial.begin(9600);

    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    randomSeed(analogRead(0));

    int n1 = random(1, 100);
    int n2 = random(1, 100);
    int result = gcd(n1, n2);

    Serial.print("Number 1: ");
    Serial.println(n1);
    Serial.print("Number 2: ");
    Serial.println(n2);
    Serial.print("GCD: ");
    Serial.println(result);
}

void loop() {
  
}