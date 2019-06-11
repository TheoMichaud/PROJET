/**
  * @author Michaud théo
  * @date   Vendredi 15 avril 2019
  * @file   GestionSerre.ino
  */


#include <driver/gpio.h>
#include "zone.h"
#include "controleurDeSerre.h"

Timer timerAttente;
Timer timerAttenteHumidite;
Vanne vanne1(GPIO_NUM_4);
Vanne vanne2(GPIO_NUM_27);





Vanne::ETAT_VANNE etatVanne1;
Vanne::ETAT_VANNE etatVanne2;


ControleurDeSerre *controleur;



bool etat;

char choix; 

void setup() {
 
    
    Serial.begin(9600);
 //   liaisonSmartphone.begin("Serre Connectée"); //Nom du signal Bluetooth
  
    Serial.println("-- Initialisation --");
   
    etat = false;

    controleur = new ControleurDeSerre();
}


void loop() { 
 
controleur->Piloter();




   
}
