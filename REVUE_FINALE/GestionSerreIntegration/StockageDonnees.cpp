/*
   File:   StockageDonnees.cpp
   Author: kauve

   Created on 18 mars 2019, 11:12
*/

#include "StockageDonnees.h"

StockageDonnees::StockageDonnees() {
  serverAddr = IPAddress(172, 18, 58, 213);
  ESP32Addr = IPAddress( 172, 18, 58, 248);
}

StockageDonnees::~StockageDonnees() {

}

/**
   @brief StockageDonnees::DefinirParametresCarte
   @details Permet de définir les adresses ip et mac de la carte
*/
void StockageDonnees::DefinirParametresCarte() {
  //definit l'adresse mac et ip de l'objet connecté
  Ethernet.begin(ESP32Mac, ESP32Addr);

}

/**
   @brief StockageDonnees::ConnexionWifi
   @details Permet de se connecter à un réseau wifi
*/
void  StockageDonnees::ConnexionWifi() {

  while (!Serial);

  //Serial.printf("\nConnexion à %s", loginWIFI);
  status = WiFi.begin(loginWIFI, mdpWIFI);

  if (status == WL_CONNECTED) {
    Serial.printf("Connecté au réseau %s. \n", loginWIFI);
  } else {

    Serial.printf("Pas de connexion au réseau %s. \n", loginWIFI);
    WiFi.begin(loginWIFI, mdpWIFI);
  }
}

/**
   @brief StockageDonnees::VerifierConnexionWifi
   @details Permet de vérifier si l'ESP32 est toujours connecté au wifi
*/
void StockageDonnees::VerifierConnexionWifi() {
  if (status != WL_CONNECTED) {
    // Serial.printf("Pas de connection au réseau %s. \n", loginWIFI);
    WiFi.begin(loginWIFI, mdpWIFI);
  } else {
    Serial.printf("Connecté au réseau %s. \n", loginWIFI);
  }
}

/**
   @brief StockageDonnees::ConnexionServeur
   @details Permet de se connecter au serveur ou se trouve la base de données
   @return conn
*/
MySQL_Connection  StockageDonnees::ConnexionServeur() {

  MySQL_Connection conn(&client);

  Serial.print("Connexion à la base de données...  ");
  //Permet de se connecter au serveur
  if (conn.connect(serverAddr, 3306, loginUtilisateurServeur, mdpUtilisateurServeur)) {
    Serial.println("CONNEXION SERVEUR ETABLI");
  }
  else {
    Serial.println("ECHEC CONNEXION SERVEUR");
  }
  return conn;
}

/**
   @brief StockageDonnees::VerifierConnexionServeur
   @param conn
   @details Permet de se vérifier si l'ESP32 est toujours connecté au serveur
*/
MySQL_Connection StockageDonnees::VerifierConnexionServeur(MySQL_Connection conn2) {
  //permet de vérifier si la connection est toujours établie
  if (conn2.connected()) {
    Serial.println("Connecté au SERVEUR");
  } else {
    // si ce n'est pas le cas, on va se reconnecter au serveur
    VerifierConnexionWifi();
    Serial.println("Plus de connexion au serveur");
    conn2.close();
    if (conn2.connect(serverAddr, 3306, loginUtilisateurServeur, mdpUtilisateurServeur)) {
      Serial.println("Connecté au serveur");
      //Permet de fermer le fichier local car la connexion est revenue
      fermeture = true;
    }
  }
  return conn2;
}

/**
   @brief StockageDonnees::InsertionDonneesRequete
   @param temperature
   @param hygrometrie
   @param luminosite
   @details Permet d'insérer les données météorologiques dans la requête sql
*/
void StockageDonnees::InsererDonneesMesuresInterieurSerre(float temperature, float hygrometrie, float luminosite) {

  String chaineTemperature, chaineHygrometrie, chaineLuminosite, date;
  //convertit les données météorologique(float) en une chaine de caractère
  chaineTemperature = String(temperature);

  chaineHygrometrie = String(hygrometrie);

  chaineLuminosite = String(luminosite);

  date = RecupereDate();
  //insere les données dans la requete SQL
  requeteMesureInterieur = "INSERT INTO laSerre.MesuresSerreInterieur(temperatureInterieur,hygrometrieInterieur,luminositeInterieur,DateMesureInterieur,idSerre,idZone) VALUES (" + chaineTemperature + "," + chaineHygrometrie + "," + chaineLuminosite + ",'" + date + "' ," + IDSERRE + ",1)";
  Serial.println(requeteMesureInterieur);
}

/**
   @brief StockageDonnees::InsererDonneesMesuresZone
   @param debitEau
   @param humiditeSol
   @details Permet d'insérer dans la requête SQL les données de débit d'eau, d'humidité
*/
void StockageDonnees::InsererDonneesMesuresZone(float debitEau, float humiditeSol) {

  String chainedebitEau, chainehumiditeSol, date;
  //convertit les données liées aux vannes(float) en une chaine de caractère
  chainedebitEau = String(debitEau);

  chainehumiditeSol = String(humiditeSol);

  date = RecupereDate();
  //insere les données dans la requete SQL
  requeteMesureZone = "INSERT INTO laSerre.MesuresZone(debitEau,humiditeSol,dateMesure,idZone) VALUES (" + chainedebitEau + "," + chainehumiditeSol + ",'" + date + "' ," + IDZONE + ")";
  Serial.println(requeteMesureZone);
}

/**
   @brief StockageDonnees::EnvoyerDonneesFichierLocalBdd
   @param conn
   @details Permet d'envoyer les données à la base
*/
void StockageDonnees::EnvoyerDonneesBdd(MySQL_Connection conn) {

  char INSERT_MESUREINTERIEUR[255];
  char INSERT_MESUREZONE[255];

  // creation du curseur mySQL
  cursor = new MySQL_Cursor(&conn);
  Serial.print("Connecté à la base de données");
  //convertit les chaine de caractère en tableau de caractère
  requeteMesureInterieur.toCharArray(INSERT_MESUREINTERIEUR, 255);
  requeteMesureZone.toCharArray(INSERT_MESUREZONE, 255);

  if (conn.connected()) {
    cursor->execute(INSERT_MESUREINTERIEUR);
    cursor->execute(INSERT_MESUREZONE);
  }
}

/**
   @brief StockageDonnees::OuvrirFichierDonneesMeteorologiquesLecture
   @details Permet d'ouvrir en lecture le fichier des donnees meteorologiques
*/
void StockageDonnees::OuvrirFichierDonneesMeteorologiquesLecture() {
  pinMode(5, OUTPUT);

  if (! SD.begin(BROCHECS)) {
    Serial.println(F("Erreur initialisation carte sd"));
  } else {
    Serial.println(F("OK"));
  }

  fichier = SD.open("/donnees.txt", FILE_READ);

  if (!fichier) {
    // Erreur d'ouverture du fichier
    Serial.println(F("Impossible d'ouvrir le fichier"));
  }

  if (SD.exists("/donnees.txt")) {
    Serial.println(F("Fichier donnee.txt OK"));
  } else {
    Serial.println(F("Fichier donnee.txt introuvable"));
  }
}

/**
   @brief StockageDonnees::OuvrirFichierDonneesMeteorologiquesEcriture
   @details Permet d'ouvrir en écriture le fichier des donnees meteorologiques
*/
void StockageDonnees::OuvrirFichierDonneesMeteorologiquesEcriture() {
  pinMode(5, OUTPUT);

  if (! SD.begin(BROCHECS)) {
    Serial.println(F("Erreur initialisation carte sd"));
  } else {
    Serial.println(F("OK"));
  }

  fichier = SD.open("/donnees.txt", FILE_WRITE);

  if (!fichier) {
    // Erreur d'ouverture du fichier
    Serial.println(F("Impossible d'ouvrir le fichier"));
  }

  if (SD.exists("/donnees.txt")) {
    Serial.println(F("Fichier donnee.txt OK"));
  } else {
    Serial.println(F("Fichier donnee.txt introuvable"));
  }
}

/**
   @brief StockageDonnees::OuvrirFichierZoneEcriture
   @details Permet d'ouvrir le fichier de données des zones en écriture
*/
void StockageDonnees::OuvrirFichierZoneEcriture() {
  pinMode(5, OUTPUT);

  if (! SD.begin(BROCHECS)) {
    Serial.println(F("Erreur initialisation carte sd"));
  } else {
    Serial.println(F("OK"));
  }

  fichierZone = SD.open("/zones.txt", FILE_WRITE);

  if (!fichierZone) {
    // Erreur d'ouverture du fichier
    Serial.println(F("Impossible d'ouvrir le fichier"));
  }

  if (SD.exists("/zones.txt")) {
    Serial.println(F("Fichier zones.txt OK"));
  } else {
    Serial.println(F("Fichier zones.txt introuvable"));
  }
}


/**
   @brief StockageDonnees::OuvrirFichierSeuilEcriture
   @details Permet d'ouvrir le fichier de données des seuils en écriture
*/
void StockageDonnees::OuvrirFichierSeuilEcriture() {
  pinMode(5, OUTPUT);

  if (! SD.begin(BROCHECS)) {
    Serial.println(F("Erreur initialisation carte sd"));
  } else {
    //Serial.println(F("OK"));
  }

  fichierSeuils = SD.open("/seuils.txt", FILE_WRITE);

  if (!fichierSeuils) {
    // Erreur d'ouverture du fichier
    Serial.println(F("Impossible d'ouvrir le fichier"));
  }

  if (SD.exists("/seuils.txt")) {
    Serial.println(F("Fichier zones.txt OK"));
  } else {
    Serial.println(F("Fichier zones.txt introuvable"));
  }
}

/**
   @brief StockageDonnees::EnregistrerDonneesFichierLocal
   @param temperature
   @param hygrometrie
   @param luminosite
   @details Permet d'enregistrer les données dans un fichier sur la carte SD
*/
void StockageDonnees::EnregistrerDonneesFichierLocal(float temperature, float hygrometrie, float luminosite) {
  //Permet d'ouvrir le fichier en écriture si il n'est pas deja ouvert
  if (fichier == false) {
    OuvrirFichierDonneesMeteorologiquesEcriture();
    Serial.println("OUVERTURE DU FICHIER DES DONNEES METEOROLOGIQUES");
  }

  String chaine, dates;

  dates = RecupereDate();
  chaine += temperature;
  chaine += ",";
  chaine += hygrometrie;
  chaine += ",";
  chaine += luminosite;
  chaine += ",'";
  chaine += dates;
  chaine += "'";
  Serial.println(chaine);

  fichier.println(chaine);
  /*
    if (fermeture == true) {
      Serial.println("FERMETURE");
      fichier.close();
    }*/
}

/**
   @brief StockageDonnees::RecupereDate
   @details Permet de récupérer la date
   @return une chaine de caractère contenant la date
*/
String StockageDonnees::RecupereDate() {
  now = rtc.now();
  String annee, mois, jour, heure, minute, seconde;

  annee = String(now.year());
  mois = String(now.month());
  jour = String(now.day());
  heure = String(now.hour());
  minute = String(now.minute());
  seconde = String(now.second());
  String date;
  date = annee + "-" + mois + "-" + jour + " " + heure + ":" + minute + ":" + seconde;

  return date;
}

/**
   @brief StockageDonnees::LireDonneesFichierLocal
   @details Permet de lire les données présentes dans le fichier local
   @return String
*/
String StockageDonnees::LireDonneesFichierLocal() {

  if (fichier == false) {
    //permet d'ouvrir le fichier en lecture
    OuvrirFichierDonneesMeteorologiquesLecture();
    Serial.println("OUVERTURE DU FICHIER DES DONNEES METEOROLOGIQUES");
  }


  String tampon;
  char carlu;

  if (fichier.read() != -1) {
    do {
      carlu = fichier.read();

      if (carlu != -1)
      {
        tampon += carlu;
      }

      i++;
    }
    while (carlu != '\n');
    Serial.println(tampon);
  } else {
    Serial.println("FICHIER VIDE!");
    tampon = "";
  }

  return tampon;

}

/**
   @brief StockageDonnees::GererPerteConnexion
   @param temperature
   @param hygrometrie
   @param luminosite
   @param conn
   @details Permet de gerer les donnees en cas de perte de connexion avec la base de donnees
*/
MySQL_Connection StockageDonnees::GererPerteConnexion(float temperature, float hygrometrie, float luminosite, MySQL_Connection connection) {
  String chaine;

  VerifierConnexionWifi();
  connection = VerifierConnexionServeur(connection);

  if (!connection.connected()) {
    Serial.println("ENREGISTREMENT DONNEES FICHIER LOCAL");
    EnregistrerDonneesFichierLocal(temperature, hygrometrie, luminosite);

  } else {
    Serial.println("Enregistrement des seuils");
    chaine = RecupererSeuilsVannes(connection);
    Serial.println(chaine);
    EnregistrerDonneesSeuilsFichierLocal(chaine);

    Serial.println("Lecture du fichier local");
    if (fermeture == true) {
      Serial.println("FERMETURE FICHIER DONNEES METEOROLOGIQUES");
      fichier.close();
    }

    /*  Serial.println("Enregistrement données fichier local");
      EnregistrerDonneesFichierLocal(temperature, hygrometrie, luminosite);

      if (i >= 5) {
        fichier.close();
        Serial.println("FERMETURE FICHIER DONNEES METEOROLOGIQUES");
      }*/
    do {
      chaine = LireDonneesFichierLocal();
      Serial.println(chaine);
      InsererDonneesMesuresLocalesInterieurSerre(chaine);
      EnvoyerDonneesLocalesBdd(connection);
      delay(5000);
    } while (chaine != "");

    if(chaine ==""){
      OuvrirFichierDonneesMeteorologiquesEcriture();
      fichier.close();
    }

  }
  return connection;
}


/**
   @brief StockageDonnees::RecupererSeuilsVannes
   @param MySQL_Connection conn
   @details Permet de récupérer les seuils des vannes dans la base de données
   @return String
*/
String StockageDonnees::RecupererSeuilsVannes(MySQL_Connection conn) {

  const char QUERY_POP[] = "SELECT idZone, minHumidite,maxHumidite FROM laSerre.Zone WHERE idSerre =1 ";
  char query[128];
  String chaine;
  String tab[4];
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);

  sprintf(query, QUERY_POP, 9000000);
  // Execute the query
  cur_mem->execute(query);
  // Fetch the columns and print them
  column_names *cols = cur_mem->get_columns();
  for (int f = 0; f < cols->num_fields; f++) {
    //Serial.print(cols->fields[f]->name);
    if (f < cols->num_fields - 1) {
      // Serial.print(' ');
    }
  }
  Serial.println();
  // Read the rows and print them
  row_values *row = NULL;
  do {
    row = cur_mem->get_next_row();
    if (row != NULL) {
      for (int f = 0; f < cols->num_fields; f++) {
        // Serial.print(row->values[f]);
        chaine += (String)row->values[f];
        if (f < cols->num_fields - 1) {
          // Serial.print(' ');
          chaine += ' ';
        }
      }
      //Serial.println();
      chaine += "\n";
    }
  } while (row != NULL);
  // Deleting the cursor also frees up memory used
  delete cur_mem;
  return chaine;
}

/**
   @brief StockageDonnees::EnregistrerDonneesZonesFichierLocal
   @param hygrometrie
   @param debitEau
   @details Permet d'enregistrer l'humidité du sol et du débit d'eau dans le fichier
*/
void StockageDonnees::EnregistrerDonneesZonesFichierLocal(float humiditeDuSol, float debitEau) {

  //Permet d'ouvrir le fichier en écriture si il n'est pas deja ouvert
  if (fichierZone == false) {
    OuvrirFichierZoneEcriture();
    Serial.println("OUVERTURE DU FICHIER DES ZONES");
  }

  String chaine, dates;

  dates = RecupereDate();
  chaine += humiditeDuSol;
  chaine += ",";
  chaine += debitEau;
  chaine += ",'";
  chaine += dates;
  chaine += "'";
  Serial.println(chaine);

  fichierZone.println(chaine);
  if (fermeture == true) {
    Serial.println("FERMETURE DU FICHIER DES ZONES");
    fichierZone.close();
  }
}

/**
   @brief StockageDonnees::InsererDonneesMesuresLocalesInterieurSerre
   @param chaine
   @details Permet d'insérer les données du fichier local dans la requête SQL
*/
void StockageDonnees::InsererDonneesMesuresLocalesInterieurSerre(String chaine) {

  if (chaine != "") {
    //insere les données dans la requete SQL
    requeteMesureLocaleInterieur = "INSERT INTO laSerre.MesuresSerreInterieur(temperatureInterieur,hygrometrieInterieur,luminositeInterieur,DateMesureInterieur,idSerre,idZone) VALUES (" + chaine + "," + IDSERRE + ",1)";
    Serial.println(requeteMesureLocaleInterieur);
  }
}

/**
   @brief StockageDonnees::EnvoyerDonneesLocalesBdd
   @param conn
   @details Permet d'envoyer les données du fichier local dans la base de données
*/
void StockageDonnees::EnvoyerDonneesLocalesBdd(MySQL_Connection conn) {
  char INSERT_MESURELOCALE[255];

  // creation du curseur mySQL
  cursor = new MySQL_Cursor(&conn);

  //convertit les chaine de caractère en tableau de caractère
  requeteMesureLocaleInterieur.toCharArray(INSERT_MESURELOCALE, 255);

  if (conn.connected()) {
    Serial.print("Connecté à la base de données");
    //Permet d'envoyer les requetes SQL
    cursor->execute(INSERT_MESURELOCALE);
  }
}

/**
   @brief StockageDonnees::EnregistrerDonneesSeuilsFichierLocal
   @param chaine
   @details Permet d'enregistrer les seuils dans le fichier local
*/
void StockageDonnees::EnregistrerDonneesSeuilsFichierLocal(String chaine) {

  //Permet d'ouvrir le fichier en écriture si il n'est pas deja ouvert
  if (fichierSeuils == false) {
    OuvrirFichierSeuilEcriture();
    Serial.println("OUVERTURE DU FICHIER DES SEUILS");
  }

  fichierSeuils.println(chaine);

  Serial.println("FERMETURE DU FICHIER DES SEUILS");
  fichierSeuils.close();

}
