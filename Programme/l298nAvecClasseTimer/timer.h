/*
   To change this license header, choose License Headers in Project Properties.
   To change this template file, choose Tools | Templates
   and open the template in the editor.
*/

/*
   File:   timer.h
   Author: tmichaud

   Created on 20 mars 2019, 09:30
*/

#ifndef TIMER_H
#define TIMER_H


#include <Arduino.h>

class Timer {
  public:
    Timer();
    virtual ~Timer();

    void Lancer(unsigned long _delay);
    bool Scruter();
    
  private:
    unsigned long tempsPrecedent;
    unsigned long delay;

 

};

#endif /* TIMER_H */
