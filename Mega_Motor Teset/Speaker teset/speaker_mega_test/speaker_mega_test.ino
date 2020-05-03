#include "SD.h"
#define SD_ChipSelectPin 53
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup()
{
tmrpcm.speakerPin=11;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(6);
tmrpcm.play("10.wav");
}

void loop() {
  // put your main code here, to run repeatedly:
// tmrpcm.play("1.wav"); 
//tmrpcm.play("2.wav");
//tmrpcm.play("3.wav");
//tmrpcm.play("4.wav");
//tmrpcm.play("5.wav");
//tmrpcm.play("6.wav");
//tmrpcm.play("7.wav");
//tmrpcm.play("8.wav");
//tmrpcm.play("9.wav");

//tmrpcm.play("11.wav");

delay(10000);

}
