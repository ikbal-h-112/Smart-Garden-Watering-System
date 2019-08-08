#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
#include<Servo.h>
Servo watervalve;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(8,OUTPUT); //red
  pinMode(9,OUTPUT);  //green
  watervalve.attach(10);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int mlevel;
  mlevel=analogRead(A0);
  mlevel=map(mlevel,0,1023,100,0);
  // displaying the moislevel
  lcd.clear();
  lcd.print("mois level=");
  lcd.print(mlevel);
  lcd.print("%");
  
  //red green indicator
  if(mlevel<60){
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    
  }else{
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
  }
  

  if (mlevel<60){
    int valpos;
    valpos=map(mlevel,0,60,180,0);
    watervalve.write(valpos);
    delay(100);
  }else{
    watervalve.write(0);
  }
  //status
  lcd.setCursor(0,1);
  if (mlevel<60){
    lcd.print("watering");
    
    
  }else{
    lcd.print("not watering");
  }
  delay(500);
}
