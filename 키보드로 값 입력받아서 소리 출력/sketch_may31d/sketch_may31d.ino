int buzzerPin = 13;
int testPin = 5;
int melodyB[] = {262, 294, 330, 349, 392, 440, 494, 523};
int melodyC[] = {131, 147, 165, 175, 196, 220, 247, 262};
char readArrayB[] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k'};
char readArrayC[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i'};
char keyRead;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(testPin, OUTPUT);
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(testPin, HIGH);
  Serial.begin(9600);
  
}

void loop() {

  if(Serial.available() > 0) {
    keyRead = Serial.read();
    Serial.println(keyRead);
  }
  for(int i = 0; i < 8; i++)
  {
    if (readArrayB[i] == keyRead)
    {
      tone(buzzerPin, melodyB[i]);
    }
    if (readArrayC[i] == keyRead)
    {
      tone(testPin, melodyC[i]);
    }
    if ( keyRead == 'x')
    {
      noTone(buzzerPin);
      noTone(testPin);
    }
  }
  
}
