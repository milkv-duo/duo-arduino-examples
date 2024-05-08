 /* 蜂鸣器的示例代码。
    Example code to Buzzer.

    注意：确保设备在3.3伏而不是5伏的电压下使用。Duo GPIO不能在5伏电平下使用。
    NOTE: Ensure the device is capable of being driven at 3.3v NOT 5v. The Duo
    GPIO cannot be used at 5v.

    如果你想在5伏的电压下使用该模块，需要额外加装电平转换器转换电平。
    You will need to use a level shifter on the lines if you want to run the
    board at 5v.

    请按下面的注释接线。
    Please wire according to the notes below.

    4 -> S Pin on Buzzer Moudle
    3.3v -> VCC on Buzzer Moudle
    GND -> GND on Buzzer Moudle
 */

#define BUZZER_PIN    4

void setup() {
  pinMode(BUZZER_PIN,OUTPUT);
}

void loop() {
  analogWriteResolution(9);    //周期512us，2KHz Period 512us, 2KHz
  analogWrite(BUZZER_PIN,200);
  delay(500);

  analogWriteResolution(10);    //周期1024us，1KHz Period 1024us, 1KHz
  analogWrite(BUZZER_PIN,400);
  delay(500);

  analogWriteResolution(11);    //周期2048us，500KHz Period 2048us, 500KHz
  analogWrite(BUZZER_PIN,800);
  delay(500);

}
