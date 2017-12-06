/*******************************************************************************

Task: Controlling a robotic base with 3 powered wheels to move in omni direction.

*******************************************************************************/

// Declaration follows architecture of MEGA board

int cWPin1 = 22 , cCWPin1 = 23 , cWPin2 = 24 , cCWPin2 = 25 , cWPin3 = 28 , cCWPin3 = 29 ;
int pwmPin1 = 2  , pwmPin2 = 3 , pwmPin3 = 4 ;
int flag = 1 ;

void setup ()
{
  
  pinMode ( cWPin1 , OUTPUT ) ;
  pinMode ( cWPin2 , OUTPUT ) ;
  pinMode ( cWPin3 , OUTPUT ) ;
  pinMode ( cCWPin1 , OUTPUT ) ;
  pinMode ( cCWPin2 , OUTPUT ) ;
  pinMode ( cCWPin3 , OUTPUT ) ;
  pinMode ( pwmPin1 , OUTPUT ) ;
  pinMode ( pwmPin2 , OUTPUT ) ;
  pinMode ( pwmPin3 , OUTPUT ) ;
  
  digitalWrite ( cWPin1 , LOW ) ;
  digitalWrite ( cWPin2 , LOW ) ;
  digitalWrite ( cWPin3 , LOW ) ;
  digitalWrite ( cCWPin1 , LOW ) ;
  digitalWrite ( cCWPin2 , LOW ) ;
  digitalWrite ( cCWPin3 , LOW ) ;
  
  analogWrite ( pwmPin1 , 0 ) ;
  analogWrite ( pwmPin2 , 0 ) ;
  analogWrite ( pwmPin3 , 0 ) ;

}

void loop ()
{

  delay ( 10000 ) ;
  motorDirection ( 0 , 1 , -1 ) ;
  motorSpeed ( 0 , 50 , 50 );
  delay ( 10000 ) ;

}

void motorSpeed ( int s1 , int s2 , int s3 )
{

  analogWrite ( pwmPin1 , s1 ) ;
  analogWrite ( pwmPin2 , s2 ) ;
  analogWrite ( pwmPin3 , s3 ) ;
  
}

void motorDirection ( int d1 , int d2 , int d3 )
{

  boolean cWState1 = LOW , cWState2 = LOW , cWState3 = LOW , cCWState1 = LOW , cCWState2 = LOW , cCWState3 = LOW ;
  
  if ( d1 == 0 )
  {

    cWState1 = LOW ;
    cCWState1 = LOW ;
    
  }
  else if ( d1 == 1 )
  {

    cWState1 = HIGH ;
    cCWState1 = LOW ;
    
  }
  else
  {

    cWState1 = LOW ;
    cCWState1 = HIGH ;
    
  }

  if ( d2 == 0 )
  {

    cWState2 = LOW ;
    cCWState2 = LOW ;
    
  }
  else if ( d2 == 1 )
  {

    cWState2 = HIGH ;
    cCWState2 = LOW ;
    
  }
  else
  {

    cWState2 = LOW ;
    cCWState2 = HIGH ;
    
  }

  if ( d3 == 0 )
  {

    cWState3 = LOW ;
    cCWState3 = LOW ;
    
  }
  else if ( d3 == 1 )
  {

    cWState3 = HIGH ;
    cCWState3 = LOW ;
    
  }
  else
  {

    cWState3 = LOW ;
    cCWState3 = HIGH ;
    
  }

  digitalWrite ( cWPin1 , cWState1 ) ;
  digitalWrite ( cCWPin1 , cCWState1 ) ;
  digitalWrite ( cWPin2 , cWState2 ) ;
  digitalWrite ( cCWPin2 , cCWState2 ) ;
  digitalWrite ( cWPin3 , cWState3 ) ;
  digitalWrite ( cCWPin3 , cCWState3 ) ;
  
}

void tuneCircularRotation ()
{

  int dt = 0 , i = 0 ;

  for ( i = 0 ; i < 10 ; i += 1 )
  {

    delay ( 5000 ) ;
    motorDirection ( 1 , 1 , 1 ) ;
    accelerate ( 1 , 1 , 1 ) ;
    delay ( dt ) ;
    brake ( 1 , 1 , 1 ) ;
    
  }
  
}


/*This function will acclerate motors from 0 to max_speed.
 * 0 < max_speed < 200
 *dir= 'f' for forward and 'b' for backward
*/
void accelerate(char dir,int max_speed)
{
  int strength=0;
  if(dir=='f')
  {
    digitalWrite(c3,HIGH);
    digitalWrite(cc2,HIGH);
    while(strength<=max_speed)
    {
      analogWrite(pwm3,strength);
      analogWrite(pwm2,(strength-10));
      delay(200);
      strength+=10;
    }
  }
  else if(dir=='b')
  {
    digitalWrite(cc3,HIGH);
    digitalWrite(c2,HIGH);
    while(strength<=max_speed)
    {
      analogWrite(pwm3,strength);
      analogWrite(pwm2,(strength-10));
      delay(200);
      strength+=10;
    }
  }
}
