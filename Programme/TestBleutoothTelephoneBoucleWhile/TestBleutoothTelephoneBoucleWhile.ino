#include <Wire.h>
#include "BluetoothSerial.h" //Bibliothèque pour utiliser le Bluetooth
#include <driver/gpio.h>

#include <string.h>

BluetoothSerial Operation_Bluetooth; // objet pour nos opérations liées à Bluetooth

String incoming;
String incoming2;
String incoming3;
unsigned long delayTime;
char commande;
char numZone;

char carlu;

void setup() {
    Serial.begin(9600);
    Operation_Bluetooth.begin("Serre Connectée"); //Nom du signal Bluetooth
  
    bool status;
    
    delayTime = 1000;

    Serial.println();  

   incoming = "";
}


void loop() { 

 delay(delayTime);

Operation_Bluetooth.println("test");

while (Operation_Bluetooth.available() )                                                  //Check if we receive anything from Bluetooth
  {
   carlu = Operation_Bluetooth.read();
   incoming += carlu;
     
  }
  
Serial.print("Received:"); Serial.println(incoming);




  /*
   incoming = incoming.substring(0, 2);
   chaine = incoming;
  
  // chaine+=incoming;

   Serial.print("Received:"); Serial.println((String)chaine);

    
   */

   commande = incoming.charAt(0);
   switch (commande)
   {
      case 'z':
        numZone = incoming.charAt(1) ;
        Serial.print("Zone ");
        Serial.print(numZone);
        Serial.print(" -> ");
        Serial.println(numZone - '1');
        break;
      default:
      break;  
   }
   /*
   incoming2 = incoming.substring(0, 2);
   incoming3 = incoming.substring(2, 3);
   
    if ((incoming2.compareTo("z1"))==0)
        {
        Serial.println("Ouvrir zone 1");
        Operation_Bluetooth.println("Ouvrir zone 1");
        
        }

    if ((incoming2.compareTo("z2"))==0)
        {
        Serial.println("Ouvrir zone 2");
        Operation_Bluetooth.println("Ouvrir zone 2");
        
        }

    if ((incoming3.compareTo("m"))==0)
        {
        Serial.println("Mode Manuel");
        Operation_Bluetooth.println("Mode Manuel");
        
        }    
*/



incoming = "";

        
  /*      
    if (incoming == "btp")
        {
        Serial.println("LED turned OFF");
        Operation_Bluetooth.println("LED turned OFF");
        }    
       */
  }
   
