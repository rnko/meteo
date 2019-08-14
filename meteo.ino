#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define BTNPIN 3
DHT dht(DHTPIN, DHT11);

LiquidCrystal_I2C lcd(0x27, 16, 2);

int loops = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin();
  lcd.backlight();
  pinMode(BTNPIN, INPUT);
}

void loop() {
  Serial.println(loops);
  
  delay(200); // 2 секунды задержки
  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 
  if (isnan(h) || isnan(t)) {  
    Serial.println("Sensor Error");
    return;
  }
  
  lcd.setCursor(0, 0);
  lcd.print("Temperat: ");
  lcd.setCursor(12, 0);
  lcd.print(t);
  
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.setCursor(12, 1);
  lcd.print(h);
  
  Serial.print("Влажность: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Температура: ");
  Serial.print(t);
  Serial.println(" *C "); //Вывод показателей на экран

  if (loops == 55) {
    lcd.noBacklight();
  }

  if (loops == 60) {
    lcd.noDisplay();
  }

  if (loops < 60) {
    loops++;
  }

  if (digitalRead(BTNPIN) == HIGH) {
    lcd.display();
    lcd.backlight();
    loops = 0;
  }
}
