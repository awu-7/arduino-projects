# Metronome
An Arduino metronome with a knob for BPM and IR remote for start/stop.

## Demo
[Demo video](https://youtu.be/4xl-vEYMi6w)

## Hardware
- UNO R3
- Active buzzer
- IR receiver module and remote control
- I2C LCD1602
- Potentiometer

## Wiring
| Component | Pin |
|-----------|-----|
| Buzzer | 8 |
| IR receiver | 11 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| Potentiometer (wiper) | A0 |  
All other pins to 5V or GND

## Libraries
- IRremote
- LiquidCrystal_I2C

## Setup
1. Install the above libraries in the Arduino IDE
2. Upload [IR-remote-setup.ino](IR_remote_setup) and follow the instructions
4. Open [metronome.ino](metronome) and update the button defines at the top
5. Upload `metronome.ino`

## Notes
- BPM range is the standard 40-208 BPM, but this can be changed
- If the display isn't working, you may need to use an I2C scanner sketch. Find your I2C address and replace '0x27' on line 26 of ``` metronome.ino ```
