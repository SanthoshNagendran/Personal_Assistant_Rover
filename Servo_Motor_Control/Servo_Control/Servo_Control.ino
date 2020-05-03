// Include the Servo library 
#include <Servo.h> 
Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
char data;

void setup() { 
   // We need to attach the servo to the used pin number 
    myservo1.attach(A0);
    myservo2.attach(A1);
    myservo3.attach(A2);
    myservo4.attach(A3);
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
            if(pos<=180)
            {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
           myservo2.write(pos);
           delay(15);
           pos+=10;
            }
          }
      else if(data=='2')
      {
            if(pos>=0)
            {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
           myservo2.write(pos);
           delay(15);
           pos-=10;
            }
      }
     else if(data == '3')              // Checks whether value of data is equal to 1
          {            
            if(pos<=180)
            {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
           myservo1.write(pos);
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
           myservo1.write(pos);
           delay(15);
           pos-=10;
            }
      }
      else if(data == '5')              // Checks whether value of data is equal to 1
            {            
            if(pos<=180)
              {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
              myservo3.write(pos);
              delay(15);
              pos+=10;
              }
            }
          else if(data == '6')
            {
            if(pos>=0)
              {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
              myservo3.write(pos);
              delay(15);
              pos-=10;
              }
             } 
          else if(data == '7')              // Checks whether value of data is equal to 1
             {            
            if(pos<=180)
                {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
              myservo4.write(pos);
              delay(15);
              pos+=10;
                }
              }
          else if(data == '8')
              {
            if(pos>=0)
                {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
              myservo4.write(pos);
              delay(15);
              pos-=10;
                }
              }   
      
   } 
}
