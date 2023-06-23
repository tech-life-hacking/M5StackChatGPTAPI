#ifndef CHATGPTAPI_H
#define CHATGPTAPI_H

#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

class ChatGPTAPI
{
public:
    ChatGPTAPI(const char *token, String model);
    ChatGPTAPI(const char *token, String prompt, int maxTokens, float temperature, float top_p, String model);
    String requestChatCompletion(String inputText);

private:
    const char *token;
    String prompt;
    int maxTokens;
    float temperature;
    float top_p;
    String model;
    WiFiClientSecure client;
};

#endif // CHATGPTAPI_H