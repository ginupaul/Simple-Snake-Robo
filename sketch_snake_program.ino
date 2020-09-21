#include <Servo.h> 
#include<stdlib.h>

  char Recdata;
  char i;
  int Distance_value=0;
  int obstacle_threshold=200;

  char servo1_angle=90;
  char servo2_angle=110;
  char servo3_angle=90;
  char servo4_angle=100;
  char servo5_angle=40;
  char servo6_angle=70;
  
  
  Servo Segment1_servo;
  Servo Segment2_servo;
  Servo Segment3_servo;
  Servo Segment4_servo;
  Servo Segment5_servo;
  Servo Segment6_servo;
  
  
  void Forward(void);
  void Stop(void);
  void Right(void);
  void Left(void);
  void obstacles_avoidance(void);
  void obstacle();
  unsigned int adc_threshold;
  

void setup()
{
    Serial.begin(9600); 
    Segment1_servo.attach(2);              //Head segment of snake robot connected to the digital pinout 2
    delay(100);
    Segment2_servo.attach(3);              //Segment2 of snake robot connected to the digital pinout 3
    delay(100);
    Segment3_servo.attach(4);              //Segment3 of snake robot connected to the digital pinout 4
    delay(100);
    Segment4_servo.attach(5);              //Segment4 of snake robot connected to the digital pinout 5
    delay(100);
    Segment5_servo.attach(6);              //Segment5 of snake robot connected to the digital pinout 6
    delay(100);
    Segment6_servo.attach(7);              //Tail segment of snake robot connected to the digital pinout 7
    delay(100);
  
   Segment1_servo.write(servo1_angle);
   delay(500);
   Segment2_servo.write(servo2_angle);
   delay(500);
   Segment3_servo.write(servo3_angle);
   delay(500);
   Segment4_servo.write(servo4_angle);
   delay(500);
   Segment5_servo.write(servo5_angle);
   delay(500);
   Segment6_servo.write(servo6_angle);
   delay(500);
   //Serial.print("SNAKE ROBOT");       
}
void loop()
{
  
if (Serial.available() > 0)
  {
  Recdata=Serial.read();

  }
  
    if(Recdata=='F') 
      {
     adc_threshold = analogRead(0);
if( ( adc_threshold > obstacle_threshold ) )
	{
      obstacles_avoidance();
          }
      else
      {
      Forward();
      }
      } 
    
    if(Recdata=='S') 
      {
      Recdata='\0';
      Stop();
      }
   


}
void Forward(void)
  {
     for (i=0;i<=45;i++)
      {
      Segment6_servo.write(servo6_angle--); 
      delay(3);
      } 
    for (i=0;i<=45;i++)
      {
      Segment4_servo.write(servo4_angle++); 
      delay(3);
      } 
   
    for (i=0;i<=55;i++)
      {
      Segment6_servo.write(servo6_angle++);
      delay(3);
     }
    for (i=0;i<=45;i++)
      {
      Segment2_servo.write(servo2_angle++); 
      delay(3);
      } 
    for (i=0;i<=55;i++)
      {
      Segment4_servo.write(servo4_angle--);
      delay(3);
      }
    for (i=0;i<=55;i++)
     {
     Segment2_servo.write(servo2_angle--);
     delay(3);
     }
     
     servo6_angle=70;
     Segment6_servo.write(servo6_angle);   
     servo4_angle=100;
     Segment4_servo.write(servo4_angle);
     servo2_angle=110;
     Segment2_servo.write(servo2_angle);
     
     
 
 }


void Left(void)
{
  
for (i=0;i<=35;i++)
      {
        Segment1_servo.write(servo1_angle++);
        delay(10);
     }  
    for (i=0;i<=35;i++)
      {
        Segment3_servo.write(servo3_angle++);
        delay(10);
     } 
      for (i=0;i<=35;i++)
      {
        Segment1_servo.write(servo1_angle--);
        delay(15);
     }
     
     for (i=0;i<=45;i++)
      {
        Segment5_servo.write(servo5_angle--);
        delay(15);
     } 
    
     
     
     
      for (i=0;i<=35;i++)
      {
        Segment3_servo.write(servo3_angle--);
        delay(15);
     } 
          for (i=0;i<=45;i++)
      {
        Segment5_servo.write(servo5_angle++);
        delay(15);
     }
    
}

void Right()
{
  // Recdata='\0';
 for (i=0;i<=45;i++)
      {
        Segment1_servo.write(servo1_angle--);
        delay(10);
     }  
    for (i=0;i<=35;i++)
      {
        Segment3_servo.write(servo3_angle--);
        delay(10);
     } 
      for (i=0;i<=45;i++)
      {
        Segment1_servo.write(servo1_angle++);
        delay(15);
     }
     
     for (i=0;i<=45;i++)
      {
        Segment5_servo.write(servo5_angle++);
        delay(15);
     } 
     
     
     
     
      for (i=0;i<=35;i++)
      {
        Segment3_servo.write(servo3_angle++);
        delay(15);
     } 
          for (i=0;i<=45;i++)
      {
        Segment5_servo.write(servo5_angle--);
        delay(15);
     }
//     for (i=0;i<=45;i++)
//      {
//        Segment1_servo.write(servo1_angle--);
//        Segment3_servo.write(servo3_angle--);
//        Segment5_servo.write(servo5_angle++);
//        delay(15);
//     } 
//     
//     for (i=0;i<=45;i++)
//      {
//        Segment1_servo.write(servo1_angle++);
//        Segment3_servo.write(servo3_angle++);
//        Segment5_servo.write(servo5_angle--);
//        delay(7);
//     }  
}


void Stop(void)
{
     servo1_angle=90;
     servo2_angle=110;
     servo3_angle=90;
     servo4_angle=100;
     servo5_angle=40;
     servo6_angle=70;
       
    Segment1_servo.write(servo1_angle);
   delay(100);
   Segment2_servo.write(servo2_angle);
   delay(100);
   Segment3_servo.write(servo3_angle);
   delay(100);
   Segment4_servo.write(servo4_angle);
   delay(100);
   Segment5_servo.write(servo5_angle);
   delay(100);
   Segment6_servo.write(servo6_angle);
   delay(100); 
}

void obstacles_avoidance(void)     ////300
{

unsigned int peak_left_threshold;
unsigned int peak_right_threshold;
adc_threshold = analogRead(0);
//Serial.print(adc_threshold);
//Serial.println('*');
if( ( adc_threshold > obstacle_threshold ) )
	{
	 delay(7);			
	peak_left_threshold  = adc_threshold;
	peak_right_threshold = adc_threshold;

			for(i=0 ;i < 30;i++ )
				{
			 Segment1_servo.write(servo1_angle++);
				 delay(7);
				adc_threshold = analogRead(0);
				if( adc_threshold > peak_left_threshold +10)
					{
				
					peak_left_threshold = adc_threshold;
					}
				}
			for(i=0 ;i < 30;i++ )
				{
				Segment1_servo.write(servo1_angle++);
				 delay(7);
				}

			for(i=0;i < 30;i++ )
					{
	
				Segment1_servo.write(servo1_angle--);
				 delay(7);
					adc_threshold = analogRead(0);
					if( adc_threshold > peak_right_threshold+10 )
						{
						peak_right_threshold = adc_threshold;
						}
					}
			for(i=0 ;i< 30;i++ )
					{
					Segment1_servo.write(servo1_angle--);
				 	delay(7);
					}

				if( peak_left_threshold > peak_right_threshold )
						{

                                //Stop();
                                 Right();Right();//Right();
				
						}
				if( peak_right_threshold > peak_left_threshold )
						{

                                  //Stop();
                                  Left();Left();//Left();
						}
	peak_left_threshold = 0;
	peak_right_threshold = 0;
    }
/*else if( adc_threshold < obstacle_threshold )
		{
		forward();
		}	*/
}
