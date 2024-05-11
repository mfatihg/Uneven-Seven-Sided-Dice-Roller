int pin = 2; 

void setup() {
  pinMode(pin, OUTPUT); 
  Serial.begin(9600); 
}

void loop() {
  tone(pin, 400); 

}
