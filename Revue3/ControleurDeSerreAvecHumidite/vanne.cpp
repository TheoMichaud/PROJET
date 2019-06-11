#include "vanne.h"

bool mutex = false;

Vanne::Vanne(gpio_num_t _brocheImpulsion):
sensA(SENS_A),
sensB(SENS_B)
{
  brocheImpulsion = _brocheImpulsion;
  
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
    etat = EN_ATTENTE_OUVERTURE;
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
  else
  {
    etat = EN_ATTENTE_FERMETURE;
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
  
  case EN_ATTENTE_OUVERTURE:
    if(!mutex)
    {
      Ouvrir();
      
    }
    else{
      Serial.println("En attente d'ouverture");
    }
    break;
    case EN_ATTENTE_FERMETURE:
    if(!mutex)
    {
      Fermer();
      
    }
    else{
      Serial.println("En attente de fermeture");
    }
    break;
  }

  return etat;
}
