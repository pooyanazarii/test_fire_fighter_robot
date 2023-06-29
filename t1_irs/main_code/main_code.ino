
int rightMotor=8;
int leftMotor=9;

int leftSens1=5;
int leftSens2=6;
int leftSens3=7;

int rightSens1=2;
int rightSens2=3;
int rightSens3=4;
int pet;

int fire_sensor=12;

void STOP (void);
void MOVE (void);
void RIGHTDIR (void);
void LEFTDIR (void);

int speedLeft =0;
int speedRight =0;

void setup() {
  // put your setup code here, to run once:

pinMode(rightMotor,OUTPUT);//RightMotor
pinMode(leftMotor,OUTPUT);//LeftMotor

pinMode(fire_sensor,INPUT); //fire Sensor
pinMode(leftSens1,INPUT);//RightSensor
pinMode(leftSens2,INPUT);//LeftSensor
pinMode(rightSens1,INPUT);//RightSensor
pinMode(rightSens2,INPUT);//LeftSensor
Serial.begin(9600);
}

void loop() {
pet=(analogRead(A0)/4.3);
  // put your main code here, to run repeatedly:
bool isFireSens= digitalRead(fire_sensor);

bool isleftSens= digitalRead(leftSens1);
bool isleftSens2= digitalRead(leftSens2);
bool isleftSens3= digitalRead(leftSens3);

bool isrightSens= digitalRead(rightSens1);
bool isrightSens2= digitalRead(rightSens2);
bool isrightSens3= digitalRead(rightSens3);
Serial.print("L2=");
Serial.println(isleftSens2);
Serial.print("L1=");
Serial.println(isleftSens);
Serial.print("R1=");
Serial.println(isrightSens);
Serial.print("R2=");
Serial.println(isrightSens2);


//delay(600);
if (isFireSens!=true){
  STOP();
  
  analogWrite(A5,0);
  Serial.println("fireeeeeeeeeee");
  
delay(2000);
analogWrite(A5,255);

}
else if ((isleftSens2 and isleftSens)and (isrightSens and isrightSens2)){
  STOP();
  Serial.println("stoooooooooooooooooooooop");
}
else if((isrightSens or isrightSens2)==true and (isleftSens or isleftSens2)==false){
  Serial.println("Sensor right 1");

  RIGHTDIR();

}
else if((isleftSens or isleftSens2)==true and (isrightSens or isrightSens2)==false){
  Serial.println("Sensor left 1");
  LEFTDIR();
  
}
else if ((isleftSens==false)and(isleftSens2==false)and(isrightSens==false)and (isrightSens2==false) ){

MOVE();
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
}

void MOVE (void){
  speedRight = 0;
  speedLeft = 0;
analogWrite(10,pet);
analogWrite(11,pet);
  digitalWrite(leftMotor,1);
  digitalWrite(rightMotor,1); 
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

}


