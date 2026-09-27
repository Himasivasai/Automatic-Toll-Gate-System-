// Automatic Toll Gate System Using Arduino

#include <Servo.h>

Servo servo;

int trigPin = 11;
int echoPin = 12;

// Defines variables
long duration;
int distance;

void setup()
{
  servo.attach(13);
  servo.write(180);
  delay(2000);

  // Initialize Serial Monitor
  Serial.begin(9600);

  // Sets the trigPin as an Output
  pinMode(trigPin, OUTPUT);

  // Sets the echoPin as an Input
  pinMode(echoPin, INPUT);
}

void loop()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin and returns the sound wave travel time
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2;

  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Vehicle detected within 25 cm
  if (distance <= 25)
  {
    servo.write(180);
    delay(3000);
  }
  else
  {
    servo.write(90);
  }
}