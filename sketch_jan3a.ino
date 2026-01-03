#include <Servo.h>

Servo fingerServo;

int flexPin = A0;     // Flex sensor connected to A0
int servoPin = 9;     // Servo signal pin

int flexValue;
int servoAngle;

void setup() {
  fingerServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  flexValue = analogRead(flexPin);

  // Map flex sensor values to servo angle
  // Adjust these values after testing
  servoAngle = map(flexValue, 600, 900, 0, 180);

  // Limit angle range
  servoAngle = constrain(servoAngle, 0, 180);

  fingerServo.write(servoAngle);

  // Debug values
  Serial.print("Flex Value: ");
  Serial.print(flexValue);
  Serial.print(" | Servo Angle: ");
  Serial.println(servoAngle);

  delay(20);
}
