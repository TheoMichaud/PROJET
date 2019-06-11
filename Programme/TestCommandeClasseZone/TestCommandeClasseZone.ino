#include "zone.h"
#include <Wire.h>
#include "BluetoothSerial.h" //Bibliothèque pour utiliser le Bluetooth
#include <driver/gpio.h>

//#include <string.h>

BluetoothSerial Operation_Bluetooth; // objet pour nos opérations liées à Bluetooth

String incoming;
unsigned long delayTime;                                                                                ////////////////////////////////////<---
char commande;
char numZone;
Zone *zones[4];    //attribut controleur de serre

char carlu;

void setup() {
    Serial.begin(9600);
    Operation_Bluetooth.begin("Serre Connectée"); //Nom du signal Bluetooth
  
    //bool status;
    
    delayTime = 1000;

    Serial.println();  

   incoming = "";

   zones[0]=new Zone(1,GPIO_NUM_4);
   zones[1]=new Zone(2,GPIO_NUM_4);
   zones[2]=new Zone(3,GPIO_NUM_4);
   zones[3]=new Zone(4,GPIO_NUM_4);
}


void loop() { 

 delay(delayTime);

Operation_Bluetooth.println("test");

while (Operation_Bluetooth.available() )                                                  //Check if we receive anything from Bluetooth
  {
   carlu = Operation_Bluetooth.read();
   incoming += carlu;
     
  }

  if(incoming.compareTo("") != 0)
  {
    Serial.print("Received:"); Serial.println(incoming);
    commande = incoming.charAt(0);
   switch (commande)
   {
      case 'z':
        numZone = incoming.charAt(1) ;
        Serial.print("Zone ");
        Serial.print(numZone);
        Serial.print(" -> ");
        Serial.println(numZone - '1');
        zones[(int)(numZone - '1')]->Controler(incoming.substring(2));
        break;
      default:
      break;  
   }
   
  incoming = "";
  }
}
   
