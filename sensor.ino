#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  float h=dht.readHumidity();
  float t= dht.readTemperature();
  float f = dht.readTemperature(true);

  float hif = dht.computeHeatIndex(f,h);
  float hic = dht.computeHeatIndex(t,h,false);

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" &\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Indice de calor: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
}
