//Compile time debugger
#define DEBUG
#include <DebugUtils.h>

//Standby 
#define FRONT_STBY 12
#define BACK_STBY 11

//Motor front left
#define FL_PWMA 3 //Speed control
#define FL_AIN1 2 //Direction
#define FL_AIN2 4 //Direction
 
//Motor front right
#define FR_PWMB 5 //Speed Control
#define FR_BIN1 7 //Direction
#define FR_BIN2 8 //Direction

//Motor back left
#define BL_PWMA 9  //Speed Control
#define BL_AIN1  A0 //Direction
#define BL_AIN2  A1 //Direction

//Motor back right
#define BR_PWMB  10 //Speed Control
#define BR_BIN1  A2 //Direction
#define BR_BIN2  A3 //Direction

int motorSpeedFL = 255;
int motorSpeedFR = 255;
int motorSpeedBL = 255;
int motorSpeedBR = 255;

void setup() {
  Serial.begin(9600);
  
  pinMode(FRONT_STBY, OUTPUT);
  pinMode(BACK_STBY, OUTPUT);
  
  pinMode(FL_PWMA, OUTPUT);
  pinMode(FL_AIN1, OUTPUT);
  pinMode(FL_AIN2, OUTPUT);
  
  pinMode(FR_PWMB, OUTPUT);
  pinMode(FR_BIN1, OUTPUT);
  pinMode(FR_BIN2, OUTPUT);
  
  pinMode(BL_PWMA, OUTPUT);
  pinMode(BL_AIN1, OUTPUT);
  pinMode(BL_AIN2, OUTPUT);
  
  pinMode(BR_PWMB, OUTPUT);
  pinMode(BR_BIN1, OUTPUT);
  pinMode(BR_BIN2, OUTPUT);
}

void loop() {
  move(1, motorSpeedFL, 0);
  move(2, motorSpeedFR, 0);
  move(3, motorSpeedBL, 0);
  move(4, motorSpeedBR, 1);
  //motorSpeedFL += 20;
  //motorSpeedFR += 20; 
  //motorSpeedBL += 20;
  //motorSpeedBR += 20;
  delay(10000);
  stop();
}

void move(int motor, int speed, int direction) {

  //Flip direction
  boolean in1 = LOW;
  boolean in2 = HIGH;

  if(direction == 1) {
    in1 = HIGH;
    in2 = LOW;
  }
  
  //Turn motor controllers on
  digitalWrite(FRONT_STBY, HIGH);
  digitalWrite(BACK_STBY, HIGH);
  
  //Controlling individual motor operations
  switch(motor) {

    //Front Left
    case 1:
      digitalWrite(FL_AIN1, in1);
      digitalWrite(FL_AIN2, in2);
      analogWrite(FL_PWMA, speed);
    break;
    
    //Front Right
    case 2:
      digitalWrite(FR_BIN1, in1);
      digitalWrite(FR_BIN2, in2);
      analogWrite(FR_PWMB, speed);
    break;

    //Back Left
    case 3:
      digitalWrite(BL_AIN1, in1);
      digitalWrite(BL_AIN2, in2);
      analogWrite(BL_PWMA, speed);
     break;

    //Back Right
    case 4:
      digitalWrite(BR_BIN1, in1);
      digitalWrite(BR_BIN2, in2);
      analogWrite(BR_PWMB, speed);
    break;

    default:
      DEBUG_PRINT("Invalid motor choice!");
    break;
  }
}

void stop() {
  digitalWrite(FRONT_STBY, LOW);
  digitalWrite(BACK_STBY, LOW);
}

