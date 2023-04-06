#include <LiquidCrystal.h>
const int rs=13,en=12,d4 = 11, d5 = 10 ,d6 = 9, d7 = 8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
#include <VirtualWire.h>
#define gas_Pin 7
int  gas_value;
void setup()
{
vw_set_ptt_inverted(true); // Required for DR3100
vw_set_rx_pin(12);
vw_setup(4000); // Bits per sec
Serial.begin(9600);
pinMode(3, OUTPUT);
vw_rx_start(); // Start the receiver PLL running
}

void loop()
{
  gas_value = digitalRead(gas_Pin);
if(gas_value==1)
{
  digitalWrite(6,HIGH);
  lcd.setCursor (0,1);
  lcd.print("alcohol detected");
  lcd.display();
}
else
{
  digitalWrite(6,LOW);
  lcd.setCursor(0,1);
  lcd.print("no alcohol finded");
  lcd.display();
}
delay(1000);
lcd.clear();
uint8_t buf[11];
uint8_t buflen = sizeof(buf);
   Serial.println();


if (vw_get_message(buf, &buflen)) // Non-blocking

{
if(buf == "alcohol detected")
{

digitalWrite(3,HIGH);

} 
else 
{

digitalWrite(3,LOW);

}
}

}
