/**
  * @author Michaud théo
  * @date   Vendredi 10 avril 2019
  * @file   zone.h
  */




#ifndef ZONE_H
#define ZONE_H

#include <driver/gpio.h>
#include <string.h>
#include "timer.h"
#include <WString.h>

#include "vanne.h"
#include "humidite.h"
#include "CyclesArrossage.h"

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
      FERMETURE,
      ARROSAGE
    };


    Zone(int nbZone, gpio_num_t _commandeVanne, gpio_num_t _brocheHumidite, CyclesArrossage *_cycles);
    ~Zone();

    int Controler(String _parametre);
  
    int ModifierDateHeure();
    int ModifierSeuilHumidite();
    int ModifierPeriodicite();
    int ModifierDuree();
    
    
  private:
    MODE_ZONE etatMode;
    ETAT_ZONE etatZone;
    int numZone;
    String incoming;

    Vanne laVanne;

    Humidite leCapteur;

    CyclesArrossage *cycles;
    int seuilMin;
    int seuilMax;
    int mesureHumidite;

    Timer timerHumidite;
  
};

#endif /* ZONE_H */
