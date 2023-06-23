#include "WifiManager.h"
#include <M5Unified.h>

WifiManager::WifiManager(const char *ssid, const char *password) : ssid(ssid), password(password) {}

void WifiManager::connect()
{
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        M5.Lcd.print(".");
    }
    M5.Lcd.print("\nWiFi connected");
    M5.Lcd.print("\nIP address: ");
    M5.Lcd.print(WiFi.localIP());
    M5.Lcd.print("\n");
}
