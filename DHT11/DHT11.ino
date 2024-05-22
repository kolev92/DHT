#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();
}

void loop() {
  delay(1000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print("Влажност: ");
  Serial.print(h);
  Serial.println("%");
  
  Serial.print("Температура: ");
  Serial.print(t);
  Serial.println("Celsius");

  Serial.print("Температура: ");
  Serial.print(f);
  Serial.println("Farenhait");
}
