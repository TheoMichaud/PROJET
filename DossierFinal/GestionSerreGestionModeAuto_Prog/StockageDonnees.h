/*
   To change this license header, choose License Headers in Project Properties.
   To change this template file, choose Tools | Templates
   and open the template in the editor.
*/

/*
   File:   StockageDonnees.h
   Author: kauve

   Created on 18 mars 2019, 11:12
*/

#ifndef STOCKAGEDONNEES_H
#define STOCKAGEDONNEES_H

#include <Wire.h>
#include "RTClib.h"

#include <SPI.h>
#include <SD.h>


class StockageDonnees {
  public:
    StockageDonnees();

    virtual ~StockageDonnees();

    String RecupereDate();
DateTime now;
  private:
    RTC_DS3231 rtc;
    

    
};

#endif /* STOCKAGEDONNEES_H */
