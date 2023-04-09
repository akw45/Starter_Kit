const int  buttonPin = 4;
const int ledPin = 13;

bool lastButtonState = LOW; // status tombol terakhir
bool ledState = LOW; // status LED

void setup() {
  pinMode(buttonPin, INPUT); // tombol sebagai input
  pinMode(ledPin, OUTPUT); // LED sebagai output
}

void loop() {
  bool buttonState = digitalRead(buttonPin); // cek status tombol
  if (buttonState != lastButtonState) { // jika status tombol berubah dari sebelumnya
    if (buttonState == LOW) { // jika tombol berubah ke status LOW (dilepas)
      if (ledState == HIGH) { // jika status LED hidup
        digitalWrite(ledPin, LOW); // maka LED dimatikan
        ledState = LOW;
      }
      else { // jika status LED mati
        digitalWrite(ledPin, HIGH); // maka LED dihidupkan
        ledState = HIGH;
      }
    }
    delay(50); // debounching
  }
  lastButtonState = buttonState; // simpan status tombol untuk loop selanjutnya
}
