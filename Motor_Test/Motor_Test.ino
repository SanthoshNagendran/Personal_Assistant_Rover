#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

const int trigPin = 8;
const int echoPin = 7;
long duration;

int data=0,x; //Variable for storing received data

TMRpcm tmrpcm;

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
void setup()
{
    Serial.begin(9600); //Sets the baud for serial data transmission                               
    pinMode(3, OUTPUT); //Dc motor control using PWM
    pinMode(5, OUTPUT); //Dc motor control using PWM
    pinMode(6, OUTPUT); //Dc motor control using PWM
    pinMode(9, OUTPUT); //Dc motor control using PWM
    pinMode(2, OUTPUT);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input

    tmrpcm.speakerPin=10;
    Serial.begin(9600);
    if(!SD.begin(SD_ChipSelectPin))
    {
    Serial.println("SD fail");
    return;
    }
    tmrpcm.setVolume(6);
}
void loop()
{
  digitalWrite(2, HIGH);
   if(Serial.available() > 0)  // Send data only when you receive data:
   {
      data = Serial.read();        //Read the  incoming  data and store it into variable data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");          //New line
   }
      if(data == '1')              // Checks whether value of data is equal to 1
         {
            digitalWrite(trigPin, HIGH);
            delay(10);
            digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
            duration = pulseIn(echoPin, HIGH);
// Calculating the distance
            x= duration*0.034/2;
         if(x>20)
         {
         Front_Move();
         }
         else
         {
          tmrpcm.play("1.wav");
         Stop_Move();
         delay(2000);
         Back_Move();
         delay(2000);
         Left_Spin();
         delay(2000);
         }
        }
      else if(data == '2')         //  Checks  whether value of data is equal to 0
          {  
         Back_Move();
         }
      else if(data == '3')         //  Checks  whether value of data is equal to 0
          {
         Left_Spin(); 
         }
      else if(data == '4')         //  Checks  whether value of data is equal to 0
          {
         Right_Spin(); ;
         }
      else if(data == '5')         //  Checks  whether value of data is equal to 0
          {
         Stop_Move();
         }
      else if(data == '6')         //  Checks  whether value of data is equal to 0
          {
         tmrpcm.play("7.wav");
         }
       else if(data == '7')         //  Checks  whether value of data is equal to 0
          {
         tmrpcm.play("8.wav");
         }
       else if(data == '8')         //  Checks  whether value of data is equal to 0
          {
         tmrpcm.play("9.wav");
         }
       else if(data == '9')         //  Checks  whether value of data is equal to 0
          {
         tmrpcm.play("10.wav");
         }
         
}
