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
} else{
   Serial.println(F("initialisation carte sd OK"));
}

}





void CyclesArrossage::LireCarteSD()
{


File fichier = SD.open("/donnees.txt",FILE_READ);

if(!fichier) {
  Serial.println(F("Impossible d'ouvrir le fichier"));
}

if(SD.exists("/donnees.txt")) {
  Serial.println(F("Fichier toto.txt OK"));
} else {
  Serial.println(F("Fichier toto.txt introuvable"));
}

/*
for(int i=0;i<5;i++){                 
Serial.write(fichier.read());
 strcpy(fichier.read(),SeuilZone[i][j]);
}*/
//char tampon[80];
String tampon;
char carlu;
int indice=0;

do {
  carlu=fichier.read();
  
  if(carlu!=-1)
  {
    //tampon[indice++]=carlu;
    tampon += carlu;
    //Serial.println(tampon);
    Serial.println(carlu);
  }
}
while(carlu!='\n');
//tampon[indice] = '\0';
//Serial.println(carlu);
//Serial.println(tampon);



fichier.close();
}


int ObtenirSeuilMax()
{
  
}


int ObtenirSeuilMin()
{

  
}

  
