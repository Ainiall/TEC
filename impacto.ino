const int pin=10;
int pinState=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, INPUT);
  Serial.println("Detector de impacto");
}

void loop() {
  pinState=digitalRead(pin);
  if(pinState==LOW){
    Serial.println("IMPACTO!");
  }
}
