#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ecrire ici le numero UID du bon badge
const byte bonUID[4] = {211, 33, 134, 25};
//

const int pinRST = 9; // pin RST du module RC522
const int pinSDA = 10; // pin SDA du module RC522
MFRC522 rfid(pinSDA, pinRST);
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{
SPI.begin();
rfid.PCD_Init();
Serial.begin(9600);
}
void loop()
{
  lcd.init();
  lcd.backlight();
String recu = "0"; // quand cette variable n'est pas nulle, c'est que le code est refusé
if (rfid.PICC_IsNewCardPresent()) // on a dédecté un tag
{
if (rfid.PICC_ReadCardSerial()) // on a lu avec succès son contenu
{
for (byte i = 0; i < rfid.uid.size; i++) // comparaison avec le bon UID
{
  Serial.print(rfid.uid.uidByte[i]);
  if(i< rfid.uid.size -1)
  {
    Serial.print(".");
  }
  else
  {
    Serial.print(",");
  }
}
Serial.flush();
}
}
if(Serial.available() > 0)
{
recu = Serial.readString();
if (recu.compareTo("0") != 0) // UID accepté
{
lcd.setCursor(3,0);
lcd.print("Bienvenue");
lcd.setCursor(2,1);
lcd.print(recu);
delay(2000);
}
else { // UID refusé
// allume LED rouge et active buzzer pendant 3 secondes
lcd.setCursor(2,0);
lcd.print("Acces refuse");
lcd.setCursor(2,1);
lcd.print("Carte refuse");
delay(2000);
}
}


}
