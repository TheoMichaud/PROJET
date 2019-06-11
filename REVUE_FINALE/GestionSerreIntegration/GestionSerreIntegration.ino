/**
  * @author Michaud théo
  * @date   Vendredi 15 avril 2019
  * @file   GestionSerre.ino
  */

#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <Ethernet.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_TSL2591.h>

#include <driver/gpio.h>

#include "Capteur.h"
#include "StockageDonnees.h"

#include "zone.h"
#include "controleurDeSerre.h"

Timer timerAttente;
Timer timerAttenteHumidite;
Vanne vanne1(GPIO_NUM_4);
Vanne vanne2(GPIO_NUM_27);

Vanne::ETAT_VANNE etatVanne1;
Vanne::ETAT_VANNE etatVanne2;

ControleurDeSerre *controleur;
ControleurDeSerre *controleur2;


bool etat;

char choix; 

void setup() {
    Serial.begin(9600);
    Serial.println("-- Initialisation --");
    etat = false;
    controleur = new ControleurDeSerre();
    controleur2 = new ControleurDeSerre();
    controleur2->Initialisation();
}
void loop() { 
    controleur->Piloter();
    controleur2->PiloterCapteurs();
}
