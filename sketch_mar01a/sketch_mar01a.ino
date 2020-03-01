int motor1_IN1=11;
int motor1_IN2=12;
int motor2_IN3=9;
int motor2_IN4=10;

char state;
void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
}
void setup() 
{
  pinMode(motor1_IN1,OUTPUT);
  pinMode(motor1_IN2,OUTPUT);
  pinMode(motor2_IN3,OUTPUT);
  pinMode(motor2_IN4,OUTPUT);
  Serial.begin(9600);

}

void Left()
{
  digitalWrite(motor1_IN1,LOW);
  digitalWrite(motor1_IN2,HIGH);
  digitalWrite(motor2_IN3,HIGH);
  digitalWrite(motor2_IN4,LOW);
}
void Right()
{
  digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,LOW);
  digitalWrite(motor2_IN4,HIGH);
}
void Front()
{
  digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,HIGH);
  digitalWrite(motor2_IN4,LOW);
}
void Back()
{
  digitalWrite(motor1_IN1,LOW);
  digitalWrite(motor1_IN2,HIGH);
  digitalWrite(motor2_IN3,LOW);
  digitalWrite(motor2_IN4,HIGH);
}

void loop()
{
 while(Serial.available())
  {state=Serial.read();}

  switch(state)
  {
    case 'F': {
  digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,HIGH);
  digitalWrite(motor2_IN4,LOW);
}
    case 'L': { digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,LOW);
  digitalWrite(motor2_IN4,HIGH);
    }
    case 'R': {
  digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,LOW);
  digitalWrite(motor2_IN4,HIGH);
}
    case 'B': {
  digitalWrite(motor1_IN1,LOW);
  digitalWrite(motor1_IN2,HIGH);
  digitalWrite(motor2_IN3,LOW);
  digitalWrite(motor2_IN4,HIGH);
}
           
  }
}

