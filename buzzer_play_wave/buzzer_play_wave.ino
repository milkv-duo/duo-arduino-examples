 /* 用蜂鸣器演奏音符。
    Play notes with the Buzzer.

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

#define BUZZER_PIN 4

// C 大调 1-7; C Major 1-7
const unsigned note[]={32,65,130,261,523,1046,2093};

const unsigned heigh[]={0,532,587,659,698,783,880,987};
const unsigned wave[]={1,2,3,1,1,2,3,1,3,4,5,3,4,5,5,6,5,4,3,1,5,6,5,4,3,1,1,5,1,1,5,1};
const unsigned length[]={1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,2000,1000,1000,2000,750,250,750,250,1000,1000,750,250,750,250,1000,1000,1000,1000,2000,1000,1000,2000};
void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200);

  Serial.println("Start play C Major 1-7.");

  // 演奏 C 大调 1-7; Play C Major 1-7.
  for(unsigned int i = 0; i < 7; i++)
  {
    tone(BUZZER_PIN, note[i]);
    delay(1000);
    noTone(BUZZER_PIN);
    delay(100);
  }
  
  delay(2000);
}
void loop() {
  Serial.println("Start play wave.");

  // 演奏两只老虎; Playing "Two Tigers".
  for(unsigned int i = 0; i <= 31; i++)
  {
    Serial.printf("i=%d,wave[i]=%d,heigh[wave[i]]=%d,length[i]=%d\n\r",i,wave[i],heigh[wave[i]],length[i]);
    tone(BUZZER_PIN, heigh[wave[i]]);
    delay(length[i]/2);
    noTone(BUZZER_PIN);
  }
  Serial.println("Stop play wave.");
  delay(2000);
}