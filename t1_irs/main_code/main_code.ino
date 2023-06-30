
int rightMotor=8;
int rightMotorPin2=A4;

int leftMotor=9;
int leftMotorPin2=A3;

int leftSens1=5;
//int leftSens2=6;
int leftSens3=7;

int rightSens1=3;
//int rightSens2=2;
int rightSens3=4;
int pet;

int fire_sensor=12;

void STOP (void);
void MOVE (void);
void RIGHTDIR (void);
void LEFTDIR (void);
void BACK (void);

void RIGHTDIRFORCE (void);
void LEFTDIRFORCE (void);

int speedLeft =0;
int speedRight =0;

int gColor;

void setup() {
  // put your setup code here, to run once:

pinMode(rightMotor,OUTPUT);//RightMotor
pinMode(leftMotor,OUTPUT);//LeftMotor
pinMode(rightMotorPin2,OUTPUT);//RightMotor
pinMode(leftMotorPin2,OUTPUT);//LeftMotor

pinMode(fire_sensor,INPUT); //fire Sensor
pinMode(leftSens1,INPUT);//RightSensor
//pinMode(leftSens2,INPUT);//LeftSensor
pinMode(rightSens1,INPUT);//RightSensor
//pinMode(rightSens2,INPUT);//LeftSensor
Serial.begin(9600);
}

void loop() {
pet=(analogRead(A0)/4.3);
  // put your main code here, to run repeatedly:
bool isFireSens= digitalRead(fire_sensor);

bool isleftSens= digitalRead(leftSens1);
//bool isleftSens2= digitalRead(leftSens2);
bool isleftSens3= digitalRead(leftSens3);

bool isrightSens= digitalRead(rightSens1);
//bool isrightSens2= digitalRead(rightSens2);
bool isrightSens3= digitalRead(rightSens3);
gColor=analogRead(A1);
Serial.print("input coloer:");
Serial.println(gColor);
// Serial.print("L1=");
// Serial.println(isleftSens);
// //Serial.print("L2=");
// //Serial.println(isleftSens2);
// Serial.print("L3=");
// Serial.println(isleftSens3);
// Serial.print("R1=");
// Serial.println(isrightSens);
// //Serial.print("R2=");
// //Serial.println(isrightSens2);
// Serial.print("R3=");
// Serial.println(isrightSens3);
// Serial.print("pet=");
// Serial.println(pet);


if (isFireSens!=true){ //Turn off fire
  STOP();
  
  analogWrite(A5,0);
  Serial.println("fireeeeeeeeeee");
  
//delay(2000);
analogWrite(A5,255);

}

else if ((isleftSens and  isleftSens3 )and (isrightSens  and isrightSens3)){
  STOP();
  MOVE();
  delay(100);
  Serial.println("stoooooooooooooooooooooop");
  if ((gColor>=580) and (gColor<=650)){
    Serial.println("Green");
    RIGHTDIRFORCE();
  }else if (gColor>=501){
Serial.println("White");
LEFTDIRFORCE();
  }
}
else if((isrightSens==true) and (isrightSens3==true)) {
  Serial.println("R force");

RIGHTDIRFORCE();
}
else if((isleftSens==true)  and (isleftSens3==true) ) {
  Serial.println("L force");
LEFTDIRFORCE();
}
else if((isrightSens or isrightSens3)==true and (isleftSens  or isleftSens3)==false){
  Serial.println("Sensor right 1");

  RIGHTDIR();

}

else if((isleftSens  or isleftSens3)==true and (isrightSens or isrightSens3)==false){
  Serial.println("Sensor left 1");
  LEFTDIR();
  
}


else if ((isleftSens==false)and(isleftSens3==false)and(isrightSens==false)  and (isrightSens3==false) ){

MOVE();
}
else{

STOP();
}
//if((isleftSens==false and isleftSens2==false) and (isrightSens==false and isrightSens2==false)){
//Serial.println("run");
//  digitalWrite(rightMotor,1);
//  digitalWrite(leftMotor,1);
//}
//else if(isleftSens2==false or isleftSens2==false){
//  Serial.println("left off");
//    digitalWrite(rightMotor,1);
//  digitalWrite(leftMotor,0);
//}
//else if(isrightSens==false or isrightSens2==false){
//Serial.println("right off");
//    digitalWrite(rightMotor,0);
//  digitalWrite(leftMotor,1);
//}
}

void STOP (void){
    speedRight = 0;
  speedLeft = 0;
  digitalWrite(leftMotor,0);
  
  digitalWrite(rightMotor,0);
   digitalWrite(leftMotorPin2,0); 
   digitalWrite(rightMotorPin2,0); 
}

void MOVE (void){
  speedRight = 0;
  speedLeft = 0;
analogWrite(10,pet);
analogWrite(11,pet);
  digitalWrite(leftMotor,1);
  digitalWrite(rightMotor,1); 
  digitalWrite(leftMotorPin2,0); 
  digitalWrite(rightMotorPin2,0); 
}
void BACK (void){


analogWrite(10,pet);
analogWrite(11,pet);
  digitalWrite(leftMotor,0);
  digitalWrite(rightMotor,0); 
  digitalWrite(leftMotorPin2,1); 
  digitalWrite(rightMotorPin2,1); 
  delay(500);
}


void LEFTDIR (void)
{
  speedRight = 0;
  if (speedLeft==0){
  speedLeft = pet;
  }
  else if (speedLeft!=190){
    speedLeft+=1;
  }
    analogWrite(10,speedLeft);
  digitalWrite(leftMotor,0);
  digitalWrite(rightMotor,1);
  digitalWrite(leftMotorPin2,0); 
  digitalWrite(rightMotorPin2,0); 
   

}

void RIGHTDIR (void)
{
  speedLeft = 0;
    if (speedRight==0){
  speedRight = pet;
  }
  else if (speedRight!=190){
    speedRight+=1;
  }
  analogWrite(11,speedRight);
  digitalWrite(leftMotor,1);
  digitalWrite(rightMotor,0); 
  digitalWrite(leftMotorPin2,0); 
  digitalWrite(rightMotorPin2,0); 

}


void LEFTDIRFORCE (void)
{
  MOVE();
  delay(500);
  STOP();
  delay(400);

    speedLeft+=1;
    speedRight+=1;
    analogWrite(10,speedLeft);
  digitalWrite(leftMotor,0);
  digitalWrite(rightMotor,1);

  digitalWrite(leftMotorPin2,1); 
  digitalWrite(rightMotorPin2,0); 
  delay(1000);
   

}

void RIGHTDIRFORCE (void)
{
    MOVE();
  delay(500);
  STOP();
  delay(400);
    speedRight+=1;
    speedLeft+=1;
  analogWrite(11,speedRight);
  digitalWrite(leftMotor,1);
  digitalWrite(rightMotor,0); 
   digitalWrite(leftMotorPin2,0); 
  digitalWrite(rightMotorPin2,1); 
    delay(1000);

}


