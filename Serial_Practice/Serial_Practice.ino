const int ledPin = 13;
int inByte = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  establishContact();
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    inByte = Serial.read();

    if (inByte == 49) {
      digitalWrite(ledPin,LOW);
    }
    else if (inByte == 50) {
      digitalWrite(ledPin,HIGH);
    }
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(2000);
  }
}
