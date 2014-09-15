// Send email example
//   http://d.hatena.ne.jp/higepon/20140915/1410733266

#include <stdarg.h>

#define PRINTF_BUFFER_SIZE 128
void Serial_printf(const char* fmt, ...) {
   char buff[PRINTF_BUFFER_SIZE];
   va_list args;
   va_start(args, fmt);
   vsnprintf(buff, PRINTF_BUFFER_SIZE, fmt, args);
   va_end(args);
   Serial.println(buff);
}

int lastVoltage = 4096;
TCPClient client;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  int currentVoltage = analogRead(A0);

  // When it becomes brighter, we'd trigger email
  bool shouldTriggerEmail = (lastVoltage - currentVoltage) > 100;
  
  Serial_printf("last=%d current=%d", lastVoltage, currentVoltage);
  if (shouldTriggerEmail) {
    client.stop();
    Serial.println("Sending email... ");
    if (client.connect("api.pushingbox.com", 80)) {
      Serial.println("connected");
      client.print("GET /pushingbox?devid=v9C81CF39A1CB60D");
      client.println(" HTTP/1.1");
      client.print("Host: ");
      client.println("api.pushingbox.com");
      client.println("User-Agent: Spark");
      client.println("Connection: close");
      client.println();
      client.flush();
    } else{
      Serial.println("connection failed");
    }
  }    
  lastVoltage = currentVoltage;
  delay(1000);
}
