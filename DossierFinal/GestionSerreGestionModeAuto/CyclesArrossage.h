/**
  * @author Michaud théo
  * @date   Vendredi 15 avril 2019
  * @file   cyclesarrossage.cpp
  */

#ifndef CYCLESARROSSAGE_H
#define CYCLESARROSSAGE_H
#include <SPI.h>
#include <SD.h> 


class CyclesArrossage
{
public:
    CyclesArrossage(gpio_num_t _brocheCarteSD);

    void LireCarteSD();
    void LireCarteSDModeProg();
     int ObtenirSeuilMax(int _zone);
  int ObtenirSeuilMin(int _zone);
    
private:

  gpio_num_t brocheCarteSD;

  int seuilZoneMin[4];
  int seuilZoneMax[4];

  bool valeurDefaut;
 
  
};

#endif // CYCLESARROSSAGE_H
