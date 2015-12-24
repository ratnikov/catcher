#include <Makeblock.h>

static MeDCMotor front(M1);
static MeDCMotor rear(M2);

void moveForward(int power) {
  front.run(power);
  rear.run(-power);
}

void moveBack(int power) {
  moveForward(-power);
}

void moveStop() {
  front.stop();
  rear.stop();
}

void turnRight(int power) {
  front.run(power);
  rear.run(power);
}

void turnLeft(int power) {
  front.run(-power);
  rear.run(-power);
}
