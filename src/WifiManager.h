#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <WiFi.h>

class WifiManager
{
public:
    WifiManager(const char *ssid, const char *password);
    void connect();

private:
    const char *ssid;
    const char *password;
};

#endif // WIFIMANAGER_H
