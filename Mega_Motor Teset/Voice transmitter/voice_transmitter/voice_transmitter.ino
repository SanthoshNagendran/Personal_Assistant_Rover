

#include <VirtualWire.h>


char *controller;

byte com = 0; //reply from voice recognition
void setup() {
  pinMode(13,OUTPUT);
vw_set_ptt_inverted(true); //
vw_set_tx_pin(12);
vw_setup(4000);// speed of data transfer Kbps
 Serial.begin(9600);
delay(2000);
  Serial.write(0xAA);
  Serial.write(0x37);
  delay(1000);
  Serial.write(0xAA);
  Serial.write(0x21);
}

void loop(){



while(Serial.available()){
    com = Serial.read();
    switch(com){
      case 0x11:
        {
          controller="1"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,1);
delay(1000);
digitalWrite(13,0);
delay(1000);
        
        break;
        }
      case 0x12:
        {
          controller="2"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,1);
delay(1000);
digitalWrite(13,0);
delay(1000);
          
      break;
        }
      case 0x13:
        {
          controller="3"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,1);
delay(1000);
digitalWrite(13,0);
delay(1000);
      break;
        }
      case 0x14:
        {
          controller="4"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,1);
delay(1000);
digitalWrite(13,0);
delay(1000);
      break;
        }
      case 0x15:
       {
        controller="5"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone
digitalWrite(13,1);
delay(1000);
digitalWrite(13,0);
delay(1000);
      break;
       }
   }
  }

}
