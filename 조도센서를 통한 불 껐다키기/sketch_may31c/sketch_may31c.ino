void setup() {
  Serial.begin(9600); // 시리얼통신 시작하기
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  Serial.println(analogRead(A5)); // 아날로그 5번 핀 읽어서 시리얼 모니터에 출력
  delay(200); // 0.1초 기다리기

  if(analogRead(A5) <= 700)
  {
    digitalWrite(5, HIGH);
  }
  else
  {
    digitalWrite(5, LOW);
  }

  if(analogRead(A5) <= 600)
  {
    digitalWrite(6, HIGH);
  }
  else
  {
    digitalWrite(6, LOW);
  }
}
