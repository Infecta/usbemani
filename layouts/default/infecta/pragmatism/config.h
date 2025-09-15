#pragma once

/*** Buttons ***/
#define BUTTON_CHANNELS   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

/*** Lights ***/
#undef  LIGHTS_ACTIVE
#define LIGHTS_ACTIVE     10
#define LIGHT_CHANNELS    0, 1, 2, 3, 4, 5, 6, 7, 8, 9

/*** Encoders ***/
#define ENCODER_CHANNELS_REVERSED
#define ENCODER_CHANNELS                0, 1
#define ENCODER_FREQUENCY               16000
#define ENCODER_SAMPLES_UNTIL_VALID     64
#define ENCODER_DIRECTION_THRESHOLD     1
#define ENCODER_DIRECTION_HOLD_TIMEOUT  200

/*** USB ***/
#define USB_BUTTONS_ACTIVE      11
#define USB_LIGHTS_ACTIVE       10
#define USB_ENCODER_AXES_ACTIVE 2
#define USB_ENCODER_AXES        USB_Axis_X, USB_Axis_Y
#define USB_STRING_VENDOR_USBEMANI  "Infecta"
#define USB_STRING_PRODUCT_USBEMANI "PRAGMATiSM"
/*** Button Combinations ***/
#define BUTTON_COMBO_ARCH_RESET   0, 1  // BT-A, BT-B
#define BUTTON_COMBO_KONAMI_CLOUD 6     // Start

/*** Additional Includes ***/
#include "usb_labels.h"
