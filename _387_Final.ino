int left_motor_back=10; // pin10 will control the left motor to back
int left_motor_forward= 9; // pin 9 will control the left motor to forward
int right_motor_back=6; // pin 6 will control the right motor to back
int right_motor_forward=5; // pin 5 will control the right motor to forward

const int SensorRight = 13; //pin 13 control the infrared sensor on rigth side
const int SensorMiddle = 7; //pin12 control the infrared sensor on middle side
const int SensorLeft= 8; //pin 8 control the infrared sensor on left side

int SL; // set up a variable for those three infared sensor above
int SM;
int SR;

void setup(){
///////////////////////////////////Motor Output///////////////////////////////
pinMode(left_motor_back, OUTPUT);
pinMode(left_motor_forward, OUTPUT);
pinMode(right_motor_back, OUTPUT);
pinMode(right_motor_forward, OUTPUT);
//pinMode(key,INPUT);
//pinMode(led,OUTPUT);
pinMode(SensorRight, INPUT);
pinMode(SensorMiddle, INPUT);
pinMode(SensorLeft, INPUT);
}
//////////////////////////////////Motion of Cart////////////////////////////////
void forward()
{
  analogWrite(right_motor_forward,110);//the right motor move forward, the change of PWM will change the speed of the motor
  analogWrite(right_motor_back,0);
  analogWrite(left_motor_forward,110);// the left motor move forward, the change of PWM will change the speed of the motor
  analogWrite(left_motor_back,0);
}

void brake()
{
  digitalWrite(right_motor_forward,LOW); //set all four pin to LOW in order to breake
  digitalWrite(right_motor_back,LOW);
  digitalWrite(left_motor_forward,LOW);
  digitalWrite(left_motor_back,LOW);
}

void turn()
{
  analogWrite(right_motor_forward,0);
  analogWrite(right_motor_back,110);  //Let the right motor move back and the left motor move forward to make a U-turn
  analogWrite(left_motor_forward,60); // The didfferent PWM value makes one wheel faster than the other 
  analogWrite(left_motor_back,0);
}

void adjust()
{
  analogWrite(right_motor_forward,0); //It is used to make a small adjust of the direction depends on the motion of the cart
  analogWrite(right_motor_back,0);
  analogWrite(left_motor_forward,60);
  analogWrite(left_motor_back,0);
}

void left()         
{
  digitalWrite(right_motor_forward,LOW); //The right motor stop
  digitalWrite(right_motor_back,LOW);
  analogWrite(left_motor_forward,0);   
  analogWrite(left_motor_back,80);//The left motor move backward to make the cart's direction changes to left.
}

//void spin_left()
//{
//  analogWrite(right_motor_forward,110); //It can change the speed of the right motor in setting up the PWM value
//  analogWrite(right_motor_back,0);
//  analogWrite(left_motor_forward,0);
//  analogWrite(left_motor_back,160);//It can change the speed of the left motor in setting up the PWM value
//}

void right()       
{
  analogWrite(right_motor_forward,0);   
  analogWrite(right_motor_back,80); //back_forward of right motor to turn the direction to right

  digitalWrite(left_motor_forward,LOW); 
  digitalWrite(left_motor_back,LOW);//
  } 


void back()// moving backward of both motor
{
  analogWrite(right_motor_forward,0);
  analogWrite(right_motor_back,80);//
  analogWrite(left_motor_forward,0);
  analogWrite(left_motor_back,80);//
}



void loop()
{
  ///If there is a signal of the infrared sensor, it will be LOW;
  ///If there is no signal of the infrared sensor, it will be HIGH;
  SR = digitalRead(SensorRight);
  SL = digitalRead(SensorLeft);
  SM = digitalRead(SensorMiddle);
  if (SR ==HIGH && SL == HIGH && SM == HIGH) //No obstacle in front of three infrared sensor
     {forward();
     delay(100);}
  else if(SL ==HIGH && SR ==HIGH && SM == LOW) //One obstacle in front of the middle sensor
      { back();  //back up a little bit in order to have a space to turn
      delay(100);
        turn();
      delay(100);}
  else if (SL ==HIGH && SR == LOW && SM ==HIGH)//One obstacle in front of right sensor
      { back();
      delay(100);
        left(); //turn left
      delay(100);}
  else if (SL ==HIGH && SR == LOW && SM ==LOW) //two obstacle in front of middle and right sensors
      { back();
      delay(100);
        left();
      delay(100);}
  else if (SL ==LOW && SR == HIGH && SM ==HIGH) //one obstacle in front of left sensors
      { back();
      delay(100);
        right();
      delay(100);}  
  else if (SL ==LOW && SR == HIGH && SM ==LOW) //two obstacle in left sides
      {back();
      delay(100);
      right();
      delay(100);
      }
  else if (SL ==LOW && SR == LOW && SM ==HIGH)//two obstacle in left side and right side, but the cart can still move forward
      {forward();
      delay(100);
       }
  else if (SL ==LOW && SR == LOW && SM ==LOW)//three obstacle in front of cart, make a U-turn
      {back();
      delay(100);
        turn();
      delay(100);}
        }
//The code above does not include the cooperation between ultrasonic sensor and servo. For further development and more details,
//Please contact the author. The Arduino cart is a power model, so it means that it can have a lot of functions.

      


  


