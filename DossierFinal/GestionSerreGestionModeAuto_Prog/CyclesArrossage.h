/**
  * @author Michaud théo
  * @date   Vendredi 15 avril 2019
  * @file   cyclesarrossage.cpp
  */

#ifndef CYCLESARROSSAGE_H
#define CYCLESARROSSAGE_H
#include <SPI.h>
#include <SD.h> 
#include <time.h>
#include "RTClib.h"



struct uneDate{
    int jour;
    int mois;
    int annee;
  };
typedef struct uneDate Date;

struct uneHeure{
    int heure;
    int minutes;
    int secondes;
  };
typedef struct uneHeure Heure;

class CyclesArrossage
{
public:
    CyclesArrossage(gpio_num_t _brocheCarteSD);

  void LireCarteSD();
  void LireCarteSDModeProg();
  int ObtenirSeuilMax(int _zone);
  int ObtenirSeuilMin(int _zone);
  int ObtenirDuree(int _zone);
  int ObtenirPeriode(int _zone);
  Date ObtenirDate(int _zone);
  Heure ObtenirHeure(int _zone);
    
private:

  gpio_num_t brocheCarteSD;

  int seuilZoneMin[4];
  int seuilZoneMax[4];

  bool valeurDefaut;

  
  Date dateDepart[4];
  Heure heureDepart[4];
  int duree[4];
  int periodicite[4];

  void ConvertirDate(String dateStr, Date *date);
  void ConvertirHeure(String heureStr, Heure *heure);
 
  
};

#endif // CYCLESARROSSAGE_H
