//this code monitor a pressure sensor and publish data on MQTT using ESP8266 customized firmware
//sensors readings are send to ESP8266 as CSV values each 5 seconds

String deviceName = "PressureMonitor";
String readTime = "POSIX";

uint8_t payload[100]; //contains the Payload do be send
String stringPayload; //used to assemble CSV Payload

//Hardware pin definitions for pressure sensor
int pressureSensorPin = A1; //Arduino Analog pin where presure sensor is connected
int LedPin = 13 ; //led pin do indicate sensor reading activity

void setup() {  
  Serial.begin(9600);           //set baud rate for the hardware serial port_0 to 9600
  pinMode(LedPin,OUTPUT);
}

void loop() { //here we go...
  digitalWrite(LedPin,HIGH);
  pressure_read();  //request a pressure read
  digitalWrite(LedPin,LOW);
  delay(5000);  //wait 5 seconds until next read
}

