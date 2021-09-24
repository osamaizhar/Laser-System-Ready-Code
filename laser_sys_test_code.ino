
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int potPin = A0;       // Analog pin 0 for the LED brightness potentiometer
//int ledPin = 6;        // LED Digital Pin with PWM
int potValue = 0;      // variable to store the value coming from the potentiometer
int brightness = 0;    // converts the potValue into a brightness 
int pBari = 0;         // progress bar
int i = 0;             // foor loop
int count = 0;
int detect = A1;
//int buzzer  = 8;
int ledPin = 8;
int button = 7;
int object1 ;
int object2 ;
int object3 ;
int object4 ;
void setup() {
 
 lcd.begin(16, 2);
 Serial.println("Start Counter");
 lcd.setCursor(0, 0);
 lcd.print(" Start Counter");
 delay(500);
}

void loop() {
 
  lcd.clear();
  Serial.begin(9600);
  //lcd.setCursor(0, 0);
  //lcd.print("Hello Hackster");
  //lcd.setCursor(0, 1);
  //lcd.print("Value : ");
  //lcd.setCursor(10, 1);
  //lcd.print(analogRead(A0));
  //Serial.println(analogRead(A0));
  //delay(500);
  // clears the LCD screen
  
  // Print a message to the LCD
  
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("count:");
  lcd.print(count);
  delay(500);
  //lcd.clear();
  //set the cursor to line number 2
    back:
    int object = analogRead(detect);
    int b=digitalRead(button);
    object1 = object;
    object2 = object1;
    int back;


   if ( (object2>100) && (object3>100) && (object4>100)){
    //count = 00000;
    lcd.setCursor(0, 0);
    Serial.println("Object static");
    lcd.print("Object static");
    //lcd.setCursor(0, 1);
    //lcd.print("count:");
    //lcd.print(count);
    delay(500);
    //lcd.clear();
    Serial.print("Current Counter:" );
    Serial.println(count);
    //delay(1000);
    goto back;
    
   }

    if (object >= 100){
      objectisthere();
    }
    if (count == 3){
      Serial.println("Counter Reset");
      lcd.setCursor(0, 0);
      lcd.print("Counter Reset");
      delay(500);
      count = 0;
      Serial.println("-------------------");
      //Serial.println("");
      Serial.println("Start the new counting");
      Serial.print("Counter:");
      Serial.println(count);
    }
    object3 = object2;
    object4 = object3;
    //delay(100);
        
}
void objectisthere()
{
  digitalWrite(ledPin,HIGH);
  //tone(buzzer,5600,300);
  count = count + 1;
  Serial.print("Counter:");
  Serial.println(count);
  delay(400);
  digitalWrite(ledPin,LOW);
  
}
