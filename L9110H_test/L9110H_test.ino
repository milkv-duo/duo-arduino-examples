/* L9110H H桥电机驱动器的示例代码。
    Example code for the L9110H H-bridge motor driver.

    注意：确保设备在3.3伏而不是5伏的电压下使用。Duo GPIO不能在5伏电平下使用。
    NOTE: Ensure the device is capable of being driven at 3.3v NOT 5v. The Duo
    GPIO cannot be used at 5v.

    如果你想在5伏的电压下使用该模块，需要额外加装电平转换器转换电平。
    You will need to use a level shifter on the lines if you want to run the
    board at 5v.

    请按下面的注释接线。
    Please wire according to the notes below.

    4 -> INA Pin on L9110H Moudle
    5 -> INB Pin on L9110H Moudle
    3.3v -> VCC on L9110H Moudle
    GND -> GND on L9110H Moudle
 */

#define INA_PIN   4
#define INB_PIN   5

void setup() {
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  for(int i = 1;i < 255;i++)
  {
    digitalWrite(INB_PIN,LOW);
    analogWrite(INA_PIN,i);
    delay(20);
  }
  for(int i = 255;i > 1;i--)
  {
    digitalWrite(INB_PIN,LOW);
    analogWrite(INA_PIN,i);
    delay(20);
  }
  for(int i = 1;i < 255;i++)
  {
    digitalWrite(INA_PIN,LOW);
    analogWrite(INB_PIN,i);
    delay(20);
  }
  for(int i = 255;i > 1;i--)
  {
    digitalWrite(INA_PIN,LOW);
    analogWrite(INB_PIN,i);
    delay(20);
  }
}
