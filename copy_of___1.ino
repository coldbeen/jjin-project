#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int RLED=8;    // 빨간색 LED 상수형변수에 아두이노 8번 핀 할당
const int GLED=9; // 녹색 LED 상수형변수에 아두이노 9번 핀 할당
const int BLED=10; //파란색 LED 상수형변수에 아두이노 10번 핀 할당
const int TEMP=0;     // 아날로그 입력 0번(A0) 핀 선언
const int LOWER_BOUND=163;      // 온도 하한 값을 정의 함
const int UPPER_BOUND=169;       // 온도 상한 값을 정의 함
int val=0;                      // 온도 센서의 현재 값을 저장하는 변수 선언
byte SpecialChar1[8] = { B00010,  B00101,  B00101, B00010,
 B00000,  B00000,  B00000,  B00000   };

void setup() {
  Serial.begin(9600);
  pinMode(RLED, OUTPUT);        // RLED를 출력으로 지정
  pinMode(GLED, OUTPUT);        // GLED를 출력으로 지정
  pinMode(BLED, OUTPUT);        // BLED를 출력으로 지정
 
 
  lcd.begin(16, 2);
  lcd.clear();
  lcd.createChar(1,SpecialChar1);     
}

void loop() {
  val=analogRead(TEMP); 
  Serial.println(val);
  float mVoltage = val*5000.0/1024.0;
  float TempDotC = (mVoltage - 500) / 10.0;
  Serial.print(TempDotC);     Serial.println("℃\n");
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(TempDotC);
  lcd.write(1);      
  lcd.print("C"); 
  delay(500);
  
   if(val < LOWER_BOUND) {       // 경계 값 비교     
    digitalWrite(RLED,LOW);
    digitalWrite(GLED,LOW);
    digitalWrite(BLED, HIGH);
   	lcd.setCursor(0,0); 
  	lcd.print("Too Low");} //  켜려고 하는 LED에 HIGH 값 지정
  else if (val>UPPER_BOUND) {//상위 경계선값 이상이면 Red LED ON
    digitalWrite(RLED,HIGH);
    digitalWrite(GLED, LOW); 
    digitalWrite(BLED, LOW);
  	lcd.setCursor(0,0); 
  	lcd.print("Too High");}
  else {  // 경계선 사이 값이라면 Green LED On
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);  
    digitalWrite(BLED, LOW);    }
  
  	
  
   


}
 