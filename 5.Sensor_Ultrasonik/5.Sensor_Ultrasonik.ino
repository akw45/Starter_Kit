#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN            "yxCNDT87eHSfNSqsOb_j4ecm1W5Mu-fI"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define ECHOPIN 5
#define TRIGPIN 4

char ssid[] = "Tukang Ngoding";
char pass[] = "kodingeverywhere";

long waktu;
int jarak;

BlynkTimer timer;

void myTimerEvent()
{
  Blynk.virtualWrite(V6, jarak);
}

void setup()
{
  Serial.begin(115200);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  // Initiates BlynkTimer
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  waktu = pulseIn(ECHOPIN, HIGH);
  jarak = waktu/58;
  
  Blynk.run();
  timer.run();


}
