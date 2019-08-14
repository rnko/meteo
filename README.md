# Meteo

Simple autonomous Arduino project.

# Parts: 
 - Arduino nano
 - LCD display 1602 with I2C
 - DHT11 Module
 - TTP223 sensor button
 - 0,9-5v to 5v DC-DC Step-Up
 - 18650 (or all other battery)
 - TP4056 USB 5V 1A for 18650 battery

# Scheme

![Image of scheme](./info/scheme.png)

# Functionality

DHT11 Module sending the data to Arduino module. 
Arduino parst this data and sending to LCD display. 
After 55 loops the sckreen turning off back light and after 60 loops it turnes off the screen. 
By pressing sensor button the display turnes on and Arduino counts the loops again.
The battery is powering the Arduino. But 4.2 v from battery is not enought for Arduino and screen and DC-DC Step-Up module is increasing voltage to stable 5v.
