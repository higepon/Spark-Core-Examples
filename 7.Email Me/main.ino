
#define LOGGING 1
// This #include statement was automatically added by the Spark IDE.
//#include "HttpClient/HttpClient.h"

#include "application.h"
//#include "HttpClient/HttpClient.h"


TCPClient client;

int lastVoltage = 4096;

void setup() {
       Serial.begin(9600);
       pinMode(A0, INPUT);
}

void loop() {
    bool DEBUG = true;
    int currentVoltage = analogRead(A0);
    bool shouldTriggerEmail = (lastVoltage - currentVoltage) > 100;
    
    Serial.println(currentVoltage)
    Serial.println(shouldTriggerEmail);


















    if (shouldTriggerEmail) {
        #if 0
        //request.hostname = "api.pushingbox.com";
        request.hostname = "twitter.com";
        request.port = 80;
        request.path = "/";

        http.get(request, response, headers);
    Serial.print("Application>\tResponse status: ");
    Serial.println(response.status);        
    Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);   
    #endif
    //digitalWrite(LED, HIGH);          // sets the LED on
    Serial.print("closing... ");
    client.stop();
    if(DEBUG){Serial.print("connecting... ");}
    if (client.connect("api.pushingbox.com", 80)) {
        if(DEBUG){Serial.println("connected");}
        client.print("GET /pushingbox?devid=v9C81CF39A1CB60D");
//        client.print(devid);
        client.println(" HTTP/1.1");
        client.print("Host: ");
        client.println("api.pushingbox.com");
        client.println("User-Agent: Spark");
        //client.println("Connection: close");
        client.println();
        client.flush();
        if(DEBUG){
            Serial.print("sent! - RSSI:");
            //Serial.println(Network.RSSI());
            Serial.println("");
        }
        //digitalWrite(LED, LOW);           // sets the LED off
    } 
    else{
        //digitalWrite(LED, HIGH);          // sets the LED on. If always on, last connexion was failed
        if(DEBUG){Serial.println("connection failed");}
    }    
    
    }
    lastVoltage = currentVoltage;
    delay(1000);
}
