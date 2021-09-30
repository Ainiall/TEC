const int pinIn1= 2; //motor derecho
const int pinIn2= 3;  //motor derecho
const int pinIn3= 4;   //motor izquierdo
const int pinIn4= 5;   //motor izquierdo

const int ENA= 9;  //habilita el motor derecho
const int ENB= 10; //habilita el motor izquierdo

int stateIn1=0;
int stateIn2=0;
int stateIn3=0;
int stateIn4=0;

const int PhotoSensorLeft =  6; // pin del Arduino conectado al sensor óptico Izquierdo
const int PhotoSensorRight = 7; // pin del Arduino conectado al sensor óptico Derecho

int stateSensorLeft=0;
int stateSensorRight=0;

const int BLANCO = 0;
const int NEGRO = 1;

void setup() {
  //envia info
  pinMode(pinIn1, OUTPUT);
  pinMode(pinIn2, OUTPUT);
  pinMode(pinIn3, OUTPUT);
  pinMode(pinIn3, OUTPUT); 
  //salida info
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT); 
  //ENVIA LA SEÑAL DE LA LUZ
  pinMode(PhotoSensorLeft, INPUT);
  pinMode(PhotoSensorRight, INPUT);
}

void loop() {
  stateIn1= digitalRead(pinIn1);
  stateIn2= digitalRead(pinIn2);
  stateIn3= digitalRead(pinIn3);
  stateIn4= digitalRead(pinIn4);

  stateSensorLeft= digitalRead(PhotoSensorLeft);
  stateSensorRight= digitalRead(PhotoSensorLeft);

 if(stateSensorLeft==NEGRO && stateSensorRight==NEGRO){ 
    adelante_vel(150);
 }
 else if(stateSensorLeft==NEGRO && stateSensorRight==BLANCO){
    giroIzquierda_vel(150);
 }
 else if (stateSensorLeft==BLANCO && stateSensorLeft==NEGRO){
    giroDerecha_vel(150);
 }
 else{
    giroDerechaAtras(150);
 }


/*
  adelante();
  delay(1000);
  atras();
  delay(1000);
  giroDerecha();
  delay(1000);
  giroIzquierda();
  delay(1000);
  parar();
  delay(1000);
  adelante_vel(200);
  delay(1000);
  atras_vel(200);
  delay(1000);
  parar(); 
  delay(4000); //para ver bien las fases
  */
}

void adelante(){
  digitalWrite(pinIn1, HIGH);
  digitalWrite(pinIn2, LOW);
  digitalWrite(pinIn3, HIGH);
  digitalWrite(pinIn4, LOW);
  analogWrite(ENA,128);
  analogWrite(ENB,128);
  
}
void atras(){
  digitalWrite(pinIn1, LOW);
  digitalWrite(pinIn2, HIGH);
  digitalWrite(pinIn3, LOW);
  digitalWrite(pinIn4, HIGH);
  analogWrite(ENA,128);
  analogWrite(ENB,128);
  
}
void giroDerecha(){
  digitalWrite(pinIn1, HIGH);
  digitalWrite(pinIn2, LOW);
  digitalWrite(pinIn3, LOW);
  digitalWrite(pinIn4, HIGH);
  analogWrite(ENA,128);
  analogWrite(ENB,128);
}
void giroDerecha_vel(int vel){
  digitalWrite(pinIn1, HIGH);
  digitalWrite(pinIn2, LOW);
  digitalWrite(pinIn3, LOW);
  digitalWrite(pinIn4, HIGH);
  analogWrite(ENA,vel);
  analogWrite(ENB,vel);
}
void giroDerechaAtras(int vel){
  digitalWrite(pinIn1, LOW);
  digitalWrite(pinIn2, HIGH);
  analogWrite(ENA,vel);
}
void giroIzquierda(){
  digitalWrite(pinIn1, LOW);
  digitalWrite(pinIn2, HIGH);
  digitalWrite(pinIn3, HIGH);
  digitalWrite(pinIn4, LOW);
  analogWrite(ENA,128);
  analogWrite(ENB,128);
}
void giroIzquierda_vel(int vel){
  digitalWrite(pinIn1, LOW);
  digitalWrite(pinIn2, HIGH);
  digitalWrite(pinIn3, HIGH);
  digitalWrite(pinIn4, LOW);
  analogWrite(ENA,vel);
  analogWrite(ENB,vel);
}
void parar(){
  digitalWrite(pinIn1, LOW);
  digitalWrite(pinIn2, LOW);
  digitalWrite(pinIn3, LOW);
  digitalWrite(pinIn4, LOW);
}
void adelante_vel(int vel){
  digitalWrite(pinIn1, HIGH);
  digitalWrite(pinIn2, LOW);
  digitalWrite(pinIn3, HIGH);
  digitalWrite(pinIn4, LOW);
  analogWrite(ENA,vel);
  analogWrite(ENB,vel);
}
void atras_vel(int vel){
  digitalWrite(pinIn1, LOW);
  digitalWrite(pinIn2, HIGH);
  digitalWrite(pinIn3, LOW);
  digitalWrite(pinIn4, HIGH);
  analogWrite(ENA,vel);
  analogWrite(ENB,vel);
}
