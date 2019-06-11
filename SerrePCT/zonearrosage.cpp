#include "zonearrosage.h"

//ZoneArrosage::ZoneArrosage(int _numZone, int _commandeVanne, int _senseAVanne, int _senseBVanne, int _brocheHumidite):
//    laVanne(_commandeVanne,_senseAVanne,_senseBVanne),
//    numZone(_numZone)
//{
//    // code du constructeur
//}

ZoneArrosage::ZoneArrosage(string _initialisation)
{
    int parametres[4];
    size_t prec = 0;
    size_t pos =  0;
    for (int indice = 0;indice < 4;indice++)
    {
        pos = _initialisation.find(' ',pos);
        parametres[indice] = atoi(_initialisation.substr(prec,pos).c_str());
        prec = pos++; // on incrémente pos pour le tour d'après.
    }
    numZone = parametres[0];
    laVanne = new Vanne(parametres[1],parametres[2],parametres[3]);
}

ZoneArrosage::~ZoneArrosage()
{
    delete laVanne;
}

void ZoneArrosage::Piloter()
{

}
