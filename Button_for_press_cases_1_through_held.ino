//this code works for determining how many times a button has been pressed or if it is held and when it is released. connect switch to input and ground//
#include<ButtonV2.h>

ButtonV2 Button1;
ButtonV2 Button2;

const byte tempUp = A1;
const byte tempDown = A2;
int temp = 20;
int tempNow = 0;

void setup()
{
  //pinMode(LEDpin, OUTPUT);
  pinMode(tempUp, INPUT_PULLUP);
  pinMode(tempDown, INPUT_PULLUP);
  Serial.begin(9600);
  Button1.SetStateAndTime(LOW);
  Button2.SetStateAndTime(LOW);
  Serial.println("Button_for_press_cases");
  Serial.println("ready");
}

void loop()

{
  temp = tempNow;
  byte type = Button1.CheckButton(tempUp); // current time and length of time to press the button as many times as you can ie. 1.5 seconds
  switch (type)
   
  {
    case WAITING:
      break;
    case PRESSED:
      Serial.println("pressed 1 time");
      tempNow=temp+1;
      break;
    case DOUBLE_PRESSED:
      Serial.println("pressed 2 times");
      tempNow=temp+2;
      break;
    case MULTI_PRESSED:
      Serial.println("pressed 3 times");
      tempNow=temp+3;
      break;
    case HELD:
      Serial.println("Button HELD");
      temp=tempNow;
      break;
     
  }
  
byte type2 = Button2.CheckButton(tempDown);
switch (type2)

  {
    case WAITING:
      break;
    case PRESSED:
      Serial.println("pressed 1 time");
      tempNow=temp-1;
      break;
    case DOUBLE_PRESSED:
      Serial.println("pressed 2 times");
      tempNow=temp-2;
      break;
    case MULTI_PRESSED:
      Serial.println("pressed 3 times");
      tempNow=temp-3;
      break;
    case HELD:
      Serial.println("Button HELD");
      temp=tempNow;
      break;
     
  }
   Serial.println(tempNow);
}
