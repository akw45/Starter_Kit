#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN            "yxCNDT87eHSfNSqsOb_j4ecm1W5Mu-fI"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define L5 13

char ssid[] = "LAPTOP";
char pass[] = "laptopku";

BLYNK_WRITE(V4) {
  digitalWrite(L5, param.asInt());
}

void setup() {
  Serial.begin(115200);
  pinMode(L5, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
}
// the loop function runs over and over again forever
void loop() {
  Blynk.run();
}
