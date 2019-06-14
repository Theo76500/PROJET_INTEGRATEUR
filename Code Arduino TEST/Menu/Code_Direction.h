#define I2C_ADDRESS 0x0f

boolean turn = false;
int direction = 2;
int limitValue = 0;

void pause(int time);
void Left(int speed);
void Right(int speed);
void up(int speed);
void down();
void stopCar();
void choiceDirection(int choice);
void bigLeft();
void bigRight();
