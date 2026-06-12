// Arduino code
int M1;
int M2;
int M3;
int M4;
void Setup(){
Serial.begin(115200);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
}

void Loop(){


M1 = Serial.parseInt();
M2 = Serial.parseInt();
M3 = Serial.parseInt();
M4 = Serial.parseInt();


if (M1 > 0.1){
 digitalWrite(2, HIGH);
 digitalWrite(3, LOW);
}
else if (M1 < 0.1){
 digitalWrite(3, HIGH);
 digitalWrite(2, LOW);
}
else{
digitalWrite(2, LOW);
digitalWrite(3, LOW);
}
if (M2 > 0.1){
 digitalWrite(4, HIGH);
 digitalWrite(5, LOW);
}
else if (M2 < 0.1){
 digitalWrite(5, HIGH);
 digitalWrite(4, LOW);
}
else{
digitalWrite(4, LOW);
digitalWrite(5, LOW);
}


if (M3 > 0.1){
 digitalWrite(6, HIGH);
 digitalWrite(7, LOW);
}
else if (M3 < 0.1){
 digitalWrite(7, HIGH);
 digitalWrite(6, LOW);
}
else{
digitalWrite(6, LOW);
digitalWrite(7, LOW);
}


if (M4 > 0.1){
 digitalWrite(8, HIGH);
 digitalWrite(9, LOW);
}
else if (M4 < 0.1){
 digitalWrite(9, HIGH);
 digitalWrite(8, LOW);
}
else{
digitalWrite(8, LOW);
digitalWrite(9, LOW);
}
}


  
