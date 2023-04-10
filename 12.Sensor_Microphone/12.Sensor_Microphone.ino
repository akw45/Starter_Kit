#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN            "oRP17_S_QER-8ZwKHleG1ltf-5W5KHIY"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define sound_digital 5
#define sound_analog A0
#define Buzzer 4

char ssid[] = "Tukang Ngoding";
char pass[] = "kodingeverywhere";

WidgetLED led3(V3);

BlynkTimer timer;

void Microphone () {
  int val_digital = digitalRead(sound_digital);
  int val_analog = analogRead(sound_analog);

  
  Serial.print(val_analog);
  Serial.print("\t");
  Serial.println(val_digital);

  if (val_digital == HIGH)  {
    Blynk.virtualWrite(V5,"Suara Terdeteksi");
    led3.on();
    digitalWrite (Buzzer, HIGH);
    delay(1000);
  }
  else  {
    Blynk.virtualWrite(V5,"Suara Tidak Terdeteksi");
    led3.off();
    digitalWrite (Buzzer, LOW);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);
  pinMode(sound_digital, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(500L, Microphone);
}

void loop() {
  Blynk.run();
  timer.run();
}
