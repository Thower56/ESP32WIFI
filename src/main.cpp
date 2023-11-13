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
  const String json = wifi->GetJsonFromAPI("https://api.open-meteo.com/v1/forecast?latitude=45.5017&longitude=-73.5672&hourly=temperature_2m");
  DynamicJsonDocument doc(50000);
  DeserializationError error = deserializeJson(doc, json);
  if(error){
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
  }
  float min = 0;
  int minIndex = 0;
  float max = 0;
  int maxIndex = 0;
  for (size_t i = 0; i < 168; i++)
  {
    if(min > (float)doc["hourly"]["temperature_2m"][i].as<float>()){
      min = (float)doc["hourly"]["temperature_2m"][i].as<float>();
      minIndex = i;
    }
    if(max < (float)doc["hourly"]["temperature_2m"][i].as<float>()){
      max = (float)doc["hourly"]["temperature_2m"][i].as<float>();
      maxIndex = i;
    }
    
  }
  
  Serial.println(String("Température min: ") +  min + " position: " + minIndex);
  Serial.println(String("Température max: ") +  max+ " position: " + maxIndex);
}

void loop() {

}
