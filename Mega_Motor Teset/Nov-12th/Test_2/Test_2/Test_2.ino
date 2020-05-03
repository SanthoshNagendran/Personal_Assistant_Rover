#include <VirtualWire.h>
#include <ServoTimer2.h>

#include "SD.h"
#define SD_ChipSelectPin 53
#include "TMRpcm.h"
#include "SPI.h"

 //typedef uint8_t boolean;
 //typedef bool boolean;

ServoTimer2 myservo1;  // create servo object to control a servo
ServoTimer2 myservo2;
ServoTimer2 myservo3;


int pos = 0,x;
const int trigPin = 48;
const int echoPin = 49;
long duration;

TMRpcm tmrpcm;

void Front_Move()
{
  analogWrite(2,128);
  digitalWrite(3,LOW);
  analogWrite(4,128);
  digitalWrite(5,LOW);
}
void Back_Move()
{
  digitalWrite(2,LOW);
  analogWrite(3,128);
  digitalWrite(4,LOW);
  analogWrite(5,128);
}
void Stop_Move()
{
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}
void Left_Spin()
{
  digitalWrite(2,LOW);
  analogWrite(3,150);
  analogWrite(4,150);
  digitalWrite(5,LOW);
}
void Right_Spin()
{
  analogWrite(2,135);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  analogWrite(5,135);
}
void setup()
{
    Serial.begin(9600); //Sets the baud for serial data transmission                               
    pinMode(2, OUTPUT); //Dc motor control using PWM
    pinMode(3, OUTPUT); //Dc motor control using PWM
    pinMode(4, OUTPUT); //Dc motor control using PWM
    pinMode(5, OUTPUT); //Dc motor control using PWM
    pinMode(6, OUTPUT);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    myservo1.attach(7);
    myservo2.attach(8);
    myservo3.attach(9);

    vw_set_ptt_inverted(true); // Required for DR3100
    vw_set_rx_pin(46);
    vw_setup(4000);  // Bits per sec
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    vw_rx_start();       // Start the receiver PLL running

    tmrpcm.speakerPin=11;

    if(!SD.begin(SD_ChipSelectPin))
    {
    Serial.println("SD fail");
    return;
    }
    tmrpcm.setVolume(6);

}
void loop()
{

      uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    //digitalWrite(13, HIGH);
   vw_set_ptt_inverted(true); // Required for DR3100
    vw_set_rx_pin(46);
    vw_setup(4000);  // Bits per sec
    vw_rx_start();       // Start the receiver PLL running
    
  digitalWrite(6, HIGH);

       
                   if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      
      if(buf[0]=='N'){  
        Serial.println("Name");
        digitalWrite(13, HIGH);
        tmrpcm.play("7.wav");
         delay(10000);
     
      }  
     if(buf[0]=='S'){ 
        Serial.println("services");
        digitalWrite(13, HIGH);
        tmrpcm.play("8.wav");
        delay(10000);
       
      }
     if(buf[0]=='F'){ 
        digitalWrite(13, HIGH);
        Serial.println("features");
        tmrpcm.play("9.wav");
         delay(10000);
    
      }
     if(buf[0]=='P'){ 
        digitalWrite(13, HIGH);
        Serial.println("play");
        tmrpcm.play("10.wav");

         delay(10000); 
      }
      if(buf[0]=='X'){   
        digitalWrite(13, HIGH);
        Serial.println("pause");
        tmrpcm.play("11.wav");
         delay(10000);
       
      }
    else  if(buf[0] == '2')              // Checks whether value of data is equal to 1
         {
         Front_Move();
         }
      else if(buf[0] == '8')         //  Checks  whether value of data is equal to 0
          {  
         Back_Move();
         }
      else if(buf[0] == '4')         //  Checks  whether value of data is equal to 0
          {
         Left_Spin(); 
         }
     else if(buf[0] == '6')         //  Checks  whether value of data is equal to 0
          {
         Right_Spin(); ;
         }
     else if(buf[0] == '5')         //  Checks  whether value of data is equal to 0
          {
         Stop_Move();
         }
        else if(buf[0] == '1')         //  Checks  whether value of data is equal to 0
          {
         tmrpcm.play("7.wav");
         delay(10000);
         }
        else if(buf[0] == '3')         //  Checks  whether value of data is equal to 0
          {
         tmrpcm.play("8.wav");
         delay(10000);
         }
        else if(buf[0] == '7')         //  Checks  whether value of data is equal to 0
          {
         tmrpcm.play("9.wav");
         delay(10000);
         }
        else if(buf[0] == '9')         //  Checks  whether value of data is equal to 0
          {
         tmrpcm.play("10.wav");
         delay(10000);
         }
      else if(buf[0] == 'A')
       {     while(1){       
            if(pos<=135)
            {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
           myservo2.write(pos);
           delay(15);
           pos+=1;
            }
       }
          }
      else if(buf[0]=='D')
      {
        while(1){
            if(pos>=45)
            {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
           myservo2.write(pos);
           delay(15);
           pos-=1;
            }
        }
      }
     else if(buf[0] == '*')              // Checks whether value of data is equal to 1
          {  
            while(1){          
            if(pos<=135)
            {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
           myservo1.write(pos);
           delay(15);
           pos+=1;
            }
            }
          }
        else if(buf[0] == '#')
      {
        while(1){
            if(pos>=45)
            {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
           myservo1.write(pos);
           delay(15);
           pos-=1;
            }
        }
      }
       else if(buf[0] == 'B')              // Checks whether value of data is equal to 1
            {     
              while(1){       
            if(pos<=135)
              {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
              myservo3.write(pos);
              delay(15);
              pos+=1;
              }
              }
            }
           else if(buf[0] == 'C')
            {
              while(1){
            if(pos>=45)
              {
              Serial.print(pos);          //Print Value inside data in Serial monitor
              Serial.print("\n");
              myservo3.write(pos);
              delay(15);
              pos-=1;
              }
              }
             }
    
      /*else{
  tone(8,0,200);
  Serial.println("wrong code\n");
    }*/
    }   
       
         
}
