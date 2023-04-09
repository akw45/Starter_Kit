const int relay1 = 5;
const int relay2 = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay1,HIGH);
  Serial.println("Relay 1 Hidup");
  delay(1000);
  digitalWrite(relay2,HIGH);
  Serial.println("Relay 1 & 2 Hidup");
  delay(1000);
  digitalWrite(relay1,LOW);
  Serial.println("Relay 1 Mati");
  delay(500);
  digitalWrite(relay2,LOW);
  Serial.println("Relay 1 Hidup");
  delay(500);
}
