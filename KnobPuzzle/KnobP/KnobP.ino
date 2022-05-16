//Setting the initial read value to 0
int knob1 =0;
int knob2 =0;
int knob3 =0;

void setup()
{
    //Setting up the potentio meters
    //Initialize serial communication at 9600 bits per second
    Serial.begin(9600);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A3, INPUT);
    pinMode(7, OUTPUT);
}
void loop()
{
    //Reading the vlaues fromt the potentio meter
    knob1 = analogRead(A0);
    knob2 = analogRead(A1)/10;
    knob3 = analogRead(A2)/100;

    int total = knob1+knob2+knob3;
    Serial.println(total);
    //Checking the vlauesof the knobs equals to provided
    if(total==100){
    digitalWrite(7, HIGH);
    }
    else{
    digitalWrite(7, LOW);
    }
    delay(100);
    //Delay in between reads for stability
}
