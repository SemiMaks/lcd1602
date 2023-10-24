#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// порты для подключения модуля ULN2003 к Arduino
#define in1 8
#define in2 9
#define in3 10
#define in4 11

LiquidCrystal_I2C lcd(0x27,16,2);
int piezo = 3;
int counter = 0;


int dl = 5; // время задержки между импульсами

void setup() {
    lcd.init();
    lcd.backlight();    
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    lcd.print("Test motora:");
    lcd.setCursor(0,1);
    lcd.print("Zapusk cikla");
    delay(500);    
    tone(piezo, 1000, 200);
    delay(1500);
    lcd.clear();
    lcd.print("_1000 chagov_");
}

void loop() {      
    while (counter<1000){
      
      digitalWrite(in1, HIGH); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, HIGH);
      delay(dl);

      digitalWrite(in1, HIGH); 
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, LOW);
      delay(dl);

      digitalWrite(in1, LOW); 
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);
      delay(dl);

      digitalWrite(in1, LOW); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, HIGH);
      delay(dl);
      counter++;
    }
    while (counter==1000){
      lcd.clear();
      lcd.print("1000 -- OK!");
      delay(1000);
      lcd.clear();
      lcd.print("END");
      delay(1000);
      lcd.clear();
      lcd.print("BY");
      delay(2000);
      lcd.clear();
      lcd.noBacklight();
      counter+=1;
    }
    

}
