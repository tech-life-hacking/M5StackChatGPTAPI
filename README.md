# M5StackChatGPTAPI

Traditionally, the use of ChatGPT has been primarily in Python and PC-based applications. However, its utilization on edge devices has been restricted due to the scarcity of libraries, with very few, if any, examples available. Bearing this in mind, we have confirmed that ChatGPT can be used on the M5Stack, which is based on the ESP32. C++ development using libraries such as M5Unified and m5stack-avatar is actively conducted on the M5Stack. Consequently, we have implemented the ChatGPT API in C++.

![stream](https://www.techlife-hacking.com/wp-content/uploads/2023/06/stream.gif)  

# Example

```cpp
#include "ChatGPTAPI.h"
#include <M5Unified.h>
#include "WifiManager.h"

String inputText =
    "Please tell us about Japan's capital city and its one attraction.";
String response;

// setup ChatGPT API class
String model = "gpt-4"; // or gpt-3.5-turbo
ChatGPTAPI chatGPTAPI(OPENAI_TOKEN, model);

// setup WiFi
WifiManager wifiManager(WIFI_SSID, WIFI_PASS);

void setup()
{
  M5.begin();
  wifiManager.connect();
}

void loop()
{
  M5.update();

  if (M5.BtnA.wasReleased() ||
      (M5.Touch.getCount() && M5.Touch.getDetail(0).wasClicked())) {
      response = chatGPTAPI.requestChatCompletion(inputText);
      M5.Lcd.print(response);
      M5.Lcd.print("\n");
  }
}

```
