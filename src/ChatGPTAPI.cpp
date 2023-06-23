#include "ChatGPTAPI.h"
#include "rootCA.h"

ChatGPTAPI::ChatGPTAPI(const char *token, String model) : token(token), prompt("You are helpful assistant."), maxTokens(100), temperature(1), top_p(1), model(model)
{
    client.setCACert(root_ca);
}

ChatGPTAPI::ChatGPTAPI(const char *token, String prompt, int maxTokens, float temperature, float top_p, String model) : token(token), prompt(prompt), maxTokens(maxTokens), temperature(temperature), top_p(top_p), model(model)
{
    client.setCACert(root_ca);
}

String ChatGPTAPI::requestChatCompletion(String inputText)
{
    String url = "https://api.openai.com/v1/chat/completions";
    String payload = "{\"messages\": [{\"role\": \"system\", \"content\": \"" + prompt + "\"}, {\"role\": \"user\", \"content\": \"" + inputText + "\"}],\"max_tokens\":" + String(maxTokens) + ", \"temperature\":" + float(temperature) + ", \"top_p\":" + float(top_p) + ", \"model\": \"" + model + "\"}";
    if (!client.connect("api.openai.com", 443))
    {
        Serial.println("connection failed");
        return "";
    }

    client.println("POST " + String(url) + " HTTP/1.1");
    client.println("Host: api.openai.com");
    client.println("Content-Type: application/json");
    client.println("Content-Length: " + String(payload.length()));
    client.println("Authorization: Bearer " + String(token));
    client.println("Connection: close");
    client.println();
    client.println(payload);

    while (client.connected())
    {
        String line = client.readStringUntil('\n');
        if (line == "\r")
        {
            break;
        }
    }

    String response = "";
    while (client.available())
    {
        char c = client.read();
        response += c;
    }

    client.stop();

    // Create DynamicJsonDocument based on the size of the response.
    DynamicJsonDocument jsonDoc(response.length());
    deserializeJson(jsonDoc, response);
    String outputText = jsonDoc["choices"][0]["message"]["content"];

    return outputText;
}
