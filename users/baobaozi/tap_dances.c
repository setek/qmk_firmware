#include "tap_dances.h"

// Declare the functions to be used with your tap dance key(s)
// Function associated with all tap dances
int cur_dance (qk_tap_dance_state_t *state) {
    if (state->pressed) {
        if (state->count == 1) {
            return SINGLE_HOLD;
        } else if (state->count == 2) {
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
void ql_finished_turn_on_layers(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_HOLD:
            layer_on(_PRI);
            break;
        case DOUBLE_HOLD:
            layer_on(_SEC);
            break;
        case TRIPLE_HOLD:
            layer_on(_TER);
            break;
        case QUADRUPLE_HOLD:
            layer_on(_QUA);
            break;
    }
}

void ql_reset_turn_off_layers(qk_tap_dance_state_t *state, void *user_data) {
    // if the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == SINGLE_HOLD) {
        layer_off(_PRI);
    }
    if (ql_tap_state.state == DOUBLE_HOLD) {
        layer_off(_SEC);
    }
    if (ql_tap_state.state == TRIPLE_HOLD) {
        layer_off(_TER);
    }
    if (ql_tap_state.state == QUADRUPLE_HOLD) {
        layer_off(_QUA);
    }

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

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [CPST] = ACTION_TAP_DANCE_DOUBLE(G(KC_C), G(KC_V)), // Tap once for Copy, twice for Paste
    [XPST] = ACTION_TAP_DANCE_DOUBLE(G(KC_X), G(KC_V)), // Tap once for Cut, twice for Paste
    [CORX] = ACTION_TAP_DANCE_DOUBLE(G(KC_C), G(KC_X)), // Tap once for Copy, twice for Cut
    [QTAB] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB),
    [F212] = ACTION_TAP_DANCE_DOUBLE(G(KC_F2), KC_F12), // Tap once for Cmd + F2, twice for F12
    [SQUO] = ACTION_TAP_DANCE_DOUBLE(A(KC_RBRC), A(S(KC_RBRC))), // Tap once for single opening quote, twice for single closing quote
    [DQUO] = ACTION_TAP_DANCE_DOUBLE(A(KC_LBRC), A(S(KC_LBRC))), // Tap once for double opening quote, twice for double closing quote
    [ENEM] = ACTION_TAP_DANCE_DOUBLE(A(KC_MINS), A(S(KC_MINS))), // Tap once for en dash, twice for em dash
    [LYRS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished_turn_on_layers, ql_reset_turn_off_layers, 275),
    [SRST] = ACTION_TAP_DANCE_FN(safe_reset),
    [SEEP] = ACTION_TAP_DANCE_FN(safe_eep_rst)
};
