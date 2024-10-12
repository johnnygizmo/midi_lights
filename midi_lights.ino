#include <MIDI.h>

const int LEDS = 4;
const int CHANNEL = 6;

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // put your setup code here, to run once:
  MIDI.begin(CHANNEL);
  pinMode(LED_BUILTIN, OUTPUT);
  for(int i = 2;i<=LEDS+1;i++){
      pinMode(i, OUTPUT);
  }
  

  MIDI.setHandleControlChange(doHandleControlChange);

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);
  
  for(int i = 2;i<=LEDS+1;i++){
      digitalWrite(i, HIGH);
  }
  delay(500);                      // wait for a second
   for(int i = 2;i<=LEDS+1;i++){
      digitalWrite(i, LOW);
  } 

}


void doHandleControlChange(byte channel, byte number, byte value){
  for(int i = 2;i<=LEDS+1;i++){
    if(number == i){
      if(value == 0){
        digitalWrite(i, LOW);
      } else {
        digitalWrite(i, HIGH);
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  MIDI.read();
}
