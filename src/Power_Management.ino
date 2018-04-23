#include <Wire.h>
int val11;
int pinOut = 10;
int pinOut2 = 11;
//Leser spenning over pin 1 og relle 1 (inverter) er på pin 10 og relle 2 (lader) på pin 11

void setup()
{
  Serial.begin(9600);
  Serial.println("Voltage:");
  Serial.print("V");
  pinMode(pinOut, OUTPUT);
  pinMode(pinOut2, OUTPUT);
}
void loop()
{ 
  //leser spenning, regner om og skriver 
      float volt;
      val11=analogRead(1);
      volt=val11/40.90;
      Serial.println(volt);
     
//Spenning under 10,8 volt starter relle 2 i 10 sekunder, med påfølgende pause etterpå
  if (volt <= 10.8){
    digitalWrite(pinOut2, HIGH);
    delay(10000);
    //delay(1800000); (30 minutter)
    digitalWrite(pinOut2, LOW);
    delay(10000);
    //delay(600000); (10 minutter)
  }
  
//Spenning over 13 volt gjør at relle skal aktiveres og holdes i 10 sekunder, etter det ventes det 10 sekunder for å la batteriene få en pause
  if (volt >= 13){
    digitalWrite(pinOut, HIGH);
    //delay(10000);
    delay(1800000);
    digitalWrite(pinOut, LOW);
    //delay(10000);
    delay(600000);
  }
  


  //Pause på 10 sekunder for å la alt "sette seg" før hele repeteres
  //delay(10000); 
  delay(60000);           
}

