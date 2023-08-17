//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'0', '1', '2', '3'},
  {'4', '5', '6', '7'},
  {'8', '9', 'a', 'b'},
  {'+', '-', '*', '/'}
};
byte rowPins[ROWS] = {30, 32, 34, 36};
byte colPins[COLS] = {28, 26, 24, 22};
char customKey;
char data = NULL;
int iData;
int totalCount;
int count;
char X;
int strA[10];
int strB[10];
Keypad customKeyPad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


void setup()
{
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Hello, world!");
  lcd.setCursor(3,1);
  lcd.print("Calculator");
  for(int i = 0; i < 10; i++)
  {
    strA[i] = NULL;
    strB[i] = NULL;
  }
  
}


void loop()
{
  keyPress(); // 여기서 data 값을 받아옴. A : +-*/, totalCount : 연산자 입력 전까지 입력한 숫자의 개수
  int frontNo[totalCount];
 
  // lcd.setCursor(7, 1);
  // lcd.print(data);

 
}

void keyPress() {
  customKey = customKeyPad.getKey();
  if(customKey) {
    Serial.println(customKey);
    data = customKey;
    iData = data - 48;
    getCount();
    doCalc();
    delay(100);
  }
}

void getCount()
{
  Serial.print("getCount : ");
  Serial.println(iData);
  if(iData >= 0 && iData <= 9)
  {
    count++;
    X = NULL;
    for(int i = 0; i < 10; i++)
      {
        if(strA[i] == NULL)
        {
          strA[i] = iData;
          iData = NULL;
        }
        for(int j = 0; j < 10; j++)
        {
          strA[j] = NULL;
        }
          strA[0] = iData;
        
      }
  }
  else if(data == '+' || data == '-' || data == '*' || data == '/')
  {
    totalCount = count;
    X = data;
    count = 0;
  }
  Serial.print("totalCount : ");
  Serial.println(totalCount);
  Serial.print("strA 출력:  ");
  for(int i = 0; i < 10; i++)
  {
    Serial.print(strA[i]);
  }
}

void doCalc()
{
  if(X != NULL)
  {
    if(iData >= 0 && iData <= 9)
    {
      for(int i = 0; i < 10; i++)
      {
        if(strB[i] == NULL)
        {
          strB[i] = iData;
          continue;
        }
        for(int j = 0; j < 10; j++)
        {
          strB[j] = NULL;
        }
      strB[0] = iData;
        
      }
    }
  }
  Serial.print("strB 출력:  ");
  for(int i = 0; i < 10; i++)
  {
    Serial.print(strB[i]);
  }
}

// void insertNum()
// {
//   if(!(data == '+' || data == '-' || data == '*' || data == '/'))
//   {
//     for(int i = 0; i < 10; i++)
//     {
//       numArray[i] = data;
//     }
//   }
//   for(int j = 0 ; j < 10; j++)
//   { Serial.print(numArray[j]); }
// }

