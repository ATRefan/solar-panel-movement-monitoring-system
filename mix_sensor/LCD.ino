void lcd_display(){

  //LCD title
  lcd.setCursor(0, 0);
  lcd.print("Solar Panel Monitor");

  //mpu6050
  lcd.setCursor(0, 2);
  lcd.print("z  : ");
  if(calPitch<10 && calPitch>=0){
    lcd.setCursor(5, 2);
    lcd.print(calPitch);
    lcd.setCursor(6, 2);
    lcd.print("  ");
  }else if(calPitch>=10 && calPitch<=95){
    lcd.setCursor(5, 2);
    lcd.print(calPitch);
    lcd.setCursor(7, 2);
    lcd.print(" ");
  }

  lcd.setCursor(0, 3);
  lcd.print("HRA: ");
  if(calRoll<-9 && calRoll>=-90){
    lcd.setCursor(4, 3);
    lcd.print(calRoll);
  }else if(calRoll>=-9 && calRoll<0){
    lcd.setCursor(4, 3);
    lcd.print(calRoll);
    lcd.setCursor(6, 3);
    lcd.print(" ");
  }else if(calRoll == 0){
    lcd.setCursor(4, 3);
    lcd.print(" ");
    lcd.setCursor(5, 3);
    lcd.print(calRoll);
    lcd.setCursor(6, 3);
    lcd.print(" ");
  }else if(calRoll>=1 && calRoll<10){
    lcd.setCursor(4, 3);
    lcd.print(" ");
    lcd.setCursor(5, 3);
    lcd.print(calRoll);
    lcd.setCursor(6, 3);
    lcd.print("  ");
  }else if(calRoll>=10 && calRoll<91){
    lcd.setCursor(4, 3);
    lcd.print(" ");
    lcd.setCursor(5, 3);
    lcd.print(calRoll);
  }
  
  //DS18B20
  lcd.setCursor(8,2);
  lcd.print("T1:");
  if(rPoly1>0 && rPoly1<10){
    lcd.setCursor(11, 2);
    lcd.print(rPoly1);
    lcd.setCursor(12, 2);
    lcd.print(" ");
  }else if(rPoly1>=10 && rPoly1<=90){
    lcd.setCursor(11, 2);
    lcd.print(rPoly1);
    lcd.setCursor(13, 2);
    lcd.print(" ");
  }
  
  lcd.setCursor(14,2);
  lcd.print("T2:");
  if(rPoly2>0 && rPoly2<10){
    lcd.setCursor(17, 2);
    lcd.print(rPoly2);
    lcd.setCursor(18, 2);
    lcd.print(" ");
  }else if(rPoly2>=10 && rPoly2<=90){
    lcd.setCursor(17, 2);
    lcd.print(rPoly2);
    lcd.setCursor(19, 2);
    lcd.print(" ");
  }
  
  

  //luxmeter
  lcd.setCursor(8,3);
  lcd.print("lx: ");
  if(luxCal>99999 && luxCal<=200000){
    lcd.setCursor(11, 3);
    lcd.print(luxCal);
  }else if(luxCal<=99999 && luxCal>9999){
    lcd.setCursor(11, 3);
    lcd.print(luxCal);
    lcd.setCursor(16, 3);
    lcd.print(" ");
  }else if(luxCal<=9999 && luxCal>999){
    lcd.setCursor(11, 3);
    lcd.print(luxCal);
    lcd.setCursor(15, 3);
    lcd.print("  ");
  }else if(luxCal<=999 && luxCal>99){
    lcd.setCursor(11, 3);
    lcd.print(luxCal);
    lcd.setCursor(14, 3);
    lcd.print("   ");
  }else if(luxCal<=99 && luxCal>9){
    lcd.setCursor(11, 3);
    lcd.print(luxCal);
    lcd.setCursor(13, 3);
    lcd.print("   ");
  }else if(luxCal<=9 && luxCal>=0){
    lcd.setCursor(11, 3);
    lcd.print(luxCal);
    lcd.setCursor(12, 3);
    lcd.print("   ");
  }
}