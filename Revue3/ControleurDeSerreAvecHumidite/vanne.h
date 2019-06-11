#ifndef VANNE_H
#define VANNE_H

//#include <soc.h>
#include <driver/gpio.h>
#include "timer.h"

#define SENS_A GPIO_NUM_16
#define SENS_B GPIO_NUM_17

class Vanne {
  public:

    enum ETAT_VANNE 
    {
      REPOS,
      OUVERT,
      FERMER,
      EN_OUVERTURE,
      EN_FERMETURE,
      EN_ATTENTE_OUVERTURE,
      EN_ATTENTE_FERMETURE
    };
     
    Vanne(gpio_num_t _brocheImpulsion);
    //SensA(gpio_num_t _SensA);
    //SensB(gpio_num_t _SensB);
    virtual ~Vanne();

    void Ouvrir();
    void Fermer();
    int Controler(char commande);

    
    
  private:
    gpio_num_t brocheImpulsion;
    Timer timerImpulsion; 
    const gpio_num_t sensA;
    const gpio_num_t sensB; 
    //gpio_num_t sensA;
    //gpio_num_t sensB; 
    ETAT_VANNE etat;
  
};

#endif /* VANNE_H */
