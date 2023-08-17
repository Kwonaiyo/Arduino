// 버튼 하나로 LED 불 껐다가 켜기

int inPinA = 3;
int keyDataA = 0;
int ledPin = 5;
int outPut = 10;
int count = 0;
void setup() {
  pinMode(inPinA, INPUT);
  pinMode(count, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(outPut, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  keyDataA = digitalRead(inPinA);
  Serial.println(keyDataA);
  digitalWrite(outPut, HIGH);
  if(digitalRead(inPinA) == 1)
  {
    count++;
    if((count % 2) == 1)
    {
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      digitalWrite(ledPin, LOW);
    }
  }
  
  delay(200);
}
