#define on LOW
#define off HIGH
const byte sensor = 3;
const byte led = 1;
byte sensorStatus, ledStatus;
void sensorCalibrationDelay(int _delay)
{
  Serial.print("Calibrating Sensor: ");
  for (int i = 0; i < _delay; i++)
  {
    Serial.print(".");
    delay(1000);
  }
}
void setup()
{

  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  digitalWrite(led, off);
  sensorCalibrationDelay(5);
}

void loop()
{
  sensorStatus = digitalRead(sensor);
  if (sensorStatus == HIGH)
  {
    digitalWrite(led, on);
  }
  if (sensorStatus == LOW)
  {
    digitalWrite(led, off);
  }
}
