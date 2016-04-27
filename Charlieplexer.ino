#define LED_A 5
#define LED_B 6
#define LED_C 7
#define SLEEP 500

// 0 - simple
// 1 - bounce
// 2
#define PATTERN 2

void setup() {
  pinMode(LED_A, INPUT);
  pinMode(LED_B, INPUT);
  pinMode(LED_C, INPUT);
}

void loop() {
  switch (PATTERN) {
    case 0:
      simple();
      break;
    
    case 1:
      bounce();
      break;

    case 2:
      int a[0];
      a[0] = 1;
      a[1] = 2;
      a[2] = 3;
      a[3] = 4;
      light_n(a);
      break;
  }
}

void light_n(int list[]) {
  for (int i = 0; i < SLEEP / sizeof(list); i++) {
      for (int j = 0; j <= sizeof(list) + 1; j++) {
        light_led(list[j]);
        delay(1);
      }
  }
  reset_pins();
  delay(SLEEP);
}

void simple() {
  for (int i = 1; i <= 6; i++)
  {
    light_led(i);
    delay(SLEEP); 
  }
}

void bounce() {
  for (int i = 2; i < 5; i++)
  {
    light_led(i);
    delay(SLEEP); 
  }
  
  light_led(6);
  delay(SLEEP * 3);

  for (int i = 5; i > 1; i--)
  {
    light_led(i);
    delay(SLEEP);
  }

  light_led(1);
  delay(SLEEP * 3);
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

