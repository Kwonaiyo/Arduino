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
  {'c', 'd', 'e', 'f'}
};
byte rowPins[ROWS] = {30, 32, 34, 36};
byte colPins[COLS] = {28, 26, 24, 22};
char customKey;
char data;
int iData;
Keypad customKeyPad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int danNo[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int crossNo[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int Gugu[9][9];

void setup()
{
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Hello, world!");
  lcd.setCursor(5,1);
  lcd.print("Gugudan");
  for(int dan = 0; dan < 9; dan++)
  {
    for(int cn = 0; cn < 9; cn++)
    {
      Gugu[dan][cn] = (dan + 1) * (cn + 1);
    }
  }
}


void loop()
{
  keyPress();
  // lcd.setCursor(7, 1);
  // lcd.print(data);
 

  if( iData >= 1 && iData <= 9)
  {
    lcd.init();
    Serial.print("iData = : ");
    Serial.println(iData);
    lcd.setCursor(0,0);
    lcd.print(iData);
    lcd.setCursor(2, 0);
    lcd.print("X");
    for(int i = 1; i < 10; i++)
    {
      if( iData == i)
      {
        for(int j = 0; j < 9; j++)
        {
          lcd.setCursor(4, 0);
          lcd.print(j+1);
          lcd.setCursor(0, 1);
          lcd.print(Gugu[i-1][j]);
          delay(1000);
        }
      }
    }
    iData = -1;
    delay(500);
    lcd.clear();
  }
  // if(iData > 9)
  // {
  //   lcd.init();
  //   lcd.setCursor(0,0);
  //   lcd.print("Input Data : ");
  //   lcd.setCursor(0,1);
  //   lcd.print(data);
  // }
}

void keyPress() {
  customKey = customKeyPad.getKey();
  if(customKey) {
    Serial.println(customKey);
    data = customKey;
    iData = data - 48;
    delay(100);
  }
}


