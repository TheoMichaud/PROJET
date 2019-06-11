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


  // mettre initialisation tableau fixe si pas de carte SD

      
     
  
  
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
      
    
    File fichier = SD.open("/seuils.txt",FILE_READ);
    
    if(!fichier) 
    {
        Serial.println(F("Impossible d'ouvrir le fichier"));

    }
    
    if(SD.exists("/seuils.txt")) 
    {
        Serial.println(F("Fichier seuils.txt OK"));     
    } 
    else 
    {
        Serial.println(F("Fichier seuils.txt introuvable"));
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





void CyclesArrossage::LireCarteSDModeProg()
{
    if(!valeurDefaut)
    {
      
    
    
    
    if(SD.exists("/modeProgramme.txt")) 
    {
        Serial.println(F("Fichier modeProgramme.txt OK"));     
    } 
    else 
    {
        Serial.println(F("Fichier modeProgramme.txt introuvable"));
    }
    
    File fichier = SD.open("/modeProgramme.txt",FILE_READ);
    
    if(!fichier) 
    {
        Serial.println(F("Impossible d'ouvrir le fichier"));

    }
    
    char tampon[80];
    char carlu;
    int indice=0;
    char *ptr;
    int cpt = 0;
    int zone;
    String date2;
    String heure;
    
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
        Serial.print("tampon : ");
        Serial.println(tampon);
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
                ConvertirDate(ptr,&dateDepart[zone]);
                cpt++;
                break;
            case 2:
                ConvertirHeure(ptr,&heureDepart[zone]);
                cpt++;
                break;
            case 3:
                periodicite[zone] = atoi(ptr);
                cpt++ ;
                break; 
            case 4:
                duree[zone] = atoi(ptr);
                cpt = 0 ;
                break; 
            }
            ptr = strtok( NULL, " ");
        }
        
    }
    fichier.close();
    }
}


void CyclesArrossage::ConvertirDate(String dateStr, Date *ladate)
{
    int parametres[3];
    size_t prec = 0;
    size_t pos =  0;
    for (int indice = 0;indice < 3;indice++)
    {
        pos = dateStr.indexOf('-',prec);
        parametres[indice] = atoi(dateStr.substring(prec,pos).c_str());
        prec = pos + 1; // on incrémente pos pour le tour d'après.
    }
    ladate-> annee = parametres[0];
    ladate-> jour = parametres[1];
    ladate-> mois = parametres[2];
}


void CyclesArrossage::ConvertirHeure(String heureStr,  Heure *heure)
{
    int parametres[3];
    size_t prec = 0;
    size_t pos =  0;
    for (int indice = 0;indice < 3;indice++)
    {
        pos = heureStr.indexOf(':',prec);
        parametres[indice] = atoi(heureStr.substring(prec,pos).c_str());
        prec = pos + 1; // on incrémente pos pour le tour d'après.
    }
    heure-> heure = parametres[0];
    heure-> minutes = parametres[1];
    heure-> secondes = parametres[2];
}



int CyclesArrossage::ObtenirDuree(int _zone)
{
  return duree[_zone] ;
}


int CyclesArrossage::ObtenirPeriode(int _zone)
{
  return periodicite[_zone] ;
}

Date CyclesArrossage::ObtenirDate(int _zone)
{
  return dateDepart[_zone] ;
}

Heure CyclesArrossage::ObtenirHeure(int _zone)
{
  return heureDepart[_zone] ;
}
