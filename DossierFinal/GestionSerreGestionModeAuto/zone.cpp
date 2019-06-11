/**
  * @author Michaud théo
  * @date   Vendredi 10 avril 2019
  * @file   zone.cpp
  */


#include "zone.h"
#include <Arduino.h>

#include "humidite.h"



/**
 * @brief Zone::Zone
 * @param int nbZone permet de connaitre le nom de la zone
 * @param gpio_num_t _commandeVanne c'est la broche de la vanne à gérer
 * @param gpio_num_t _brocheHumidite, c'est la broche du capteur d'humidité
 * @details Constructeur de la classe.
 */

Zone::Zone(int nbZone, gpio_num_t _commandeVanne, gpio_num_t _brocheHumidite, CyclesArrossage *_cycles):
numZone(nbZone),
laVanne(_commandeVanne),
leCapteur(_brocheHumidite),
cycles(_cycles)
{
  seuilMin = cycles->ObtenirSeuilMin(numZone-1);
  seuilMax = cycles->ObtenirSeuilMax(numZone-1);
  Serial.print(seuilMin);
  Serial.print(" - ");
  Serial.println(seuilMax);

  etatZone = ATTENTE; 
  
}

/**
 * @brief Zone::~Zone
 * @details Déstructeur de la classe.
 */
Zone::~Zone(){
  
}

/**
 * @brief Zone::Controler
 * @param string _parametre, c'est la chaine que renvoie l'application lorsqu'une action est effectuée 
 * @details Si la chaine de caractère reçue commence par un m, alors on passe en mode manuel et l'ouverture ou la fermeture dependera du caractère suivant.
 * @details Si elle commence par un p on passe en mode programmé et si elle commence par un a alors on passe en mode auto.
 */
 
int Zone::Controler(String _parametre)
{

  char parametre = _parametre.charAt(0);

switch (parametre)
   {
      case 'm':
        timerHumidite.Arreter();
        Serial.print("Mode Manuel ");
        Serial.print("zone ");
        Serial.println(numZone);
              
        if(_parametre.charAt(1) == 'o')
        {
          Serial.println("Ouverture Vanne");
          laVanne.Controler('O');
        }
           
        if(_parametre.charAt(1) == 'f') 
        {
          Serial.println("Fermeture Vanne");
          laVanne.Controler('F');
        }
           
       
        break;

      case 'p':
        timerHumidite.Arreter();
        Serial.print("Mode Programmé ");
        Serial.print("zone ");
        Serial.println(numZone);
        break;

      case 'a':
        Serial.print("Mode Automatique ");
        Serial.print("zone ");
        Serial.println(numZone);
        timerHumidite.Lancer(0,0,10);

        
        
        
        
          
          
        break;
      default:
      if(timerHumidite.Scruter())
        {
        mesureHumidite = leCapteur.PreleverHumidite();
        if((mesureHumidite<= seuilMin) && (etatZone == ATTENTE))
        {
          Serial.println("Ouverture Vanne");
          laVanne.Controler('O');
          etatZone = ARROSAGE;
        }
        if((mesureHumidite >= seuilMax) && (etatZone == ARROSAGE ))
        {
          Serial.println("Fermeture Vanne");
          laVanne.Controler('F');
          etatZone = ATTENTE;
        }
        }
      break;  
   }

   laVanne.Controler('X');


  }
    
