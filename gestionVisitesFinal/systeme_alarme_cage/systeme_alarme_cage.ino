#define PIN_BUZZER 13 //numéro de la broche sur laquelle le buzzer est branché 
#define PIN_LED_ROUGE 12 

#define PIN_Capteur 6

char data; //variable contenant le caractère lu

void setup() {
  pinMode(PIN_BUZZER, OUTPUT);//initialisation de la broche du buzzer
  pinMode(PIN_LED_ROUGE, OUTPUT);//initialisation de la broche de la led rouge
  digitalWrite(PIN_LED_ROUGE, LOW);


  pinMode(PIN_Capteur, INPUT);

   Serial.begin(9600); //permet d'initialiser le moniteur série à 9600 bauds

}

void loop() {
 
      if(digitalRead(PIN_Capteur)==HIGH){
        Serial.println('1');
        delay(2000);
      }
      /*if(digitalRead(PIN_Capteur)==LOW){
        Serial.println('0');
        delay(100);
      }*/
    if(Serial.available()){ 
    data=Serial.read();
    if(data=='1')
    {
      digitalWrite(PIN_LED_ROUGE, HIGH);
      tone(13,900);
      delay(2000);
      noTone(13);
      digitalWrite(PIN_LED_ROUGE, LOW);
      
    }  
    /*exit(0);*/
  }
  
}
