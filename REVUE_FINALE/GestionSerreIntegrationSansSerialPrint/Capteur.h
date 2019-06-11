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

class Capteur {
  public:
    Capteur();
    virtual ~Capteur();
    void ReleverTemperature();
    void ReleverHygrometrie();
    void ReleverLuminosite();

    float temperature;
    float hygrometrie;
    uint16_t luminosite;
    
  private:
  
    Adafruit_BME280 bme;
    Adafruit_TSL2591 tsl;
    //Pin du capteur d'huimité du sol
    const int YL69Pin = 34;
    int pourcentageHumidite = 0;

};

#endif /* STOCKAGEDONNEES_H */
