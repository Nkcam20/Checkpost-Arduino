#include <Servo.h>

Servo myservo;

int pos = 0;

int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  digitalWrite(12,LOW);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  cm = 0.01723 * readUltrasonicDistance(6, 7);
  myservo.write(0);

  if(cm<5 && cm != 0){
    Serial.print(cm);
    Serial.println("cm");

    myservo.write(120); // move servo to high position

    // wait for 30 ms before bringing servo back
    delay(3000);
  } else {
    myservo.write(0); // hold servo at 0 position
    delay(20);
  }
}