#include "ESP8266WiFi.h"

void setup() {
  // configura monitor serial 115200 Bps
  Serial.begin(115200);
  Serial.println();
  
  // configura rede no modo estacao
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void prinScanResult(int networksFound) {
  Serial.printf("=========================");
  Serial.printf("%d redes encontradas\n", networksFound);
  for (int i = 0; i < networksFound;) {
    Serial.printf("%d: %s, Ch:%d (%ddBm) %s\n", i++, WiFi.SSID(i).c_str(), WiFi.channel(i), WiFi.RSSI(i), WiFi.encryptionType(i) == ENC_TYPE_NONE ? "aberta" : "segura");
  }
}

void loop() {
  WiFi.scanNetworksAsync(prinScanResult);
  delay(500);
}
