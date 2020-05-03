//simple Tx on pin D12
//Written By : Mohannad Rawashdeh
// 3:00pm , 13/6/2013
//http://www.genotronex.com/
//..................................
#include <VirtualWire.h>

#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;
void setup()
{
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_set_rx_pin(8);
    vw_setup(4000);  // Bits per sec
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    vw_rx_start();       // Start the receiver PLL running
        tmrpcm.speakerPin=10;

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
    vw_set_rx_pin(8);
    vw_setup(4000);  // Bits per sec
    vw_rx_start();       // Start the receiver PLL running
   
    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      
      if(buf[0]=='1'){  
        Serial.println("Name");
        digitalWrite(13, HIGH);
        tmrpcm.play("7.wav");
         delay(10000);
     
      }  
      if(buf[0]=='2'){ 
        Serial.println("services");
        digitalWrite(13, HIGH);
        tmrpcm.play("8.wav");
        delay(10000);
       
      }
      if(buf[0]=='3'){ 
        digitalWrite(13, HIGH);
        Serial.println("features");
        tmrpcm.play("9.wav");
         delay(10000);
    
      }
      if(buf[0]=='4'){ 
        digitalWrite(13, HIGH);
        Serial.println("play");
        tmrpcm.play("10.wav");

         delay(10000);
      
      }
      if(buf[0]=='5'){   
        digitalWrite(13, HIGH);
        Serial.println("pause");
        tmrpcm.play("11.wav");
         delay(10000);
       
      }
    
      /*else{
  tone(8,0,200);
  Serial.println("wrong code\n");
    }*/
    }


}
