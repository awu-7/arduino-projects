# Simple Melody Player for Arduino 
Plays a melody given user-defined arrays of notes and durations. Note frequencies are defined. User can change the BPM and note durations will be calculated automatically. 

## Setup
- No libraries needed
- Change the ``melody[]`` and ``durations[]`` arrays to whatever you want

## Wiring
| Component | Pin |
|-----------|-----|
| Buzzer + | 8 |
| Buzzer - | GND |

## Hardware
- Requires any Arduino-compatible dev board and a passive buzzer
- For wiring, connect any digital I/O pin to the buzzer's positive leg and GND to negative
  - I used pin 8 on the Uno R3
