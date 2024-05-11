int outputPin = 2; 
int inputPin = 7;   
int pwmValue;       

const int numPins = 5;
int additionalPins[numPins] = {9, 10, 11, 12, 13}; 
int digitalValues[numPins]; 

void setup() {
 
  pinMode(outputPin, OUTPUT);

  pinMode(inputPin, INPUT);
  Serial.begin(2000000);

  for(int i = 0; i < numPins; i++) {
    pinMode(additionalPins[i], INPUT);
    digitalWrite(additionalPins[i], LOW); 
  }
}

void loop() {
 pwmValue = digitalRead(inputPin) * 5; 
  Serial.print(pwmValue); 

  for (int i = 0; i < numPins; i++) {
    digitalValues[i] = digitalRead(additionalPins[i]) * 5; 
    Serial.print(",");
    Serial.print(digitalValues[i]);
  }

  Serial.println(); 
  delay(1);
}
