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

  valeurDefaut = false;

  if (! SD.begin(brocheCarteSD)){
  Serial.println(F("Erreur initialisation carte sd"));
  // mettre initialisation tableau fixe si pas de carte SD
      seuilZoneMin[0]=20;
      seuilZoneMin[1]=25;
      seuilZoneMin[2]=30;
      seuilZoneMin[3]=35;
      seuilZoneMax[0]=60;
      seuilZoneMax[1]=85;
      seuilZoneMax[2]=80;
      seuilZoneMax[3]=75;

   valeurDefaut = true;
 
} else{
   Serial.println(F("initialisation carte sd OK"));
    for(int i=0;i<4;i++)
    { 
      seuilZoneMin[i]=0;
      seuilZoneMax[i]=0;
    }
}

}

void CyclesArrossage::LireCarteSD()
{
    if(!valeurDefaut)
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
}


int CyclesArrossage::ObtenirSeuilMax(int _zone)
{
  return seuilZoneMax[_zone] ;
}

int CyclesArrossage::ObtenirSeuilMin(int _zone)
{
  return seuilZoneMin[_zone] ;
} 
