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

ArduinoToEsp32.ino contains the code that is uploaded to Arduino. It uses the 'DHT Sensor Library' to read data from DHT11 connected to pin 2 of Arduino. The data is written on to the serial port.

## Interfacing Arduino and ESP32

## Connecting ESP32 to WiFi

## Sending data to XAMPP database
To send data to XAMPP database, we use a php file. The XAMPP database is made visible as localhost on the WiFi to which the computer is connected. Since it is localhost, the ESP32 and the computer must connect to the same WiFi.

In Esp32toDatabase.ino, String URL can be found which contains the information about where the php file is located and of the localhost. The http request to send the data is made to the local host, this is done using the http.begin() function.

The php file receives the temperature and humidity from the http request. It connects to the database and performs an SQL query to enter the data. 
