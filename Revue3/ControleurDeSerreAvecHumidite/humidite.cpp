#include "humidite.h"
#include "timer.h"

Timer timerAttentes;

Humidite::Humidite(gpio_num_t _brocheMesure):
YL69Pin(_brocheMesure)
{

  
   

  
}


Humidite::~Humidite()
{
  

  
}



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
