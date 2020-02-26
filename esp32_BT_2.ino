#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
int led=2;
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  SerialBT.begin("ESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}
int i=0;
void loop() {

 char x=' ';
 
  if (SerialBT.available()) {
    x=SerialBT.read();
    Serial.println(x);
    if(x=='A')
    {
      if(i==0)
      {
      digitalWrite(led, HIGH);
      i=1;
      }
      else if(i==1)
      {
        digitalWrite(led, LOW);
      i=0;
        }
        
      }
      
  }
  delay(20);
}
