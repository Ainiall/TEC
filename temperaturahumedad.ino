#include <DHT.h>
#define DHT11_PIN 4
#define DHTTYPE DHT11

//comenzar comunicacion con DHT11
DHT dht_sensor(DHT11_PIN,DHTTYPE);

void setup() {
 Serial.begin(9600); 
  dht_sensor.begin();
  Serial.print("Medicion de temperatura y humedad:");
}

void loop() { 
  delay(2000); //delay 2s
 
  float temperatura=dht_sensor.readTemperature();
  float humedad=dht_sensor.readHumidity();


  Serial.println("TEMPERATURA ºC");
  Serial.println(temperatura); //mide temperatura
  Serial.println("HUMEDAD %");
  Serial.println(humedad);  //mide humedad
}
