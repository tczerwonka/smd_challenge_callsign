/*
  ATMEL ATTINY45/85 Pin Assignments
                   +-\/-+
  Ain0 (D 5) PB5  1|    |8  Vcc
  Ain3 (D 3) PB3  2|    |7  PB2 (D 2) Ain1
  Ain2 (D 4) PB4  3|    |6  PB1 (D 1) pwm1
             GND  4|    |5  PB0 (D 0) pwm0

*/


// this code is not at all clever, but it got the job done in less than an hour.
// T Czerwonka WO9U
// 24 Feb 2018
// https://github.com/tczerwonka/smd_challenge_callsign

//intra char delay
int ict = 2;
//intra element timing
int iet = 8;
//dit length
int ditlen = 2;
int dahlen = 10;
int factor = 190;


void setup() {
  for (int LED = 0; LED < 5; LED++) {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
  }
}




void loop() {

  throb(0, 5);
  delay(8000);
  roll();
  roll();
  roll();
  roll();
  roll();
  //fade();
  //fade();
  delay(8000);

  de(0);
  delay(2000);
  w(1);
  o(2);
  nine(3);
  u(4);
  delay(8000);

}




void throb(int led, int times) {
  for (int repeat = 0; repeat < times; repeat++) {
    for (int br = 0; br < 255; br++) {
      analogWrite(led, br);
      delay(13);
    }
    for (int br = 254; br > 0; br--) {
      analogWrite(led, br);
      delay(15);
    }
    digitalWrite(led, LOW);
    delay(1500);
  }

}



void roll() {
  for (int LED = 0; LED < 5; LED++) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
  }
  for (int LED = 4; LED > -1; LED--) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
  }
}

void fade() {
  for (int LED = 0; LED < 5; LED++) {
    for (int br = 0; br < 255; br++) {
      analogWrite(LED, br);
      delay(1);
    }
    for (int br = 254; br > 0; br--) {
      analogWrite(LED, br);
      delay(1);
    }
    digitalWrite(LED, LOW);

  }
  for (int LED = 4; LED > -1; LED--) {
    for (int br = 0; br < 255; br++) {
      analogWrite(LED, br);
      delay(1);
    }
    for (int br = 254; br > 0; br--) {
      analogWrite(LED, br);
      delay(1);
    }
    delay(100);
    analogWrite(LED, 0);
  }
}

void w(int el) {
  dit(el);
  dah(el);
  dah(el);
  delay(ict * factor);
}

void o(int el) {
  dah(el);
  dah(el);
  dah(el);
  delay(ict * factor);
}

void nine(int el) {
  dah(el);
  dah(el);
  dah(el);
  dah(el);
  dit(el);
  delay(ict * factor);
}

void u(int el) {
  dit(el);
  dit(el);
  dah(el);
  delay(ict * factor);
}

void de(int el) {
  dah(el);
  dit(el);
  dit(el);
  delay(ict * factor);
  dit(el);
  delay(ict * factor);

}


void dit(int pin) {
  digitalWrite(pin, HIGH);
  delay(ditlen * factor);
  digitalWrite(pin, LOW);
  delay(iet * factor);
}


void dah(int pin) {
  digitalWrite(pin, HIGH);
  delay(dahlen * factor);
  digitalWrite(pin, LOW);
  delay(iet * factor);
}
