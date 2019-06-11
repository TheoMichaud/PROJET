#include <driver/gpio.h>
#include "timer.h"
#include "vanne.h"

Timer timerAttente;
Vanne vanne1(GPIO_NUM_4, GPIO_NUM_17, GPIO_NUM_16);
Vanne vanne2(GPIO_NUM_27, GPIO_NUM_26, GPIO_NUM_25);



Vanne::ETAT_VANNE etatVanne1;
Vanne::ETAT_VANNE etatVanne2;


bool etat;

char choix;

void setup() {
    Serial.begin(9600);
    
        
    Serial.println("-- Initialisation --");

    timerAttente.Lancer(1000);

    etat = false;
}


void loop() { 
 
    vanne1.Controler('R');
    vanne2.Controler('P');
/*
    if(timerAttente.Scruter())
    {
      
      if(etat==true)
      {
        vanne1.Controler('O');
        etat=false;
       // Serial.println("Ouvert");
      }
      else
      {
        vanne1.Controler('F');
        etat=true;
        //Serial.println("Fermé");
      }      
    }
    */

    if(Serial.available()>0)
    {
      choix=Serial.read();
      switch(choix)
      {
        case 'O':
        vanne1.Controler('O');
        Serial.println("Ouverture de la vanne1");
        break;

        case 'F':
        vanne1.Controler('F');
        Serial.println("Fermeture de la vanne1");
        break;

        case 'K':
        vanne2.Controler('O');
        Serial.println("Ouverture de la vanne2");
        break;

        case 'Z':
        vanne2.Controler('F');
        Serial.println("Fermeture de la vanne2");
        break;
      }
    }

   
}
