#include <Servo.h>

/*
 Code to make servo go from 0 deg to 180 deg position and back agin in 5 seconds interval
 */

Servo myservo;  

int pos = 0;    

void setup() {
  myservo.attach(12); 
}

void loop()
{

  myservo.write(0);              
  delay(5000);                      

  myservo.write(180);                 
  delay(5000);                   

}

