#include "zone.h"
#include <Arduino.h>

#include "humidite.h"

Zone::Zone(int nbZone, gpio_num_t _commandeVanne, gpio_num_t _brocheHumidite):
numZone(nbZone),
laVanne(_commandeVanne),
leCapteur(_brocheHumidite)
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

   laVanne.Controler('P');


  }
    
