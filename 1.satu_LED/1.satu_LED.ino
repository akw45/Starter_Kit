#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN            "yxCNDT87eHSfNSqsOb_j4ecm1W5Mu-fI"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define L1 5

char ssid[] = "AMD2122";
char pass[] = "Pass29072122";

BLYNK_WRITE(V0) {
  digitalWrite(L1, param.asInt());
}

void setup() {
  Serial.begin(115200);
  pinMode(L1, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass,"blynk.cloud",80);
}

void loop() {
  Blynk.run();
}
