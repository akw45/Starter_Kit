#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN            "yxCNDT87eHSfNSqsOb_j4ecm1W5Mu-fI"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define L1 5
#define L2 4
#define L3 14
#define L4 12
#define L5 13
#define L6 15

char ssid[] = "LAPTOP";
char pass[] = "laptopku";

BLYNK_WRITE(V0) {
  digitalWrite(L1, param.asInt());
}
BLYNK_WRITE(V1) {
  digitalWrite(L2, param.asInt());
}
BLYNK_WRITE(V2) {
  digitalWrite(L3, param.asInt());
}
BLYNK_WRITE(V3) {
  digitalWrite(L4, param.asInt());
}
BLYNK_WRITE(V4) {
  digitalWrite(L5, param.asInt());
}
BLYNK_WRITE(V5) {
  digitalWrite(L6, param.asInt());
}

void setup() {
  Serial.begin(115200);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);

}

void loop() {
  Blynk.run();
}
