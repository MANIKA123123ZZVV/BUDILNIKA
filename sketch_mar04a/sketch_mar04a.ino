#include <LiquidCrystal.h>


#include "Wire.h"
LiquidCrystal lcd(11,10,9,8,7,6);
 
#include "iarduino_RTC.h"
iarduino_RTC time (RTC_DS1302,1,3,2);  // DS1302
// iarduino_RTC time (RTC_DS1307);     // DS1307 i2C
// iarduino_RTC time (RTC_DS3231);     // DS3231 i2C

void setup() {
  Serial.begin(9600);    
  lcd.begin(16,2);
  time.begin();
  // 0  sec, 30 min, 18 hour, 2 date, january, 2022, wed
  time.settime(0, 30, 18, 2, 1, 22, 0);
}

void loop() {
  // выводим время 1 раз в секунду
  if (millis() % 1000 == 0) {
     Serial.println(time.gettime("d-m-Y, H:i:s, D"));

     lcd.setCursor(0,0);
     lcd.print(time.gettime("d M Y, D"));
     lcd.setCursor(4,1);
     lcd.print(time.gettime("H:i:s"));
  }
}
