/**
  * @author Michaud théo
  * @date   Vendredi 15 avril 2019
  * @file   humidite.cpp
  */


#include "humidite.h"
#include "timer.h"

Timer timerAttentes;


/**
 * @brief Humidite::Humidite
 * @param gpio_num_t _brocheMesure c'est le numéro de la broche du capteur d'humidité
 * @details Constructeur de la classe
 */
Humidite::Humidite(gpio_num_t _brocheMesure):
YL69Pin(_brocheMesure)
{
}

/**
 * @brief Humidite::~Humidite
 * @param gpio_num_t _brocheMesure c'est le numéro de la broche du capteur d'humidité
 * @details Déstructeur de la classe
 */
Humidite::~Humidite()
{
}


/**
 * @brief Humidite::PreleverHumidite
 * @details On va venir lire le capteur et récuperer le taux d'humidité que l'on va convertir en pourcentage
 */
int Humidite::PreleverHumidite()
{

  
 /*if(timerAttentes.Scruter())
 {*/
  // Serial.println(readYL69value);
  int readYL69value = analogRead(YL69Pin);
  //plus la valeur diminue, plus le pourcentage augmente
  //map permet de convertir les valeurs reçus en pourcentage, 4095 et 1200 sont les plages de mesure du capteur
  //si la valeur de l'humidité est 4095 alors l'humidité sera de 0% et si elle est à 1200, l'humidité sera à 100%
  int convertedPercentage = map(readYL69value, 4095, 925, 0, 100);
  Serial.print("Humidité du sol (YL-69): ");
  Serial.print(convertedPercentage);
  Serial.print("%\n");

  return convertedPercentage;
 //}
  
}
