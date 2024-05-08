/* LCD2004 屏幕的示例代码。
    Sample code for LCD2004 screen.

    注意：确保设备在3.3伏而不是5伏的电压下使用。Duo GPIO不能在5伏电平下使用。
    NOTE: Ensure the device is capable of being driven at 3.3v NOT 5v. The Duo
    GPIO cannot be used at 5v.

    如果你想在5伏的电压下使用该模块，需要额外加装电平转换器转换电平。
    You will need to use a level shifter on the lines if you want to run the
    board at 5v.

    请按下面的注释接线。
    Please wire according to the notes below.
    
    如果你使用的是 Duo
    If you are using Duo:
      I2C0_SCL -> SCL Pin on LCD2004 Moudle
      I2C0_SDA -> SDA Pin on LCD2004 Moudle
      3.3v -> VCC on LCD2004 Moudle
      GND -> GND on LCD2004 Moudle

    如果你使用的是 Duo256M
    If you are using Duo256M:
      I2C1_SCL -> SCL Pin on LCD2004 Moudle
      I2C1_SDA -> SDA Pin on LCD2004 Moudle
      3.3v -> VCC on LCD2004 Moudle
      GND -> GND on LCD2004 Moudle
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.print("Hello MilkV Duo!");
  lcd.setCursor(0,1);
  lcd.print("Have a Nice Day!");
  lcd.setCursor(0,2);
  lcd.print("123456");
  lcd.setCursor(0,3);
  lcd.print("ABCDEFGHI");
}

void loop() {
  delay(1000);
}