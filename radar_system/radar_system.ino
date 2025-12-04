/*
// Includes the Servo library
#include <Servo.h>. 
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;

// Variables for the duration and the distance
long duration;
int distance;

int servo_delay = 15;

Servo myServo; // Creates a servo object for controlling the servo motor

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(12); // Defines on which pin is the servo motor attached
}

void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
    servoAction(i);
  }

  // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
    servoAction(i);
  }
}

int servoAction(int degree) {
  myServo.write(degree);
  delay(servo_delay);
  distance = calculateDistance(); // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  // Serial.print(i); // Sends the current degree into the Serial Port
  // Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  // Serial.print(distance); // Sends the distance value into the Serial Port
  // Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing

  Serial.print(degree);
  Serial.print(", ");
  Serial.print(distance);
  Serial.println();
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
*/
// NEW 

#include <Servo.h>

Servo myservo;  

int servo_pos = 0;    
int servo_delay = 30;

const int SERVO_ATTACH_PIN = 12;
const int trigPin = 10;
const int echoPin = 11;

// Variables for the duration and the distance
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  myservo.attach(SERVO_ATTACH_PIN); 
  Serial.begin(9600);
}

void loop()
{


  delay(100);
    for (servo_pos = 0; servo_pos <= 180; servo_pos += 1) // change here in the place 0 and 180 , into any two degrees you wish the servo to sweep.
    { 
     servoAction(servo_pos);
    //  distanceCalculate();
    }
    
    for (servo_pos = 180; servo_pos >= 0; servo_pos -= 1)  // change here also  in the place 0 and 180 , into any two degrees you wish the servo to sweep.
    { 
     servoAction(servo_pos);    
    //  distanceCalculate();              
    }
    
}

int servoAction(int degree) {
  myservo.write(degree);
  delay(servo_delay);
  distance = calculateDistance(); // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  Serial.print(degree); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance() { 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;

}




