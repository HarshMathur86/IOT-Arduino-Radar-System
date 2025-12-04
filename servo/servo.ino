#include <Servo.h>

Servo myservo;  

int servo_pos = 0;    
int servo_delay = 30;

int SERVO_ATTACH_PIN = 12;

void setup() {
  myservo.attach(SERVO_ATTACH_PIN); 
}

void loop()
{

  // myservo.write(180);

    for (servo_pos = 0; servo_pos <= 180; servo_pos += 1) // change here in the place 0 and 180 , into any two degrees you wish the servo to sweep.
    { 
     servoAction(servo_pos);                        
    }
    
    for (servo_pos = 180; servo_pos >= 0; servo_pos -= 1)  // change here also  in the place 0 and 180 , into any two degrees you wish the servo to sweep.
    { 
     servoAction(servo_pos);                       
    }
}

int servoAction(int degree) {
  myservo.write(degree);
  delay(servo_delay);
  // distance = calculateDistance(); // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  // Serial.print(i); // Sends the current degree into the Serial Port
  // Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  // Serial.print(distance); // Sends the distance value into the Serial Port
  // Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing

  Serial.print(degree);
  Serial.print(", ");
  // Serial.print(distance);
  // Serial.println();
}

