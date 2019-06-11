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

              
        if(_parametre.charAt(1) == 'o')
        {

          laVanne.Controler('O');
        }
           
        if(_parametre.charAt(1) == 'f') 
        {

          laVanne.Controler('F');
        }
           
       
        break;

      case 'p':
        timerHumidite.Arreter();

        break;

      case 'a':

        timerHumidite.Lancer(0,0,10);

        
        
        
        
          
          
        break;
      default:
      if(timerHumidite.Scruter())
        {
        mesureHumidite = leCapteur.PreleverHumidite();
        if((mesureHumidite<= seuilMin) && (etatZone == ATTENTE))
        {

          laVanne.Controler('O');
          etatZone = ARROSAGE;
        }
        if((mesureHumidite >= seuilMax) && (etatZone == ARROSAGE ))
        {

          laVanne.Controler('F');
          etatZone = ATTENTE;
        }
        }
      break;  
   }

   laVanne.Controler('X');


  }
    
