#include "Arduino.h"
#include "FastLED.h"

#define LED_PIN 4
#define NUM_LEDS 16
#define DELAY 55

CRGB leds[NUM_LEDS];

void setup() {
    pinMode(BUILTIN_LED, OUTPUT);
    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
    Serial.begin(115200);
}

int16_t number = 0;

void displayNumber(int16_t num) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    for (int i = 0; i < NUM_LEDS; i++) {
        if (num & 1) {
            if (i > 7) {
                leds[(7 + NUM_LEDS) - i] = CRGB::Red;
                Serial.print("Setting led number ");
                Serial.print(7+NUM_LEDS-i);
                Serial.println();

            } else {
                leds[i] = CRGB::Red;
            }
        }
        num = num >> 1;
    }
}

void loop() {
    displayNumber(number);
    number++;
    FastLED.show();
    delay(DELAY);
}

