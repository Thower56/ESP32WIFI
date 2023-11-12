#include <Arduino.h>
#include <ESP32Wifi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define WIFI_SSID "The Reseau"
#define WIFI_PASSWORD "1357924680"

int nbEssais = 0;
int nbEssaisMaximum = 10;
ESP32Wifi* wifi;

void setup() {
  wifi = new ESP32Wifi(WIFI_SSID, WIFI_PASSWORD);
  Serial.begin(9600);
  Serial.println(wifi->GetJsonFromAPI("https://api.open-meteo.com/v1/forecast?latitude=45.5017&longitude=-73.5672&hourly=temperature_2m"));
}

void loop() {

}
