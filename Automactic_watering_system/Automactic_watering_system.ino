#include <LiquidCrystal.h>  //Thêm thư viện LiquitCrystal - nó có sẵn vì vậy bạn không cần cài thêm gì cả

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);  //Khởi tạo với các chân

float Doamdat;

void setup() {



  Serial.begin(9600);  //Mở cổng Serial ở mức 9600

  pinMode(2, INPUT_PULLUP);

  pinMode(A0, INPUT_PULLUP);

  pinMode(13, OUTPUT);

  lcd.begin(16, 2);  //Thông báo đây là LCD 1602
}

void loop() {

  int Doamdat = analogRead(A0);  //Đọc giá trị chân A0



  Serial.print("Độ ẩm là:");  //in chữ ra Serial Monitor



  Serial.print(Doamdat * 100 / 1000);  //in giá trị đo được ra Serial Monitor



  if (Doamdat < 500)



  {

    digitalWrite(13, LOW);

    Serial.println("Cây đủ nước");  //in chữ ra Serial Monitor

    lcd.setCursor(0, 1);

    lcd.print("Cay du nuoc   ");  //in chữ ra màn hình LCD



  }

  else {



    digitalWrite(13, HIGH);

    Serial.println("Thiếu nước, cần tưới cây");  //in chữ ra Serial Monitor

    lcd.setCursor(0, 1);

    lcd.print("Cay thieu nuoc");  //in chữ ra màn hình LCD
  }



  delay(1000);

  lcd.noDisplay();

  delay(100);

  lcd.display();

  delay(100);