#include "baobaozi.h"

enum combo_events {
    CHD_TGNAV,
    CHD_TAB,
    CHD_GRV,
    CHD_ENT,
    // CHD_NUMENT,
    CHD_ESC,
    CHD_APO,
    CHD_OSS,
    CHD_OSSL,
    CHD_BSPC,
    CHD_BSPCPRI,
    CHD_BSPCSEC,
    CHD_BSPCTER,
    CHD_CLR,
    CHD_LKB,
    CHD_QWER,
    CHD_F6,
    CHD_F7,
    CHD_F8,
    CHD_F9,
    CHD_F10,
    // XV_PASTE
#if defined(UNICODEMAP_ENABLE) || defined(UNICODE_ENABLE)
    CHD_EMO,
#endif
#ifdef MOUSEKEY_ENABLE
    CHD_CUR,
#endif

#ifdef ARSTNEIO_ENABLE
    // a
    GIN_W,
    GIN_X,
    GIN_P,
    GIN_J,
    GIN_Q,
    GIN_LPRN,
    GIN_BSPC,

    // r
    GIN_F,
    GIN_C,
    GIN_K,
    GIN_Z,
    GIN_DOT,
    GIN_RPRN,

    // s
    GIN_D,
    GIN_M,
    GIN_COMM,
    GIN_MINS,
    GIN_QUOT,

    // t
    GIN_B,
    GIN_V,
    GIN_G,
    GIN_QUES,

    // n
    GIN_H,
    GIN_Y,
    GIN_L,

    // e
    GIN_U,
    GIN_EXLM,

    // i
    GIN_SCLN,

    // o
    GIN_ENT,
#endif
};

const uint16_t PROGMEM tab_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM grv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_COMM, KC_DOT, COMBO_END};
// const uint16_t PROGMEM nument_combo[] = {KC_2, KC_3, COMBO_END}; // still be able to hit enter with the same spot as default layer … though I usually don’t. Maybe turn off?
const uint16_t PROGMEM esc_combo[] = {MS(SLSH), KC_M, COMBO_END};
const uint16_t PROGMEM tgnav_combo[] = {KC_SCLN, KC_O, MS(SLSH), COMBO_END}; // for when I watch TV
const uint16_t PROGMEM apo_combo[] = {KC_P, KC_T, COMBO_END}; // vertical combo works well on DSA, but it a bit troublesome on OEM
const uint16_t PROGMEM oss_combo[] = {KC_N, KC_E, KC_I, COMBO_END}; // one shot shift in same spot both hands, so depending on which letter next you need to shift
const uint16_t PROGMEM ossl_combo[] = {KC_R, KC_S, KC_T, COMBO_END}; // left hand mirror here
const uint16_t PROGMEM bspc_combo[] = {KC_L, KC_U, KC_Y, COMBO_END}; // trial backspace in combo
const uint16_t PROGMEM bspcpri_combo[] = {AA(LEFT), KC_PGUP, KC_PGDN, COMBO_END}; // trial backspace in combo in primary layer
const uint16_t PROGMEM bspcsec_combo[] = {KC_RBRC, KC_RPRN, KC_PPLS, COMBO_END}; // trial backspace in combo in secondary layer
// const uint16_t PROGMEM bspcsec_combo[] = {KC_LBRC, KC_RBRC, KC_QUOT, COMBO_END}; // trial backspace in combo in secondary layer
const uint16_t PROGMEM bspcter_combo[] = {KC_7, KC_8, KC_9, COMBO_END}; // trial backspace in combo in tertiary layer
const uint16_t PROGMEM clr_combo[] = {KC_C, KC_COMM, COMBO_END}; // reutilising for clearing one shots
const uint16_t PROGMEM lkb_combo[] = {MS(Z), LT0(X), COMBO_END};
const uint16_t PROGMEM qwer_combo[] = {LTN(Q), LTS(W), KC_E, KC_R, COMBO_END}; // qwerty
const uint16_t PROGMEM f6_combo[] = {KC_F1, KC_F2, COMBO_END};
const uint16_t PROGMEM f7_combo[] = {KC_F2, KC_F3, COMBO_END};
const uint16_t PROGMEM f8_combo[] = {KC_F3, KC_F4, COMBO_END};
const uint16_t PROGMEM f9_combo[] = {KC_F4, KC_F5, COMBO_END};
const uint16_t PROGMEM f10_combo[] = {KC_F2, KC_F3, KC_F4, COMBO_END};

#if defined(UNICODEMAP_ENABLE) || defined(UNICODE_ENABLE)
const uint16_t PROGMEM emo_combo[] = {KC_L, KC_SCLN, COMBO_END};
#endif

#ifdef MOUSEKEY_ENABLE
const uint16_t PROGMEM cur_combo[] = {LTS(W), KC_F, KC_P, COMBO_END};
#endif

#ifdef ARSTNEIO_ENABLE
// GINNY
const uint16_t PROGMEM gin_w_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM gin_x_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM gin_p_combo[] = {KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM gin_j_combo[] = {KC_A, KC_N, COMBO_END};
const uint16_t PROGMEM gin_q_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM gin_lprn_combo[] = {KC_A, KC_I, COMBO_END};
const uint16_t PROGMEM gin_bspc_combo[] = {KC_A, KC_O, COMBO_END};

const uint16_t PROGMEM gin_f_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM gin_c_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM gin_k_combo[] = {KC_R, KC_N, COMBO_END};
const uint16_t PROGMEM gin_z_combo[] = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM gin_dot_combo[] = {KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM gin_rprn_combo[] = {KC_R, KC_O, COMBO_END};

const uint16_t PROGMEM gin_d_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM gin_m_combo[] = {KC_S, KC_N, COMBO_END};
const uint16_t PROGMEM gin_comm_combo[] = {KC_S, KC_E, COMBO_END};
const uint16_t PROGMEM gin_mins_combo[] = {KC_S, KC_I, COMBO_END};
const uint16_t PROGMEM gin_quot_combo[] = {KC_S, KC_O, COMBO_END};

const uint16_t PROGMEM gin_b_combo[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM gin_v_combo[] = {KC_T, KC_E, COMBO_END};
const uint16_t PROGMEM gin_g_combo[] = {KC_T, KC_I, COMBO_END};
const uint16_t PROGMEM gin_ques_combo[] = {KC_T, KC_O, COMBO_END};

const uint16_t PROGMEM gin_h_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM gin_y_combo[] = {KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM gin_l_combo[] = {KC_N, KC_O, COMBO_END};

const uint16_t PROGMEM gin_u_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM gin_exlm_combo[] = {KC_E, KC_O, COMBO_END};

const uint16_t PROGMEM gin_scln_combo[] = {KC_I, KC_O, COMBO_END};

const uint16_t PROGMEM gin_ent_combo[] = {KC_N, KC_E, KC_I, KC_O, COMBO_END};
#endif

combo_t key_combos[] = {
    [CHD_TAB] = COMBO(tab_combo, KC_TAB),
    [CHD_GRV] = COMBO(grv_combo, KC_GRV),
    [CHD_ENT] = COMBO(ent_combo, KC_ENT),
    // [CHD_NUMENT] = COMBO(nument_combo, KC_ENT),
    [CHD_ESC] = COMBO(esc_combo, KC_ESC),
    [CHD_TGNAV] = COMBO(tgnav_combo, TGNAV),
    [CHD_APO] = COMBO(apo_combo, A(S(KC_RBRC))),
    [CHD_OSS] = COMBO(oss_combo, OS(LSFT)),
    [CHD_OSSL] = COMBO(ossl_combo, OS(LSFT)),
    [CHD_BSPC] = COMBO(bspc_combo, KC_BSPC),
    [CHD_BSPCPRI] = COMBO(bspcpri_combo, KC_BSPC),
    [CHD_BSPCSEC] = COMBO(bspcsec_combo, KC_BSPC),
    [CHD_BSPCTER] = COMBO(bspcter_combo, KC_BSPC),
    [CHD_CLR] = COMBO_ACTION(clr_combo),
    [CHD_LKB] = COMBO(lkb_combo, OSL(_KB)),
    [CHD_QWER] = COMBO(qwer_combo, TGQWER),
    [CHD_F6] = COMBO(f6_combo, KC_F6),
    [CHD_F7] = COMBO(f7_combo, KC_F7),
    [CHD_F8] = COMBO(f8_combo, KC_F8),
    [CHD_F9] = COMBO(f9_combo, KC_F9),
    [CHD_F10] = COMBO(f10_combo, KC_F10),
#if defined(UNICODEMAP_ENABLE) || defined(UNICODE_ENABLE)
    [CHD_EMO] = COMBO(emo_combo, OSL(_EMO)),
#endif
#ifdef MOUSEKEY_ENABLE
    [CHD_CUR] = COMBO(cur_combo, TGCUR),
#endif

#ifdef ARSTNEIO_ENABLE
    [GIN_W] = COMBO(gin_w_combo, KC_W),
    [GIN_X] = COMBO(gin_x_combo, KC_X),
    [GIN_P] = COMBO(gin_p_combo, KC_P),
    [GIN_J] = COMBO(gin_j_combo, KC_J),
    [GIN_Q] = COMBO(gin_q_combo, KC_Q),
    [GIN_LPRN] = COMBO(gin_lprn_combo, KC_LPRN),
    [GIN_BSPC] = COMBO(gin_bspc_combo, KC_BSPC),
    [GIN_F] = COMBO(gin_f_combo, KC_F),
    [GIN_C] = COMBO(gin_c_combo, KC_C),
    [GIN_K] = COMBO(gin_k_combo, KC_K),
    [GIN_Z] = COMBO(gin_z_combo, KC_Z),
    [GIN_DOT] = COMBO(gin_dot_combo, KC_DOT),
    [GIN_RPRN] = COMBO(gin_rprn_combo, KC_RPRN),
    [GIN_D] = COMBO(gin_d_combo, KC_D),
    [GIN_M] = COMBO(gin_m_combo, KC_M),
    [GIN_COMM] = COMBO(gin_comm_combo, KC_COMM),
    [GIN_MINS] = COMBO(gin_mins_combo, KC_MINS),
    [GIN_QUOT] = COMBO(gin_quot_combo, KC_QUOT),
    [GIN_B] = COMBO(gin_b_combo, KC_B),
    [GIN_V] = COMBO(gin_v_combo, KC_V),
    [GIN_G] = COMBO(gin_g_combo, KC_G),
    [GIN_QUES] = COMBO(gin_ques_combo, KC_QUES),
    [GIN_H] = COMBO(gin_h_combo, KC_H),
    [GIN_Y] = COMBO(gin_y_combo, KC_Y),
    [GIN_L] = COMBO(gin_l_combo, KC_L),
    [GIN_U] = COMBO(gin_u_combo, KC_U),
    [GIN_EXLM] = COMBO(gin_exlm_combo, KC_EXLM),
    [GIN_SCLN] = COMBO(gin_scln_combo, KC_SCLN),
    [GIN_ENT] = COMBO(gin_ent_combo, KC_ENT),
#endif
};

int COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

void process_combo_event(uint16_t combo_index, bool pressed) {
    // action_tapping_process((keyrecord_t){});
    // mod_state = get_mods();

    switch(combo_index) {
        case CHD_CLR:
            if (pressed) {
                clear_oneshot_mods();
            }
            break;
        // case CHD_PRI:
        // case CHD_TGNAV:
        //     if (pressed) {
        //         layer_on(_NAV);
        //     }
        //     break;
        // case CHD_LKB:
        //     if (pressed) {
        //         set_oneshot_layer(_KB, ONESHOT_START);
        //     } else {
        //         clear_oneshot_layer_state(ONESHOT_PRESSED);
        //     }
        //     break;
//         // case XV_PASTE:
//         //     if (pressed) {
//         //         tap_code16(LCTL(KC_V));
//         //     }
//         //     break;
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    // if (KEYCODE_IS_MOD(combo->keycode)) return COMBO_MOD_TERM; // you have to config this yourself if you're using COMBO_TERM_PER_COMBO
    // switch (combo->keycode) {
    //     case KC_X:
    //         return 50;
    // }
    // or with combo index, i.e. its name from enum.
    switch (index) {
        case CHD_OSS:
        case CHD_OSSL:
        case CHD_TGNAV:
        case CHD_BSPC:
            return COMBO_TERM + 10;

        default:
            return COMBO_TERM;
    }
    // And if you're feeling adventurous, you can even decide by the keys in the chord,
    // i.e. the exact array of keys you defined for the combo.
    // This can be useful if your combos have a common key and you want to apply the
    // same combo term for all of them.
    // if (combo->keys[0] == KC_ENTER) { // if first key in the array is KC_ENTER
    //     return 150;
    // }
}
