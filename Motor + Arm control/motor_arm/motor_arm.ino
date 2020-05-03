#include <Servo.h> 
Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;

int pos = 0;  // variable to store the servo position
char data; //Variable for storing received data

void Front_Move()
{
  analogWrite(3,128);
  digitalWrite(5,LOW);
  analogWrite(6,128);
  digitalWrite(9,LOW);
}
void Back_Move()
{
  digitalWrite(3,LOW);
  analogWrite(5,128);
  digitalWrite(6,LOW);
  analogWrite(9,128);
}
void Stop_Move()
{
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
}
void Left_Spin()
{
  digitalWrite(3,LOW);
  analogWrite(5,150);
  analogWrite(6,150);
  digitalWrite(9,LOW);
}
void Right_Spin()
{
  analogWrite(3,135);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  analogWrite(9,135);
}


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600); //Sets the baud for serial data transmission                               
    pinMode(13, OUTPUT); //Sets digital pin 13 as output pin
    pinMode(3, OUTPUT); //Dc motor control using PWM
    pinMode(5, OUTPUT); //Dc motor control using PWM
    pinMode(6, OUTPUT); //Dc motor control using PWM
    pinMode(9, OUTPUT); //Dc motor control using PWM
    pinMode(2, OUTPUT);
    myservo1.attach(A0);
    myservo2.attach(A1);
    myservo3.attach(A2);
    myservo4.attach(A3);
}

void loop()
{
  digitalWrite(2, HIGH); // L293D - 5v enable pin.
   if(Serial.available() > 0)  // Send data only when you receive data:
   {
      data = Serial.read();        //Read the  incoming  data and store it into variable data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");          //New line
      if(data == 'f')              // Checks whether value of data is equal to 1
         {
         digitalWrite(13, HIGH);   //If value is 1 then LED turns ON
         Front_Move();
         }
      else if(data == 'b')         //  Checks  whether value of data is equal to 0
          {
         digitalWrite(13, LOW);   
         Back_Move();
         }
      else if(data == 's')         //  Checks  whether value of data is equal to 0
          {
         digitalWrite(13, HIGH);   
         Stop_Move();
         }
      else if(data == 'l')
          {
          digitalWrite(13, HIGH);   
          Left_Spin(); 
          }
      else if(data == 'r')
          {
          digitalWrite(13, HIGH);   
          Right_Spin(); 
          }
      else if(data == '1')
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
