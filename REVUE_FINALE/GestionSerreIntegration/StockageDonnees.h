/*
   To change this license header, choose License Headers in Project Properties.
   To change this template file, choose Tools | Templates
   and open the template in the editor.
*/

/*
   File:   StockageDonnees.h
   Author: kauve

   Created on 18 mars 2019, 11:12
*/

#ifndef STOCKAGEDONNEES_H
#define STOCKAGEDONNEES_H
#define ADRESSEIPSERVEUR

//Definition donnees wifi
#define IDWIFI "SNIR03"
#define MDPWIFI "totototo"

//Definition donnees serveur
#define IDSERVEUR "serreUtilisateur"
#define MDPSERVEUR "Touchard72"

#define IDSERRE 1
#define IDZONE 1

#define BROCHECS 5
#define NBMAXTAB 255

//#include "Capteur.h"
#include <WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <Ethernet.h>
#include "timer.h"

#include <Wire.h>
#include "RTClib.h"

#include <SPI.h>
#include <SD.h>

class StockageDonnees {
  public:
    StockageDonnees();

    virtual ~StockageDonnees();

    void EnvoyerDonneesBdd( MySQL_Connection conn);

    void EnregistrerDonneesFichierLocal(float temperature, float hygrometrie, float luminosite);

    String LireDonneesFichierLocal();

    void ControlerFichier();

    void ConnexionWifi();

    MySQL_Connection ConnexionServeur();

    void MemoriserIncidentPerteConnexion();

    void DefinirParametresCarte();

    void InsererDonneesMesuresInterieurSerre(float temperature, float hygrometrie, float luminosite);

    void InsererDonneesMesuresZone(float debitEau, float humiditeSol);

    void VerifierConnexionWifi();

    MySQL_Connection VerifierConnexionServeur(MySQL_Connection conn);

    void OuvrirFichierDonneesMeteorologiquesLecture();

    void OuvrirFichierDonneesMeteorologiquesEcriture();

    void OuvrirFichierSeuilEcriture();

    String RecupereDate();

    void VerifierDonneesFichierLocal();

    void MemoriserDonneesFichierLocal();

    MySQL_Connection GererPerteConnexion(float temperature, float hygrometrie, float luminosite, MySQL_Connection conn);

    String RecupererSeuilsVannes(MySQL_Connection conn);

    void EnregistrerDonneesZonesFichierLocal(float hygrometrie, float debitEau);

    void InsererDonneesMesuresLocalesInterieurSerre(String chaine);

    void EnvoyerDonneesLocalesBdd(MySQL_Connection connection);

    void EnregistrerDonneesSeuilsFichierLocal(String chaine);

    void OuvrirFichierZoneEcriture();
int i =0;
    WiFiClient client;
    boolean fermeture = false;
  private:
    int status ;
    RTC_DS3231 rtc;

    String requeteMesureInterieur = " ";
    String requeteMesureZone = " ";
    String requeteMesureLocaleInterieur = "";

    MySQL_Cursor* cursor;
    MySQL_Connection *conn;
    File fichier;
    File fichierZone;
    File fichierSeuils;
    DateTime now;
    Timer attentes;


    //Paramètres de la carte
    byte ESP32Mac [6]  = { 0xDE , 0xAD , 0xBE , 0xEF , 0xFE , 0xED };
    IPAddress ESP32Addr;

    //Informations du serveur
    IPAddress serverAddr; // Adresse IP du serveur raspberry pi
    char loginUtilisateurServeur[50] = IDSERVEUR;// login de l'utilisateur du serveur
    char mdpUtilisateurServeur[50] = MDPSERVEUR;// mdp de l'utilisateur du serveur

    // Informations Wifi
    char loginWIFI[50] = IDWIFI;         //  login SSID
    char mdpWIFI[50] = MDPWIFI;     //  mot de passe SSID
    
};

#endif /* STOCKAGEDONNEES_H */
