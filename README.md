# IOT temperature and humidity datalogger 

In this project, we have used DHT11 sensor to read temperature and humidity and send it to a XAMPP database via an ESP32.

Hardware used:
- ESP32
- DHT11
- Arduino Uno R3

Communication Protocol:
- USART/UART

Software used:
- Arduino IDE
- XAMPP

## Reading the DHT11
To read from DHT11, Arduino UNO is used because the model of ESP32 used isn't compatible with the DHT11 model used.

ArduinoToEsp32.ino