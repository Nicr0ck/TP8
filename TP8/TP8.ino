#include <LiquidCrystal.h>


#define buzzerPin 13 
//  LiquidCrystal(rs, e, d4, d5, d6, d7)
LiquidCrystal lcd( 5, 6,  8,  9, 10, 11);
const int NOTE_C4 = 261;
const int NOTE_D4 = 293;
const int NOTE_E4 = 329;
const int NOTE_F4 = 349;
const int NOTE_G4 = 392;
const int NOTE_A4 = 440;
const int NOTE_B4 = 494;


int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,
};


int noteDurations[] = {
  250, 250, 250, 250, 250, 250, 250,
  250, 250, 250, 250, 250, 250, 250,
  
};

void setup() {
  pinMode(buzzerPin, OUTPUT);
  lcd.begin( 16 , 2 );
  Serial.begin(9600);
}

void loop() {
 
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int noteDuration = noteDurations[i];
    tone(buzzerPin, melody[i], noteDuration);
    lcd.setCursor( 2 , 0);
    lcd.print(melody[i]);
    delay(noteDuration);
    noTone(buzzerPin);
    lcd.clear();
  }
  
  delay(200);
}