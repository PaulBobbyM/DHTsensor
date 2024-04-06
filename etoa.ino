#include <WiFi.h> 
#include <HTTPClient.h> 

#define RXp2 16
#define TXp2 17

String URL = "http://172.20.10.13/dht_11/temp.php";

const char* ssid = "Yasir ansari"; 
const char* password = "youo1234"; 

int temperature = 50; 
int humidity = 50;

void setup() {
  Serial.begin(115200); 
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  connectWiFi();
}

void loop() {
  if(WiFi.status() != WL_CONNECTED) { 
    connectWiFi();
  }

  String readInput = Serial2.readString();

  int temperature__ = (readInput[0]-'0')*10 + (readInput[1]-'0');
  int humidity__ = (readInput[3]-'0')*10 + (readInput[4]-'0');

  // Serial.print(temperature__);
  // Serial.print("a");
  // Serial.print(humidity__);
  // Serial.println();

  String postData = "temperature=" + String(temperature__) + "&humidity=" + String(humidity__); 

  HTTPClient http; 
  http.begin(URL);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
  
  int httpCode = http.POST(postData); 
  String payload = http.getString(); 
  
  // String payload = "";

  if(httpCode > 0) {
    // file found at server
    if(httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  
  http.end();  //Close connection
  
  Serial.print("URL : "); Serial.println(URL); 
  Serial.print("Data: "); Serial.println(postData); 
  Serial.print("httpCode: "); Serial.println(httpCode); 
  Serial.print("payload : "); Serial.println(payload); 
  Serial.println("--------------------------------------------------");
}



void connectWiFi() {
  WiFi.mode(WIFI_OFF);
  // delay(250);
  //This line hides the viewing of ESP as wifi hotspot
  WiFi.mode(WIFI_STA);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    
  Serial.print("connected to : "); Serial.println(ssid);
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}