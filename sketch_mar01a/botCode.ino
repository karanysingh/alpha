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
char mode;
void setup() {
pinMode(trigPin_0, OUTPUT); 
pinMode(echoPin_0, INPUT); 
pinMode(trigPin_90, OUTPUT);
pinMode(echoPin_90, INPUT);
pinMode(motor1_IN1,OUTPUT);
pinMode(motor1_IN2,OUTPUT);
pinMode(motor2_IN3,OUTPUT);
pinMode(motor2_IN4,OUTPUT);

extern char mode;
extern char state; // global variable
mode='A'; 
state = 'P';//no use in automatic transmission
Serial.begin(9600); 
}

void loop(){
   trans();
   if(mode=='M'){
   state = Serial.read(); // Reads the data from the serial por
  //getting data from ultrasonic sensors by calling read()
   }
  else{
  distance_90,distance_0 = read();
  
  //Taking decision on the basis of sensor values
  int decision_final = decision(distance_90,distance_0);
  
  //Executing a bot action on the basis of decision(Automatic Transmission)
  if(decision_final=='1'){
    state = 'A';//for left turn
  }else if(decision_final=='2'){
    state = 'D'; //for right turn
  }else{
    state = 'W';
  }}
//  Serial.println("This is state - > ");
//  Serial.print(state);
  execution(state,mode);
  
  // Serial.print("Distance: ");
  // Serial.print(distance_0);
  // Serial.print("           Distance: ");
  // Serial.print(distance_90);
  // Serial.println();

}

//checks whether manual or automatic transmission
void trans(){
  char temp = Serial.read();
//  Serial.println("This is serial");
//  Serial.println(temp);
  if(temp=='M'){
  mode = 'M';
  Serial.println("Shifted to manual!!!");
  }
  if(temp=='Q'){
    mode='A';
    Serial.println("Shifted to Automatic!!");
    }
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
  switch(state)
  {
    case 'W': {
  Serial.println("Forward");
  digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,HIGH);
  digitalWrite(motor2_IN4,LOW);
  break;
}
    case 'A': { 
  Serial.println("Rotate Left");
  digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,LOW);
  digitalWrite(motor2_IN4,HIGH);
  break;
    }
    case 'D': {
  Serial.println("Rotate Right");
  digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,LOW);
  digitalWrite(motor2_IN4,HIGH);
  break;
}
    case 'S': {
  Serial.println("Backward");
  digitalWrite(motor1_IN1,LOW);
  digitalWrite(motor1_IN2,HIGH);
  digitalWrite(motor2_IN3,LOW);
  digitalWrite(motor2_IN4,HIGH);
  break;
}
  }
  }
else if(mode == 'A'){
  switch(state)
  {//WASD control
    case 'W': {
  digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,HIGH);
  digitalWrite(motor2_IN4,LOW);
}
    case 'A': { 
  digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,LOW);
  digitalWrite(motor2_IN4,HIGH);
    }
    case 'D': {
  digitalWrite(motor1_IN1,HIGH);
  digitalWrite(motor1_IN2,LOW);
  digitalWrite(motor2_IN3,LOW);
  digitalWrite(motor2_IN4,HIGH);
}
    case 'S': {
  digitalWrite(motor1_IN1,LOW);
  digitalWrite(motor1_IN2,HIGH);
  digitalWrite(motor2_IN3,LOW);
  digitalWrite(motor2_IN4,HIGH);
}
  }
}
}
