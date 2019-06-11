/**
  * @author Michaud théo
  * @date   Vendredi 15 avril 2019
  * @file   controleurDeSerre.cpp
  */



#include "controleurDeSerre.h"

/**
 * @ControleurDeSerre::ControleurDeSerre
 * @details Constructeur de la classe, on va initialiser dans un tableau nos différentes zones ici 4 et on va démarrer la liaison bluetooth.
 */
ControleurDeSerre::ControleurDeSerre()
{
  cycles = new CyclesArrossage(GPIO_NUM_5);
  cycles->LireCarteSD();
  cycles->LireCarteSDModeProg();
  //cyclesProg = new CyclesArrossage(GPIO_NUM_5);
  //cyclesProg->LireCarteSDModeProg();
   
  
  zones[0]=new Zone(1,GPIO_NUM_4,GPIO_NUM_34,cycles);
  zones[1]=new Zone(2,GPIO_NUM_27,GPIO_NUM_34,cycles);
  zones[2]=new Zone(3,GPIO_NUM_4,GPIO_NUM_34,cycles);
  zones[3]=new Zone(4,GPIO_NUM_4,GPIO_NUM_34,cycles);

  liaisonSmartphone.begin("Serre Connectée 3");             //Nom du signal Bluetooth
  liaisonSmartphone.println("Connexion Réussie");
  Serial.println("Connexion Réussie");

  rtc.begin();
 
}

/**
 * @ControleurDeSerre::~ControleurDeSerre
 * @details Déstructeur de la classe, on va venir supprimer, effacer les zones crées dans le constructeur.
 */
ControleurDeSerre::~ControleurDeSerre()
{
  
  for(int i=0; i<4; i++)
  {
    delete *zones;    
  }

  
}


/**
 * @ControleurDeSerre::ControleurDeSerre
 * @details Première Partie : Tant que la liaison bluetooth fonctionne on récupére la chaine de caractère envoyée
 * @details Deuxième Partie : On compare la chaine de caractère, si le premier caractère est un z on regarde le deuxième pour obtenir le numéro de la zone. puis on appelle la méthode Controler ().
 */
void ControleurDeSerre::Piloter()
{
  
  DateTime valCourant;
  valCourant = rtc.now();
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
        zones[(int)(numZone - '1')]->Controler(incoming.substring(2),valCourant);
        break;
      default:
        
      break;  
   }
     
  incoming = "";
  }

  for(int indice=0; indice<4; indice++){
      
      zones[indice]->Controler(" ",valCourant);
   }
  
}
