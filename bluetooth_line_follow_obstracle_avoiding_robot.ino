#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3); // RX, TX
Servo headServo;

// Motor pins
const int IN1 = 4, IN2 = 5, IN3 = 6, IN4 = 7;

// IR sensor pins
const int IR_LEFT = A0;
const int IR_RIGHT = A1;

// Ultrasonic pins
const int TRIG = 10;
const int ECHO = 9;

// Servo pin
const int SERVO_PIN = 11;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);

  pinMode(TRIG, OUTPUT); pinMode(ECHO, INPUT);

  pinMode(IR_LEFT, INPUT); pinMode(IR_RIGHT, INPUT);

  headServo.attach(SERVO_PIN);
  headServo.write(90); // center
  delay(500);
}

void loop() {
  if (BT.available()) {
    handleBluetooth(BT.read());
  } else {
    lineFollowAvoid();
  }
}

void handleBluetooth(char cmd) {
  switch (cmd) {
    case 'F': forward(); break;
    case 'B': backward(); break;
    case 'L': left(); break;
    case 'R': right(); break;
    case 'S': stop(); break;
  }
}

void lineFollowAvoid() {
  int distFront = getDistance(90);

  if (distFront < 20) {
    stop();
    int distLeft = getDistance(150);
    int distRight = getDistance(30);

    if (distLeft > distRight) {
      left(); delay(300);
    } else {
      right(); delay(300);
    }
  } else {
    int irL = digitalRead(IR_LEFT);
    int irR = digitalRead(IR_RIGHT);

    if (irL == LOW && irR == LOW) forward();
    else if (irL == LOW) left();
    else if (irR == LOW) right();
    else stop();
  }
}

int getDistance(int angle) {
  headServo.write(angle);
  delay(400); // wait for servo to move
  digitalWrite(TRIG, LOW); delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long dur = pulseIn(ECHO, HIGH);
  return dur * 0.034 / 2;
}

// Motor control
void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void stop() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
