int motor1_IN1=11;
int motor1_IN2=12;
int motor2_IN3=9;
int motor2_IN4=10;
const int trigPin_0= 2;
const trigPin_90=8;
const echoPin_90=7;
const int echoPin_0 = 5;

long duration_0,duration_90;
int distance_0,distance_90;

char state;

void setup() 
{
  pinMode(motor1_IN1,OUTPUT);
  pinMode(motor1_IN2,OUTPUT);
  pinMode(motor2_IN3,OUTPUT);
  pinMode(motor2_IN4,OUTPUT);
  pinMode(trigPin_0, OUTPUT); 
  pinMode(echoPin_0, INPUT); 
  pinMode(trigPin_90, OUTPUT);
  pinMode(echoPin_90, INPUT);
  Serial.begin(9600);
}

float read_sensor1()
{
  digitalWrite(trigPin_0, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_0, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_0, LOW);
  duration_0 = pulseIn(echoPin_0, HIGH);
  distance_0= duration_0*0.034/2;
  return distance_0;
}

float read_sensor2()
{
// second ultrasonic sensor
  digitalWrite(trigPin_90, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_90, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_90, LOW);
  duration_90 = pulseIn(echoPin_90, HIGH);
  distance_90= duration_90*0.034/2;
  return distance_90;
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

