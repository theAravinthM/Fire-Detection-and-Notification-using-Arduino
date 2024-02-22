// MULTIPLE ARDUINOS - SLAVE ARDUINO 1
#include <Wire.h>

const int piezo = 7;
const int GS1 = A0;
const int GS2 = A1;
double SensedValue =0;
int threshold = 110;

void setup()
{
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  double A = GasSensor(GS1);
  double B = GasSensor(GS2);
  
  Serial.print("GasSensor1 : ");
  Serial.println(A);
  
  Serial.print("GasSensor2 : ");
  Serial.println(B);
  
  // BUZZER ALARM CONDITION
  if((A>threshold)||(B>threshold)){
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    
    // NOTIFICATION CONDITIONS
    if((A>threshold) && (B<=threshold)){
    Serial.println("Fire is near Exit-1.\nUse Exit-2 staircase..!");
    }
    if((B>threshold) && (A<=threshold)){
      Serial.println("Fire is near Exit-2.\nUse Exit-1 staircase..!");
    }
    if((A>threshold) && (B>threshold)){
      Serial.println("Fire is on both sides.\nUse EMERGENCY EXIT SOON..!");
    }
    //---
  }
  else{
    digitalWrite(7,LOW);
    Serial.println("No Fire detected :-)");
  }
  //---
  Serial.println("\n");
  
  delay(3000);
}

// function to get the temperature values
double GasSensor(int a)
{
  SensedValue = analogRead(a);
  return SensedValue;
}
