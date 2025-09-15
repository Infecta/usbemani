#pragma once

#define ONBOARD_LED 25 // Onboard Pico LED

#define BUTTON_DRIVER direct
#define BUTTONS_AVAILABLE 11
// A/B/C/D, L/R, Start
#define BUTTON_PINS \
  4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 27,

#define LIGHT_DRIVER direct
#define LIGHTS_AVAILABLE 10
#define LIGHT_PINS \
  5, 7, 9, 11, 13, 15, 17, 19, 21, 26,

#define ENCODER_DRIVER direct
#define ENCODERS_AVAILABLE 2
// VOL-L, VOL-R
#define ENCODER_PINS [0] = {0,1}, [1] = {2,3}

/*** Chain Inclusion ***/
#include_next "config.h"