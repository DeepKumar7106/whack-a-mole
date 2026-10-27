#include <Arduino.h>

// Shift Register Pin Mappings from your schematic
const int LATCH_PIN = 10; // ST_CP (74HC595 pin 12)
const int CLOCK_PIN = 12; // SH_CP (74HC595 pin 11)
const int DATA_PIN  = 11; // DS (74HC595 pin 14)

void setup() {
  // Configure shift register control pins as outputs
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
}

void loop() {
  // 1. Ground LATCH_PIN low to prepare for data transmission
  digitalWrite(LATCH_PIN, LOW);

  // 2. Shift out data for all 16 LEDs (2 bytes / 8 bits each)
  // 0xFF means all 8 bits are HIGH (all 8 LEDs ON per chip)
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0xFF); // Second shift register (LEDs 9-16)
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0xFF); // First shift register (LEDs 1-8)

  // 3. Pull LATCH_PIN high to latch/output the data to the LEDs instantly
  digitalWrite(LATCH_PIN, HIGH);

  delay(1000); // Leave them on for 1 second
}