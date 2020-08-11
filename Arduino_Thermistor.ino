int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

#include <LiquidCrystal.h>

LiquidCrystal lcd(10, 8, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

void setup() {
Serial.begin(9600);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(9, OUTPUT);

}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0)/ 5.0 + 32.0; 

  Serial.print("Temperature: "); 
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");

lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print("Temperature: "); 
lcd.setCursor(0, 1);
lcd.print(Tf);
lcd.print(" F; ");
lcd.print(Tc);
lcd.println(" C");
delay(1000);

 if(Tc > 35.0){
  Serial.print("OVERHEAT ")
 ;}

 if(Tc < 33.0){
  Serial.print("COOL ")
 ;}
else{
  Serial.print("");
 ;}
 
  if(Tc < 35.0&&Tc > 33.0){
  Serial.print("HEATING ")
 ;}
 else{
  Serial.print("");
 ;}

if(Tc < 33.0){
  digitalWrite(13, HIGH);
 ;}
 else{
  digitalWrite(13, LOW);
 ;}

 if(Tc > 33.0){
  digitalWrite(12, HIGH);
 ;}
 else{
  digitalWrite(12, LOW);
 ;}
 if(Tc > 35.0){
  digitalWrite(12, LOW);
 ;}
 
  if(Tc > 35.0){
  digitalWrite(11, HIGH);
 ;}
 else{
  digitalWrite(11, LOW);
 ;}
 
  delay(1000);

 if(Tc > 35.0){
  tone(9, 500);
  delay(1000);
  noTone(9);
  delay(2000)
 ;}

}
