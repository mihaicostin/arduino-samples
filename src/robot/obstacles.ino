#define SENZOR_OBSTACOL 7
#define SPEED 110

int MOTOR2_PIN1 = 3;
int MOTOR2_PIN2 = 5;
int MOTOR1_PIN1 = 6;
int MOTOR1_PIN2 = 9;
int BUTTON_PIN = 4;

boolean startEngine = false;

void setup() {
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  //pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {

  int senzorObstacol = digitalRead(SENZOR_OBSTACOL);
  int btn = digitalRead(BUTTON_PIN);
  
  Serial.print(" SENZOR OBSTACOL: ");
  Serial.println(senzorObstacol);  
  Serial.print(" BUTTON: ");
  Serial.println(btn);
  
//  if (btn == HIGH) {
//    startEngine = !startEngine;
//    Serial.print(" ENGINE IS: ");
//    Serial.println(startEngine);
//  }

  if (senzorObstacol == 0) {
    go(-SPEED, -SPEED);
    delay(1000);
    go(-SPEED, SPEED);
    delay(1000);
  } else {
    go(SPEED, SPEED);
  }
}

void go(int speedLeft, int speedRight) {
  if (speedLeft > 0) {
    analogWrite(MOTOR1_PIN1, speedLeft);
    analogWrite(MOTOR1_PIN2, 0);
  }
  else {
    analogWrite(MOTOR1_PIN1, 0);
    analogWrite(MOTOR1_PIN2, -speedLeft);
  }

  if (speedRight > 0) {
    analogWrite(MOTOR2_PIN1, speedRight);
    analogWrite(MOTOR2_PIN2, 0);
  } else {
    analogWrite(MOTOR2_PIN1, 0);
    analogWrite(MOTOR2_PIN2, -speedRight);
  }
}
