#include <ESP32Wifi.h>

ESP32Wifi::ESP32Wifi(){};

ESP32Wifi::ESP32Wifi(String ssid, String password)
{
    int nbEssais = 0;
    int nbEssaisMaximum = 10;
    WiFi.begin(ssid, password);

    Serial.print("Connexion : ");
    while (nbEssais < nbEssaisMaximum && WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        nbEssais++;
    }
    Serial.println("");

    if (WiFi.status() == WL_CONNECTED) {
        Serial.print("Connecté au réseau WiFi, adresse IP : ");
        Serial.println(WiFi.localIP());
        Serial.println("");
    }
};

String ESP32Wifi::GetJsonFromAPI(String api)
{
    String res = "";
  if(WiFi.status() == WL_CONNECTED)
  {
    String url = api;
    HTTPClient httpClient;
    httpClient.begin(url);
    int codeStatut = httpClient.GET();

    if(codeStatut != 200){
      Serial.println(HTTPClient::errorToString(codeStatut));
    }
    else
    {
      res = httpClient.getString();
    }
  } 
  else 
  {
    Serial.println("Non connecte");
  }

  return res;
};

String ESP32Wifi::GetIp()
{
    return String(WiFi.localIP());
};