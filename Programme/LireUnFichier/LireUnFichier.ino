#include <SPI.h> // Pour la communication SPI
#include <SD.h>  // Pour la communication avec la carte SD

File mesDonnees;


/* Broche CS de la carte SD */
const byte SDCARD_CS_PIN = 5; // TODO A remplacer suivant votre shield SD


/** Fonction setup() */
void setup() {

  /* Initialisation du port série (debug) */
  Serial.begin(9600);

  /* Initialisation du port SPI */
  pinMode(5, OUTPUT); // Arduino UNO

  /* Initialisation de la carte SD */
  Serial.print(F("Init SD card... "));
  if (!SD.begin(SDCARD_CS_PIN)) {
    Serial.println(F("FAIL"));
  }else{
      Serial.println(F("OK"));
      mesDonnees = SD.open("toto.txt", FILE_READ);
          if (mesDonnees) {
              Serial.println("test.txt:");
          while (mesDonnees.available()) {
              Serial.print(mesDonnees.read());
         }
             mesDonnees.close();
         } else {
             Serial.println("error opening test.txt");
        }

  }

  
  
}


/** Fonction loop() */
void loop() {
  



}
