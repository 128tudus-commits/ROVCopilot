const int E1A = 2;
const int E1B = 3;
const int E2A = 4;
const int E2B = 5;
const int E3A = 6;
const int E3B = 7;
const int E4A = 8;
const int E4B = 9;

const float threshold = 0.2; 

unsigned long lastCommunicationTime = 0;
const unsigned long timeoutDuration = 1000;

void setup() {
  Serial.begin(115200); 
  
  pinMode(E1A, OUTPUT);
  pinMode(E1B, OUTPUT);
  pinMode(E2A, OUTPUT);
  pinMode(E2B, OUTPUT);
  pinMode(E3A, OUTPUT);
  pinMode(E3B, OUTPUT);
  pinMode(E4A, OUTPUT);
  pinMode(E4B, OUTPUT);
  
  lastCommunicationTime = millis();
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    data.trim();
    
    int firstSemi = data.indexOf(';');
    int secondSemi = data.indexOf(';', firstSemi + 1);
    int thirdSemi = data.indexOf(';', secondSemi + 1);
    
    if (firstSemi != -1 && secondSemi != -1 && thirdSemi != -1) {
      float val1 = data.substring(0, firstSemi).toFloat();
      float val2 = data.substring(firstSemi + 1, secondSemi).toFloat();
      float val3 = data.substring(secondSemi + 1, thirdSemi).toFloat();
      float val4 = data.substring(thirdSemi + 1).toFloat();
      
      controlMotor(E1A, E1B, val1);
      controlMotor(E2A, E2B, val2);
      controlMotor(E3A, E3B, val3);
      controlMotor(E4A, E4B, val4);
      
      lastCommunicationTime = millis();
    }
  }

  if (millis() - lastCommunicationTime > timeoutDuration) {
    stopAllMotors();
  }
}

void controlMotor(int pinA, int pinB, float value) {
  if (value > threshold) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
  } 
  else if (value < -threshold) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
  } 
  else {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
  }
}

void stopAllMotors() {
  digitalWrite(E1A, LOW);
  digitalWrite(E1B, LOW);
  digitalWrite(E2A, LOW);
  digitalWrite(E2B, LOW);
  digitalWrite(E3A, LOW);
  digitalWrite(E3B, LOW);
  digitalWrite(E4A, LOW);
  digitalWrite(E4B, LOW);
}
