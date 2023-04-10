#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN            "oRP17_S_QER-8ZwKHleG1ltf-5W5KHIY"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define selenoid 5
#define buttonPin 4

char ssid[] = "Tukang Ngoding";
char pass[] = "kodingeverywhere";

bool lastButtonState = LOW; // status tombol terakhir
bool selenoidState = LOW; // status LED

WidgetLED led3(V3);

BlynkTimer timer;

void Selenoid() {
  String h = "Pintu Tertutup";
  String c = "Pintu Terbuka";
  bool buttonState = digitalRead(buttonPin); // cek status tombol
  Serial.println(buttonState);
  if (buttonState != lastButtonState) { // jika status tombol berubah dari sebelumnya
    if (buttonState == LOW) { // jika tombol berubah ke status LOW (dilepas)
      if (selenoidState == HIGH) { // jika status LED hidup
        Blynk.virtualWrite(V2,h);
        led3.on();
        digitalWrite(selenoid, LOW); // maka LED dimatikan
        selenoidState = LOW;
      }
      else { // jika status LED mati
        Blynk.virtualWrite(V2,c);
        led3.off();
        digitalWrite(selenoid, HIGH); // maka LED dihidupkan
        selenoidState = HIGH;
        
      }
    }
    delay(50); // debounching
  }
  lastButtonState = buttonState;
}
void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT); // tombol sebagai input
  pinMode(selenoid, OUTPUT); // LED sebagai output
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(500L, Selenoid);
}

void loop() {
  Blynk.run();
  timer.run();
}
