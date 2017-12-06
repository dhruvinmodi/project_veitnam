//motor 1
int c1=22,cc1=23,pwm1=2;
//motor 2
int c2=24,cc2=25,pwm2=3;
//motor 3
int c3=28,cc3=29,pwm3=4;

int opins[]={c1,cc1,pwm1,c2,cc2,pwm2,c3,cc3,pwm3};
int i=0;

void setup() {
  for(i=0;i<9;i++)
  {
    pinMode(opins[i],OUTPUT);                                        //Loop for intitalizing pins. To avoid writing too much code
  }
  for(i=0;i<9;i++)
  {
    if((i==2)||(i==5)||(i==8))
    i++;
    digitalWrite(opins[i],LOW);
  }

}

void loop() {
  delay(10000);
  rotate_clockwise();
}

/*This function will acclerate motors from 0 to max_speed.
 * 0 < max_speed < 200
 * dir=1 for clockwise or 0 for counter clockwise
 * motor_no=1,2,3
*/
void acclerate(int motor_no, int dir, int max_speed)
{
  int strength=0;
  int c,cc,pwm;
  if(motor_no==1)
  {
    c=opins[0];
    cc=opins[1];
    pwm=opins[2];  
  }
  else if(motor_no==2)
  {
    c=opins[3];
    cc=opins[4];
    pwm=opins[5];  
  }
  else if(motor_no==3)
  {
    c=opins[6];
    cc=opins[7];
    pwm=opins[8];  
  }
  if(dir==1)
  digitalWrite(c,HIGH);
  else if(dir==0)
  digitalWrite(cc,HIGH);
  while(strength<=max_speed)
  {
    analogWrite(pwm,strength);
    strength+=10;
    delay(200);
  }
}

//Function to stop the input motor
void stop_motor(int motor_no)
{
  int c,cc,pwm;
  if(motor_no==1)
  {
    c=opins[0];
    cc=opins[1];
    pwm=opins[2];  
  }
  else if(motor_no==2)
  {
    c=opins[3];
    cc=opins[4];
    pwm=opins[5];  
  }
  else if(motor_no==3)
  {
    c=opins[6];
    cc=opins[7];
    pwm=opins[8];  
  }
  digitalWrite(c,LOW);
  digitalWrite(cc,LOW);
  analogWrite(pwm,0);
}

void test1()
{
  acclerate(1,1,0);
  delay(1000);
  acclerate(2,1,40);
  acclerate(3,0,50);
  delay(10000);
  stop_motor(2);
  stop_motor(3);
}

void rotate_clockwise()
{
  acclerate(1,1,50);
  acclerate(2,1,50);
  acclerate(3,1,50);
  delay(500);
  stop_motor(1);
}



