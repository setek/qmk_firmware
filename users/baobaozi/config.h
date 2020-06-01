#pragma once

// I think this is causing issues with typing words like saturday or ask when I have LTs on a and s
// #define PERMISSIVE_HOLD

// disable the old style of macros, and no action function, see if it saves space
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// #if !defined(NO_DEBUG) && !defined(DEBUG)
// #    define NO_DEBUG
// #endif // !NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#    define NO_PRINT
#endif // !NO_PRINT

// remove any definitions of
#undef ONESHOT_TAP_TOGGLE

// Holding and releasing a dual function key without pressing another key will result in nothing happening.
// With retro tapping enabled, releasing the key without pressing another will send the original keycode
// even if it is outside the tapping term.
// For instance, holding and releasing `LT(2, KC_SPACE)` without hitting another key will result in nothing happening.
// With this enabled, it will send `KC_SPACE` instead.

// I don’t like retro tapping because when you’re selecting multiple items with command in a mod-tap, when you let go,
// it will send the tap character, and deselect your stuff.
// #define RETRO_TAPPING

// How long to hold an LT before it does the "held" rather than "tap" key
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif  // TAPPING_TERM
#define TAPPING_TERM 200
// Allow custom tapping term for just a few keys
#define TAPPING_TERM_PER_KEY

// If you're a fast typist and type an LT and then another key really quickly, instead of considering it a mod + second,
// consider it tap + second
#define IGNORE_MOD_TAP_INTERRUPT
// #ifdef IGNORE_MOD_TAP_INTERRUPT
// #    undef IGNORE_MOD_TAP_INTERRUPT
// #endif

// if you do mod-tap plus key all within tapping term, consider it a mod
// #define PERMISSIVE_HOLD
#ifdef PERMISSIVE_HOLD
#    undef PERMISSIVE_HOLD
#endif

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_LAYERS
// #    define RGBLIGHT_EFFECT_BREATHING
// #    define BACKLIGHT_CAPS_LOCK
#endif
