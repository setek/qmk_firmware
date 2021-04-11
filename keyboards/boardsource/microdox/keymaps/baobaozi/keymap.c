#include QMK_KEYBOARD_H
#include "split_util.h"

#include "baobaozi.h"

/* Re-pass though to allow templates to be used */
#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_wrapper(
        // ┌─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐         ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┐
            _________________ROW_TOP_COLMK_L_________________,          _________________ROW_TOP_COLMK_R_________________,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┤
            _________________ROW_MID_COLMK_L_________________,          _________________ROW_MID_COLMK_R_________________,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┤
            _________________ROW_BOT_COLMK_L_________________,          _________________ROW_BOT_COLMK_R_________________,
        // └─────────┴─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┴─────────┘
                                __T_L3___,__T_L2___,__T_L1___,          __T_R1___,__T_R2___,__T_R3___
                            // └─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┘
    ),

    [_NAV] = LAYOUT_wrapper(
        // ┌─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐         ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┐
            _________________ROW_TOP_NAV_L___________________,          _________________ROW_TOP_NAV_R___________________,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┤
            _________________ROW_MID_NAV_L___________________,          _________________ROW_MID_NAV_R___________________,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┤
            _________________ROW_BOT_NAV_L___________________,          _________________ROW_BOT_NAV_R___________________,
        // └─────────┴─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┴─────────┘
                                _______  ,_______  ,_______  ,          _______  ,KC_F     ,KC_ENT
                            // └─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┘
    ),

    [_SYM] = LAYOUT_wrapper(
        // ┌─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐         ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┐
            _________________ROW_TOP_SYM_L___________________,          _________________ROW_TOP_SYM_R___________________,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┤
            _________________ROW_MID_SYM_L___________________,          _________________ROW_MID_SYM_R___________________,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┤
            _________________ROW_BOT_SYM_L___________________,          _________________ROW_BOT_SYM_R___________________,
        // └─────────┴─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┴─────────┘
                                _______  ,_______  ,_______  ,          _______  ,_______  ,_______
                            // └─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┘
    ),

    [_NUM] = LAYOUT_wrapper(
        // ┌─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐         ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┐
            _________________ROW_TOP_NUM_L___________________,          _________________ROW_TOP_NUM_R___________________,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┤
            _________________ROW_MID_NUM_L___________________,          _________________ROW_MID_NUM_R___________________,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┤
            _________________ROW_BOT_NUM_L___________________,          _________________ROW_BOT_NUM_R___________________,
        // └─────────┴─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┴─────────┘
                                _______  ,_______  ,_______  ,          _______  ,KC_0     ,KC_DOT
                            // └─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┘
    ),

    [_KB] = LAYOUT_wrapper(
        // ┌─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐         ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┐
            _________________ROW_TOP_KB_L____________________,          _________________ROW_TOP_KB_R____________________,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┤
            _________________ROW_MID_KB_L____________________,          _________________ROW_MID_KB_R____________________,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┤
            _________________ROW_BOT_KB_L____________________,          _________________ROW_BOT_KB_R____________________,
        // └─────────┴─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┴─────────┘
                                _______  ,_______  ,_______  ,          _______  ,_______  ,_______
                            // └─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┘
    ),

    [_CUR] = LAYOUT_wrapper(
        // ┌─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐         ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┐
            _________________ROW_TOP_CUR_L___________________,          _________________ROW_TOP_CUR_R___________________,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┤
            _________________ROW_MID_CUR_L___________________,          _________________ROW_MID_CUR_R___________________,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┤
            _________________ROW_BOT_CUR_L___________________,          _________________ROW_BOT_CUR_R___________________,
        // └─────────┴─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┴─────────┘
                                _______  ,_______  ,_______  ,          _______  ,_______  ,_______
                            // └─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┘
    ),
};

#ifdef OLED_DRIVER_ENABLE
// static uint32_t oled_timer = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master())
        return OLED_ROTATION_180;
    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
        0
    };
    oled_write_P(PSTR(" \n"), false);
    oled_write_P(qmk_logo, false);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("cap sft ctl opt cmd\n"), false);

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR(" ^  ") : PSTR("    "), false);

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(PSTR(" ^  "), false);
    } else {
        oled_write_P(PSTR("    "), false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(PSTR(" ^  "), false);
    } else {
        oled_write_P(PSTR("    "), false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(PSTR(" ^  "), false);
    } else {
        oled_write_P(PSTR("    "), false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(PSTR(" ^  "), false);
    } else {
        oled_write_P(PSTR("    "), false);
    }
}

static void render_status(void) {
    // oled_write_P(PSTR("CK Na Sy Nm KB Cu Em\n"), false); // you get a max of 20 chars on these small OLEDs. 4 lines actually fits though!
    switch (get_highest_layer(layer_state)) {
        // You also have access to a `default_layer_state` for when you DF … so you can tell difference between which default layer you’re on
        case _NAV:
            oled_write_P(PSTR("NAVIGATION   > move\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYMBOLS       > !@#\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUMPAD        > 123\n"), false);
            break;
        case _KB:
            oled_write_P(PSTR("KEYBOARD  > actions\n"), false);
            break;
        case _CUR:
            oled_write_P(PSTR("CURSOR      > mouse\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("QWERTY      > sucks\n"), false);
            break;
        default:
            oled_write_P(PSTR("COLEMAK    > typing\n"), false);
    }
}

// void keyboard_post_init_user(void) {
//     // set initial animation type (in that I don’t want it)
//     rgblight_mode(RGBLIGHT_MODE_KNIGHT);
// }

// bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//     if (record->event.pressed) {
//         oled_timer = timer_read32(); // when you type again, reset the timer to let you know inactivity
//     }

//     return true;
// }

void oled_task_user(void) {
    // if (timer_elapsed32(oled_timer) > 60000) {
    //     oled_off();
    //     rgblight_disable_noeeprom();

    //     return;
    // } else {
        oled_on();
        // rgblight_disable_noeeprom();
        // rgblight_enable_noeeprom();

        if (is_keyboard_master()) {
            render_status();
            oled_write_P(PSTR("\n"), false);
            render_mod_status(get_mods()|get_oneshot_mods());
        } else {
            render_logo();
            oled_scroll_left();
        }
    // }
}
#endif
