#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN            "oRP17_S_QER-8ZwKHleG1ltf-5W5KHIY"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define hujan 5
#define buzzer 4

char ssid[] = "Tukang Ngoding";
char pass[] = "kodingeverywhere";

WidgetLED led3(V3);

BlynkTimer timer;

void sensorhujan() {
  String h = "Hujan";
  String c = "Cerah";
  int kondisi_sensor = digitalRead(hujan);
  if (kondisi_sensor == LOW) {
    Blynk.virtualWrite(V2,h);
    led3.on();
    Serial.println("Cuaca Hujan");
    digitalWrite(buzzer, HIGH);
  }
  else {
    Blynk.virtualWrite(V2,c);
    led3.off();
    Serial.println("Cuaca Cerah");
    digitalWrite(buzzer, LOW);
  }
}

void setup () {
  Serial.begin(115200);
  pinMode (hujan, INPUT);
  pinMode (buzzer, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(1000L, sensorhujan);
}

void loop() {
  Blynk.run();
  timer.run();
}
