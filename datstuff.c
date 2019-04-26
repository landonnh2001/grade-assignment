#include <SPI.h>
#include <Wire.h>
#include <ArdusatSDK.h>
#include <math.h>

Display display;
int demodelay=2000;
ArdusatSerial serialConnection(SERIAL_MODE_HARDWARE_AND_SOFTWARE, 8, 9);

Acceleration accel;
float gForce;
int sensorReading;

void printCentered(const char* text, int line, int lineHeight = 12) {
  int16_t x1, y1;
  uint16_t w, h;
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  display.setCursor(display.width()/2 - w/2, line * lineHeight);
  display.print(text);
}
void printMessage2_P(PGM_P text1, PGM_P text2) {
  display.clearDisplay();
  printCentered_P(text1, 0);
  printCentered_P(text2, 1);
  display.display();
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    serialConnection.begin(9600);
  accel.begin();

  serialConnection.println("");
}
float getGravForce(Acceleration* a) {
  return sqrt(sq((*a).x)+sq((*a).y)+sq((*a).z)) / 9.8;
}


void loop() {
accel.read();
        gForce = getGravForce(&accel);
        if (gForce > 0.1 && gForce < 4.0){
         display.display(safe);
        }
}

