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



class ControleurDeSerre {
  public:
  
   ControleurDeSerre();
   ~ControleurDeSerre();

   Zone *zones[4];

   void Piloter();
   
    
  private:
    String incoming;
    BluetoothSerial liaisonSmartphone;
    char commande;
    char carlu;
    char numZone;
    
};

#endif /* CONTROLEURDESERRE_H */
