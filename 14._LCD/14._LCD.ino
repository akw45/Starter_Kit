#define BLYNK_PRINT Serial

#define BLYNK_AUTH_TOKEN            "oRP17_S_QER-8ZwKHleG1ltf-5W5KHIY"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LiquidCrystal.h>

char ssid[] = "Tukang Ngoding";
char pass[] = "kodingeverywhere";

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
LiquidCrystal lcd(12, 13, 14, 2, 0, 4);

BlynkTimer timer;

void LCD() {
  String text = Serial.readString();
  Blynk.virtualWrite(V7,text);
  lcd.setCursor(0, 1);
  lcd.print(text);

}

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(115200);
  lcd.begin(16, 2);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(500L, LCD);
  // Print a message to the LCD.

}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  Blynk.run();
  timer.run();
}
