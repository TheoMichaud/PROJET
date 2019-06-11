#include "timer.h"

//definition de la pin
const int YL69Pin = 34;
int pourcentage = 0;

Timer timerAttente;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  timerAttente.Lancer(5000);

}

void loop() {
  // put your main code here, to run repeatedly:

  int const readYL69value = analogRead(YL69Pin);

  

  //delay(5000);

  if(timerAttente.Scruter())
    {
     // Serial.println(readYL69value);

  //plus la valeur diminue, plus le pourcentage augmente
  //map permet de convertir les valeurs reçus en pourcentage, 4095 et 1200 sont les plages de mesure du capteur
  //si la valeur de l'humidité est 4095 alors l'humidité sera de 0% et si elle est à 1200, l'humidité sera à 100%
  int const convertedPercentage = map(readYL69value, 4095, 925, 0, 100);
  Serial.print("Humidité du sol (YL-69): ");
  Serial.print(convertedPercentage);
  Serial.print("%\n");
       
    }

}
