#define LED_A 5
#define LED_B 6
#define LED_C 7
#define SLEEP 50

void setup() {
  pinMode(LED_A, INPUT);
  pinMode(LED_B, INPUT);
  pinMode(LED_C, INPUT);
}

void loop() {
  // loop through one at a time
  for (int i=1; i<=6; i++)
  {
    light_led(i);
    delay(SLEEP); 
  }
}

void reset_pins() {
  pinMode(LED_A, INPUT);
  pinMode(LED_B, INPUT);
  pinMode(LED_C, INPUT);
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_C, LOW);
}

void set_pins(int high_pin, int low_pin) {
  reset_pins();

  // set the high and low pins to output
  pinMode(high_pin, OUTPUT);
  pinMode(low_pin, OUTPUT);

  // set logic as required
  digitalWrite(high_pin, HIGH);
  digitalWrite(low_pin, LOW);
}

void light_led(int led_num) {
  switch (led_num) {
  case 1:
    set_pins(LED_B, LED_A);
    break;
  case 2:
    set_pins(LED_A, LED_B);
    break;
  case 3:
    set_pins(LED_C, LED_B);
    break;
  case 4:
    set_pins(LED_B, LED_C);
    break;
  case 5:
    set_pins(LED_C, LED_A);
    break;
  case 6:
    set_pins(LED_A, LED_C); 
    break;
  }
}

