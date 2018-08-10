#include <Wire.h>
float amplitude;
float angle;
float frequency;
int on=0;
float d;

byte y;
byte x;
byte f;
byte k;




void setup() { Wire.begin();
Serial.begin(9600);
digitalWrite(2, HIGH);}

void loop()
{
 on=digitalRead(4);

 amplitude = analogRead(A0); 
 amplitude = map(amplitude, 1, 1023, 0, 8);
 frequency = analogRead(A1);
 frequency = map(frequency, 1, 1023, 1, 10);
 angle= (57.2957795130* acos(amplitude/10));
 float n;
 float g;
 float ff;
 for(n=angle;n<=90;n++)
    {
      ff= n*(90-angle)/90;
      g = g+(12-(10.24*sin(ff*0.0174532925)));
    }
    d =frequency*(1997.22/(4*g));
    g=0;
 
 x=on;
 y=angle;
 f= frequency;
 k=d;
 Serial.println(f);
 Serial.println(amplitude);
 delay(1000);
 Wire.beginTransmission(7);
 Wire.write(f);        
 Wire.write(y);
 Wire.write(x);
 Wire.write(k);
 Wire.endTransmission(); 
}

