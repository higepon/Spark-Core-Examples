// What is this?
//   Change color of the RGB LED periodically.
//
int led = D0;  // The RGB LED

// This routine runs only once upon reset
void setup() {
  pinMode(led, OUTPUT);
  RGB.control(true);
}

int random(int minVal, int maxVal)
{
  return rand() % (maxVal - minVal + 1) + minVal;
}

int randomColor() {
    return random(0, 255);
}

// This routine gets called repeatedly, like once every 5-15 milliseconds.
void loop() {
  digitalWrite(led, HIGH);  // Turn ON the LED pins
  delay(50);
  RGB.color(255, randomColor(), randomColor());
  digitalWrite(led, LOW);
  delay(50);
}
