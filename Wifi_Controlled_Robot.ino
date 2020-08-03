//#define BLYNK_PRINT SwSerial //For debugging purposes

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
    
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon)
char auth[] = "3578a03b4f1d4ca9a124b8948d3c45c8"; 

#define m11 D0 // motor pins 
#define m12 D1
#define m21 D2
#define m22 D3

void forward()
{
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);
}
void backward()        
{
  digitalWrite(m11,LOW);
  digitalWrite(m12,HIGH);
  digitalWrite(m21,LOW);
  digitalWrite(m22,HIGH);
}
void right()
{
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);
  digitalWrite(m21,LOW);
  digitalWrite(m22,HIGH);
}
void left()
{
  digitalWrite(m11,LOW);
  digitalWrite(m12,HIGH);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);
}
void Stop()
{
  digitalWrite(m11,LOW);
  digitalWrite(m12,LOW);
  digitalWrite(m21,LOW);
  digitalWrite(m22,LOW);
}

BLYNK_WRITE(V1) 
{
int x=param[0].asInt();  // Read x coordinate of joystick
int y=param[1].asInt();  // Read y coordinate of joystick
 if(y>220)        // Joystick is pushed forward 
   forward();  
 else if(y<35)    // Joystick is pushed backward
   backward();
 else if(x>220)   // Joystick is pushed left
   right();
 else if(x<35)    // Joystick is pushed right
   left();
 else
   Stop();
}

void setup()
{
  Serial.begin(9600);
  pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  pinMode(m21,OUTPUT);
  pinMode(m22,OUTPUT);
  Blynk.begin(Serial, auth); // Connect Blynk
}

void loop()
{
  Blynk.run();
}
