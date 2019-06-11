#include "timer.h"

   
Timer::Timer() {

}

Timer::~Timer(){
  
}



void Timer::Lancer(unsigned long _delay){

    tempsPrecedent=millis(); 
    Serial.println(tempsPrecedent);
    delay = _delay;

}


bool Timer::Scruter(){

   //unsigned long calcul=millis()-tempsPrecedent;
   bool retour = false;
   if((millis()-tempsPrecedent)>delay)
    {
      
    retour = true;
   
    tempsPrecedent = millis();
    Serial.println(tempsPrecedent);
    }

      return retour;
}
