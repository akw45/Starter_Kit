#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN            "yxCNDT87eHSfNSqsOb_j4ecm1W5Mu-fI"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define btnPin 4

char ssid[] = "Tukang Ngoding";
char pass[] = "kodingeverywhere"; 

WidgetLED led3(V4);

BlynkTimer timer;

// V3 LED Widget represents the physical button state
boolean btnState = false;
void buttonLedWidget()
{
  // Read button
  boolean isPressed = (digitalRead(btnPin) == HIGH);

  // If state has changed...
  if (isPressed != btnState) {
    if (isPressed) {
      led3.on();
    } else {
      led3.off();
    }
    btnState = isPressed;
  }
}
void setup() {
  Serial.begin(115200);
  pinMode(btnPin, INPUT); // tombol sebagai input
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(500L, buttonLedWidget);
}

void loop() {
  Blynk.run();
  timer.run();
}
