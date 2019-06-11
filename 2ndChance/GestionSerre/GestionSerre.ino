/**
  * @author Michaud théo
  * @date   Vendredi 15 avril 2019
  * @file   GestionSerre.ino
  */
#include <Wire.h>

#include "controleurDeSerre.h"


ControleurDeSerre *controleur;

bool etat;

char choix; 

void setup() {
    Serial.begin(9600);
    
    //etat = false;
    
    controleur = new ControleurDeSerre();

    controleur->Initialisation();
}
void loop() { 
    controleur->Piloter();
    controleur->PiloterCapteurs();
}
