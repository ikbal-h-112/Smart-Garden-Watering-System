#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
#include<Servo.h>
Servo watervalve;

int red_led=8;
int green_led=9;
int motor_power=12;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(red_led,OUTPUT); //red
  pinMode(green_led,OUTPUT);  
  pinMode(motor_power,OUTPUT);
  
//green
  watervalve.attach(10);
  
}

void loop() {
  int mlevel;
  mlevel=analogRead(A0);
  mlevel=map(mlevel,0,1023,100,0);
  lcd.clear();
  lcd.print("mois level=");
  lcd.print(mlevel);
  lcd.print("%");
  
  if(mlevel<40){
    digitalWrite(red_led,HIGH);
    digitalWrite(green_led,LOW);
    
    
  }else{
    digitalWrite(green_led,HIGH);
    digitalWrite(red_led,LOW);
  }
  

  if (mlevel<40){
         int valpos;
         valpos=map(mlevel,0,60,180,0);
         watervalve.write(valpos);
         delay(100);
  }else{
    
    watervalve.write(0);
  }
  //status
  
  lcd.setCursor(0,1);
  
  if (mlevel<40){
    lcd.print("watering");
    digitalWrite(motor_power,LOW);
    digitalWrite(green_led,HIGH);
    
  }else{
    lcd.print("not watering");
    digitalWrite(motor_power,HIGH);
    digitalWrite(green_led,HIGH);
  }
  delay(500);
}
