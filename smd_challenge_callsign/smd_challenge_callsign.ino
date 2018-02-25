/*
  ATMEL ATTINY45/85 Pin Assignments
                   +-\/-+
  Ain0 (D 5) PB5  1|    |8  Vcc
  Ain3 (D 3) PB3  2|    |7  PB2 (D 2) Ain1
  Ain2 (D 4) PB4  3|    |6  PB1 (D 1) pwm1
             GND  4|    |5  PB0 (D 0) pwm0

*/


int LEDS[] = {0, 1, 2, 3, 4};
bool STATES[] = {true, true, true, true, true};


// Pins are different between Arduino and Attiny
#if defined(__AVR_ATtiny85__)
#define ARDUINO 0
#define ledPin 0
#define lightPin 3    // CdS or pushbutton hooked from PB4 (Pin 3, A2/D4) to ground
#define lightPullUp 3
#define touchPin 1
#define touchPullUp 2
#else
#define ARDUINO 1
#define ledPin 9  // RGB red
#define lightPin A1
#define lightPullUp A1
#define touchPin A3
#define touchPullUp A3
#endif

//intra char delay
int ict = 300;
//intra element timing
int iet = 75;
//dit length
int ditlen = 200;
int dahlen = 200;


void setup() {
  for (int LED = 0; LED < (sizeof(LEDS) / sizeof(int)); LED++) {
    pinMode(LEDS[LED], OUTPUT);
    digitalWrite(LEDS[LED], STATES[LED]);
  }
}

void loop() {

  all_off();
  de(0);
  w(1);
  o(2);
  nine(3);
  u(4);
}


void w(int el) {
  dit(el);
  dah(el);
  dah(el);
  delay(ict);
}

void o(int el) {
  dah(el);
  dah(el);
  dah(el);
  delay(ict);
}

void nine(int el) {
  dah(el);
  dah(el);
  dah(el);
  dah(el);
  dit(el);
  delay(ict);
}

void u(int el) {
  dit(el);
  dit(el);
  dah(el);
  delay(ict);
}

void de(int el) {
  dah(el);
  dit(el);
  dit(el);
  delay(ict);
  dit(el);
  delay(ict);

}


void all_off() {
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void dit(int pin) {
  digitalWrite(pin, HIGH);
  delay(ditlen);
  digitalWrite(pin, LOW);
  delay(iet);
}


void dah(int pin) {
  digitalWrite(pin, HIGH);
  delay(dahlen);
  digitalWrite(pin, LOW);
  delay(iet);
}
