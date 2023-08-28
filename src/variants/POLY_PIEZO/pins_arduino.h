#pragma once
#include <stdint.h>
#include <macros.h>

#ifndef __PINS_ARDUINO__
#define __PINS_ARDUINO__

#define ANALOG_CONFIG

/* Analog reference options 
 * Different possibilities available combining Reference and Gain
 */
enum _AnalogReferenceMode
{
  AR_VDD,         // 3.3 V
  AR_INTERNAL,    // 0.6 V
  AR_INTERNAL1V2, // 1.2 V
  AR_INTERNAL2V4  // 2.4 V
};

/* Analog acquisition time options */
enum _AnalogAcquisitionTime
{
  AT_3_US,         
  AT_5_US,    
  AT_10_US, // Default value
  AT_15_US,
  AT_20_US,  
  AT_40_US  
};

// Frequency of the board main oscillator
#define VARIANT_MAINOSC (32768ul)

// Master clock frequency
#define VARIANT_MCK     (64000000ul)

// Pins
// ----

// Number of pins defined in PinDescription array
#ifdef __cplusplus
extern "C" unsigned int PINCOUNT_fn();
#endif
#define PINS_COUNT           (PINCOUNT_fn())
#define NUM_DIGITAL_PINS     (11u)
#define NUM_ANALOG_INPUTS    (2u)
#define NUM_ANALOG_OUTPUTS   (0u)

extern PinName digitalPinToPinName(pin_size_t P);


// Analog pins
// -----------
#define PIN_A0	(17u)
#define PIN_LB	(18u)
static const uint8_t A0  = PIN_A0;
static const uint8_t LB  = PIN_LB;
#define ADC_RESOLUTION 12

// Digital pins
// -----------
#define D0  (14u)
#define D1  (16u)
#define D2  (7u)
#define D3  (8u)
#define D4  (33u)
#define D5  (26u)
#define D6  (13u)
#define D7  (30u)

// MUX selection pins
// -----------
#define MUXS0	(21u)
#define MUXS1	(20u)
#define MUXS2	(19u)

/*
 * Serial interfaces
 */

// Wire
#define PIN_WIRE_SDA        (34u)
#define PIN_WIRE_SCL        (27u)

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1


// Mbed specific defines
#define SERIAL_HOWMANY		0

#define SERIAL_CDC			1
#define HAS_UNIQUE_ISERIAL_DESCRIPTOR
#define BOARD_VENDORID			0x2341
#define BOARD_PRODUCTID		0x805a
#define BOARD_NAME			"PolyPiezo"

#define DFU_MAGIC_SERIAL_ONLY_RESET   0xb0

#define WIRE_HOWMANY		1

#define I2C_SDA				(digitalPinToPinName(PIN_WIRE_SDA))
#define I2C_SCL				(digitalPinToPinName(PIN_WIRE_SCL))

#define SPI_HOWMANY			0

#define digitalPinToPort(P)		(digitalPinToPinName(P)/32)

uint8_t getUniqueSerialNumber(uint8_t* name);
void _ontouch1200bps_();

#endif //__PINS_ARDUINO__
