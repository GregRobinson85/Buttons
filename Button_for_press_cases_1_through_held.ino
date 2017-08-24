//this code works for determining how many times a button has been pressed or if it is held and when it is released. connect switch to input and ground//
#include<ButtonV2.h>

ButtonV2 Button1;
ButtonV2 Button2;
ButtonV2 Button3;
ButtonV2 Button4;
ButtonV2 Button5;

const byte tempUp = 11;
const byte tempDown = 10;
const byte M1 = 7;
const byte M2 = 8;
const byte M3 = 9;

int target = 20;
int Mem1 = 0;
int Mem2 = 0;
int Mem3 = 0;
int Temp = 0;

//debugging

void setup()
{
  //pinMode(LEDpin, OUTPUT);
  pinMode(tempUp, INPUT_PULLUP);
  pinMode(tempDown, INPUT_PULLUP);
  pinMode(M1, INPUT_PULLUP);
  pinMode(M2, INPUT_PULLUP);
  pinMode(M3, INPUT_PULLUP);
  Serial.begin(9600);
  Button1.SetStateAndTime(LOW);
  Button2.SetStateAndTime(LOW);
  Button3.SetStateAndTime(LOW);
  Button4.SetStateAndTime(LOW);
  Button5.SetStateAndTime(LOW);
  
  Serial.println("Button_for_press_cases");
  Serial.println("ready");
}

void loop()

{
  
  Temp = target;
  
  
  byte type = Button1.CheckButton(tempUp); // current time and length of time to press the button as many times as you can ie. 1.5 seconds
  switch (type)
   
  {
    case WAITING:
      break;
    case PRESSED:
      Serial.println("pressed 1 time");
      target=target+1;
      break;
    case DOUBLE_PRESSED:
      Serial.println("pressed 2 times");
      target=target+2;
      break;
    case MULTI_PRESSED:
      Serial.println("pressed 3 times");
      target=target+3;
      break;
    case HELD:
      target=target+1;
      break;
  delay(100);
     
  }
  
byte type2 = Button2.CheckButton(tempDown);
switch (type2)

  {
    case WAITING:
      break;
    case PRESSED:
      Serial.println("pressed 1 time");
      target=target-1;
      break;
    case DOUBLE_PRESSED:
      Serial.println("pressed 2 times");
      target=target-2;
      break;
    case MULTI_PRESSED:
      Serial.println("pressed 3 times");
      target=target-3;
      break;
    case HELD:
      target=target-1;
      break;
      delay(100);
     
  }
    byte type3 = Button3.CheckButton(M1); // current time and length of time to press the button as many times as you can ie. 1.5 seconds
  switch (type3)
   
  {
    case WAITING:
      break;
    case PRESSED:
      Serial.println("pressed 1 time");
      target = Mem1;
      break;
    case DOUBLE_PRESSED:
      Serial.println("pressed 2 times, so what?");
      break;
    case MULTI_PRESSED:
      Serial.println("pressed 3 times, so what?");
      break;
    case HELD:
      Mem1 = Temp;
      Serial.print("Mem 1 reset to: ");
      Serial.println(Mem1);
      break;
     
  }
     byte type4 = Button4.CheckButton(M2); // current time and length of time to press the button as many times as you can ie. 1.5 seconds
  switch (type4)
   
  {
    case WAITING:
      break;
    case PRESSED:
      Serial.println("pressed 1 time");
      target = Mem2;
      break;
    case DOUBLE_PRESSED:
      Serial.println("pressed 2 times, so what?");
      break;
    case MULTI_PRESSED:
      Serial.println("pressed 3 times, so what?");
      break;
    case HELD:
      Mem2 = Temp;
      Serial.print("Mem 2 reset to: ");
      Serial.println(Mem2);
      break;
     
  }
  
     byte type5 = Button5.CheckButton(M3); // current time and length of time to press the button as many times as you can ie. 1.5 seconds
  switch (type5)
   
  {
    case WAITING:
      break;
    case PRESSED:
      Serial.println("pressed 1 time");
      target = Mem3;
      break;
    case DOUBLE_PRESSED:
      Serial.println("pressed 2 times, so what?");
      break;
    case MULTI_PRESSED:
      Serial.println("pressed 3 times, so what?");
      break;
    case HELD:
      Mem3 = Temp;
      Serial.print("Mem 3 reset to: ");
      Serial.println(Mem3);
      break;
     
  }
  
   Serial.println(target);
 
}
