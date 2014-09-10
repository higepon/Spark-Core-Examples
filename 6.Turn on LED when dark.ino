// Turn on LED when it's dark
//   http://d.hatena.ne.jp/higepon/20140910/1410353300

int led = D7;
bool isOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
    int voltage = analogRead(A0);
    bool isDark = voltage <= 50;
    Serial.print(isDark);
    if (isDark && isOn) {
        // keep it on    
    } else if (isDark && !isOn) {
        // it's dark!
        digitalWrite(led, HIGH);
        isOn = true;
    } else {
        digitalWrite(led, LOW);
        isOn = false;
    }
    delay(500);
}
