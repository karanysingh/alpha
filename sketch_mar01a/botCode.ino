const int trigPin_0= 2,trigPin_90=8,echoPin_90=7;
const int echoPin_0 = 5;
int motor1_IN1=11;
int motor1_IN2=12;
int motor2_IN3=9;
int motor2_IN4=10;
long duration_0,duration_90,l,f;
int distance_0,distance_90;
int ll,hl;
char state;


void setup() {
pinMode(trigPin_0, OUTPUT); 
pinMode(echoPin_0, INPUT); 
pinMode(trigPin_90, OUTPUT);
pinMode(echoPin_90, INPUT);
pinMode(motor1_IN1,OUTPUT);
pinMode(motor1_IN2,OUTPUT);
pinMode(motor2_IN3,OUTPUT);
pinMode(motor2_IN4,OUTPUT);
extern char state; // global variable 
state = 'A';//no use in automatic transmission
Serial.begin(9600); 
}

void loop(){
  //getting data from ultrasonic sensors by calling read()
  distance_90,distance_0 = read();
  
  //Taking decision on the basis of sensor values
  int decision_final = decision(distance_90,distance_0);
  
  //Executing a bot action on the basis of decision(Automatic Transmission)
  char mode = 'A';
  if(decision_final=='1'){
    state = 'L';//for left turn
  }else if(decision_final=='2'){
    state = 'R'; //for right turn
  }else{
    state = 'F';
  }
  execution(state,mode);
  
  // Serial.print("Distance: ");
  // Serial.print(distance_0);
  // Serial.print("           Distance: ");
  // Serial.print(distance_90);
  // Serial.println();

}
int read(){//method to read value from the ultrasonic sensors
  
  //first ultrasonic sensor
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
  
//Decision  
int decision(long l, long f){
  //getting values from read method (returning 1 for left and 2 for right)
  l,f = read();
  
  //Decision for all the possible cases
  if(l>5 && f>5){
    Serial.println("Left");
    return(1);
    }
  else if(l<=7 && f<=7){
    Serial.println("Right");
    return(2);
  }
  else if(l>5 && f<=7){
    Serial.println("Left");
    return(1);
  }
  return(0);
  
  
}
////////

//Method responsible for controlling motors
void execution(char state,char mode){
  if(mode=='M'){
 while(Serial.available())
  {state=Serial.read();
  switch(state)
  {
    case 'F': {
  digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,HIGH);
  digitalWrite(motor2_IN4,LOW);
}
    case 'L': { 
  digitalWrite(motor1_IN1,HIGH);
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
}else if(mode == 'A'){
  switch(state)
  {
    case 'F': {
  digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,HIGH);
  digitalWrite(motor2_IN4,LOW);
}
    case 'L': { 
  digitalWrite(motor1_IN1,HIGH);
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
}

