/***************************************************************************
  This is a library for the BME280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME280 Breakout
  ----> http://www.adafruit.com/products/2650

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface. The device's I2C address is either 0x76 or 0x77.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>

#include <driver/gpio.h>





unsigned long delayTime;

void setup() {
    Serial.begin(9600);
    
    bool status;
    
      
    Serial.println("-- Default Test --");
    delayTime = 250;

    

    gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);

    
}


void loop() { 
    printValues();

    gpio_set_level(GPIO_NUM_4, 1);
    Serial.println("LED : Allumée");
    
    delay(delayTime);

    gpio_set_level(GPIO_NUM_4, 0);
    Serial.println("LED : Eteinte");

    delay(delayTime);
    
}


void printValues() {
   /* 
    Serial.print("Led = ");
    if(gpio_set_level(GPIO_NUM_17, 1)){
       Serial.println(" %");
    }
   */

    Serial.println();
}
