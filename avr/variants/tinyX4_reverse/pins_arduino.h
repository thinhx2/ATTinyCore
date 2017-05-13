/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#define ATTINYX4 1
#define __AVR_ATtinyX4__
#define USE_SOFTWARE_SPI 1

#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            12
#define NUM_ANALOG_INPUTS           64

#define analogInputToDigitalPin(p)  (p)

#define digitalPinHasPWM(p)         ((p) == 5 || (p) == 6 || (p) == 7 || (p) == 8)

#define SS   3
#define MOSI 6
#define MISO 5
#define SCK  4

#define USI_DDR_PORT DDRA
#define USCK_DD_PIN DDA4
#define DO_DD_PIN DDA5
#define DI_DD_PIN DDA6

static const uint8_t SDA = 6;
static const uint8_t SCL = 4;

//Ax constants should not be used for digitalRead/digitalWrite/analogWrite functions, only analogRead().
//#define ANALOG_PINS_ARE_ADC_NUMBERS 1
static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;
static const uint8_t A6 = 6;
static const uint8_t A7 = 7;
#define PIN_A0  (0)
#define PIN_A1  ( 1)
#define PIN_A2  ( 2)
#define PIN_A3  ( 3)
#define PIN_A4  ( 4)
#define PIN_A5  ( 5)
#define PIN_A6  ( 6)
#define PIN_A7  ( 7)
#define PIN_B0  ( 10)
#define PIN_B1  ( 9)
#define PIN_B2  ( 8)
#define PIN_B3  (11)  /* RESET */
#define LED_BUILTIN (8)

//----------------------------------------------------------
//----------------------------------------------------------
//Core Configuration (used to be in core_build_options.h)

//If Software Serial communications doesn't work, run the TinyTuner sketch provided with the core to give you a calibrated OSCCAL value.
//Change the value here with the tuned value. By default this option uses the default value which the compiler will optimise out. 
#define TUNED_OSCCAL_VALUE                        OSCCAL
//e.g
//#define TUNED_OSCCAL_VALUE                        0x57

//Choosing not to initialise saves power and flash. 1 = initialise.
#define INITIALIZE_ANALOG_TO_DIGITAL_CONVERTER    1
#define INITIALIZE_SECONDARY_TIMERS               1
/*
  The old standby ... millis on Timer 0.
*/
#define TIMER_TO_USE_FOR_MILLIS                   0

/*
  Where to put the software serial? (Arduino Digital pin numbers)
*/
//WARNING, if using software, TX is on AIN0, RX is on AIN1. Comparator is favoured to use its interrupt for the RX pin.
#define USE_SOFTWARE_SERIAL						  1
//Please define the port on which the analog comparator is found.
#define ANALOG_COMP_DDR						 	  DDRA
#define ANALOG_COMP_PORT						  PORTA
#define ANALOG_COMP_PIN						 	  PINA
#define ANALOG_COMP_AIN0_BIT					  1
#define ANALOG_COMP_AIN1_BIT					  2


/*
  Analog reference bit masks.
*/
// VCC used as analog reference, disconnected from PA0 (AREF)
#define DEFAULT (0)
// External voltage reference at PA0 (AREF) pin, internal reference turned off
#define EXTERNAL (1)
// Internal 1.1V voltage reference
#define INTERNAL (2)
#define INTERNAL1V1 INTERNAL

//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------


// PCICR = Pin Change Interrupt Control Register
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 11) ? (&GIMSK) : ((uint8_t *)NULL))
#define digitalPinToPCICRbit(p) ( ((p) <= 7) ? PCIE0 : PCIE1 )
#define digitalPinToPCMSK(p)    ( ((p) <= 7) ? (&PCMSK0) : (((p) <= 10) ? (&PCMSK1) : ((uint8_t *)0)) )
#define digitalPinToPCMSKbit(p) ( ((p) <= 7) ? (p) : (10 - (p)) )

#define digitalPinToInterrupt(p)  ((p) == 8 ? 0 : NOT_AN_INTERRUPT)
#ifdef ARDUINO_MAIN

// ATMEL ATTINY84 / ARDUINO
//
//                           +-\/-+
//                     VCC  1|    |14  GND
//            (D  10)  PB0  2|    |13  PA0  (D  0)        AREF
//             (D  9)  PB1  3|    |12  PA1  (D  1) 
//             (D 11)  PB3  4|    |11  PA2  (D  2) 
//  PWM  INT0  (D  8)  PB2  5|    |10  PA3  (D  3) 
//  PWM        (D  7)  PA7  6|    |9   PA4  (D  4) 
//  PWM        (D  6)  PA6  7|    |8   PA5  (D  5)        PWM
//                           +----+
const uint16_t PROGMEM port_to_mode_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t)&DDRA,
  (uint16_t)&DDRB,
};

const uint16_t PROGMEM port_to_output_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t)&PORTA,
  (uint16_t)&PORTB,
};

const uint16_t PROGMEM port_to_input_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t)&PINA,
  (uint16_t)&PINB,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = 
{
  PA, /* 0 */
  PA,
  PA,
  PA,
  PA,
  PA,
  PA,
  PA,
  PB, /* 8 */
  PB,
  PB,
  PB, /* 11 */
};



const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = 
{
  _BV(0), /* port A */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5), 
  _BV(6),
  _BV(7),
  _BV(2), /* port B */
  _BV(1),
  _BV(0),
  _BV(3),
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = 
{
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER, 
  NOT_ON_TIMER,
  TIMER1B, /* OC1B */
  TIMER1A, /* OC1A */
  TIMER0B, /* OC0B */
  TIMER0A, /* OC0A */
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
};

#endif

#endif




//Old code, just here for temporary backup until I decide it is not needed.
/*
//WARNING, if using software, RX must be on a pin which has a Pin change interrupt <= 7 (e.g. PCINT6, or PCINT1, but not PCINT8)
#define USE_SOFTWARE_SERIAL						  1
//These are set to match Optiboot pins.
#define SOFTWARE_SERIAL_PORT 					  PORTA
#define SOFTWARE_SERIAL_TX 						  9
#define SOFTWARE_SERIAL_PIN 					  PINA
#define SOFTWARE_SERIAL_RX 						  8*/
