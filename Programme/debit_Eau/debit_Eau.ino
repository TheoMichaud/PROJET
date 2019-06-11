

volatile int NbTopsFan; //mesurer le front de montée du signal
int Calc;                               
const int YF85 = 34;    //Où placer le capteur
/*
vide tr/min ()     //Voici la fonction que l'interruption déclenche  
{ 
  NbTopsFan++;  //Cette fonction mesure les fronts de montée et de descente du signal envoyé par les capteurs à effet Hall
} 
*/
 // La méthode setup() se lance une fois, lorsque le programme démarre
void setup()//
{ 
  pinMode(YF85, OUTPUT); //initialiser la broche 2 numérique en tant qu'entrée
  Serial.begin(9600); // Voici la fonction setup (configuration) où le port série est initialisé,
  //attachInterrupt(0, rpm, RISING); //et l'interruption attachée

  NbTopsFan++;
} 



void loop()    
{
  NbTopsFan = 0;   // Configurer NbTops sur 0 prêt pour les calculs  sei();      //Activer les interruptions
  delay (1000);   //Attendre 1  seconde
  cli();      //Désactiver les interruptions
  Calc = (NbTopsFan * 60 / 7.5); //(Fréquence des impulsions x 60) / 7.5Q, = débit  en L/h 
  
  Serial.print (Calc, DEC); //Imprime les chiffres calculés ci-dessus
  Serial.println(" en L/h"); //Imprime "en L/h" et change de ligne
}
