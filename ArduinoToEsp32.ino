//Measures the Temperature and Humidity with the help of a DHT11 sensor and sends it to Arduino 
//From Arduino the data is transferred to the ESP32 
#include<DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);



void setup() {
  Serial.begin(9600);

  dht.begin();

}

void loop() {
  int temperature=dht.readTemperature();
  int humidity=dht.readHumidity();

  

  Serial.print(temperature);
  Serial.print(" ");
  Serial.print(humidity);
  Serial.println();

  delay(1500);

}


