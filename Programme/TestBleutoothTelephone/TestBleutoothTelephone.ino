#include <Wire.h>
#include "BluetoothSerial.h" //Bibliothèque pour utiliser le Bluetooth
#include <driver/gpio.h>


BluetoothSerial Operation_Bluetooth; // objet pour nos opérations liées à Bluetooth

int incoming;
unsigned long delayTime;

void setup() {
    Serial.begin(9600);
    Operation_Bluetooth.begin("Serre Connectée"); //Nom du signal Bluetooth
  
    bool status;
    
    delayTime = 1000;

    Serial.println();    
}


void loop() { 

 delay(delayTime);

Operation_Bluetooth.println("test");

if (Operation_Bluetooth.available()) //Check if we receive anything from Bluetooth
  {
    incoming = Operation_Bluetooth.read(); //Read what we recevive 
    Serial.print("Received:"); Serial.println(incoming);

    if (incoming == '1')
        {
        Serial.println("LED turned ON");
        Operation_Bluetooth.println("LED turned ON");
        }
        
    if (incoming == '0')
        {
        Serial.println("LED turned OFF");
        Operation_Bluetooth.println("LED turned OFF");
        }      
  }
}
