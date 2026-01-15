#include <Arduino.h>

void setup() {
  const uint32_t pin = D0; // Example: D13
  pinMode(pin, OUTPUT);

  // Get the underlying nRF pin number (for Arduino Nano 33 BLE)
  uint32_t nrf_pin = g_APinDescription[pin].ulPin;

  // Configure GPIO drive: H0H1 (high drive for both high and low)
  NRF_GPIO->PIN_CNF[nrf_pin] =
    (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos) |
    (GPIO_PIN_CNF_DRIVE_H0H1 << GPIO_PIN_CNF_DRIVE_Pos) |
    (GPIO_PIN_CNF_INPUT_Disconnect << GPIO_PIN_CNF_INPUT_Pos);
}

void loop() {
  digitalWrite(pin, HIGH);
}
