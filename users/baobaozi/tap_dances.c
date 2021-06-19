#include "tap_dances.h"

// Declare the functions to be used with your tap dance key(s)
// Function associated with all tap dances
int cur_dance (qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    }

    if (state->count == 2 && (state->interrupted || !state->pressed)) return DOUBLE_TAP;

    if (state->pressed) {
        if (state->count == 2) {
            return DOUBLE_HOLD;
        } else if (state->count == 3) {
            return TRIPLE_HOLD;
        } else if (state->count == 4) {
            return QUADRUPLE_HOLD;
        } else {
            return 8;
        }
    }

    else return 8;
}

// Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
    .is_press_action = true,
    .state = 0
};

// Functions that control what our tap dance key does
// void alt_apo(qk_tap_dance_state_t *state, void *user_data) {
//     ql_tap_state.state = cur_dance(state);
//     switch (ql_tap_state.state) {
//         case SINGLE_TAP:
//             tap_code16(A(S(KC_RBRC)));
//             break;
//         case SINGLE_HOLD:
//             set_mods(MOD_BIT(KC_LALT));
//             break;
//         case DOUBLE_TAP:
//             tap_code(KC_QUOT);
//             break;
//     }
// }

// void alt_apo_finish(qk_tap_dance_state_t *state, void *user_data) {
//     if (ql_tap_state.state == SINGLE_HOLD) {
//         unregister_mods(MOD_BIT(KC_LALT));
//     }

//     ql_tap_state.state = 0;
// }

void ql_finished_turn_on_layers(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_HOLD:
            layer_on(_NAV);
            break;
        case DOUBLE_HOLD:
            layer_on(_SYM);
            break;
        case TRIPLE_HOLD:
            layer_on(_NUM);
            break;
        case QUADRUPLE_HOLD:
            layer_on(_KB);
            break;
    }
}

void ql_reset_turn_off_layers(qk_tap_dance_state_t *state, void *user_data) {
    // if the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == SINGLE_HOLD) {
        layer_off(_NAV);
    }
    if (ql_tap_state.state == DOUBLE_HOLD) {
        layer_off(_SYM);
    }
    if (ql_tap_state.state == TRIPLE_HOLD) {
        layer_off(_NUM);
    }
    if (ql_tap_state.state == QUADRUPLE_HOLD) {
        layer_off(_KB);
    }

    ql_tap_state.state = 0;
}

void ql_guisft_on(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_QUOT);
            break;
        case SINGLE_HOLD:
            set_mods(MOD_LGUI);
            break;
        case DOUBLE_HOLD:
            set_mods(MOD_LSFT);
            break;
    }
}


void ql_guisft_off(qk_tap_dance_state_t *state, void *user_data) {
    clear_mods();

    ql_tap_state.state = 0;
}

void safe_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        // Reset the keyboard if you tap the key more than three times
        reset_keyboard();
        reset_tap_dance(state);
    }
}

void safe_eep_rst(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        // Reset the keyboard if you tap the key more than three times
        eeconfig_init();
        reset_tap_dance(state);
    }
}

// void sentence_end(qk_tap_dance_state_t *state, void *user_data) {
//     switch (state->count) {
//         // Double tapping TD_DOT produces
//         // ". <one-shot-shift>" i.e. dot, space and capitalize next letter.
//         // This helps to quickly end a sentence and begin another one
//         // without having to hit shift.
//         case 2:
//             /* Check that Shift is inactive */
//             if (!(get_mods() & MOD_MASK_SHIFT)) {
//                 tap_code(KC_SPC);
//                 /* Internal code of OSM(MOD_LSFT) */
//                 set_oneshot_mods(MOD_LSFT | get_oneshot_mods());
//             } else {
//                 // send ">" (KC_DOT + shift → ">")
//                 tap_code(KC_DOT);
//             }
//             break;

//         // Since `sentence_end` is called on each tap
//         // and not at the end of the tapping term,
//         // the third tap needs to cancel the effects
//         // of the double tap in order to get the expected
//         // three dots ellipsis.
//         case 3:
//             // remove the added space of the double tap case
//             tap_code(KC_BSPC);
//             // remove the first dot
//             tap_code(KC_BSPC);
//             // replace with a …
//             tap_code16(A(KC_SCLN));
//             // tap a space … or not, not sure I like it to
//             // tap_code(KC_SPC);
//             break;

//         // send KC_DOT on every normal tap of TD_DOT
//         default:
//             tap_code(KC_DOT);
//     }
// };

// void sentence_end_tap(qk_tap_dance_state_t *state, void *user_data) {
//     tap_code16((int16_t)user_data);
// }
// void sentence_end_fin(qk_tap_dance_state_t *state, void *user_data) {
//     switch (state->count) {
//         // Double tapping produces
//         // "<key> <one-shot-shift>" i.e. dot, space and capitalize next letter.
//         // This helps to quickly end a sentence and begin another one
//         // without having to hit shift.
//         case 2:
//             /* Check that Shift is inactive */
//             if (!(get_mods() & MOD_MASK_SHIFT)) {
//                 tap_code(KC_BSPC);
//                 tap_code(KC_SPC);
//                 /* Internal code of OSM(MOD_LSFT) */
//                 set_oneshot_mods(MOD_LSFT | get_oneshot_mods());
//             }
//             break;
//     }
// };

// #define ACTION_TAP_DANCE_FN_ADVANCED_USER(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, user_user_data) { .fn = {user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = (void*)user_user_data, }

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [CPST] = ACTION_TAP_DANCE_DOUBLE(G(KC_C), G(KC_V)), // Tap once for Copy, twice for Paste
    [XPST] = ACTION_TAP_DANCE_DOUBLE(G(KC_X), G(KC_V)), // Tap once for Cut, twice for Paste
    [CORX] = ACTION_TAP_DANCE_DOUBLE(G(KC_C), G(KC_X)), // Tap once for Copy, twice for Cut
    // [F212] = ACTION_TAP_DANCE_DOUBLE(G(KC_F2), KC_F12), // Tap once for Cmd + F2, twice for F12
    [SQUO] = ACTION_TAP_DANCE_DOUBLE(A(KC_RBRC), A(S(KC_RBRC))), // Tap once for single opening quote, twice for single closing quote
    [DQUO] = ACTION_TAP_DANCE_DOUBLE(A(KC_LBRC), A(S(KC_LBRC))), // Tap once for double opening quote, twice for double closing quote
    [ENEM] = ACTION_TAP_DANCE_DOUBLE(A(KC_MINS), A(S(KC_MINS))), // Tap once for en dash, twice for em dash
    // [BORP] = ACTION_TAP_DANCE_DOUBLE(G(KC_LEFT), A(G(KC_LEFT))), // Tap once for browser back, twice for previous tab
    // [FORN] = ACTION_TAP_DANCE_DOUBLE(G(KC_RIGHT), A(G(KC_RIGHT))), // Tap once for browser forward, twice for next tab
    [RFSH] = ACTION_TAP_DANCE_DOUBLE(S(G(KC_R)), G(KC_R)), // Tap once for hard refresh, twice for regular refresh
    [LYRS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished_turn_on_layers, ql_reset_turn_off_layers, 275),
    [APPR] = ACTION_TAP_DANCE_DOUBLE(A(S(KC_RBRC)), KC_QUOT),
    // [AAPO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_apo, alt_apo_finish),
    // [SEND] = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, NULL, NULL),
    // [SEND] = ACTION_TAP_DANCE_FN_ADVANCED_USER(sentence_end_tap, sentence_end_fin, NULL, KC_DOT),
    [BRCO] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LT),
    [BRCC] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_GT),
    [GUISFT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_guisft_on, ql_guisft_off, 275),
    // [SEQU] = ACTION_TAP_DANCE_FN_ADVANCED_USER(sentence_end_tap, sentence_end_fin, NULL, KC_QUES),
    // [SEEX] = ACTION_TAP_DANCE_FN_ADVANCED_USER(sentence_end_tap, sentence_end_fin, NULL, KC_EXLM),
    [SRST] = ACTION_TAP_DANCE_FN(safe_reset),
    [SEEP] = ACTION_TAP_DANCE_FN(safe_eep_rst)
};
