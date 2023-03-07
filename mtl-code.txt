//Modern Traffic Light System - Code
//Created by @alexoiik

const byte interruptPin = 2;
volatile byte Led1State = 0;
volatile byte Led2State = 1;
volatile byte Led3State = 0;

void setup()
{
  pinMode(13, OUTPUT);   
  pinMode(8, OUTPUT);   
  pinMode(12, OUTPUT); 
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), changeTime, RISING);
}

int lastMillis1 = 0;
int currentMillis1 = 0;
int time1 = 15000; //15000msec = 15sec waiting time.

void loop()
{ 
  digitalWrite(13, Led1State);   //Red Traffic Light.
  digitalWrite(8, Led2State);   //Green Traffic Light.	
  digitalWrite(12, Led3State); //Orange Traffic Light. 
  currentMillis1 = millis();

  if(currentMillis1 - lastMillis1 >= time1) 
  {
    lastMillis1 = currentMillis1; 
    
    //If Green=High 
    if(digitalRead(8)) {
      Led1State = 0;   //Red=Low
      Led2State = 0;  //Green=Low
      Led3State = 1; //Orange=High <-
    }
    //If Orange=High 
    if(digitalRead(12)) {
      Led1State = 1;   //Red=High <-
      Led2State = 0;  //Green=Low
      Led3State = 0; //Orange=Low
       
    }
    //If Red=High 
    if(digitalRead(13)) {
      Led1State = 0;   //Red=Low 
      Led2State = 1;  //Green=High <-
      Led3State = 0; //Orange=Low
       
    }
  }
}

void changeTime() {
  //If Green=High
  if(digitalRead(8))  
  {
    delay(400);
    Led1State = 0;   //Red=Low
    Led2State = 0;  //Green=Low
    Led3State = 1; //Orange=High <-
  }
}
