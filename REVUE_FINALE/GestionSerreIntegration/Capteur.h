/*
   To change this license header, choose License Headers in Project Properties.
   To change this template file, choose Tools | Templates
   and open the template in the editor.
*/

/**
    @author kauve
    @file   Capteur.h
*/



#ifndef CAPTEUR_H
#define CAPTEUR_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME280.h"
#include "Adafruit_TSL2591.h"
#include "timer.h"


class Capteur {
  public:
    Capteur();
    virtual ~Capteur();
    void ReleverTemperature();
    void ReleverHygrometrie();
    void ReleverLuminosite();
    float ReleverHumidite();
    float ReleverDebitEau();

    float temperature;
    float hygrometrie;
    uint16_t luminosite;
    
  private:
  
    Adafruit_BME280 bme;
    Adafruit_TSL2591 tsl;
    const int YL69Pin = 34;
    int pourcentageHumidite = 0;

};

#endif /* STOCKAGEDONNEES_H */
