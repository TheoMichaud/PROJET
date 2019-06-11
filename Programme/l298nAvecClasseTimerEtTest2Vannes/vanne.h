

#ifndef VANNE_H
#define VANNE_H

//#include <soc.h>
#include <driver/gpio.h>
#include "timer.h"


class Vanne {
  public:

    enum ETAT_VANNE 
    {
      REPOS,
      EN_OUVERTURE,
      EN_FERMETURE
    };
     
    Vanne(gpio_num_t _brocheImpulsion, gpio_num_t _SensA, gpio_num_t _SensB);
    //SensA(gpio_num_t _SensA);
    //SensB(gpio_num_t _SensB);
    virtual ~Vanne();

    void Ouvrir();
    void Fermer();
    int Controler(char commande);

    
    
  private:
    gpio_num_t brocheImpulsion;
    Timer timerImpulsion; 
    //const gpio_num_t sensA;
   // const gpio_num_t sensB; 
    gpio_num_t sensA;
    gpio_num_t sensB; 
    ETAT_VANNE etat;
  
};

#endif /* VANNE_H */
