int rele=2;
void setup() {
 Serial.begin(9600);
 pinMode(rele, OUTPUT);
}

void loop() {
  digitalWrite(rele,LOW);
float value= analogRead(A0);
float relevalue = digitalRead(rele);

float voltage = value*(5.0/1023.0);

float rLDR= ((5.0*10000.0)/voltage)-10000.0;

if(rLDR < 10000.0){
  digitalWrite(rele, HIGH);
}if (rLDR >30000.0){
  digitalWrite(rele,LOW);
}
  
Serial.println(rLDR);

}
