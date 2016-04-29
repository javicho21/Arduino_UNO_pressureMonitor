void sendPayload(String deviceName, String sensorName, String sensorType, String sensorUnit, String readTime, String reading,String messageType){
  stringPayload = deviceName;
  stringPayload += ",";

  stringPayload += sensorName;
  stringPayload += ",";

  stringPayload += sensorType;
  stringPayload += ",";
  

  stringPayload += sensorUnit;
  stringPayload += ",";

  stringPayload += readTime;
  stringPayload += ",";

  stringPayload += reading;
  stringPayload += ",";

  stringPayload += messageType;
  stringPayload += ",\n";

  for (int i=0 ; i < 100 ; i++){  //clean the payload array
    payload[i]= 0x00;
  }
  
  for (int i=0 ; i < stringPayload.length() ; i++){   //fill payload with reading data
    payload[i]= stringPayload.charAt(i);
  }

Serial.print(stringPayload);  //send payload as CSV to ESP8266

  /* exemples of how data are send to ESP8266
  PressureMonitor,pressureSensor,pressure,psi,POSIX,27.30,M,/n
  */


}
