/**
  * @author kauve
  * @file   Capteur.cpp
  */

#include "Capteur.h"

Capteur::Capteur() {

  bool status;
  
  status = bme.begin();

  if (!status) {
        Serial.println("Le capteur BME280 ne fonctionne pas" );
        while (1);
    }

}

Capteur::~Capteur() {

}

/**
   @brief Capteur::ReleverTemperatureInterieur
   @details Permet de relever la temperature du capteur bme280
*/
void Capteur::ReleverTemperature() {

  temperature = bme.readTemperature();

}

/**
   @brief Capteur::ReleverHygrometrieInterieur
   @details Permet de relever la hygrométrie du capteur bme280
*/
void Capteur::ReleverHygrometrie() {

  hygrometrie = bme.readHumidity();

}

/**
   @brief Capteur::ReleverLuminositeInterieur
   @details Permet de relever la luminosité du capteur tsl2591
*/
void Capteur::ReleverLuminosite() {
  
  luminosite = tsl.getLuminosity(TSL2591_VISIBLE);

}
