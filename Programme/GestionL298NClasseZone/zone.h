#ifndef ZONE_H
#define ZONE_H

#include <driver/gpio.h>
#include "timer.h"


class Zone {
  public:

    
     enum MODE_ZONE 
    {
      MODE_MANUEL,
      MODE_PROGRAMME,
      MODE_AUTOMATIQUE
    };

    enum ETAT_ZONE 
    {
      ATTENTE,
      OUVERTURE,
      FERMETURE
    };


    Zone(gpio_num_t _commandeVanne);
    ~Zone();

    int Controler();
  
    int ModifierDateHeure();
    int ModifierSeuilHumidite();
    int ModifierPeriodicite();
    int ModifierDuree();
    
    
  private:
    MODE_ZONE etatMode;
    ETAT_ZONE etatZone;
    
  
};

#endif /* ZONE_H */
