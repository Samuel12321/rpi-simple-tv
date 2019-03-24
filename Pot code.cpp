
// This sketch will send IR codes to my TV based on the position of a potentiometer or 10 position rotary switch.
// This code is public.
// This code is adapted from http://www.ladyada.net/learn/sensors/ir.html

int potPin = A0;    // The potentiometer is connected to analog pin 0
unsigned long timer = 0;    // Initializes a timer
int potValue = 0;    // Initializes the potentiometer reading to 0
int switchState = 0;    // Initializes the switch state to 0
int lastState = 0;    // Stores the last state of the switch
boolean checked = false;    // Checks to see if the channel has already been changed.

void setup() {
  pinMode(IRledPin, OUTPUT);    // sets the IR led pin to an output
}

void loop() {
  potValue = analogRead(potPin);    // Reads the value of the potentiometer and stores it as potValue
  
  // Maps the potentiometer value into 10 different evenly divided(if your pot is linear) states.
  switchState = potValue / 110;

  if (lastState != switchState) {
    timer = millis();
    lastState = switchState;
    checked = false;
  }

  if (millis() - timer == 1300 && !checked)
  {
    if(switchState == 0) {
      ESPN();
    } else if (switchState == 1) {
      ESPN2();
    } else if (switchState == 2) {
      ComedyCentral();
    } else if (switchState == 3) {
      NFLnetwork();
    } else if (switchState == 4) {
      CBS();
    } else if (switchState == 5) {
      ABC();
    } else if (switchState == 6) {
      NBC();
    } else if (switchState == 7) {
      TNT();
    } else if (switchState == 8) {
      SECnetwork();
    } else if (switchState == 9) {
      History();
    }
    checked = true;

  }


}
