#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>

#define irPIN 11 // pin for remote input
#define buzzerPIN 8

// map remote buttons
#define BTN_P 0x45  // power
#define BTN_S 0x47  // start/stop

/* Unused buttons, might use for another project
#define BTN_U 0x9   // bpm up
#define BTN_D 0x7   // bpm down
#define BTN_0 0x16
#define BTN_1 0xC
#define BTN_2 0x18
#define BTN_3 0x5E
#define BTN_4 0x8
#define BTN_5 0x1c
#define BTN_6 0x5A
#define BTN_7 0x42
#define BTN_8 0x52
#define BTN_9 0x4A 
*/

LiquidCrystal_I2C lcd(0x27, 16, 2);

int BPM = 120; 
bool active = false;
unsigned long lastBeat = 0;     // used for buzzer timing
unsigned long lastDisplay = 0;  // used for refreshing the LCD

void setup() {

  pinMode(buzzerPIN, OUTPUT);
  IrReceiver.begin(irPIN);

  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("Metronome");
  delay(2000);
  lcd.clear();
}

void loop() {

  BPM = map(analogRead(A0), 0, 1023, 40, 208);

  // update display
  if (millis() - lastDisplay >= 250) {
    lastDisplay = millis();
    lcd.backlight();
    lcd.setCursor(0, 0);
    if (active) {
      lcd.print("BPM: ");
      lcd.print(BPM);
      lcd.print("   ");
    } else {
      lcd.print("BPM: --- "); // display when metronome is off
    }
  }
  // handle the remote control input
 if (IrReceiver.decode()) {
    // ignore repeat inputs from holding down button
    if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) {
      IrReceiver.resume();
      return;
    }
    int code = IrReceiver.decodedIRData.command;
    IrReceiver.resume();
    if (code == BTN_P) active = !active; // switch metronome on and off
}

  // handle the buzzer timing
  unsigned long interval = 60000 / BPM;
  if (active && millis() - lastBeat >= interval) {
    lastBeat = millis();
    digitalWrite(buzzerPIN, HIGH);
    delay(20);
    digitalWrite(buzzerPIN, LOW);
  }
}
