#include <Arduino.h>

// Calculate the modular inverse and number of iterations
long extended_ea(long a, long b, int *loop) {
    long u = 1, v = 0, d = a;
    long u1 = 0, v1 = 1, v3 = b;

    while (v3 != 0) {
        long q = d / v3;

        long t3 = d % v3;
        d = v3;
        v3 = t3;

        long t1 = u - q * u1;
        u = u1;
        u1 = t1;

        if (t1 < 0) {
            t1 += a;
        }

        long t2 = v - q * v1;
        v = v1;
        v1 = t2;

        (*loop)++;
    }

    if (v < 0) {
        v += b;
    }

    return u; // Return the modular inverse, if necessary
}

void setup() {
    Serial.begin(9600);

    while (!Serial) {
        ; // Wait for serial port to connect. Needed for native USB port only
    }

    int loops = 0;
    long result = extended_ea(0x33, 0x0001FFFF, &loops);

    Serial.print("Result (u) = 0x");
    Serial.print(result, HEX);
    Serial.print(" Iterations = ");
    Serial.println(loops);
}

void loop() { }