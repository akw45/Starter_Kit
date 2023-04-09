#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN "oRP17_S_QER-8ZwKHleG1ltf-5W5KHIY"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTPIN 5     //Pin apa yang digunakan
#define DHTTYPE DHT11   // DHT 11


char ssid[] = "Tukang Ngoding";
char pass[] = "kodingeverywhere";

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V0, t);
}

void setup() {
  Serial.begin(115200); //baud komunikasi serial
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  Serial.println("Pengujian DHT11!"); //penulisan di serial monitor
  dht.begin(); //prosedur memulai pembacaan module sensor
  timer.setInterval(500L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
