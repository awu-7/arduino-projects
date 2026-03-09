// define pin number
const int PIN = 8;

// define note frequencies
// reference: https://mixbutton.com/music-tools/frequency-and-pitch/music-note-to-frequency-chart
// note: frequencies are slightly rounded, sorry if you have perfect pitch

#define C3  131
#define D3  147
#define E3  165
#define F3  175
#define G3  196
#define A3  220
#define B3  247

#define C4  262
#define D4  294
#define E4  330
#define F4  349
#define G4  392
#define A4  440
#define B4  494

#define C5  523
#define D5  587
#define E5  659
#define F5  698
#define G5  784
#define A5  880
#define B5  988

// sharps/flats
#define CS3 139  // C#3 / Db3
#define DS3 156  // D#3 / Eb3
#define FS3 185  // F#3 / Gb3
#define GS3 208  // G#3 / Ab3
#define AS3 233  // A#3 / Bb3

#define CS4 277
#define DS4 311
#define FS4 370
#define GS4 415
#define AS4 466

#define CS5 554
#define DS5 622
#define FS5 740
#define GS5 831
#define AS5 932

// define note durations

#define BPM 110 // Change this

#define Q (60000 / BPM) // quarter note
#define H (Q * 2)       // half note
#define W (Q * 4)       // whole note
#define E (Q / 2)       // eighth note
#define S (Q / 4)       // sixteenth note

// default: Fire Emblem Main Theme
int melody[] = {
  A3, D4, FS4, FS4, B3, B3, CS4, D4, E4, D4, CS4, A3, D4, FS4, A4, G4, FS4, B3, CS4, D4, E4, E4 // change this
  }; 

// note durations can be added together for legato
// corresponds with the same index note in melody[]
int durations[] = {
  H, Q, Q, H, H, H+E, E, E, E, H, H, H, Q, Q, H, Q, Q, H+E, E, E, E, W // change this
}; 

int notes = sizeof(melody) / sizeof(melody[0]); // get the number of notes for loop

void setup() {
}

void loop() {
  for (int i = 0; i < notes; i++) {
    tone(PIN, melody[i], durations[i]);
    delay(durations[i] * 1.1);
  }
  noTone(PIN);
  delay(1000);
  }