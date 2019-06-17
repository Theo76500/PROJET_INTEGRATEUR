#include <Grove_I2C_Motor_Driver.h>
#include "Code_Direction.h"
#include "PathFinding.h"

/*int left =  2;
int middleL = 3;
int middleR = 8;
int right = 6;


int green = 1;
int red = 4;
int yellow = 7;
int blue = 5;

int compteur = 0;
// MOTOR1 = Roue gauche
// MOTOR2 = Roue droite
*/

void setup() {
  /*Motor.begin(I2C_ADDRESS);
  pinMode(left, INPUT);
  pinMode(middleL, INPUT);               
  pinMode(middleR, INPUT);
  pinMode(right, INPUT);

  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
*/
  Serial.begin(9600);
  Path = pathFinding("J", "O");
  Serial.println(Path);
}
void loop() {

/*
  Serial.print(digitalRead(left)); 
  Serial.print(digitalRead(middleL));
  Serial.print(digitalRead(middleR));
  Serial.print(digitalRead(right));
  Serial.print(" "+ turn);
  Serial.println(" "+direction);
  digitalWrite(yellow,digitalRead(left));
  digitalWrite(red,digitalRead(middleL));
  digitalWrite(blue,digitalRead(middleR));
  digitalWrite(green,digitalRead(right));

  if (turn == true) {
    compteur++;
  }
  else {
    compteur = 0;
  }
  
  //black line not detected (0,0,0,0)
  if(0 == digitalRead(left) && 0 == digitalRead(middleL) && 0 == digitalRead(middleR) && 0 == digitalRead(right) && turn == false) {
    up(-50);
  }
  // Black line detected everywhere (1,1,1,1)
  else if(1 == digitalRead(left) && 1 == digitalRead(middleL) && 1 == digitalRead(middleR) && 1 == digitalRead(right) && turn == false) {
    int hasard = random(0,1);
    if (hasard == 0) {
      bigRight();
    }
    else {
      bigLeft();
    }
  }
  // Black line detected to the left and middle left (1,1,0,0)
  else if(1 == digitalRead(left) && 1 == digitalRead(middleL) && 0 == digitalRead(middleR) && 0 == digitalRead(right) && turn == false) {
    bigLeft();
  }
  // Black line detected to the right and middle right (0,0,1,1)
  else if(0 == digitalRead(left) && 0 == digitalRead(middleL) && 1 == digitalRead(middleR) && 1 == digitalRead(right) && turn == false) {
    bigRight();
  }
  // Black line detected to the middle right (0,0,1,0)
  else if(0 == digitalRead(left) && 0 == digitalRead(middleL) && 1 == digitalRead(middleR) && 0 == digitalRead(right) && turn == false) {
    Right(-50);
  }
  // Black line detected to the middle left (0,1,0,0)
  else if(0 == digitalRead(left) && 1 == digitalRead(middleL) && 0 == digitalRead(middleR) && 0 == digitalRead(right) && turn == false) {
    Left(-50);
  }
  // Black line detected to the middle right (0,0,1,0)
  else if(0 == digitalRead(left) && 0 == digitalRead(middleL) && 1 == digitalRead(middleR) && 0 == digitalRead(right) && turn == true && direction == 1 && compteur >= limitValue) {
    turn = false;
    direction = 2;
    limitValue = 0;
  }
  // Black line detected to the middle left (0,1,0,0)
  else if(0 == digitalRead(left) && 1 == digitalRead(middleL) && 0 == digitalRead(middleR) && 0 == digitalRead(right) && turn == true && direction == 0 && compteur >= limitValue) {
    turn = false;
    direction = 2;
    limitValue = 0;
  }
  // Black line detected to the left, the middle left and the middle right (1,1,1,0)
  else if(1 == digitalRead(left) && 1 == digitalRead(middleL) && 1 == digitalRead(middleR) && 0 == digitalRead(right) && turn == false) {
    Right(-50);
  }
  // Black line detected to the the middle left, the middle right and the right (0,1,1,1)
  else if(0 == digitalRead(left) && 1 == digitalRead(middleL) && 1 == digitalRead(middleR) && 1 == digitalRead(right) && turn == false) {
    Left(-50);
  }
  // Black line detected to the left (1,0,0,0)
  else if(1 == digitalRead(left) && 0 == digitalRead(middleL) && 0 == digitalRead(middleR) && 0 == digitalRead(right) && turn == false) {
    Left(-50);
  }
  // Black line detected to the right (0,0,0,1)
  else if(0 == digitalRead(left) && 0 == digitalRead(middleL) && 0 == digitalRead(middleR) && 1 == digitalRead(right) && turn == false) {
    Right(-50);
  }
  // Black line detected to the right (1,0,0,1)
  else if(1 == digitalRead(left) && 0 == digitalRead(middleL) && 0 == digitalRead(middleR) && 1 == digitalRead(right) && turn == false) {
    int hasard = random(0,1);
    if (hasard == 0) {
      bigRight();
    }
    else {
      bigLeft();
    }
  }
  // Black line detected to the middle Left and middle Right (0,1,1,0)
  else if(0 == digitalRead(left) && 1 == digitalRead(middleL) && 1 == digitalRead(middleR) && 0 == digitalRead(right) && turn == false) {
    up(-50);
  }
  /*
  // All others : (1,0,1,0) ; (0,1,0,1) ;  (1,1,0,1) ; (1,0,1,1)
  else {
     pause(5000);
  }
  */
}
