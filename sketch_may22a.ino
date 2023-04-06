#include <LiquidCrystal.h>
#define gas_pin 7
const int rs=13,en=12,d4 = 11, d5 = 10 ,d6 = 9, d7 = 8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int  gas_value;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
gas_value = digitalRead(gas_Pin);
if(gas_value==1)
{
  digitalWrite(6,HIGH);
  lcd.setcursor (0,1);
  lcd.print("alcohol detected");
  lcd.display();
}
else
{
  digitalWrite(6,LOW);
  lcd.setcursor(0,1);
  lcd.print("no alcohol finded");
  lcd.display();
}
delay(1000);
lcd.clear();
}
