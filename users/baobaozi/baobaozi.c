#include "baobaozi.h"
#include "quantum.h"
#include "action.h"

// bool try_handle_macro(uint16_t keycode, keyrecord_t *record) { // don't use this. what is this even for? i thought it was for keymaps to play nice with the process_record_user, but it isn't. the above process_record_keymap is.

uint16_t last_kc;
uint16_t last_registered;

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t active_mods = get_mods();
    uint8_t active_oneshot_mods = get_oneshot_mods();

    if (IS_KEY(keycode) || keycode == LTN(Q) || keycode == LTS(W) || keycode == LT0(X) || keycode == MS(Z) || keycode == MS(SLSH) || keycode == MG(QUOT) || keycode == MA(MINS) || keycode == MG(SPC)) {
        last_kc = keycode;
    }

    // other macros
    switch (keycode) {
        // hijack an unused keycode to do mod- and layer-taps with cooler taps than just basic keycodes

        case MA(F21):
            // one shot shift
            if (record->tap.count == 1) {
                if (record->event.pressed && !(active_mods & MOD_MASK_SHIFT)) {
                    set_oneshot_mods(MOD_LSFT);
                    // set_oneshot_layer(_CUR, ONESHOT_START);
                // } else {
                    // clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                    // unregister_code16(KC_LEAD);
                } else if (active_mods & MOD_MASK_SHIFT) {
                    // cancel the sticky shift
                    del_mods(MOD_LSFT);
                }
                return false;
            } else if (record->tap.count == ONESHOT_TAP_TOGGLE) {
                // on ONESHOT_TAP_TOGGLE taps, make shift sticky
                if (record->event.pressed) {
                    add_mods(MOD_LSFT);
                }
                return false;
            }
            break;
        case MC(F22):
            // key repeater
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    last_registered = last_kc;
                    // tap_code16(last_kc);
                    register_code16(last_registered);
                } else {
                    unregister_code16(last_registered);
                }
                return false;
            }
            break;
        case MJSPL:
            if (record->event.pressed) {
                // when keycode is pressed, type out ${} and position caret in between {}
                tap_code16(KC_DLR);
                tap_code16(KC_LCBR);
                tap_code16(KC_RCBR);
                tap_code(KC_LEFT);
            }
            break;
    //     case MCSG4: // eh, just keep this here so i can refer to it if i wanted to have a send_string macro
    //         if (record->event.pressed) {
    //             // when keycode is pressed, screenshot portion of window to clipboard
    //             // SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI("4"))));
    //             // for brevity, this works too apparently:
    //             tap_code16(C(S(G(KC_4))));
    //         }
    //         break;
        // case GOQWER: // i don't like either of these because my rgb light layer doesn't change
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_QWERTY);
        //     }
        //     return false;
        // case GOCLMK: // i don't like either of these because my rgb light layer doesn't change
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_COLEMAK);
        //     }
        //     return false;
    }

    // turbo delete forward: costs 66 bytes on corne, but 104 bytes on redox
    if (
        record->event.pressed
            && keycode == KC_BSPC
            && (active_mods & MOD_MASK_SHIFT
                || active_oneshot_mods & MOD_MASK_SHIFT)
    ) {
        if (active_mods & MOD_MASK_ALT || active_oneshot_mods & MOD_MASK_ALT) {
            clear_mods(); // get rid of shift
            clear_oneshot_mods();
            set_mods(MOD_BIT(KC_LALT)); // but put the alt back on (delete word)
        } else if (active_mods & MOD_MASK_GUI || active_oneshot_mods & MOD_MASK_GUI) {
            tap_code(KC_RGHT); // because in certain apps, cmd + delete doesn’t always do anything (Firefox, WhatsApp) and i want to delete all the way to the end of line
            clear_mods(); // then get rid of cmd
            clear_oneshot_mods(); // clear the oneshots too just in case
        } else {
            clear_mods(); // because vscode will send shift + delete, and do nothing
            clear_oneshot_mods(); // clear the oneshots too just in case
        }

        tap_code(KC_DEL);

        set_mods(active_mods); // put it all back to normal

        return false;
    }

    // // mask numpad for Function keys: costs 224 bytes
    // if (record->event.pressed && layer_state_is(_NUM) && (active_mods & MOD_MASK_SHIFT) && (active_mods & MOD_MASK_CTRL) && (active_mods & MOD_MASK_GUI)) {
    //     clear_mods(); // get rid of the mods

    //     switch (keycode) {
    //         case KC_1:
    //             tap_code(KC_F1);
    //             break;
    //         case KC_2:
    //             tap_code(KC_F2);
    //             break;
    //         case KC_3:
    //             tap_code(KC_F3);
    //             break;
    //         case KC_4:
    //             tap_code(KC_F4);
    //             break;
    //         case KC_5:
    //             tap_code(KC_F5);
    //             break;
    //         case KC_6:
    //             tap_code(KC_F6);
    //             break;
    //         case KC_7:
    //             tap_code(KC_F7);
    //             break;
    //         case KC_8:
    //             tap_code(KC_F8);
    //             break;
    //         case KC_9:
    //             tap_code(KC_F9);
    //             break;
    //         case KC_PPLS:
    //             tap_code(KC_F10);
    //             break;
    //         case KC_0:
    //             tap_code(KC_F11);
    //             break;
    //         case KC_DOT:
    //             tap_code(KC_F12);
    //             break;
    //         default:
    //             tap_code(keycode);
    //     }

    //     set_mods(active_mods); // put it all back to normal

    //     return false;
    // }

    return process_record_keymap(keycode, record);
};

#ifdef LEADER_DICTIONARY
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // https://unicode.org/emoji/charts/full-emoji-list.html

        // for single key sequences
        SEQ_ONE_KEY(KC_L) {
            send_unicode_string("😆"); // 1F606
        }

        // SEQ_ONE_KEY(KC_S) {
        //     SEND_STRING(":smile:");
        // }

        // SEQ_ONE_KEY(KC_C) {
        //     SEND_STRING(":sob:");
        // }

        // SEQ_ONE_KEY(KC_H) {
        //     SEND_STRING(":heart:");
        // }

        SEQ_ONE_KEY(KC_T) {
            send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
        }

        // for two-key sequences
        // SEQ_TWO_KEYS(KC_XXXX, KC_YYYY) {
            // INSERT CODE HERE: anything you can do in a macro https://docs.qmk.fm/macros.html
        // }

        // for three-key sequences
        // SEQ_THREE_KEYS(KC_XXXX, KC_YYYY, KC_ZZZZ) {
            // INSERT CODE HERE: anything you can do in a macro https://docs.qmk.fm/macros.html
        // }

        // ..., the rest of your Leader Key definitions.
    }
}
#endif

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case KC_BSLO:
//       return TAPPING_LAYER_TERM;
//     case KC_SPRA:
//       return TAPPING_LAYER_TERM;
//     default:
//       return TAPPING_TERM;
//   }
// }
// uint16_t get_tapping_term(keyevent_t* event) {
//     uint16_t keycode = keymap_key_to_keycode(layer_switch_get_layer(event->key), event->key);
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
        case KC_LALT:
        case KC_LGUI:
        case KC_RGUI:
        case KC_RALT:
        case KC_RCTL:
        case AAG(NO):
            return TAPPING_TERM - 50;

        case __T_L1___:
        case __T_R1___:
        case LTN(Q):
        case LTS(W):
        case LT0(X):
        case MS(Z):
        case MS(SLSH):
            return TAPPING_TERM + 10;

        default:
            return TAPPING_TERM;
    }
    // if (keycode == KC_LCTL || keycode == KC_LALT || keycode == KC_LGUI || keycode == KC_RGUI || keycode == KC_RALT || keycode == KC_RCTL || keycode == AAG(NO)) {
    //     return TAPPING_TERM - 50;
    // }

    // if (keycode == LTN(Q) || keycode == LTS(W) || keycode == LT0(X) || keycode == MS(Z) || keycode == MS(SLSH) || keycode == MG(SPC) || keycode == MG(QUOT)) {
    //     return TAPPING_TERM + 15;
    // }

    // return TAPPING_TERM;
}

// bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // case MS(Z): // can’t type amazon (amaOn) properly
//         case MS(SLSH):
//             // turn off IGNORE_MOD_TAP_INTERRUPT for my mod- and layer-taps, because sometimes I type so fast it does the tapping instead of the mod (eg. `wn` instead of `(` like I want)
//             return false;
//         default:
//             return true;
//     }
// }

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case __T_L1___:
        case __T_R1___:
            return false;
        default:
            return true;
    }
}

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
// default is 100, 50, 20. speed things up yeahhh
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {16, 8, 4};
#endif
