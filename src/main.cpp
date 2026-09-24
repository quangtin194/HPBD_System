#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <WebServer.h>
#include "buzzer.h"
#include "led7.h"
#include "oled.h"
#include "UIhtml.h"

// === DEFINES ====

// === VARIABLES ===
const char *ssid = "Nguyen_L5";
const char *password = "9tren1duong4";

WebServer server(80);

// === API FUNCTIONS ====
void home () {
  server.send(200, "text/html", html_home);
}

void work()
{
    String name = server.arg("name");
    int8_t count = server.arg("count").toInt();

    Serial.println("Name: " + name);
    Serial.println("Count: " + String(count));

    Oled_display("ALERT!!!", nullptr);
    for (int8_t i = count; i >= 0; i--)
    {
        Buzzer_bip_Sound();
        Led7_display(i);
        delay(300);
        Buzzer_stop();
        delay(700);
    }

    Oled_display("Happi Birthday", name.c_str());
    Buzzer_music();
    server.send(200, "text/html", html_success);
}

// === SETUP & SUPER LOOP ===
void setup() {
  Serial.begin(9600);

  // Setup WiFi
  WiFi.disconnect();
  WiFi.begin(ssid, password);
  Serial.print("Connecting\r\n");
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(200);
  }
  Serial.println("Connected to " + WiFi.SSID());
  Serial.print("IP server: ");
  Serial.println(WiFi.localIP());

  // Setup Webserver
  server.on("/", home);
  server.on("/work", work);
  server.begin();

  // Setup Peripherals
  Buzzer_init(23, 0);
  Led7_init(19, 18, 5, 17, 16, 4, 2);
  Oled_init(21, 22);
}

void loop() {
  server.handleClient();
}