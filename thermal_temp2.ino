#include "MLX90615.h"
#include <I2cMaster.h>

#define SDA_PIN 3   //define the SDA pin
#define SCL_PIN 2   //define the SCL pin

SoftI2cMaster i2c(SDA_PIN, SCL_PIN);
MLX90615 mlx90615(DEVICE_ADDR, &i2c);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
// set the LCD address to 0x27 for a 16 chars and 2 line display



void setup()
{
  Serial.begin(9600);
  Serial.println("Setup...");

  //mlx90615.writeEEPROM(Default_Emissivity); //write data into EEPROM when you need to adjust emissivity.
  //mlx90615.readEEPROM(); //read EEPROM data to check whether it's a default one.

lcd.init(); // initialize the lcd
// Print a message to the LCD.

lcd.backlight();


}

void loop()
{
  Serial.print("Object temperature: ");
  Serial.println(mlx90615.getTemperature(MLX90615_OBJECT_TEMPERATURE));
  Serial.print("Ambient temperature: ");
  Serial.println(mlx90615.getTemperature(MLX90615_AMBIENT_TEMPERATURE));

  lcd.setCursor(0, 0);
  lcd.print("B.TEMP:");
  lcd.setCursor(8, 0);
  lcd.print(mlx90615.getTemperature(MLX90615_AMBIENT_TEMPERATURE));


  
  lcd.setCursor(0, 1);
  lcd.print("O.TEMP:");
  lcd.setCursor(8, 1);
  lcd.print(mlx90615.getTemperature(MLX90615_OBJECT_TEMPERATURE));
  delay(3000);
}
