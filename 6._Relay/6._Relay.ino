#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN            "yxCNDT87eHSfNSqsOb_j4ecm1W5Mu-fI"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define RELAY1 5
#define RELAY2 4
#define RELAY3 14
#define RELAY4 12

char ssid[] = "Tukang Ngoding";
char pass[] = "kodingeverywhere";

BLYNK_WRITE(V0) {
  digitalWrite(RELAY1, param.asInt());
}
BLYNK_WRITE(V1) {
  digitalWrite(RELAY2, param.asInt());
}
BLYNK_WRITE(V2) {
  digitalWrite(RELAY3, param.asInt());
}
BLYNK_WRITE(V3) {
  digitalWrite(RELAY4, param.asInt());
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
}
void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
