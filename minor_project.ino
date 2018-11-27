#include<LiquidCrystal.h>

String voice;
int
led1 = 7, //Connect LED 1 To Pin #7
led2 = 8, //Connect LED 2 To Pin #8
led3 = 9, //Connect LED 3 To Pin #9
led4 = 10; //Connect LED 4 To Pin #10

void turn_on()
{
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
}
void turn_off()
{
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
}

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16,2);
  analogWrite(6,15);
  
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  lcd.print("Password Please");
}

void loop() 
{
  // Print a message to the LCD.
   
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  if (voice.length() > 0) {
    Serial.println(voice);
    lcd.setCursor(0, 1);
//-----------------------------------------------------------------------//   
  //----------Control Multiple Pins/ LEDs----------// 
       if(voice == "*turn on") 
       {
        turn_on();
        lcd.clear();
        lcd.print("Accepted");
       }  //Turn On All Pins (Call Function)
  else if(voice == "*turn off"){turn_off(); lcd.clear();lcd.print("Accepted");} //Turn Off  All Pins (Call Function)
 
  //----------Turn On One-By-One----------//
  else if(voice == "*TV on") {digitalWrite(led1, HIGH);lcd.clear();lcd.print("Accepted");}
  else if(voice == "*fan on") {digitalWrite(led2, HIGH);lcd.clear();lcd.print("Accepted");}
  else if(voice == "*computer on") {digitalWrite(led3, HIGH);lcd.clear();lcd.print("Accepted");}
  else if(voice == "*bedroom lights on") {digitalWrite(led4, HIGH);lcd.clear();lcd.print("Accepted");}
  //----------Turn Off One-By-One----------//
  else if(voice == "*TV off") {digitalWrite(led1, LOW);lcd.clear();lcd.print("Accepted");}
  else if(voice == "*fan off") {digitalWrite(led2, LOW);lcd.clear();lcd.print("Accepted");}
  else if(voice == "*computer off") {digitalWrite(led3, LOW);lcd.clear();lcd.print("Accepted");}
  else if(voice == "*bedroom lights off") {digitalWrite(led4, LOW);lcd.clear();lcd.print("Accepted");}
//-----------------------------------------------------------------------// 
voice="";}
}
 
