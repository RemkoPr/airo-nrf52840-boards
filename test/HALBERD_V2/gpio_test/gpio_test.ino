#define NUM_ANALOG_PINS 8


int analog_pins[NUM_ANALOG_PINS] = {A0, A1, A2, A3, A4, A5, A6, A7};
int apin = 6;
int prev_apin = 1;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  for(int i = 0 ; i < NUM_ANALOG_PINS ; i++) {
    pinMode(analog_pins[i], OUTPUT);
    digitalWrite(analog_pins[i], LOW);
  }
}

void loop() {
  Serial.print("Setting pin A");
  Serial.print(apin);
  Serial.println(" high");
  analogWrite(analog_pins[apin], 128);
  Serial.print("Set pin A");
  Serial.print(apin);
  Serial.println(" high");
  //digitalWrite(analog_pins[prev_apin], LOW);
  prev_apin = apin;
  apin++;
  if (apin == NUM_ANALOG_PINS) {
    apin = 0;
  }
  delay(2000);
}
