/*
Author: Luciano Scarpaci Copyright (c) 2025
*/
#include "AESLib.h"
#include <EEPROM.h>
#define BAUD 9600

AESLib aesLib;

#define INPUT_BUFFER_LIMIT (128 + 1) 

unsigned char plaintext[INPUT_BUFFER_LIMIT] = {0}; // THIS IS INPUT BUFFER (FOR TEXT)
unsigned char ciphertext[2*INPUT_BUFFER_LIMIT] = {0}; // THIS IS OUTPUT BUFFER (FOR ENCRYPTED DATA)

unsigned char readBuffer[17] = "Hide my message!";

// AES Encryption Key
byte aes_key[N_BLOCK];

// Generate key using EEPROM
void generate_aes_key() {
  for (int i = 0; i < N_BLOCK; i++) {
    aes_key[i] = EEPROM.read(i);
  }
}

byte aes_iv[N_BLOCK];

// Generate IV (once)
void aes_init() {
  aesLib.gen_iv(aes_iv); // Generate a random IV
  generate_aes_key();
  aesLib.set_paddingmode((paddingMode)0);
}

uint16_t encrypt_to_ciphertext(char * msg, uint16_t msgLen, byte iv[]) {
  Serial.println("Calling encrypt (string)...");
  int cipherlength = aesLib.encrypt64((const byte*)msg, msgLen, (byte*)ciphertext, aes_key, sizeof(aes_key), iv);
  return cipherlength;
}

uint16_t decrypt_to_plaintext(byte msg[], uint16_t msgLen, byte iv[]) {
  Serial.print("Calling decrypt...; ");
  uint16_t dec_bytes = aesLib.decrypt64(msg, msgLen, (byte*)plaintext, aes_key, sizeof(aes_key), iv);
  return dec_bytes;
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(BAUD);
  Serial.setTimeout(60000);
  delay(2000);

  aes_init(); // generate random IV and AES key

}

/* non-blocking wait function */
void wait(unsigned long milliseconds) {
  unsigned long timeout = millis() + milliseconds;
  while (millis() < timeout) {
    yield();
  }
}

unsigned long loopcount = 0;

// AES IV for each encryption
byte enc_iv[N_BLOCK];
byte enc_iv_to[N_BLOCK];
byte enc_iv_from[N_BLOCK];

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  Serial.print("readBuffer length: "); Serial.println(sizeof(readBuffer));

   // must not exceed INPUT_BUFFER_LIMIT bytes; may contain a newline
  sprintf((char*)plaintext, "%s", readBuffer);

  // Encrypt
  // iv_block gets written to, provide own fresh copy... so each iteration of encryption will be the same.
  uint16_t msgLen = sizeof(readBuffer);
  aesLib.gen_iv(enc_iv); // Generate a new random IV for each encryption
  memcpy(enc_iv_to, enc_iv, sizeof(enc_iv));
  uint16_t encLen = encrypt_to_ciphertext((char*)plaintext, msgLen, enc_iv);

  Serial.println("Encrypted. "); 
  Serial.print("Encrypted ciphertext: "); Serial.println((char*)ciphertext);
  Serial.println("Decrypting...");
  Serial.flush();
  
  memcpy(enc_iv_from, enc_iv_to, sizeof(enc_iv_to));
  uint16_t decLen = decrypt_to_plaintext(ciphertext, encLen, enc_iv_from);
  Serial.print("Decrypted plaintext:\n"); Serial.println((char*)plaintext);

  if (strcmp((char*)readBuffer, (char*)plaintext) == 0) {
    Serial.println("Decrypted correctly.");
  } else {
    Serial.println("Decryption test failed.");
  }

  Serial.println("---");
  delay(1000); // Add delay to prevent rapid looping
}
