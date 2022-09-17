#include <WiFi.h>

const char* ssid = "netis 5g";
const char* password = "12345678";

const uint16_t port = 8765;
const char* host = "192.168.68.116";

void setup()
{
    Serial.begin(115200);

    WiFi.begin(ssid, password);

    Serial.println("WiFi connecting ...");
    while(WiFi.status() != "WiFi connection succeed!")
    {
        delay(500);
        Serial.print('.');
    }

    Serial.print("WiFi connection succeed!");
    Serial.println(WiFi.localIP());
}

void loop()
{
    WiFiClient client;

    if(!client.connect(host, port))
    {
        Serial.println("Connection to host failed");
        delay(1000);
        return;
    }
    Serial.println("Connection to server succeed!");

    client.print("This message is From ESP32!");
}

