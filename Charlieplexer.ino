#define LED_A 4
#define LED_B 5
#define LED_C 6
#define LED_D 7
#define SLEEP 50
#define CHASE_WIDTH 5
#define LIGHTS 15

// 0 - simple
// 1 - bounce
// 2 - chaser
#define PATTERN 2

void setup() {
  //Serial.begin(9600);
  pinMode(LED_A, INPUT);
  pinMode(LED_B, INPUT);
  pinMode(LED_C, INPUT);
  pinMode(LED_D, INPUT);
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
  for (int i = 1; i <= LIGHTS; i++)
  {
    light_led(i);
    delay(SLEEP); 
  }

  Serial.println("------");
}

void bounce() {
  for (int i = 1; i <= LIGHTS; i++) {
    light_led(i);
    delay(SLEEP); 
  }

  for (int i = LIGHTS; i >= 1; i--) {
    light_led(i);
    delay(SLEEP);
  }
}

void reset_pins() {
  pinMode(LED_A, INPUT);
  pinMode(LED_B, INPUT);
  pinMode(LED_C, INPUT);
  pinMode(LED_D, INPUT);
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_C, LOW);
  digitalWrite(LED_D, LOW);
}

void set_pins(int high_pin, int low_pin) {
  reset_pins();

  // set the high and low pins to output
  pinMode(high_pin, OUTPUT);
  pinMode(low_pin, OUTPUT);

  // set logic as required
  //Serial.print(high_pin);
  //Serial.print(" HIGH, ");
  digitalWrite(high_pin, HIGH);

  //Serial.print(low_pin);
  //Serial.println(" LOW");
  digitalWrite(low_pin, LOW);

  //Serial.println("");
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
    
  case 7:
    set_pins(LED_D, LED_A); 
    break;  
  case 8:
    set_pins(LED_A, LED_D); 
    break;
      
  case 9:
    set_pins(LED_D, LED_B); 
    break;
  case 10:
    set_pins(LED_B, LED_D); 
    break;

  case 11:
    set_pins(LED_D, LED_C); 
    break;

  case 12:
    set_pins(LED_C, LED_D); 
    break;
  }
}

