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

  if ( d1 == 0 )
  {

    digitalWrite ( cWPin1 , LOW ) ;
    digitalWrite ( cCWPin1 , LOW ) ;
    
  }
  else if ( d1 == 1 )
  {

    digitalWrite ( cWPin1 , HIGH ) ;
    digitalWrite ( cCWPin1 , LOW ) ;
    
  }
  else
  {

    digitalWrite ( cWPin1 , LOW ) ;
    digitalWrite ( cCWPin1 , HIGH ) ;
    
  }

  if ( d2 == 0 )
  {

    digitalWrite ( cWPin2 , LOW ) ;
    digitalWrite ( cCWPin2 , LOW ) ;
    
  }
  else if ( d2 == 1 )
  {

    digitalWrite ( cWPin2 , HIGH ) ;
    digitalWrite ( cCWPin2 , LOW ) ;
    
  }
  else
  {

    digitalWrite ( cWPin2 , LOW ) ;
    digitalWrite ( cCWPin2 , HIGH ) ;
    
  }

  if ( d3 == 0 )
  {

    digitalWrite ( cWPin3 , LOW ) ;
    digitalWrite ( cCWPin3 , LOW ) ;
    
  }
  else if ( d3 == 1 )
  {

    digitalWrite ( cWPin3 , HIGH ) ;
    digitalWrite ( cCWPin3 , LOW ) ;
    
  }
  else
  {

    digitalWrite ( cWPin3 , LOW ) ;
    digitalWrite ( cCWPin3 , HIGH ) ;
    
  }
  
}
