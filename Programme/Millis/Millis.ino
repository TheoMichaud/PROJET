
unsigned long times;

void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.print("Time: ");
  times = millis();

  Serial.println(times); //prints time since program started
  delay(1000);          // wait a second so as not to send massive amounts of data
}
