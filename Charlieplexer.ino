#define LED_A 5
#define LED_B 6
#define LED_C 7
#define SLEEP 50
#define CHASE_WIDTH 4
#define LIGHTS 6

// 0 - simple
// 1 - bounce
// 2 - chaser
#define PATTERN 2

void setup() {
  Serial.begin(9600);
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
      chaser(CHASE_WIDTH);
      break;
  }
}

void chaser(int width) {
  for (int i = 1 - width; i < LIGHTS + 1; i++) {
    light_some(i, width);
  }
}

void light_some(int start, int width) {
  for (int j = 0; j < SLEEP / width; j++) {
    for (int i = start; i < start + width; i++) {
      light_led(i);
      delay(1);
    }
  }
  reset_pins();
}

void simple() {
  for (int i = 1; i <= 6; i++)
  {
    light_led(i);
    delay(SLEEP); 
  }
}

void bounce() {
  for (int i = 1; i <= 6; i++) {
    light_led(i);
    delay(SLEEP); 
  }

  for (int i = 6; i >= 1; i--) {
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

