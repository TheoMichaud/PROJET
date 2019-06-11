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

  status = WiFi.begin(loginWIFI, mdpWIFI);
  if (status == WL_CONNECTED) {
  } else {
    WiFi.begin(loginWIFI, mdpWIFI);
  }
}

/**
   @brief StockageDonnees::VerifierConnexionWifi
   @details Permet de vérifier si l'ESP32 est toujours connecté au wifi
*/
void StockageDonnees::VerifierConnexionWifi() {
  // attentes.Lancer(5000);
  // if (attentes.Scruter())
  // {
  if (status != WL_CONNECTED) {
    WiFi.begin(loginWIFI, mdpWIFI);
  } else {
  }
}
//}

/**
   @brief StockageDonnees::ConnexionServeur
   @details Permet de se connecter au serveur ou se trouve la base de données
   @return conn
*/
MySQL_Connection  StockageDonnees::ConnexionServeur() {

  MySQL_Connection conn(&client);

   //Permet de se connecter au serveur
  if (conn.connect(serverAddr, 3306, loginUtilisateurServeur, mdpUtilisateurServeur)) {
  }
  else {
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
  } else {
    // si ce n'est pas le cas, on va se reconnecter au serveur
    VerifierConnexionWifi();
    conn2.close();
    if (conn2.connect(serverAddr, 3306, loginUtilisateurServeur, mdpUtilisateurServeur)) {
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
}

/**
   @brief StockageDonnees::EnvoyerDonneesFichierLocalBdd
   @param conn
   @details Permet d'envoyer les données à la base
*/
void StockageDonnees::EnvoyerDonneesBdd(MySQL_Connection conn) {

  char INSERT_MESUREINTERIEUR[NBMAXTAB];
  char INSERT_MESUREZONE[NBMAXTAB];

  // creation du curseur mySQL
  cursor = new MySQL_Cursor(&conn);
  //convertit les chaine de caractère en tableau de caractère
  requeteMesureInterieur.toCharArray(INSERT_MESUREINTERIEUR, NBMAXTAB);
  requeteMesureZone.toCharArray(INSERT_MESUREZONE, NBMAXTAB);

  if (conn.connected()) {
    //Permet d'envoyer les requetes SQL
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

  fichier = SD.open("/donnees.txt", FILE_READ);

}

/**
   @brief StockageDonnees::OuvrirFichierDonneesMeteorologiquesEcriture
   @details Permet d'ouvrir en écriture le fichier des donnees meteorologiques
*/
void StockageDonnees::OuvrirFichierDonneesMeteorologiquesEcriture() {
  pinMode(5, OUTPUT);

  fichier = SD.open("/donnees.txt", FILE_WRITE);
}

/**
   @brief StockageDonnees::OuvrirFichierZoneEcriture
   @details Permet d'ouvrir le fichier de données des zones en écriture
*/
void StockageDonnees::OuvrirFichierZoneEcriture() {
  pinMode(5, OUTPUT);

  fichierZone = SD.open("/zones.txt", FILE_WRITE);

 
}


/**
   @brief StockageDonnees::OuvrirFichierSeuilEcriture
   @details Permet d'ouvrir le fichier de données des seuils en écriture
*/
void StockageDonnees::OuvrirFichierSeuilEcriture() {
  pinMode(5, OUTPUT);

  fichierSeuils = SD.open("/seuils.txt", FILE_WRITE);
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

  fichier.println(chaine);

  if (fermeture == true) {
    fichier.close();
  }
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
  } else {
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
    EnregistrerDonneesFichierLocal(temperature, hygrometrie, luminosite);

  } else {

    if (fermeture == true) {
      fichier.close();
    }

    do {
      chaine = LireDonneesFichierLocal();
      InsererDonneesMesuresLocalesInterieurSerre(chaine);
      //Problème pour envoyer les données
      connection = EnvoyerDonneesLocalesBdd(connection);
      delay(5000);
    } while (chaine != "");

    if (chaine == "") {
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
  char query[NBMAXTAB];
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
  }

  String chaine, dates;

  dates = RecupereDate();
  chaine += humiditeDuSol;
  chaine += ",";
  chaine += debitEau;
  chaine += ",'";
  chaine += dates;
  chaine += "'";

  fichierZone.println(chaine);
  if (fermeture == true) {
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
   // Serial.println(requeteMesureLocaleInterieur);
  }
}

/**
   @brief StockageDonnees::EnvoyerDonneesLocalesBdd
   @param conn
   @details Permet d'envoyer les données du fichier local dans la base de données
*/
MySQL_Connection StockageDonnees::EnvoyerDonneesLocalesBdd(MySQL_Connection conn) {
  char INSERT_MESURELOCALE[NBMAXTAB];

  // creation du curseur mySQL
  cursor = new MySQL_Cursor(&conn);

  //convertit les chaine de caractère en tableau de caractère
  requeteMesureLocaleInterieur.toCharArray(INSERT_MESURELOCALE, NBMAXTAB);

  if (conn.connected()) {
    //Permet d'envoyer les requetes SQL
    cursor->execute(INSERT_MESURELOCALE);
  }
  return conn;
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
  }

  fichierSeuils.println(chaine);
  fichierSeuils.close();

}

String StockageDonnees::RecupererModeProgramme(MySQL_Connection conn) {

  const char QUERY_POP[] = "SELECT modeArrosage, heureOuverture,periodiciteArrosage FROM laSerre.Zone WHERE idSerre =1 ";
  char query[NBMAXTAB];
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
   @brief StockageDonnees::EnregistrerDonneesSeuilsFichierLocal
   @param chaine
   @details Permet d'enregistrer les seuils dans le fichier local
*/
void StockageDonnees::EnregistrerDonneesRecupererModeProgrammeFichierLocal(String chaine) {

  //Permet d'ouvrir le fichier en écriture si il n'est pas deja ouvert
  if (fichierModeProgramme == false) {
    OuvrirFichierModeProgramme();
  }

  fichierModeProgramme.println(chaine);

  fichierModeProgramme.close();

}

/**
   @brief StockageDonnees::OuvrirFichierSeuilEcriture
   @details Permet d'ouvrir le fichier de données des seuils en écriture
*/
void StockageDonnees::OuvrirFichierModeProgramme() {
  pinMode(5, OUTPUT);

  fichierSeuils = SD.open("/modeProgramme.txt", FILE_WRITE);
  
}
