#define NUM_DIGITAL_PINS 17


int digital_pins[NUM_DIGITAL_PINS ] = {D0, D1, D2, D3};
int pin = 0;
int prev_pin = 1;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  for(int i = 0 ; i < NUM_DIGITAL_PINS ; i++) {
    pinMode(digital_pins[i], OUTPUT);
    digitalWrite(digital_pins[i], HIGH);
  }
  Serial.println("Setup complete");
}

void loop() {
  delay(2000);
}
