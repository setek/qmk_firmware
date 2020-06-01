#pragma once

// disable the old style of macros, and no action function, see if it saves space
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#if !defined(NO_DEBUG) && !defined(DEBUG)
#    define NO_DEBUG
#endif // !NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#    define NO_PRINT
#endif // !NO_PRINT

// no oneshots to save space
// #define NO_ACTION_ONESHOT
// remove any definitions of
// #undef ONESHOT_TAP_TOGGLE

// Holding and releasing a dual function key without pressing another key will result in nothing happening.
// With retro tapping enabled, releasing the key without pressing another will send the original keycode
// even if it is outside the tapping term.
// For instance, holding and releasing `LT(2, KC_SPACE)` without hitting another key will result in nothing happening.
// With this enabled, it will send `KC_SPACE` instead.

// I don’t like retro tapping because when you’re selecting multiple items with command in a mod-tap, when you let go,
// it will send the tap character, and deselect your stuff.
// #define RETRO_TAPPING
#ifdef RETRO_TAPPING
#    undef RETRO_TAPPING
#endif

// How long to hold an LT before it does the "held" rather than "tap" keY
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 160
// Allow custom tapping term for just a few keys (if you reduce tapping term on mods, it’s nice imo, unless you have mod-taps)
#define TAPPING_TERM_PER_KEY

// If you're a fast typist and type an LT and then another key really quickly, instead of considering it a mod + second,
// consider it tap + second
#define IGNORE_MOD_TAP_INTERRUPT
// #ifdef IGNORE_MOD_TAP_INTERRUPT
// #    undef IGNORE_MOD_TAP_INTERRUPT
// #endif
// #define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

// if you do mod-tap plus key all within tapping term, consider it a mod
#define PERMISSIVE_HOLD
// or, don’t do it
// #ifdef PERMISSIVE_HOLD
// #    undef PERMISSIVE_HOLD
// #endif

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_SLEEP
// #    define BACKLIGHT_CAPS_LOCK
#endif

// #define RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_EFFECT_TWINKLE // single colour pulse in and out, 1/10
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD // all same colour, slowwww fade to other colours, 3/10
// #define RGBLIGHT_EFFECT_SNAKE // single colour rolling wave, 2/10
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL // different colours, fade to other colours, 10/10
// #define RGBLIGHT_EFFECT_BREATHING // slowly pulses in a breathing fashion, 3/10
// #define RGBLIGHT_EFFECT_KNIGHT // one colour that flashes back and forth, 0/10
// #define RGBLIGHT_EFFECT_CHRISTMAS // alternating red and green, 0/10
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT // whole rainbow but doesn’t actually animate, 1/10
// #define RGBLIGHT_EFFECT_RGB_TEST // harsh flash between different colours, 0/10
// #define RGBLIGHT_EFFECT_ALTERNATING // single colour flashing in and out, 0/10

/* Add combos */
// #define COMBO_COUNT 6
#define COMBO_VARIABLE_LEN
#define COMBO_TERM 35
#define COMBO_TERM_PER_COMBO
// #define COMBO_ONLY_FROM_LAYER 0

// #define ARSTNEIO_ENABLE

// One shot settings
#define ONESHOT_TAP_TOGGLE 3
// #define ONESHOT_TIMEOUT 5000

#define LEADER_TIMEOUT TAPPING_TERM
