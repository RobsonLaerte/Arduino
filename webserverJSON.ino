
#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoJson.h>
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 15, 254);
EthernetServer server(80);

void setup() {
 
  pinMode(2,OUTPUT);  pinMode(3,OUTPUT);  pinMode(5,OUTPUT);  pinMode(6,OUTPUT);  pinMode(7,OUTPUT);pinMode(8,OUTPUT);pinMode(9,OUTPUT);
  
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Ethernet WebServer Example");

   Ethernet.begin(mac, ip);

  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1);
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

 
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        
        digitalWrite(2, HIGH);
        if (c == '\n' && currentLineIsBlank) {
          
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: application/json");
          client.println("Connection: close");
          client.println();
          client.print("{\"status\":");
          client.print(digitalRead(2));
          client.print(",");
          client.print("\"status\":");
          client.print(digitalRead(3));
          client.print(",");
          client.print("\"status\":");
          client.print(digitalRead(5));
          client.print(",");
          client.print("\"status\":");
          client.print(digitalRead(6));
          client.print(",");
          client.print("\"status\":");
          client.print(digitalRead(7));
          client.print(",");
          client.print("\"status\":");
          client.print(digitalRead(8));
          client.print(",");
          client.print("\"status\":");
          client.print(digitalRead(9));
          client.print("}");
           
          
          break;
        }
        if (c == '\n') {
         
          currentLineIsBlank = true;
        } else if (c != '\r') {
        
          currentLineIsBlank = false;
        }
      }
    }
  
    delay(1);
   
    client.stop();
    Serial.println("client disconnected");
  }
}
