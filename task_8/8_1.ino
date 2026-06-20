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

void drawPixelXY(int x, int y, uint32_t color) {
  if (x < 0 || x >= 8 || y < 0 || y >= 8) return;
  
  int index;
  if (y % 2 == 0) {
    index = (y * 8) + (7 - x);
  } 
  else {
    index = (y * 8) + x;
  }
  
  matrix.setPixelColor(index, color);
}

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
    if (sun[i] == 1) {
      matrix.setPixelColor(i, sunColor);
    }
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

    int y1 = 4 + step; 
    int y2 = 4 + step - 1; 

    drawPixelXY(1, y1, rainColor);
    drawPixelXY(4, y1, rainColor);

    drawPixelXY(3, y2, rainColor);
    drawPixelXY(6, y2, rainColor);
    
    matrix.show();
    delay(250);
  }
}