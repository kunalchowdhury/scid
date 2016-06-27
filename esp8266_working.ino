#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

void handleRoot()
{
   server.send(200, "text/html", "<h1>Welcome to the Matrix</h1>");
}

void setup() {
  // put your setup code here, to run once:

   delay(1000);
   Serial.begin(4800);
   Serial.println();
   Serial.print("Configuring the AP");
   WiFi.softAP("STAR_TREK","kunal123");
   IPAddress ipadd = WiFi.softAPIP();
   Serial.print("AP IP address ");
   Serial.println(ipadd);
   server.on("/", handleRoot);
   server.begin();
   Serial.println("server started");
}

void loop() {
  delay(8000);
  // put your main code here, to run repeatedly:
   server.handleClient();
   //server.send(200, "text/html", "<h1>Welcome to the Matrix</h1>");
   WiFiClient client = server.client();
   if(client != NULL)
   {
      client.write("Welcome to matrix..",19 ); 
      server.handleClient();
      server.send(200, "text/html", "<h1>Welcome to the Matrix</h1>");

   }
}

