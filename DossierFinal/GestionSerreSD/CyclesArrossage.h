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
    
private:

  gpio_num_t brocheCarteSD;
  float donnee[4];        // a supprimer juste pour test
  //tableau 2 dim

  double SeuilZone[4][3];


  int ObtenirSeuilMax();
  int ObtenirSeuilMin();
  
};

#endif // CYCLESARROSSAGE_H
