/* Use this sketch to set up your IR remote. 
After uploading, open the serial monitor.
Press each button you want to use and record the output. 
Buttons will be mapped in the main sketch metronome.ino */

#include <IRremote.hpp>
#define RECEIVE_PIN 2 // connect the IR receiver module to this pin

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECEIVE_PIN);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    Serial.println(IrReceiver.decodedIRData.command, HEX); 
    // you don't have to use hex, but if you do, make sure to put 0x in front of the serial monitor output when mapping
  }
}


