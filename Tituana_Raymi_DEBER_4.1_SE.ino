#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,5,4,3,2);
LiquidCrystal lcd1(9,8,7,6,1,0);
int conversor;
int conversor1;

float voltaje; // variable de conversion a voltaje
int dutty; // variable para el uso de pwm
float voltaje1; // variable de conversion a voltaje
int dutty1; // variable para el uso de pwm

void setup() {
  lcd.begin(16,2);
  lcd1.begin(16,2);
}

void loop() {
  
conversor=analogRead(A0);

conversor1=analogRead(A1);

voltaje1=(conversor1*0.5)/1023.0;
dutty1=conversor1/4;

voltaje=(conversor*0.5)/1023.0;
dutty=conversor/4;


analogWrite(11,dutty);
analogWrite(10,dutty1);
lcd.setCursor(0,0);
lcd1.setCursor(0,0);
lcd.print("CAD");
lcd1.print("CAD");
lcd.setCursor(5,0);
lcd1.setCursor(5,0);
lcd.print(conversor);
lcd1.print(conversor1);
lcd.setCursor(0,1);
lcd1.setCursor(0,1);
lcd.print("V: ");
lcd1.print("V: ");
lcd.setCursor(3,1);
lcd1.setCursor(3,1);
lcd.print(voltaje);
lcd1.print(voltaje1);
lcd.setCursor(9,1);
lcd1.setCursor(9,1);
lcd.print("PWM: ");
lcd1.print("PWM: ");
lcd.setCursor(13,1);
lcd1.setCursor(13,1);
lcd.print(dutty*100/255);
lcd1.print(dutty1*100/255);
delay(300);
lcd.clear();
lcd1.clear();


}
