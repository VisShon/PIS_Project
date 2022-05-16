#define HALL_SEN_PIN 13
#define HALL_SEN_ANALOG_PIN A0
#define LED 2


void setup() {
  Serial.begin(9600);
  pinMode(HALL_SEN_PIN, INPUT);
  pinMode(LED, OUTPUT);
 
}

void loop() 
{
  Serial.print("Hall Value: ");
  Serial.println(analogRead(HALL_SEN_ANALOG_PIN));
  
  if(digitalRead(HALL_SEN_PIN) == 0)
  {
    Serial.println("Detect");
    digitalWrite(LED,HIGH);  
  }
  else
  {
    digitalWrite(LED,LOW);  
  }
}
