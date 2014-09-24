// Turn on/off Piezo Buzzar
//   

void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
}

void loop() {
  delay(1000);
  analogWrite(A0, 2000);
  delay(100);
  analogWrite(A0, 0);
}
