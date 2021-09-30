//constantes

#include <math.h>
const int pin=A0;
double valor_digital=0.0; //estado del pin A0
double v0=0.0;
double Rtermistor=0.0;
double T=0.0;
double Tinverso=0.0;
double T0=298.0;
double R0=10000.0;
double B=3900.0;
double Binv=0.00025;

double a=0.0;

void setup() {
 Serial.begin(9600);

}

void loop() {
  valor_digital=analogRead(pin);
  v0= valor_digital*5/1023; //ans 4.55 ~
  Serial.println(v0);
  //Rtermistor=((5-v0)/v0)*R0; //ans -13414 ~
  //Rtermistor=(50000/v0)-10000;
  Rtermistor=(1023/valor_digital-1)*R0;
  Serial.println(Rtermistor);
  
  a=Binv*log(Rtermistor/R0);
  Tinverso=(1/T0)+a;
  
  T=(1/Tinverso);
  Serial.println(T); 
}
