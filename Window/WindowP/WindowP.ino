
const int ldrPin = A0;
const int ledPin = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
void loop()
{
  int ldrStatus = analogRead(ldrPin);
  
  if (ldrStatus <= 400) {
    digitalWrite(ledPin, HIGH);
    Serial.println("It is dark");
  } else {
  
    digitalWrite(ledPin, LOW);
    Serial.println("It is bright");
  }
}
