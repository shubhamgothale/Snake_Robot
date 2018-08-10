#include <Wire.h>
#include <Servo.h>
Servo myservo;
float pos = 0;
float pp;
int in;
float m;

float t;
int z=0;
float q=0;
float h=0;
float d=2;
void setup()
{
  Serial.begin(9600);
  myservo.attach(9);
  Wire.begin(7);                
  Wire.onReceive(e);
  for (in = 10; in <= 90; in += 1)
  {
   myservo.write(in);           
   delay(20);                       
  }
  delay(500);

}

void loop() 
{
    for (pos = q; pos <= h; pos += 1)
    {
      myservo.write(pos);
      pp=map(pos,q,h,0,180);     
      m = 12-(10.24*sin(0.0174532925*pp));
      delay((d*m)+1);
      Serial.print("position is ");
      Serial.print(pos);
      Serial.print("\t delay is ");
      Serial.println(24/(m*d));     
    }
    for (pos =h; pos >=q; pos -= 1) 
    {
      myservo.write(pos);
      pp=map(pos,q,h,0,180);          
      m = 12-(10.24*sin(0.0174532925*pp));
      delay((d*m)+1);
      Serial.print("position is  ");
      Serial.print(pos);
      Serial.print("\t  delay is ");
      Serial.println(24/(m*d));
       
    }
}

void e(int b)
{
  float f = Wire.read();
  float y = Wire.read();
  int x = Wire.read();
  float k = Wire.read();
  t=1997.22*f;
  delay(15);
  z=x;
  if(z==1){
  delay(t/4);
  q=y;
  h=(180-y);
  
  d=k;
  }
}
