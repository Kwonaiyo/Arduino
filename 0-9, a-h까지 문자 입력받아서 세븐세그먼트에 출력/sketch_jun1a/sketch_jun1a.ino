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
int alphabet[8][7] {
  {0, 0, 0, 1, 0, 0, 0}, // A
  {0, 0, 0, 0, 0, 0, 0}, // B
  {0, 1, 1, 0, 0, 0, 1}, // C
  {1, 0, 0, 0, 0, 1, 0}, // D
  {0, 1, 1, 0, 0, 0, 0}, // E
  {0, 1, 1, 1, 0, 0, 0}, // F
  {0, 0, 0, 0, 1, 0, 0}, // g
  {1, 0, 0, 1, 0, 0, 0}  // H
};
char input;

void setup() {
  Serial.begin(9600);
  // 7개의 디지털 핀의 모드를 출력으로 변경
  for(int i = 0; i < 7; i++){
    pinMode(ledPin[i],OUTPUT);
  }
  pinMode(3, OUTPUT);
}

void loop() {
  if(Serial.available() > 0)
  {
    input = Serial.read();
    if(isDigit(input) == true){
    Serial.print("number = ");
    Serial.println(input);
    Serial.print("int(number) = ");
    Serial.println(int(input));
    }
  }

  if(isDigit(input) == true) // 0~9 까지의 값을 입력받아올때
  {
    int iNum = int(input);  // char인 input을 int로 변환
    for(int i = 48; i < 58; i++)
    {
      if(iNum == i)
      {
        for(int j = 0; j < 7 ; j++)
        {
          digitalWrite(ledPin[j], num[iNum-48][j]);
        }
      }
    }
  }
  if(isAlpha(input) == true)
  {
    int iNum = int(input);
    for(int i = 97; i < 105; i++)
    {
      if (iNum == i)
      {
       for(int j = 0; j < 7; j++)
       {
         digitalWrite(ledPin[j], alphabet[iNum-97][j]);
       }
      }
    }
      
  }

}
  // switch(int(number)) 
  // {
  //   case 48:  // 0
  //   {
  //     digitalWrite(led[0], 0);
  //     digitalWrite(led[1], 0);
  //     digitalWrite(led[2], 0);
  //     digitalWrite(led[3], 0);
  //     digitalWrite(led[4], 0);
  //     digitalWrite(led[5], 0);
  //     digitalWrite(led[6], 1);
  //     break;
  //   }
  //   case 49:  // 1
  //   {
  //     digitalWrite(led[0], 1);
  //     digitalWrite(led[1], 0);
  //     digitalWrite(led[2], 0);
  //     digitalWrite(led[3], 1);
  //     digitalWrite(led[4], 1);
  //     digitalWrite(led[5], 1);
  //     digitalWrite(led[6], 1);
  //     break;
  //   }
  //   case 50:
  //   {
  //     digitalWrite(led[0], 0);
  //     digitalWrite(led[1], 0);
  //     digitalWrite(led[2], 1);
  //     digitalWrite(led[3], 0);
  //     digitalWrite(led[4], 0);
  //     digitalWrite(led[5], 1);
  //     digitalWrite(led[6], 0);
  //     break;
  //   }


  // }
// }

// number = 0이면
// a b c d e f -> LOW
// g -> HIGH
// a LOW
// b LOW
// c LOW
// d LOG
// ...
// int a[10][7] = {
//   {0, 0, 0, 0, 0, 0, 1}, // 0 a[0][1]
//   {1, 0, 0, 1, 1, 1, 1}, // 1 a[1][]
// }
// 0이면 
// a[0][0] LOW
// a[0][1] LOW
// a[0][2] LOW
// ...
// a[0][6] HIGH


  // // 0~9까지 나타내는 i
  // for(int i = 0; i < 10; i++){
  //   // 7개의 세그먼트 led를 나타내는 j
  //   for(int j = 0; j < 7; j++){
  //     digitalWrite(led[j], !num[i][j]);
  //   }
  //   digitalWrite(3, 1);
  //   delay(500);
  //   digitalWrite(3, 0);
  //   delay(500);
  // }
// }