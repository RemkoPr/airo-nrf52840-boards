#define NUM_DIGITAL_PINS 17


int digital_pins[NUM_DIGITAL_PINS ] = {D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15, D16};
int pin = 0;
int prev_pin = 1;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  for(int i = 0 ; i < NUM_DIGITAL_PINS ; i++) {
    pinMode(digital_pins[i], OUTPUT);
    digitalWrite(digital_pins[i], LOW);
  }
}

void loop() {
  Serial.print("Setting pin D");
  Serial.print(pin);
  Serial.println(" high");
  digitalWrite(digital_pins[pin], 128);
  Serial.print("Set pin D");
  Serial.print(pin);
  Serial.println(" high");
  digitalWrite(digital_pins[prev_pin], LOW);
  prev_pin = pin;
  pin++;
  if (pin == NUM_DIGITAL_PINS) {
    pin = 0;
  }
  delay(2000);
}
