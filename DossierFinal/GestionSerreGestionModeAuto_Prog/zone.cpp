/**
  * @author Michaud théo
  * @date   Vendredi 10 avril 2019
  * @file   zone.cpp
  */


#include "zone.h"
#include <Arduino.h>

#include "humidite.h"



/**
 * @brief Zone::Zone
 * @param int nbZone permet de connaitre le nom de la zone
 * @param gpio_num_t _commandeVanne c'est la broche de la vanne à gérer
 * @param gpio_num_t _brocheHumidite, c'est la broche du capteur d'humidité
 * @details Constructeur de la classe.
 */

Zone::Zone(int nbZone, gpio_num_t _commandeVanne, gpio_num_t _brocheHumidite, CyclesArrossage *_cycles):
numZone(nbZone),
laVanne(_commandeVanne),
leCapteur(_brocheHumidite),
cycles(_cycles)
{
  seuilMin = cycles->ObtenirSeuilMin(numZone-1);
  seuilMax = cycles->ObtenirSeuilMax(numZone-1);
  Serial.print(seuilMin);
  Serial.print(" - ");
  Serial.println(seuilMax);

  duree = cycles->ObtenirDuree(numZone-1);
  periode = cycles->ObtenirPeriode(numZone-1);
  date = cycles->ObtenirDate(numZone-1);
  heureDep = cycles->ObtenirHeure(numZone -1);
  Serial.print("duree : ");
  Serial.print(duree);
  Serial.print(" - période : ");
  Serial.print(periode);
  Serial.print(" - date : ");
  Serial.print(date.jour);
  Serial.print("/");
  Serial.print(date.mois);
  Serial.print("/");
  Serial.print(date.annee);
  Serial.print(" - heure : ");
  Serial.print(heureDep.heure);
  Serial.print("::");
  Serial.print(heureDep.minutes);
  Serial.print("::");
  Serial.println(heureDep.secondes);

  etatZone = ATTENTE; 
  
}

/**
 * @brief Zone::~Zone
 * @details Déstructeur de la classe.
 */
Zone::~Zone(){
  
}

/**
 * @brief Zone::Controler
 * @param string _parametre, c'est la chaine que renvoie l'application lorsqu'une action est effectuée 
 * @details Si la chaine de caractère reçue commence par un m, alors on passe en mode manuel et l'ouverture ou la fermeture dependera du caractère suivant.
 * @details Si elle commence par un p on passe en mode programmé et si elle commence par un a alors on passe en mode auto.
 */
 
int Zone::Controler(String _parametre, DateTime now)
{

  char parametre = _parametre.charAt(0);

switch (parametre)
   {
      case 'm':
        etatMode = MODE_MANUEL;
      
        timerHumidite.Arreter();
        Serial.print("Mode Manuel ");
        Serial.print("zone ");
        Serial.println(numZone);
              
        if(_parametre.charAt(1) == 'o')
        {
          Serial.println("Ouverture Vanne");
          laVanne.Controler('O');
        }
           
        if(_parametre.charAt(1) == 'f') 
        {
          Serial.println("Fermeture Vanne");
          laVanne.Controler('F');
        }
           
       
        break;

      case 'p':
        etatMode = MODE_PROGRAMME;
      
        timerHumidite.Arreter();
        Serial.print("Mode Programmé ");
        Serial.print("zone ");
        Serial.println(numZone);
        timerTemps.Lancer(0,0,30);
        etatZone = ATTENTE;
        
        
        

        
        break;

      case 'a':
        etatMode = MODE_AUTOMATIQUE;
      
        Serial.print("Mode Automatique ");
        Serial.print("zone ");
        Serial.println(numZone);
        timerHumidite.Lancer(0,0,10);

        
        
        
        
          
          
        break;
      default:

         switch (etatMode)
         {
          case MODE_AUTOMATIQUE:
              if(timerHumidite.Scruter())
              {
                  mesureHumidite = leCapteur.PreleverHumidite();
                    if((mesureHumidite<= seuilMin) && (etatZone == ATTENTE))
                    {
                        Serial.println("Ouverture Vanne");
                        laVanne.Controler('O');
                        etatZone = ARROSAGE;
                        
                    }
              if((mesureHumidite >= seuilMax) && (etatZone == ARROSAGE ))
              {
                  Serial.println("Fermeture Vanne");
                  laVanne.Controler('F');
                  etatZone = ATTENTE;
              }
              }
           break;

            case MODE_PROGRAMME:
              if(etatZone == ATTENTE)
              {
                if(timerTemps.Scruter())
                {
                 /* Serial.print(" - date : ");
                  Serial.print(date.jour);
                  Serial.print("/");
                  Serial.print(date.mois);
                  Serial.print("/");
                  Serial.print(date.annee);
                  Serial.print(" - heure : ");
                  Serial.print(heureDep.heure);
                  Serial.print("::");
                  Serial.print(heureDep.minutes);
                  Serial.print("::");
                  Serial.println(heureDep.secondes);
                  
                  Serial.print(" - date : ");
                  Serial.print(now.day());
                  Serial.print("/");
                  Serial.print(now.month());
                  Serial.print("/");
                  Serial.print(now.year());
                  Serial.print(" - heure : ");
                  Serial.print(now.hour());
                  Serial.print("::");
                  Serial.print(now.minute());
                  Serial.print("::");
                  Serial.println(now.second());*/
                  
                }
                
                 if((date.annee == now.year()) && (date.mois == now.month()) && (date.jour == now.day()))
                 {
                  
                    if((heureDep.heure == now.hour()) && (heureDep.minutes == now.minute()))
                    {
                      Serial.println("Ouvrir Vanne");
                      laVanne.Controler('O');
                      etatZone = ARROSAGE;
                      timerTemps.Lancer(0,0,duree);       // pour le test durée en seconde
                    }
                  }
              }
              if(etatZone == ARROSAGE)
              {
                if(timerTemps.Scruter())
                {                  
                Serial.println("Fermer Vanne");
                laVanne.Controler('F');
                etatZone = REPOS;
                timerTemps.Arreter();
                timerTemps.Lancer(0,0,periode);           // pour le test periode en seconde
                }
              }
              
              if(etatZone == REPOS)
              {
                if(timerTemps.Scruter())
                {                  
                Serial.println("Ouvrir Vanne");
                laVanne.Controler('O');
                etatZone = ARROSAGE;
                timerTemps.Arreter();
                timerTemps.Lancer(0,0,duree);             // pour le test durée en seconde
                }
              }              
           break;
           
          default:    
          break;
         }
      break;  
   }

   laVanne.Controler('X');
  


  }
    
