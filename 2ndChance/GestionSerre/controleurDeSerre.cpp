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
   
  
  zones[0]=new Zone(1,GPIO_NUM_4,GPIO_NUM_34,cycles);
  zones[1]=new Zone(2,GPIO_NUM_27,GPIO_NUM_34,cycles);
  //zones[2]=new Zone(3,GPIO_NUM_4,GPIO_NUM_34,cycles);
  //zones[3]=new Zone(4,GPIO_NUM_4,GPIO_NUM_34,cycles);

  liaisonSmartphone.begin("Serre Connectée");             //Nom du signal Bluetooth
  liaisonSmartphone.println("Connexion Réussie");

  capteur = new Capteur();
  s1 = new StockageDonnees();

 
}

/**
 * @ControleurDeSerre::~ControleurDeSerre
 * @details Déstructeur de la classe, on va venir supprimer, effacer les zones crées dans le constructeur.
 */
ControleurDeSerre::~ControleurDeSerre()
{
  
  for(int i=0; i<2; i++)
  {
    delete *zones;    
  }

  
}


/**
   @brief ControleurDeSerre::Initialisation
   @details Permet d'Initialiser la carte ESP32
*/
void ControleurDeSerre::Initialisation()
{
  MySQL_Connection conn(&s1->client);
  //Création du timer fixé à 15 minutes
  attente.Lancer(0, 0, 20);

  s1->DefinirParametresCarte();

  s1->ConnexionWifi();
  conn = s1->ConnexionServeur();

}





/**
 * @ControleurDeSerre::ControleurDeSerre
 * @details Première Partie : Tant que la liaison bluetooth fonctionne on récupére la chaine de caractère envoyée
 * @details Deuxième Partie : On compare la chaine de caractère, si le premier caractère est un z on regarde le deuxième pour obtenir le numéro de la zone. puis on appelle la méthode Controler ().
 */
void ControleurDeSerre::Piloter()
{
  
  while (liaisonSmartphone.available() )                                                  //Check if we receive anything from Bluetooth
  {
   carlu = liaisonSmartphone.read();
   incoming += carlu;
     
  }

  if(incoming.compareTo("") != 0)
  {
    
    commande = incoming.charAt(0);
   switch (commande)
   {
      case 'z':
        numZone = incoming.charAt(1) ;
        zones[(int)(numZone - '1')]->Controler(incoming.substring(2));
        break;
      default:
        
      break;  
   }
     
  incoming = "";
  }

  for(int indice=0; indice<2; indice++){
      zones[indice]->Controler(" ");
   }
  
}


/**
   @brief ControleurDeSerre::PiloterCapteurs
   @details Permet de lancer toutes les opérations que l'ESP32 va effectuer
*/
void ControleurDeSerre::PiloterCapteurs()
{

  MySQL_Connection conn(&s1->client);
  
  //Toutes les 15 minutes,l'ESP32 va effectuer les opérations suivantes
  if (attente.Scruter())
  {
   /* s1->VerifierConnexionWifi();
    conn = s1->VerifierConnexionServeur(conn);
*/
    //Permet de récupérer les données météorologiques
    capteur->ReleverTemperature();

    capteur->ReleverHygrometrie();

    capteur->ReleverLuminosite();

    conn = s1->GererPerteConnexion(capteur->temperature, capteur->hygrometrie, capteur->luminosite, conn);

    s1->InsererDonneesMesuresInterieurSerre(capteur->temperature, capteur->hygrometrie, capteur->luminosite);
    s1->VerifierConnexionWifi();
    conn = s1->VerifierConnexionServeur(conn);
    
  s1->EnvoyerDonneesBdd(conn);
//s1->i++;

  }

}
