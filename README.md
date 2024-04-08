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
The data that is collected by the Arduino is then sent to the ESP32. The communication protocol used between the Arduino and ESP32 is USART/UART.

UART(Universal Asynchronous Receiver/Transmitter) is a commonly used serial communication protocol in embedded systems and computer peripherals. It facilitates asynchronous communication between devices by transmitting data serially, one bit at a time, over a single wire or pair of wires.

## Connecting ESP32 to WiFi
The ESP32 connects to the WiFi using the WiFi module present on the ESP32 itself.

The ESP32's WiFi module connects to wireless networks, communicates with devices, and transfers data. It initializes, scans for networks, and connects securely using credentials. Once connected, it sends and receives data packets over the network. It can also function as an access point, creating its own network. Security features like encryption are supported. Power-saving mechanisms optimize energy consumption for battery-operated devices. Overall, it enables seamless wireless communication in IoT and embedded applications.

## Sending data to XAMPP database
To send data to XAMPP database, we use a php file. The XAMPP database is made visible as localhost on the WiFi to which the computer is connected. Since it is localhost, the ESP32 and the computer must connect to the same WiFi.

In Esp32toDatabase.ino, String URL can be found which contains the information about where the php file is located and of the localhost. The http request to send the data is made to the local host, this is done using the http.begin() function.

The php file receives the temperature and humidity from the http request. It connects to the database and performs an SQL query to enter the data. 
