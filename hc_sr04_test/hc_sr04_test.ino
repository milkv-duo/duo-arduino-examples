/* SR04超声波测距传感器的示例代码。
    Sample code for SR04 ultrasonic ranging sensor.

    注意：确保设备在3.3伏而不是5伏的电压下使用。Duo GPIO不能在5伏电平下使用。
    NOTE: Ensure the device is capable of being driven at 3.3v NOT 5v. The Duo
    GPIO cannot be used at 5v.

    如果你想在5伏的电压下使用该模块，需要额外加装电平转换器转换电平。
    You will need to use a level shifter on the lines if you want to run the
    board at 5v.

    请按下面的注释接线。
    Please wire according to the notes below.

    1 -> trig Pin on SR04 Moudle
    2 -> echo Pin on SR04 Moudle
    3.3v -> VCC on SR04 Moudle
    GND -> GND on SR04 Moudle
 */

const int trigPin = 1;
const int echoPin = 2;
volatile byte state = HIGH;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
