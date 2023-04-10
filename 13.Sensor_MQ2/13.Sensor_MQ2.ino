#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN            "oRP17_S_QER-8ZwKHleG1ltf-5W5KHIY"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define pinA A0
#define pinD 4
#define buzzer 5

char ssid[] = "Tukang Ngoding";
char pass[] = "kodingeverywhere";

WidgetLED led3(V3);

BlynkTimer timer;

void sensorMQ2() {
  int gassensorAnalog = analogRead(pinA);
  int gassensorDigital = digitalRead(pinD);


  Serial.print("Gas Sensor: ");
  Serial.print(gassensorAnalog);
  Serial.print("\t");
  Serial.print("Gas Class: ");
  Serial.print(gassensorDigital);
  Serial.print("\t");
  Serial.print("\t");

  if (gassensorAnalog > 900) {
    Blynk.virtualWrite(V5, "Gas Terdeteksi");
    Serial.println("Gas");
    led3.on();
    digitalWrite (buzzer, HIGH) ; //send tone
    delay(1000);
    digitalWrite (buzzer, LOW) ;  //no tone
  }
  else {
    Blynk.virtualWrite(V5, "Gas Tidak Terdeteksi");
    led3.off();
    Serial.println("No Gas");
  }
  delay(100);
}

void setup() {
  Serial.begin(115200);
  pinMode(pinA, INPUT); //Declare pin A0 as input
  pinMode(buzzer, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(500L, sensorMQ2);
}

void loop() {
  Blynk.run();
  timer.run();
}
