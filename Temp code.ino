#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Hello, IST3040 CLASS");
  pinMode(A2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  delay(2000);
  lcd.clear();
  lcd.print("Temp= ");
  lcd.setCursor(0,1);
  lcd.print("Fan= ");

}

void loop()
{
  //temperature sensor
      float b =0;
      float voltage=0;
      float celsius = 0;

      b=analogRead(A0);
      voltage=b*5000/1024;
      voltage=voltage-500;
      celsius=voltage/10;

      lcd.setCursor(6,0);
  lcd.print(celsius); 
  	
 

 //DC Motor
  
  if(celsius>32){
  digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
          digitalWrite(10, HIGH);
          digitalWrite(8,LOW);
          digitalWrite(9,LOW);
          Serial.print(" Temperature: ");
          Serial.print(celsius);
          Serial.println(" Fan is ON now"); 
          lcd.setCursor(5,1);
    lcd.print("ON ");
  }      
  else if(celsius > 25){
          digitalWrite(12, HIGH);
          digitalWrite(10, HIGH);
          digitalWrite(8,LOW);
          digitalWrite(9,LOW);
    		digitalWrite(11, LOW);
          Serial.print(" Temperature: ");
          Serial.print(celsius);
          Serial.println(" Fan is ON now"); 
          lcd.setCursor(5,1);
    lcd.print("ON ");
        }
  		else if(celsius<25 && celsius>20){
          digitalWrite(12, HIGH);
          digitalWrite(8, HIGH);
          digitalWrite(10,LOW);
          digitalWrite(9,LOW);
          digitalWrite(11, LOW);
          Serial.print(" Temperature: ");
          Serial.print(celsius);
          Serial.println(" Fan is Off now"); 
          lcd.setCursor(5,1);
          lcd.print("OFF ");
        }
  		else{
          digitalWrite(12, LOW);
          digitalWrite(9, HIGH);
          digitalWrite(8,LOW);
          digitalWrite(10,LOW);
          digitalWrite(11, LOW);
          Serial.print(" Temperature: ");
          Serial.print(celsius);
          Serial.println(" Fan is Off now"); 
          lcd.setCursor(5,1);
          lcd.print("OFF ");
        }

 
  
  //photoresistor
    
       int a=analogRead(A2);
        if(a<800){
          digitalWrite(13, HIGH);
          Serial.println(a);
          Serial.print(" LED ON");
        }
        else{
          digitalWrite(13,LOW);
          Serial.println(a);
          Serial.print(" LED OFF");
        }
  
}