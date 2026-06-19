#include <Adafruit_NeoPixel.h>

#define PIN 3
#define NUMPIXELS 64

Adafruit_NeoPixel matrix(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const byte sun[64] = {
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0
};

const byte cloud[64] = {
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0
};

uint32_t skyColor;
uint32_t sunColor;
uint32_t cloudColor;
uint32_t rainColor;

void setup() {
  matrix.begin();
  matrix.setBrightness(100);

  skyColor = matrix.Color(0, 150, 255);
  sunColor = matrix.Color(255, 230, 0);
  cloudColor = matrix.Color(230, 240, 255);
  rainColor = matrix.Color(0, 0, 255);
}

void fillSky() {
  for (int i = 0; i < NUMPIXELS; i++) {
    matrix.setPixelColor(i, skyColor);
  }
}

void loop() {
  fillSky();
  for (int i = 0; i < NUMPIXELS; i++) {
    if (sun[i] == 1) matrix.setPixelColor(i, sunColor);
  }
  matrix.show();
  delay(1500);

  fillSky();
  for (int i = 0; i < NUMPIXELS; i++) {
    if (cloud[i] == 1) matrix.setPixelColor(i, cloudColor);
  }
  matrix.show();
  delay(1200);

  for (int step = 0; step < 5; step++) {
    fillSky();

    for (int i = 0; i < NUMPIXELS; i++) {
      if (cloud[i] == 1) matrix.setPixelColor(i, cloudColor);
    }

    if ((4 + step) < 8) {
      matrix.setPixelColor((4 + step) * 8 + 1, rainColor);
    }
    if ((4 + step - 1) >= 4 && (4 + step - 1) < 8) {
      matrix.setPixelColor((4 + step - 1) * 8 + 3, rainColor);
    }
    if ((4 + step) < 8) {
      matrix.setPixelColor((4 + step) * 8 + 4, rainColor);
    }
    if ((4 + step - 1) >= 4 && (4 + step - 1) < 8) {
      matrix.setPixelColor((4 + step - 1) * 8 + 6, rainColor);
    }
    
    matrix.show();
    delay(250);
  }
}
