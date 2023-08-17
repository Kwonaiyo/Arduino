// #include <Key.h>
#include <Keypad.h>
// #include <Wire.h>

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'0', '1', '2', '3'},
  {'4', '5', '6', '7'},
  {'8', '9', 'a', 'b'},
  {'c', 'd', 'e', 'f'}
};
byte rowPins[ROWS] = {30, 32, 34, 36};
byte colPins[COLS] = {28, 26, 24, 22};
char customKey;
Keypad customKeyPad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
// Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// 세그먼트 디지털핀 13 ~ 7
int ledPin[7] = {13, 12, 11, 10, 9, 8, 7};

// 세그먼트에서 0을 출력하기 위한 배열
int num[7] = {0, 0, 0, 0, 0, 0, 1};

int A;
char password[4] = "ab12";  // 비밀번호
char inputNo[4];            // 입력할 4자리 번호

int iColor[3] = {53, 51, 49};
int buzzerPin = 52;
int ultraSensorOutput = 47;
char serialInput;   // 키보드로 받아오는 값 저장하는 변수.

int trigPin = 5;    // 초음파센서 trigger 핀
int echoPin = 6;    // 초음파센서 echo핀
float duration;
float distance;

void setup() {
  Serial.begin(9600);

  for(int i = 0; i < 3; i++)
  {
    pinMode(iColor[i], OUTPUT);
  }

  pinMode(buzzerPin, OUTPUT); // buzzer핀(출력)
  pinMode(trigPin, OUTPUT);   // 센서 Trigger핀 (출력)
  pinMode(echoPin, INPUT);    // 센서 echo핀 (입력)
  pinMode(ultraSensorOutput, OUTPUT);
  digitalWrite(ultraSensorOutput, HIGH);

  for(int i = 0; i < 7; i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
  for(int i = 0; i < 4; i++)
  {
    inputNo[i] = NULL;  // 입력할 4자리 번호 배열을 NULL로 초기화
  }

}

void keyPress();

void loop() {
  if(Serial.available()-1 > 0)
  {
    serialInput = Serial.read();
    Serial.println(serialInput);
  }

  if(serialInput == '1')
  {
    Serial.println("case 1: 3색 LED");

    for(int i = 0; i < 3; i++)
    {
      digitalWrite(iColor[i], HIGH);
      delay(1000);
      digitalWrite(iColor[i], LOW);
    }
  }

  else if(serialInput == '2')
  {
    Serial.println("case 2: music");

    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
  }

  else if(serialInput == '3')
  {
    Serial.println("case 3: Ultra Sensor");

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);  // Echo핀 : HIGH -> LOW 간격을 측정
    distance = (duration / 2) * 340 / 10000;

    Serial.print(distance);
    Serial.println(" cm");

    delay(300);

    if(distance > 12 && distance < 20)
    {
    tone(buzzerPin, 700);
      delay(1000);
      noTone(buzzerPin);
    }
    else if(distance >= 15 && distance < 30)
    {
      tone(buzzerPin, 700);
      delay(700);
      noTone(buzzerPin);
    }
    else if(distance >= 9 && distance < 15)
    {
      tone(buzzerPin, 700);
      delay(400);
      noTone(buzzerPin);
    }
    else if(distance >= 6 && distance < 9)
    {
      tone(buzzerPin, 700);
      delay(150);
      noTone(buzzerPin);
    }
    else if(distance >= 4 && distance < 6)
    {
      tone(buzzerPin, 700);
      delay(50);
      noTone(buzzerPin);
    }
    else if(distance < 4)
    {
      tone(buzzerPin,700);
    }
    else
    {
      noTone(buzzerPin);
    }
  }

  else if(serialInput == '4')
  {
    // Doorlock
    keyPress();
    if(inputNo[0] == password[0] && inputNo[1] == password[1] && inputNo[2] == password[2] && inputNo[3] == password[3])
    {
      for(int i = 0; i < 7; i++)
      {
        digitalWrite(ledPin[i], num[i]);
      }
    }
    else
    {
      for(int i = 0; i < 7; i++)
      {
        digitalWrite(ledPin[i], 1);
      }
    }
  }

}

void keyPress() {
  customKey = customKeyPad.getKey();
  A = int(customKey);
  if(customKey) {
    Serial.print("keyRead : ");
    Serial.println(customKey);
    delay(100);
    if(inputNo [0] == NULL)
    {
      inputNo[0] = customKey;
    }
    else if(inputNo[1] == NULL)
    {
      inputNo[1] = customKey;
    }
    else if(inputNo[2] == NULL)
    {
      inputNo[2] = customKey;
    }
    else if(inputNo[3] == NULL)
    {
      inputNo[3] = customKey;
    }
    else
    {
      for(int i = 0; i < 4; i++)
      {
        inputNo[i] = NULL;
      }
      inputNo[0] = customKey;
    }
    Serial.print("inputNo : ");
    Serial.println(inputNo);
  }
}
 