/*
   File:   StockageDonnees.cpp
   Author: kauve

   Created on 18 mars 2019, 11:12
*/

#include "StockageDonnees.h"

/**
   @brief StockageDonnees::StockageDonnees() 
   @details Constructeur
*/
StockageDonnees::StockageDonnees() 
{
  if(rtc.begin())
  {
    Serial.println("RTC OK");
  }
  
   
}

/**
   @brief StockageDonnees::~StockageDonnees() 
   @details Destructeur
*/

StockageDonnees::~StockageDonnees() 
{
}


/**
   @brief StockageDonnees::RecupereDate
   @details Permet de récupérer la date
   @return une chaine de caractère contenant la date
*/
String StockageDonnees::RecupereDate() {
  now = rtc.now();
  String annee, mois, jour, heure, minute, seconde;

  annee = String(now.year());
  mois = String(now.month());
  jour = String(now.day());
  heure = String(now.hour());
  minute = String(now.minute());
  seconde = String(now.second());
  String date;
  date = annee + "-" + mois + "-" + jour + " " + heure + ":" + minute + ":" + seconde;

  return date;
}
