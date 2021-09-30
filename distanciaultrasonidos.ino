
const int trigger=2;
const int echo=3;

int triggerState=0;

float distancia=0;
float t=0;


void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT); //trigger lee y envia
  pinMode(echo, INPUT); //echo recibe la señal
  Serial.println("Medicion de distancia con sensor de ulstrasonidos");
}

void loop() {
  triggerState=digitalRead(trigger);
  delay(1000);
  digitalWrite(trigger, HIGH); //trigger recibe señal 1 -> sube
  delayMicroseconds(10); //delay en microsegundos
  digitalWrite(trigger, LOW);  //trigger recibe señal 0 ->baja
  t=pulseIn(echo, HIGH); //tiempo transcurrido desde el envio de la señal hasta su recepcion
  distancia= t/2 *0.034; // distancia -> velocidad sonido *tiempo/2 ya que hace ida y vuelta
  if(digitalRead(echo)==LOW){
    Serial.println(distancia); //se imprime la distancia
  }
}
