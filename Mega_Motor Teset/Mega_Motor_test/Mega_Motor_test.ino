
int data=0; //Variable for storing received data


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

    Serial.begin(9600);

}
void loop()
{
  digitalWrite(6, HIGH);
   if(Serial.available() > 0)  // Send data only when you receive data:
   {
      data = Serial.read();        //Read the  incoming  data and store it into variable data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");          //New line
   }
      if(data == '1')              // Checks whether value of data is equal to 1
         {
          
         Front_Move();
       
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

         
}
