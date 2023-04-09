int Status = 12;  // Digital pin D6

int sensor = 13;  // Digital pin D7
void setup() {
  Serial.begin(115200);
  pinMode(sensor, INPUT);   // declare sensor as input
  pinMode(Status, OUTPUT);  // declare LED as output
}
void loop() {

  long state = digitalRead(sensor);
  if (state == HIGH) {
    digitalWrite (Status, HIGH);
    Serial.println("Motion detected!");
//    delay(500);
  }
  else {
    digitalWrite (Status, LOW);
    Serial.println("Motion absent!");
//    delay(500);
  }
}
