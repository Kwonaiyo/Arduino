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

int num[10][7] {
  {0, 0, 0, 0, 0, 0, 1},  // 0  
  {1, 0, 0, 1, 1, 1, 1},  // 1
  {0, 0, 1, 0, 0, 1, 0},  // 2
  {0, 0, 0, 0, 1, 1, 0},  // 3
  {1, 0, 0, 1, 1, 0, 0},  // 4
  {0, 1, 0, 0, 1, 0, 0},  // 5
  {0, 1, 0, 0, 0, 0, 0},  // 6
  {0, 0, 0, 1, 1, 1, 1},  // 7
  {0, 0, 0, 0, 0, 0, 0},  // 8
  {0, 0, 0, 1, 1, 0, 0}   // 9
};

int alphabet[6][7] {
  {0, 0, 0, 1, 0, 0, 0}, // A
  {0, 0, 0, 0, 0, 0, 0}, // B
  {0, 1, 1, 0, 0, 0, 1}, // C
  {1, 0, 0, 0, 0, 1, 0}, // D
  {0, 1, 1, 0, 0, 0, 0}, // E
  {0, 1, 1, 1, 0, 0, 0}, // F
};
int A;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 7; i++){
    pinMode(ledPin[i],OUTPUT);
  }

}
void keyPress();

void loop() {
  keyPress();
  if(isDigit(customKey) == true) // 0~9까지
  {
    for(int i = 48; i < 58; i++)
    {
      if(A == i)
      {
        for(int j = 0; j < 7; j++)
        {
          digitalWrite(ledPin[j], num[A-48][j]);
        }
      }
    }
  }
  if(isAlpha(customKey) == true)
  {
    for(int i = 97; i < 103; i++)
    {
      if( A == i)
      {
        for(int j = 0; j < 7; j++)
        {
          digitalWrite(ledPin[j], alphabet[A-97][j]);
        }
      }
    }
  }
}

void keyPress() {
  customKey = customKeyPad.getKey();
  A = int(customKey);
  if (customKey) {
    Serial.println(customKey);
    delay(100);
  }
}
