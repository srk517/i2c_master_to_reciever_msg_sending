//#include<SoftwareSerial.h>
//SoftwareSerial s(2,3);
#include <Wire.h>
String a;
int str_len=0;
void setup() {
  Serial.begin(9600);
  Wire.begin(); // join I2C bus (address optional for master)
}

void loop() {
  while (Serial.available()) {
 a=Serial.readString();
 str_len = a.length()+1;
 char arr[str_len];
 a.toCharArray(arr,str_len);

  Wire.beginTransmission(8); 
  Wire.write(arr,str_len);              
  Wire.endTransmission();    
  delay(500);
}
}
