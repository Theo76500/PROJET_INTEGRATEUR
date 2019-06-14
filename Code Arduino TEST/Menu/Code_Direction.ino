#include <Grove_I2C_Motor_Driver.h>
int hasard = 2;

void Left(int speed) {
  Motor.speed(MOTOR1, 50);
  Motor.speed(MOTOR2, speed);
}

void Right(int speed) {
  Motor.speed(MOTOR2, 50);
  Motor.speed(MOTOR1, speed);
}

void up(int speed) {
  Motor.speed(MOTOR1, speed);
  Motor.speed(MOTOR2, speed);
}

void down(int time) {
  Motor.speed(MOTOR1, 10);
  Motor.speed(MOTOR2, 10);
}

void stopCar() {
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
}

void pause(int time) {
  Motor.speed(MOTOR1, 0);
  Motor.speed(MOTOR2, 0);
  delay(time);
}

void bigLeft() {
  Left(-100);
  turn = true;
  direction = 1;
  limitValue = limitedValue();
}

void bigRight() {
  Right(-100);
  turn = true;
  direction = 0;
  limitValue = limitedValue();
}

int limitedValue() {
  int hasard = random(0,1);
  if (hasard == 0) {
    return 50;
  }
  else {
    return 0;
  }
}
