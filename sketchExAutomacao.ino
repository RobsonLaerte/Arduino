#include <ArduinoJson.h>
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; 
IPAddress ip(192, 168, 15, 254);
EthernetServer server(80);
String readString; 
int canal1 = 2;
int canal2 = 3;
int canal3 = 4;
int canal4 = 5;
int canal5 = 6;
int canal6 = 7;
int canal1In = 8;
int canal2In = 9;
int canal3In = 14;
int canal4In = 15;
int canal5In = 16;
int canal6In = 17;
int canal[]={1,2,3,4,5,6};
boolean estado= false;

void setup(){
    Ethernet.begin(mac, ip); 
    Serial.begin(9600);
    server.begin();
          
    pinMode(canal1, OUTPUT); 
     pinMode(canal2, OUTPUT);
      pinMode(canal3, OUTPUT);
       pinMode(canal4, OUTPUT);
        pinMode(canal5, OUTPUT);
         pinMode(canal6, OUTPUT);

    pinMode(canal1In, INPUT_PULLUP);
    pinMode(canal2In, INPUT_PULLUP);
    pinMode(canal3In, INPUT_PULLUP);
    pinMode(canal4In, INPUT_PULLUP);
    pinMode(canal5In, INPUT_PULLUP);
    pinMode(canal6In, INPUT_PULLUP);
 }
 
void loop(){

    EthernetClient client = server.available();
    if (client) {
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) { 
                char c = client.read();
                Serial.write(c);
                if (readString.length() < 100) {
                  readString += c;           
                }
               
     
                if (c == '\n' && currentLineIsBlank) {
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: application/json");
                    client.println("Connection: close");
                    client.println();
                    client.print("{\"c1\":");
                    client.print(digitalRead(canal1));
                    client.print(",\"c2\":");
                    client.print(digitalRead(canal2));
                    client.print(",\"c3\":");
                    client.print(digitalRead(canal3));
                    client.print(",\"c4\":");
                    client.print(digitalRead(canal4));
                    client.print(",\"c5\":");
                    client.print(digitalRead(canal5));
                    client.print(",\"c6\":");
                    client.print(digitalRead(canal6));
                    client.println("}");
                  
              
                                                          
                    break;
                }
                
                if (c == '\n') {
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    currentLineIsBlank = false;
                }
            }
        }
        delay(5);
        client.stop();
       
              
        if(readString.indexOf("?L1") > 0){
          digitalWrite(2, HIGH);
        } 
        else if(readString.indexOf("?D1") > 0){
          digitalWrite(2, LOW);
        }
         if(readString.indexOf("?L2") > 0){
          digitalWrite(3, HIGH);
        } 
        else if(readString.indexOf("?D2") > 0){
          digitalWrite(3, LOW);
        }
         if(readString.indexOf("?L3") > 0){
          digitalWrite(4, HIGH);
        } 
        else if(readString.indexOf("?D3") > 0){
          digitalWrite(4, LOW);
        }
         if(readString.indexOf("?L4") > 0){
          digitalWrite(5, HIGH);
        } 
        else if(readString.indexOf("?D4") > 0){
          digitalWrite(5, LOW);
        }
         if(readString.indexOf("?L5") > 0){
          digitalWrite(6, HIGH);
        } 
        else if(readString.indexOf("?D5") > 0){
          digitalWrite(6, LOW);
        }
         if(readString.indexOf("?L6") > 0){
          digitalWrite(7, HIGH);
        } 
        else if(readString.indexOf("?D6") > 0){
          digitalWrite(7, LOW);
        }
    }
    readString=""; 
   
    if( digitalRead(canal1In) == LOW ){ 
        delay(500);
        digitalWrite( canal1, !digitalRead(canal1) );
         }
    if( digitalRead(canal2In) == LOW ){ 
        delay(500);
        digitalWrite( canal2, !digitalRead(canal2) );
         }
    if( digitalRead(canal3In) == LOW ){ 
        delay(500);
        digitalWrite( canal3, !digitalRead(canal3) );
         } 
    if( digitalRead(canal4In) == LOW ){ 
        delay(500);
        digitalWrite( canal4, !digitalRead(canal4) );
         }  
    if( digitalRead(canal5In) == LOW ){ 
        delay(500);
        digitalWrite( canal5, !digitalRead(canal5) );
         }  
    if( digitalRead(canal6In) == LOW ){ 
        delay(500);
        digitalWrite( canal6, !digitalRead(canal6) );
         }
}

   

  
  

  


  
