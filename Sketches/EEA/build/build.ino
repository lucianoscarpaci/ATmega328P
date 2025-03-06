#include <Arduino.h>

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

    int loops = 0;
    long inverse1 = extended_ea(0x33, 0x0001FFFF, &loops);

    Serial.print("Result (modular inverse) = 0x");
    Serial.print(inverse1, HEX);
    Serial.print(" Iterations = ");
    Serial.println(loops);

    long inverse2 = extended_ea(0x31, 0x0001FFFF, &loops);

    Serial.print("Result (modular inverse) = 0x");
    Serial.print(inverse2, HEX);
    Serial.print(" Iterations = ");
    Serial.println(loops);

    long inverse3 = extended_ea(0xC7, 0x0001FFFF, &loops);

    Serial.print("Result (modular inverse) = 0x");
    Serial.print(inverse3, HEX);
    Serial.print(" Iterations = ");
    Serial.println(loops);
}

void loop() {
    // No need for repeated operations here
}