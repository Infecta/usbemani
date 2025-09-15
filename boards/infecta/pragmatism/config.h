#pragma once
// The Raspberry Pi Pico is a general development board.
// The following describes the available capabilities of the Pico development board in a way that makes it easy to use in controller configurations.

// Development boards receive a special marker to separate them from "production" boards.
// This is done since development boards have overlap across nearly every device.
// For example, channel "0" for any device (buttons, encoders, etc.) is pin 0.
// This overlap makes it harder for dev boards to work with layouts versus production boards.
// #define BOARD_DEVELOPMENT

#define ONBOARD_LED 25 // Pico's onboard LED

// This description is set up in a way to align Pico "GP" numbers with channels numbers.
// Certain channels will not be available because of this alignment. These will be marked with "PIN_NC"
#define BUTTON_DRIVER direct
#define BUTTONS_AVAILABLE 11
#define BUTTON_PINS \
   4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 27

// The channel number of the encoder indicates the Pico pin number + the pin after
// e.g. Encoder channel 5 uses Pico pins 5 and 6
// Channels 22-25 and 28 are not valid since they contain a non-valid pin number.
#define ENCODER_DRIVER direct
#define ENCODERS_AVAILABLE 2
#define ENCODER_PINS \
  [0] = {0,1}, \
  [1] = {2,3}

#define LIGHT_DRIVER direct
#define LIGHTS_AVAILABLE 10
#define LIGHT_PINS \
    5, 7, 9, 11, 13, 15, 17, 19, 21, 26

/*** Chain Inclusion ***/
// This is what tells the compiler to include the controller configuration.
#include_next "config.h"