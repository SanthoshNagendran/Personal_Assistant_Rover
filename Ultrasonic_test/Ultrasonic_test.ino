const int trigPin = 8;
const int echoPin = 7;
long duration;

int x; //Variable for storing received data

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Sets the baud for serial data transmission   
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
// Calculating the distance
  x= duration*0.034/2;
  Serial.print(x);          //Print Value inside data in Serial monitor
      Serial.print("\n");          //New line
}
