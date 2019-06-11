// Ardwinner Moteur DC-003-L298N bidirectionnel.
// code Arduino pour contrôler un moteur continu à partir d'un module L298N et de le faire tourner dans un sens pendant 5 secondes, puis l'arrête pendant 2 secondes, et le fait 
// repartir dans l'autre sens pendant 5 secondes ; le tout à une vitesse de 200 sur 255.

void setup() {              // Void Setup ------------------------------------------------------------------------------------------------------------------------------------------
  //pinMode(enA, OUTPUT);         // indique que la broche de la variable "enA" donc ici la PIN 10, est une sortie.
 // pinMode(in1, OUTPUT);         // indique que la broche de la variable "in1" donc ici la PIN 9, est une sortie.
 // pinMode(in2, OUTPUT);         // indique que la broche de la variable "in2" donc ici la PIN 8, est une sortie.

  gpio_set_direction(GPIO_NUM_36, GPIO_MODE_OUTPUT);  // enA
  gpio_set_direction(GPIO_NUM_39, GPIO_MODE_OUTPUT);  // in1
  gpio_set_direction(GPIO_NUM_34, GPIO_MODE_OUTPUT);   // in2
  
}


void loop() {               // Void Loop -------------------------------------------------------------------------------------------------------------------------------------------
  digitalWrite(GPIO_NUM_39,HIGH);      // envoie l'électricité dans la broche in1 (donc la PIN 9)ce qui fait donc tourner le moteur dans le sens de rotation de in1.
  digitalWrite(GPIO_NUM_34,LOW);       // en mettant la broche in2 à l'état bas, la carte n'injecte pas d'électricité, le moteur peut donc continuer à tourner dans le sens de in1.
  //analogWrite(GPIO_NUM_36,200);        // défini la vitesse du moteur, ici 200 sur un maximum de 255 (échélle comprise entre 0 et 255, car cela correspond à 8 bits soit 1 octet).
   delay(250);                 // créer un delais de 5 secondes, donc le moteur tourne pendant 5 secondes.



/*
  digitalWrite(in1,LOW);       // en mettant la broche in1 à l'état bas, la carte n'injecte pas d'électricité, le moteur est donc à l'arrêt.
  digitalWrite(in2,LOW);       // en mettant la broche in2 à l'état bas, la carte n'injecte pas d'électricité, le moteur est donc à l'arrêt.
  delay(2000);                 // créer un delais où le moteur ne tourne pas pendant 2 secondes. 
 
  digitalWrite(in1,LOW);       // met la broche in1 à l'état bas, la carte n'injecte pas d'électricité, le moteur ne tourne pas dans le sens de in1.
  digitalWrite(in2,HIGH);      // envoie l'électricité dans la broche in2 (donc la PIN 8)ce qui fait donc tourner le moteur dans le sens de rotation de in2.
  analogWrite(enA,200);        // défini la vitesse du moteur, ici 200 sur un maximum de 255 (échélle comprise entre 0 et 255, car cela correspond à 8 bits soit 1 octet).
  delay(5000);                 // créer un delais de 5 secondes, donc le moteur tourne pendant 5 secondes. 
*/
}
