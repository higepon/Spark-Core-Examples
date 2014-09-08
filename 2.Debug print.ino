// Example for debug print
//   See http://d.hatena.ne.jp/higepon/20140908/1410150226

void setup() {
  Serial.begin(9600); // open serial over US
}

void loop() {
   Serial.println("Hello, World");
   delay(1000); // Sleep 1 sec
}
