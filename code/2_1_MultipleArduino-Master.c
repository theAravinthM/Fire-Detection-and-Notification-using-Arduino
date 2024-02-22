// MULTIPLE ARDUINOS - MASTER ARDUINO
#include <Wire.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(8)==HIGH && digitalRead(9)==HIGH && digitalRead(10)==HIGH)
  {
    Serial.println("FIRE is in all the Buildings! EXIT soon..");
  }
  else if(digitalRead(8)==HIGH && digitalRead(9)==HIGH)
  {
    Serial.println("FIRE is near Building 1 & 2. Don't go there..");
  }
  else if(digitalRead(9)==HIGH && digitalRead(10)==HIGH)
  {
    Serial.println("FIRE is near Building 2 & 3. Don't go there..");
  }
  else if(digitalRead(8)==HIGH && digitalRead(10)==HIGH)
  {
    Serial.println("FIRE is near Building 1 & 3. Don't go there..");
  }
  else if(digitalRead(8)==HIGH)
  {
    Serial.println("Fire is near Building 1.. You can go to Building 2 & 3..");
  }
  else if(digitalRead(9)==HIGH)
  {
    Serial.println("Fire is near Building 2.. You can go to Building 1 & 3..");
  }
  else if(digitalRead(10)==HIGH)
  {
    Serial.println("Fire is near Building 3.. You can go to Building 1 & 2..");
  }
  
  delay(3000);
}
