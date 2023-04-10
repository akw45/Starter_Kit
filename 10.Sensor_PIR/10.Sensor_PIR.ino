#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN            "oRP17_S_QER-8ZwKHleG1ltf-5W5KHIY"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define PIR 5
#define Buzzer 4

char ssid[] = "Tukang Ngoding";
char pass[] = "kodingeverywhere";

WidgetLED led3(V3);

BlynkTimer timer;

void sensorPIR() {
  String h = "Gerakan Terdeteksi";
  String c = "Tidak Terdeteksi";
  long state = digitalRead(PIR);
  if (state == HIGH) {
    Blynk.virtualWrite(V2, h);
    led3.on();
    digitalWrite (Buzzer, HIGH);
    Serial.println("Motion detected!");
  }
  else {
    Blynk.virtualWrite(V2, c);
    led3.off();
    digitalWrite (Buzzer, LOW);
    Serial.println("Motion absent!");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(PIR, INPUT);   // declare sensor as input
  pinMode(Buzzer, OUTPUT);  // declare LED as output
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(500L, sensorPIR);
}
void loop() {
  Blynk.run();
  timer.run();
}
