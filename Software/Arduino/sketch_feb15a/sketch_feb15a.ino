// C++ code
//

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 9, d5 = 8, d6 = 7, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// pushbutton pin
const int buttonPin1 = A5;
const int buttonPin2 = A4;
const int buttonPin3 = A3;
const int buttonPin4 = A2;

static bool used1, used2, used3, used4;
static int buttonState1, buttonState2, buttonState3, buttonState4; 

void setup()
{
  //pinMode(LED_BUILTIN, OUTPUT);
  // Set up the pushbutton pins to be an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

  used1 = false;
  used2 = false;
  used3 = false;
  used4 = false;
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, press a");
  lcd.setCursor(0,2);
  lcd.print("button to start\n");

  Serial.begin(9600);
}

void loop()
{
  // local variable to hold the pushbutton states
  buttonState1 = analogRead(A5);
  delay(15);
  buttonState1 = analogRead(A5);
  delay(30);
  buttonState2 = analogRead(A4);
  delay(15);
  buttonState2 = analogRead(A4);
  delay(30);
  buttonState3 = analogRead(A3);
  delay(15);
  buttonState3 = analogRead(A3);
  delay(30);
  buttonState4 = analogRead(A2);
  delay(15);
  buttonState4 = analogRead(A2);
  delay(30);

  if (buttonState1 > 300 && !used1) {
    used1 = true;
    Serial.print("R");
    //Serial.println(buttonState1 * 5.0 / 1024.0);
    delay(50);
  }
  else if (buttonState1 < 50) {
    used1 = false;
    delay(10);
  }
  if (buttonState2 > 300 && !used2) {
    used2 = true;
    Serial.print("U");
    //Serial.println(buttonState2 * 5.0 / 1024.0);
    delay(50);
  } 
  else if (buttonState2 < 50) {
    used2 = false;
    delay(10);
  }
  if (buttonState3 > 300 && !used3) {
    used3 = true;
    Serial.print("L");
    //Serial.println(buttonState3 * 5.0 / 1024.0);
    delay(50);
  } 
  else if (buttonState3 < 50) {
    used3 = false;
    delay(10);
  }
  if (buttonState4 > 300 && !used4) {
    used4 = true;
    Serial.print("D");
    //Serial.println(buttonState4 * 5.0 / 1024.0);
    delay(50);
  } 
  else if (buttonState4 < 50) {
    used4 = false;
    delay(10);
  }
}
