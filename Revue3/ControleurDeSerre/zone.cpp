#include "zone.h"
#include <Arduino.h>


Zone::Zone(int nbZone, gpio_num_t _commandeVanne):
numZone(nbZone)
{

}

Zone::~Zone(){
  
}


int Zone::Controler(String _parametre)
{

  char parametre = _parametre.charAt(0);

switch (parametre)
   {
      case 'm':
        Serial.print("Mode Manuel ");
        Serial.print("zone ");
        Serial.println(numZone);
              
        if(_parametre.charAt(1) == 'o')
           Serial.println("Ouverture Vanne");
        else 
          Serial.println("Fermeture Vanne");
       
        break;

      case 'p':
        Serial.print("Mode Programmé ");
        Serial.print("zone ");
        Serial.println(numZone);
        break;

      case 'a':
        Serial.print("Mode Automatique ");
        Serial.print("zone ");
        Serial.println(numZone);
        break;
      default:
      break;  
   }


  }
    
