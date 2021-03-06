#define DIST_MAX 50    // максимальное расстояние (см). Датчик бьёт до 4 метров, но будут шумы
#define MAX_ANGLE 180   // максимальный угол поворота
#define MIN_ANGLE 0    // минимальный угол поворота

// Includes the Servo library
#include <Servo.h>.

// Defines Tirg and Echo pins of the Ultrasonic Sensor
#define ECHO 7
#define TRIG 6
#define SERVO 9

#include <Ultrasonic.h>
Ultrasonic ultrasonic(6, 7);

//#include <NewPing.h>
//NewPing sonar(TRIG, ECHO, DIST_MAX);

// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor

void setup() {
  pinMode(TRIG, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(SERVO); // Defines on which pin is the servo motor attached
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for (int i = MIN_ANGLE; i <= MAX_ANGLE; i++) {
    myServo.write(i);
    delay(30);
//    int curr_dist = sonar.ping_cm();
//    if (curr_dist == 0) curr_dist = DIST_MAX;
    
    int curr_dist = ultrasonic.read(CM);
    if (curr_dist > 50) curr_dist = 50;
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(curr_dist);
    Serial.print(".");
  }
  // Repeats the previous lines from 165 to 15 degrees
  for (int i = MAX_ANGLE; i > MIN_ANGLE; i--) {
    myServo.write(i);
    delay(30);
//    int curr_dist = sonar.ping_cm();
//    if (curr_dist == 0) curr_dist = DIST_MAX;

    int curr_dist = ultrasonic.read(CM);
    if (curr_dist > 50) curr_dist = 50;

    
    Serial.print(i);
    Serial.print(",");
    Serial.print(curr_dist);
    Serial.print(".");


    
  }
}
