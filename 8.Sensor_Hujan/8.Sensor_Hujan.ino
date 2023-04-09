const int sensor_hujan = 5;
const int LED = 4;

void setup () {
  Serial.begin(115200);
  pinMode (sensor_hujan, INPUT);
  pinMode (LED, OUTPUT);
}

void loop() {
  int kondisi_sensor = digitalRead(sensor_hujan);
  if (kondisi_sensor == LOW) {
    Serial.println("Cuaca Hujan");
    digitalWrite(LED, HIGH);
  }
  else {
    Serial.println("Cuaca Cerah");
    digitalWrite(LED, LOW);
  }
  delay (1000);
}
