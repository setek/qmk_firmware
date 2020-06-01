#include "baobaozi.h"
#include "quantum.h"
#include "action.h"

__attribute__ ((weak)) // what is this for?

enum userspace_layers {
    KC_MAKE = SAFE_RANGE,
    NEW_SAFE_RANGE,  // use "NEW_SAFE_RANGE" for keymap specific codes
    QWERTY,
    PRI,
    SEC,
    TER,
    QUA
};

// bool try_handle_macro(uint16_t keycode, keyrecord_t *record) { // somewhere I saw do this, but don’t, it doesn’t work
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MCSG3:
            if (record->event.pressed) {
                // when keycode is pressed, screenshot window to clipboard
                // SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI("3"))));
                // for brevity, this works too apparently:
                tap_code16(C(S(G(KC_3))));
            }
            break;
        case MCSG4:
            if (record->event.pressed) {
                // when keycode is pressed, screenshot portion of window to clipboard
                // SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI("4"))));
                // for brevity, this works too apparently:
                tap_code16(C(S(G(KC_4))));
            }
            break;
        case MGF2:
            if (record->event.pressed) {
                // when keycode is pressed, screenshot portion of window to clipboard
                // SEND_STRING(SS_LGUI(KC_F2));
                // for brevity, this works too apparently:
                tap_code16(G(KC_F2));
            }
            break;
    }

    return true;
};
