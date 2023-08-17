void setup() {
  Serial.begin(9600);
  Serial.println("Serial Test");
  Serial.print("ECHO>> ");
  Serial.begin(9600);
  
}

void loop() {
  char data;
  pinMode(5, OUTPUT);

  if(Serial.available() > 0) {
    data = Serial.read();
    Serial.write(data);
  }

  if(data == 'o' || data == 'O')
  {
    digitalWrite(5, HIGH);
  }
  if(data == 'x' || data == 'X')
  {
    digitalWrite(5, LOW);
  }
  

}
