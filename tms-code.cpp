//Temprature Measurement System - Code
//Created by @alexoiik

const byte red = 11;
const byte green = 9;
const byte blue = 10;
const byte interruptPin = 2;
volatile byte state = LOW;
volatile byte RedState = 0;
volatile byte GreenState = 0;
volatile byte BlueState = 0;

void setup()
{
  pinMode(red, OUTPUT);      //red 11
  pinMode(green, OUTPUT);   //green 9
  pinMode(blue, OUTPUT);   //blue 10
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), push, RISING);
}

int lastMillis = 0;
int currentMillis = 0;
float voltage;
float temp;

void loop()
{
  analogWrite(red, RedState); 
  analogWrite(green, GreenState);  
  analogWrite(blue, BlueState);
  currentMillis = millis();
  if(currentMillis - lastMillis >= 2500) //RGB: 2.5 seconds
  {
    lastMillis = currentMillis;
    Temprature();
  }
}

void push()
{
  Temprature();
}

void Temprature()
{
  voltage = (analogRead(A3) * 5.0) / 1024;
  temp = (voltage - 0.5) * 100;
    
  if(temp > 25)
    {
      Serial.print("Temprature is: ");
      Serial.print(temp); Serial.println(" degrees C");
      //Κόκκινο(R=255,G=0,B=0)
      Serial.println("Led Color: red\n");
      RedState = 255;
      GreenState = 0;
      BlueState = 0;
    }
    else if(temp < 5)
    {
      Serial.print("Temprature is: ");
      Serial.print(temp); Serial.println(" degrees C");
      //Μπλε(R=0,G=0,B=255)
      Serial.println("Led Color: blue\n");
      RedState = 0;
      GreenState = 0;
      BlueState = 255;
    }
    else
    {
      Serial.print("Temprature is: ");
      Serial.print(temp); Serial.println(" degrees C");
      //Κίτρινο(R=255,G=255,B=0)
      Serial.println("Led Color: yellow\n");
      RedState = 255;
      GreenState = 255;
      BlueState = 0;
    }  
}
