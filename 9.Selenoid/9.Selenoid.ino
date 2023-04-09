const int  buttonPin = 4;
const int SelenoidPin = 5;

bool lastButtonState = LOW; // status tombol terakhir
bool selenoidState = LOW; // status LED

void setup() {
  pinMode(buttonPin, INPUT); // tombol sebagai input
  pinMode(SelenoidPin, OUTPUT); // LED sebagai output
}

void loop() {
  bool buttonState = digitalRead(buttonPin); // cek status tombol
  Serial.println(buttonState);
  if (buttonState != lastButtonState) { // jika status tombol berubah dari sebelumnya
    if (buttonState == LOW) { // jika tombol berubah ke status LOW (dilepas)
      if (selenoidState == HIGH) { // jika status LED hidup
        digitalWrite(SelenoidPin, LOW); // maka LED dimatikan
        selenoidState = LOW;
      }
      else { // jika status LED mati
        digitalWrite(SelenoidPin, HIGH); // maka LED dihidupkan
        selenoidState = HIGH;
      }
    }
    delay(50); // debounching
  }
  lastButtonState = buttonState; // simpan status tombol untuk loop selanjutnya
}
