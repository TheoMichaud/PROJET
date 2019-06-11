#include <SPI.h>
#include <SD.h> 

#define BROCHE 5

void setup() {
  pinMode(5, OUTPUT);
  Serial.begin(9600);
if (! SD.begin(BROCHE)){
  Serial.println(F("Erreur initialisation carte sd"));
} else{
   Serial.println(F("OK"));
/*
   File fichier = SD.open("/toto.txt",FILE_WRITE);
if(!fichier) {
// Erreur d'ouverture du fichier
  Serial.println(F("Impossible d'ouvrir le fichier"));
*/
}

}


void loop() {


}
