#include <driver/gpio.h>
#include "timer.h"
#include "vanne.h"
#include "zone.h"
#include "controleurDeSerre.h"

Timer timerAttente;
Vanne vanne1(GPIO_NUM_4);
Vanne vanne2(GPIO_NUM_27);




Vanne::ETAT_VANNE etatVanne1;
Vanne::ETAT_VANNE etatVanne2;


ControleurDeSerre *controleur;

bool etat;

char choix;

void setup() {
  controleur = new ControleurDeSerre();
    Serial.begin(9600);
 //   liaisonSmartphone.begin("Serre Connectée"); //Nom du signal Bluetooth
  
    Serial.println("-- Initialisation --");
    
    etat = false;

   
}


void loop() { 
 
controleur->Piloter();
   
}
