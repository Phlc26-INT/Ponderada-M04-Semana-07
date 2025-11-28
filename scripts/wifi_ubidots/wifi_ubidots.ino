#include <WiFi.h>
#include <PubSubClient.h>

// Configuração de chaves de acesso para as conexões no wifi e ubidots

#define TOKEN "XXXXXXXXXXXX"
#define WIFINAME "XXXXXXX"
#define WIFIPASS "XXXXXXXXX"

// Configurações do MQTT para conexão com Ubidots
const char* mqtt_server = "industrial.api.ubidots.com";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);


// Funções
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando ao WiFi: ");
  Serial.println(WIFINAME);

  WiFi.begin(WIFINAME, WIFIPASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao Ubidots...");
    
    if (client.connect("ESP32Client", TOKEN, "")) {
      Serial.println("Conectado!");
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 2 segundos");
      delay(2000);
    }
  }
}

void sendToUbidots(float value) {
  String payload = "{\"rssi\": " + String(value) + "}";
  String topic = "/v1.6/devices/wifi-monitor";
  
  client.publish(topic.c_str(), payload.c_str());
}

//Setup e Loop

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  
  Serial.println("Sistema iniciado!");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  
  // Lê RSSI e envia para Ubidots
  int rssi = WiFi.RSSI();
  sendToUbidots(rssi);
  
  // Mostra no Serial
  Serial.print("RSSI: ");
  Serial.print(rssi);
  Serial.println(" dBm - Enviado!");
  
  client.loop();
  delay(3000); // Envia a cada 3 segundos
}