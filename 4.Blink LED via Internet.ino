// Control LED blink speed via the Internet
//   See http://d.hatena.ne.jp/higepon/20140909/1410229118

// We name pin D0 as led
int led = D0;

// This routine runs only once upon reset
void setup()
{
  // Initialize D0 pin as output
  pinMode(led, OUTPUT);
  Spark.function("blink", blink);  
}

int blink(String command) {
    // Default is fast blink
    int ms = 50;
    if (command == "slow") {
        // slow
        ms = 300;
    }
    for (int i = 0; i < 20; i ++) {
      digitalWrite(led, HIGH);
      delay(ms);             
      digitalWrite(led, LOW);
      delay(ms);
    }
    return 0;
}

// This routine loops forever
void loop()
{
}
