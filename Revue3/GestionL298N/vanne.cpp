#include "vanne.h"

bool mutex = false;

Vanne::Vanne(gpio_num_t _brocheImpulsion, gpio_num_t _SensA, gpio_num_t _SensB)
//SensA(gpio_num_t _SensA),
//SensB(gpio_num_t _SensB)
{
  brocheImpulsion = _brocheImpulsion;
  sensA = _SensA;
  sensB = _SensB;
  gpio_set_direction(brocheImpulsion, GPIO_MODE_OUTPUT);
  gpio_set_pull_mode(brocheImpulsion, GPIO_PULLUP_ONLY);
  gpio_set_direction(sensA, GPIO_MODE_OUTPUT);
  gpio_set_direction(sensB, GPIO_MODE_OUTPUT);
  etat = REPOS;
}

Vanne::~Vanne(){
  
}

void Vanne::Ouvrir()
{
  if(!mutex)
  {
    mutex = true;
    gpio_set_level(sensA, 1);
  gpio_set_level(sensB, 0);

  gpio_set_level(brocheImpulsion, 1);

  timerImpulsion.Lancer(250);
  etat = EN_OUVERTURE;
  }
  else
  {
    Serial.print("Impossible - ");
    Serial.println(brocheImpulsion);
  }
  
}


void Vanne::Fermer()
{
  if(!mutex)
  {
    mutex = true;
  gpio_set_level(sensA, 0);
  gpio_set_level(sensB, 1);

  gpio_set_level(brocheImpulsion, 1);

  timerImpulsion.Lancer(250);
  etat = EN_FERMETURE;
  }
}



int Vanne::Controler(char commande)
{
  switch(etat)
  {
    case EN_OUVERTURE:
    if(timerImpulsion.Scruter())
    {
      gpio_set_level(brocheImpulsion, 0);
      etat = REPOS;
      mutex= false;
       Serial.println("Ouvert");
    }
    break;
    case EN_FERMETURE:
    if(timerImpulsion.Scruter())
    {
      gpio_set_level(brocheImpulsion, 0);
      etat = REPOS;
      mutex=false;
       Serial.println("Fermé");
    }
    break;
    case REPOS:
    if(commande=='O')
    {
      Ouvrir();
    }
    if(commande=='F')
    {
      Fermer();
    }
    break;
  }

  return etat;
}
