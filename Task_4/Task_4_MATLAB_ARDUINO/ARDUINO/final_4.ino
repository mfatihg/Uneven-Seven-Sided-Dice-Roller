const int numPins = 12;
int additionalPins[numPins] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; 
int digitalValues[numPins]; 


const int highFreqPin = 2; 

void setup() {
    Serial.begin(2000000); 
    for(int i = 0; i < numPins; i++) {
        pinMode(additionalPins[i], INPUT);
    }
}

void loop() {
    
    Serial.print(highFreqValue);
    Serial.print(",");

    for (int i = 1; i < numPins; i++) { 
        digitalValues[i] = digitalRead(additionalPins[i]) * 5; 
        Serial.print(digitalValues[i]);
        if (i < numPins - 1) {
            Serial.print(",");
        }
    }

    Serial.println(); 
    delay(00000001); 
}
