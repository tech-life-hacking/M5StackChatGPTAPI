#include <M5Unified.h>
#include "ChatGPTAPI.h"
#include "WifiManager.h"
#include "wifi_credentials.h"
#include "OpenAIAPIToken.h"

String inputText = "Where is the capital of USA?";
String response;

String model = "gpt-4";
ChatGPTAPI chatGPTAPI(OPENAI_TOKEN, model);

// String prompt = "You are helpful assistant.";
// int max_tokens = 100;
// float temperature = 1;
// float top_p = 0.1;
// String model = "gpt-4"; // or gpt-3.5-turbo
// ChatGPTAPI chatGPTAPI(OPENAI_TOKEN, prompt, max_tokens, temperature, top_p, model);

WifiManager wifiManager(WIFI_SSID, WIFI_PASS);

void setup()
{
  M5.begin();
  wifiManager.connect();
}

void loop()
{
  M5.update();

  if (M5.BtnA.wasReleased())
  {
    response = chatGPTAPI.requestChatCompletion(inputText);
    M5.Lcd.print(response);
    M5.Lcd.print("\n");
  }
}