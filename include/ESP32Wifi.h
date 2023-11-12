#pragma once 
#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

class ESP32Wifi
{
public:
    ESP32Wifi();
    ESP32Wifi(String ssid, String password);
    String GetJsonFromAPI(String api);
    String GetIp();
private:
    String m_Ip;
};