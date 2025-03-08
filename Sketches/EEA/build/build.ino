#include <Arduino.h>
#include <Crypto.h>
#include <RNG.h>
// Calculate the modular inverse using the Extended Euclidean Algorithm
long extended_ea(long a, long b, int *loop) {
    long u = 1, new_u = 0;
    long v = 0, new_v = 1;
    long r = a, new_r = b;

    while (new_r != 0) {
        long quotient = r / new_r;

        long temp_u = u;
        u = new_u;
        new_u = temp_u - quotient * new_u;

        long temp_v = v;
        v = new_v;
        new_v = temp_v - quotient * new_v;

        long temp_r = r;
        r = new_r;
        new_r = temp_r - quotient * new_r;

        (*loop)++;
    }

    // Make result positive
    if (u < 0) {
        u += b;
    }

    return u; // Return the modular inverse
}

void setup() {
    Serial.begin(9600);

    while (!Serial) {
        ; // Wait for serial port to connect. Needed for native USB port only
    }
}

void loop() {
    RNG.loop();
    // Use byte to represent the random number
    byte random; 
    RNG.rand(&random, sizeof(random));
    int loops = 0;
    long inverse = extended_ea(random, 0x0001FFFF, &loops);
    Serial.print("Result (modular inverse) = 0x");
    Serial.print(inverse, HEX);
    Serial.print(" Iterations = ");
    Serial.println(loops);

    delay(1000);
}