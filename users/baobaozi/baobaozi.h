#pragma once
#include QMK_KEYBOARD_H

#include "version.h"
#include "eeprom.h"
#include "quantum.h"
#include "layout_macros.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _PRI 1
#define _SEC 2
#define _TER 3
#define _QUA 4

#ifdef TAP_DANCE_ENABLE
#    include "tap_dances.h"
#endif  // TAP_DANCE_ENABLE

// #ifdef TAP_DANCE_ENABLE
// #    define KC_SAFE_RESET TD(TD_SAFE_RESET)
// #else  // TAP_DANCE_ENABLE
// #    define KC_SAFE_RESET RESET
// #endif  // TAP_DANCE_ENABLE

// Init macro keycodes, define what they do in <name>.c
enum custom_keys {
    MCSG3 = SAFE_RANGE,
    MCSG4,
    MGF2
};
