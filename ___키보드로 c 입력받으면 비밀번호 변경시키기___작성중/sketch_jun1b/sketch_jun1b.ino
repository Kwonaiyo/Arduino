#include <Keypad.h>
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
Keypad customKeyPad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// 세그먼트 디지털 핀 13~7
int ledPin[7] = {13, 12, 11, 10, 9, 8, 7};

int num[7] {0, 0, 0, 0, 0, 0, 1};  // 0 


int A;
char password[4] = "ab12";
char inputNo[4];
char readType;
char keyTyping;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 7; i++){
    pinMode(ledPin[i],OUTPUT);
  }
  for(int i = 0; i < 4; i++)
  {
    inputNo[i] = NULL;
  }
  
}
void keyPress();

void loop() {
  keyPress();
  if(Serial.available() > 0)
  {
    keyTyping = Serial.read();
    if(keyTyping == 'c' || keyTyping == 'C')
    {
      Serial.println("바꿀 비밀번호 4자리 입력")
      readType = Serial.read();      
    }
  }
  passwordOX();
  
}

void passwordChange()
{

}

void passwordOX()
{
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

void keyPress() {
  
  customKey = customKeyPad.getKey();
  A = int(customKey);
  if (customKey) {
    Serial.print("keyRead : ");
    Serial.println(customKey);
    delay(100);
    if(inputNo[0] == NULL)
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
