const int trigPin_0= 2,trigPin_90=8,echoPin_90=7;
const int echoPin_0 = 5;
int motor1_IN1=11;
int motor1_IN2=12;
int motor2_IN3=9;
int motor2_IN4=10;
long duration_0,duration_90,l,f;
int distance_0,distance_90;
int ll,hl;


void setup() {
pinMode(trigPin_0, OUTPUT); 
pinMode(echoPin_0, INPUT); 
pinMode(trigPin_90, OUTPUT);
pinMode(echoPin_90, INPUT);
Serial.begin(9600); 
}

void loop() {
  distance_90,distance_0 = read();
  decision(distance_90,distance_0);
  Serial.print("Distance: ");
  Serial.print(distance_0);
  Serial.print("           Distance: ");
  Serial.print(distance_90);
  Serial.println();

}
int read(){
  digitalWrite(trigPin_0, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_0, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_0, LOW);
duration_0 = pulseIn(echoPin_0, HIGH);
distance_0= duration_0*0.034/2;
// second ultrasonic sensor
digitalWrite(trigPin_90, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_90, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_90, LOW);
duration_90 = pulseIn(echoPin_90, HIGH);
distance_90= duration_90*0.034/2;
return(distance_90,distance_0);
  }
int decision(long l, long f){
  l,f = read();
  if(l<=7 && f>5){
    Serial.println("Right");
    return(1);
    }
    return(0);
  }
