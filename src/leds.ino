/*
Connect one led to pin 7 and the second one on pin 8.
*/

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(7, HIGH); 
  digitalWrite(8, LOW);
  delay(50);                      
  digitalWrite(7, LOW); 
  digitalWrite(8, HIGH); 
  delay(50);                       
}
