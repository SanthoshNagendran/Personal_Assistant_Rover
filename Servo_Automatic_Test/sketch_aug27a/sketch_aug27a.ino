// Include the Servo library 
#include <Servo.h> 
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int data =0;

void setup() { 
   // We need to attach the servo to the used pin number 
    myservo.attach(A0);
   Serial.begin(9600);
}
void loop(){ 
   // Make servo go to 0 degrees 
   
   if(Serial.available() > 0)  // Send data only when you receive data:
   {
      data = Serial.read();        //Read the  incoming  data and store it into variable data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");
     
     if(data == '1')
      {
        for (pos = 0; pos <= 180; pos += 1) {
           myservo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(15);                     // waits 15ms for the servo to reach the position
              }
          for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
           delay(15);
              }
      }
      else if(data=='2')
      {
        myservo.write(68);
           delay(15);
      }
     else if(data == '3')              // Checks whether value of data is equal to 1
          {            
            if(pos<=180)
            {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
           myservo.write(pos);
           delay(15);
           pos+=10;
            }
          }
       else if(data == '4')
      {
            if(pos>=0)
            {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
           myservo.write(pos);
           delay(15);
           pos-=10;
            }
      }
      
   } 
}
