/**
  * @author Michaud théo
  * @date   Vendredi 15 avril 2019
  * @file   humidite.h
  */


#ifndef HUMIDITE_H
#define HUMIDITE_H

#include <driver/gpio.h>
#include <string.h>
#include "timer.h"
#include <WString.h>





class Humidite {
  public:
  
   Humidite(gpio_num_t _brocheMesure);
   ~Humidite();

   int PreleverHumidite();
   

    
  private:
   const int YL69Pin;
   
   int pourcentage = 0;

   Timer timerHumidite;
   
    
};

#endif /* HUMIDITE_H */
