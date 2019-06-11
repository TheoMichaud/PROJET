/**
  * @author Michaud théo
  * @date   Vendredi 15 avril 2019
  * @file   controleurDeSerre.h
  */


#ifndef CONTROLEURDESERRE_H
#define CONTROLEURDESERRE_H

#include <driver/gpio.h>
#include <string.h>
#include "timer.h"
#include <WString.h>
#include "BluetoothSerial.h"
#include <Wire.h>
#include "zone.h"
#include "CyclesArrossage.h"

#include "Capteur.h"
#include "StockageDonnees.h"


class ControleurDeSerre {
  public:
  
   ControleurDeSerre();
   ~ControleurDeSerre();

   Zone *zones[2];

   void Piloter();
   void PiloterCapteurs();
   
   void Initialisation();
    
  private:
    String incoming;
    BluetoothSerial liaisonSmartphone;
    char commande;
    char carlu;
    char numZone;
    CyclesArrossage *cycles;


    Capteur *capteur;
    StockageDonnees *s1 ;
    Timer attente;
    int i = 0;
    String chaine;
    
};

#endif /* CONTROLEURDESERRE_H */
