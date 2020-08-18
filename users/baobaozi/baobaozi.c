#include "baobaozi.h"
#include "quantum.h"
#include "action.h"

__attribute__ ((weak)) // what is this for?

enum userspace_layers {
    KC_MAKE = SAFE_RANGE,
    NEW_SAFE_RANGE,  // use "NEW_SAFE_RANGE" for keymap specific codes
    QWERTY,
    COLEMAK,
    PRI,
    SEC,
    TER,
    QUA
};

// bool try_handle_macro(uint16_t keycode, keyrecord_t *record) { // Use this to define macros in addition to the user macros. As in, the crkbd has extra macros defined over there.
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
        case GOQWER:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case GOCLMK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
    }

    return true;
};

uint16_t get_tapping_term(keyevent_t* event) {
    uint16_t keycode = keymap_key_to_keycode(layer_switch_get_layer(event->key), event->key);
    // I don’t have any mod-taps, so it’s safe to do this. Rethink this if you decide to do mod-taps
    if (keycode == keycode == KC_LCTL || KC_LALT || keycode == KC_LGUI || keycode == KC_RGUI || keycode == KC_RALT || keycode == KC_RCTL || keycode == AAG(NO)) {
        return TAPPING_TERM - 50;
    }

    if (keycode == LT1(Q) || keycode == LT2(W) || keycode == LT3(X) || keycode == LT4(CAPS) || keycode == MG(SPC)) {
        return TAPPING_TERM + 15;
    }

    return TAPPING_TERM;
}
