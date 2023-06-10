int in1=8;
int in2=9;
int leftMotor = 10;
int in3=12;
int in4=13;
int rightMotor=11;

//void STOP (void);
//void RightDir (void);
int chLeft1=0;
int chLeft2=0;
int chmidSen=0;
int chRight2=0;
int chRight1=0;


int rightSen1=2;
int rightSen2=3;
int midSen=4;
int leftSen2=5;
int leftSen1=6;


void setup() {
  Serial.begin(9600);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  digitalWrite(in1,OUTPUT);


  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);

}

void loop() {

//  analogWrite(leftMotor,80);
//  analogWrite(rightMotor,50);

while(1)
  {
    chLeft1=digitalRead(leftSen1);
    chLeft2=digitalRead(leftSen2);
    chmidSen=digitalRead(midSen);
    chRight2=digitalRead(rightSen2);
    chRight1=digitalRead(rightSen1);
    
    //Serial.println((chmidSen));
    if((chLeft1==1 && chLeft2==1 && chmidSen==1 && chRight2==1 && chRight1==1))
    {
    STOP();
    Serial.println("go stop");
    }
    else if((chLeft1==0 && chLeft2==0 && chmidSen==1 && chRight2==0 && chRight1==0))
    {
    Serial.println("go straight");
  analogWrite(leftMotor,70);
  analogWrite(rightMotor,60);
    }
     else if((chLeft1==0 && chLeft2==0 && chmidSen==0 && chRight2==0 && chRight1==0))
    {
    Serial.println("stoooooop");
    STOP();
    Serial.println("go stop");
    }
    else if((chLeft1==1 && chLeft2==0 && chmidSen==0 && chRight2==0 && chRight1==0))
    {
    Serial.println("go left90");
    analogWrite(leftMotor,0);
    analogWrite(rightMotor,55);

    }
    else if((chLeft1==0 && chLeft2==1 && chmidSen==0 && chRight2==0 && chRight1==0))
    {
    Serial.println("go left45");
    analogWrite(leftMotor,0);
    analogWrite(rightMotor,55);
    }
    else if((chLeft1==0 && chLeft2==0 && chmidSen==0 && chRight2==0 && chRight1==1))
    {
    Serial.println("go right90");
    analogWrite(leftMotor,55);
    analogWrite(rightMotor,0);
    }
        else if((chLeft1==0 && chLeft2==00 && chmidSen==0 && chRight2==1 && chRight1==0))
    {
    Serial.println("go right45");
    analogWrite(leftMotor,55);
    analogWrite(rightMotor,0);
    }
    
    
  }






  
//  while(1)
//  {
//    chLeft=digitalRead(leftSen);
//    chRight=digitalRead(rightSen);
//    
//    if((chLeft==0 && chRight==1)==1)
//    //LEFTVoid();
//    Serial.println("left");
//    else if((chRight==0 && chLeft==1)==1)
//    RIGHTVoid();
//    else if(
//  }

  

}

//void RIGHTVoid (void)
//{
//   analogWrite(rightMotor,60);
//
//  
//    while(chRight==0)
//     {
//      chLeft=digitalRead(leftSen);
//      chRight=digitalRead(rightSen);
//      if(chLeft==0)
//      {
//        int lprev=chLeft;
//        int rprev=chRight;
//       STOP();
//        while(((lprev==chLeft)&&(rprev==chRight))==1)
//        {
//           chLeft=digitalRead(leftSen);
//           chRight=digitalRead(rightSen);
//        }
//     }
//     analogWrite(leftMotor,150);
//     }
//  analogWrite(rightMotor,150);
//}

//------------------------ for stop robot
void STOP (void)
{
  analogWrite(leftMotor,0);
  analogWrite(rightMotor,0); 
}

//last code
