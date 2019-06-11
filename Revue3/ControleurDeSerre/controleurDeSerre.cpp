#include "controleurDeSerre.h"


ControleurDeSerre::ControleurDeSerre()
{
  
  zones[0]=new Zone(1,GPIO_NUM_4);
  zones[1]=new Zone(2,GPIO_NUM_4);
  zones[2]=new Zone(3,GPIO_NUM_4);
  zones[3]=new Zone(4,GPIO_NUM_4);

  liaisonSmartphone.begin("Serre Connectée");             //Nom du signal Bluetooth
  liaisonSmartphone.println("Connexion Réussie");
  Serial.println("Connexion Réussie");
  
}


ControleurDeSerre::~ControleurDeSerre()
{
  
  for(int i=0; i<4; i++)
  {
    delete *zones;    
  }
  
}



void ControleurDeSerre::Piloter()
{
  
  while (liaisonSmartphone.available() )                                                  //Check if we receive anything from Bluetooth
  {
   carlu = liaisonSmartphone.read();
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
