#ifndef ZONEARROSAGE_H
#define ZONEARROSAGE_H

#include <string>
#include <iostream>
#include "vanne.h"

using namespace std;

class ZoneArrosage
{
private:
    Vanne *laVanne;
    int numZone;
public:
//    ZoneArrosage(int _numZone,
//                 gpio_num_t _commandeVanne,
//                 gpio_num_t _senseAVanne,
//                 gpio_num_t _senseBVanne,
//                 gpio_num_t _brocheHumidite);
    ZoneArrosage(string _initialisation);
    ~ZoneArrosage();
    void Piloter();
};

#endif // ZONEARROSAGE_H
