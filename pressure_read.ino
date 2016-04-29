void pressure_read(){
  int pressureRead = averageAnalogRead(pressureSensorPin, 10);  //request a average of 10 pressure readings
  float pressure = mapfloat(pressureRead, 0, 1023, -7.0, 67.0); //Convert the pressureRead to a pressure value from -7 to 67
  sendPayload(deviceName,"pressureSensor","pressure","psi",readTime,String(pressure),"M");
}


//Takes an average of readings on a given pin
//Returns the average
int averageAnalogRead(int pinToRead, int numberOfReadings){
  unsigned int runningValue = 0; 
  for(int x = 0 ; x < numberOfReadings ; x++)
    runningValue += analogRead(pinToRead);
  runningValue /= numberOfReadings;
  return(runningValue);  
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
