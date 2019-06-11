/**
  * @author Michaud théo
  * @date   Vendredi 15 avril 2019
  * @file   cyclesarrossage.cpp
  */


#include "CyclesArrossage.h"

CyclesArrossage::CyclesArrossage(gpio_num_t _brocheCarteSD):
brocheCarteSD(_brocheCarteSD)
{
  pinMode(brocheCarteSD, OUTPUT);

  if (! SD.begin(brocheCarteSD)){
  Serial.println(F("Erreur initialisation carte sd"));

  // mettre initialisation tableau fixe si pas de carte SD
  
} else{
   Serial.println(F("initialisation carte sd OK"));
}

}





void CyclesArrossage::LireCarteSD()
{
    File fichier = SD.open("/donnees.txt",FILE_READ);
    
    if(!fichier) 
    {
        Serial.println(F("Impossible d'ouvrir le fichier"));
    }
    
    if(SD.exists("/donnees.txt")) 
    {
        Serial.println(F("Fichier toto.txt OK"));     
    } 
    else 
    {
        Serial.println(F("Fichier toto.txt introuvable"));
    }
    
    
    char tampon[80];
    char carlu;
    int indice=0;
    char *ptr;
    int cpt = 0;
    int zone;
    
    for(int nbZone = 0 ; nbZone < 4 ; nbZone++)
    {
        
        do {
            carlu=fichier.read();
            
            if(carlu!=-1)
            {
                tampon[indice++] = carlu;
            }
        }
        while(carlu!='\n');
        if(indice > 0)
          tampon[indice-1] = '\0';
        
        indice = 0;      
        ptr = strtok(tampon, " ");  
        while (ptr != NULL)
        {
            switch(cpt)
            {
            case 0:
                zone = atoi(ptr) -1;
                cpt++;
                break;
            case 1:
                seuilZoneMin[zone] = atoi(ptr);
                cpt++;
                break;
            case 2:
                seuilZoneMax[zone] = atoi(ptr);
                cpt = 0 ;
                break;  
            }
            ptr = strtok( NULL, " ");
        }
        
    }
    fichier.close();
}


int CyclesArrossage::ObtenirSeuilMax(int _zone)
{
  return seuilZoneMax[_zone] ;
}


int CyclesArrossage::ObtenirSeuilMin(int _zone)
{
  return seuilZoneMin[_zone] ;
}

  
