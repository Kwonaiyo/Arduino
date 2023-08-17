int trigPin = 3;
int echoPin = 2;
int buzPin = 13;
float duration;
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(buzPin, OUTPUT);  // buzzer핀 (출력)
  pinMode(trigPin, OUTPUT); // 센서 Trigger 핀(출력)
  pinMode(echoPin, INPUT);  // 센서 Echo 핀(입력)
  digitalWrite(buzPin, HIGH);
}

void loop() {
   digitalWrite(trigPin, HIGH);  // 센서에 Trigger 신호 입력
   delayMicroseconds(10);        // 10^-6 s 정도 유지
   digitalWrite(trigPin, LOW);   // Trigger 신호 off
 
   duration = pulseIn(echoPin, HIGH); // Echo pin : HIGH -> LOW 간격을 측정
   distance = (duration / 2) * 340 / 10000;  // 거리(cm)로 변환
 
   Serial.print(distance);
   Serial.println(" cm");

   delay(75);
 
  if(distance >= 12 && distance < 20)
  {
    tone(buzPin, 700);
    delay(1000);
    noTone(buzPin);
  }

  else if(distance >= 15 && distance < 30)
  {
    tone(buzPin, 700);
    delay(700);
    noTone(buzPin);
  }
  else if(distance >= 9 && distance < 15)
  {
    tone(buzPin, 700);
    delay(400);
    noTone(buzPin);

  }
  else if(distance >= 6 && distance < 9)
  {
    tone(buzPin, 700);
    delay(150);
    noTone(buzPin);
  }
  else if(distance >= 4 && distance < 6)
  {
    tone(buzPin, 700);
    delay(50);
    noTone(buzPin);
  }
  else if(distance < 4)
  {
    tone(buzPin, 700);
  }
  else
  {
    noTone(buzPin);
  }

}