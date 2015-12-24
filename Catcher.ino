#include <Makeblock.h>

#include "movement.h"

#define KEY_UP 'k'
#define KEY_DOWN 'j'
#define KEY_LEFT 'h'
#define KEY_RIGHT 'l'
#define KEY_POWERUP 'p'
#define KEY_POWERDOWN 'o'

void beep() {
  buzzerOn();
  delay(50);
  buzzerOff();
  delay(100);
}

void debug(char* str) {
  Serial.println(str);
}

MeBluetooth bluetooth(PORT_5);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}

static int kPower = 100;
void printPower() {
  Serial.print("Power: ");
  Serial.println(kPower);
}

void loop() {
  if (bluetooth.available()) {
    char c = bluetooth.read();
    Serial.print("Serial: ");
    Serial.print(c);
    switch (c) {
    case KEY_UP:
      moveForward(kPower);
      delay(500);
      break;
    case KEY_DOWN:
      moveBack(kPower);
      delay(500);
      break;
    case KEY_POWERUP:
      kPower += 10;
      if (kPower > 255) {
	kPower = 255;
      }
      printPower();
      break;
    case KEY_POWERDOWN:
      kPower -= 10;
      if (kPower < 0) {
	kPower = 0;
      }
      printPower();
      break;
    default:
      Serial.print("Unsupported key... Power: ");
      Serial.println(kPower);
    }
  } else {
    Serial.println("Nothing on bluetooth");
  }
}
