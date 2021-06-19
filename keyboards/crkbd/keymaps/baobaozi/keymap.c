#include QMK_KEYBOARD_H

#include "baobaozi.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

/* Re-pass though to allow templates to be used */
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_wrapper(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                   ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Bkspc ─┐
            KC_TAB   ,_________________ROW_TOP_COLMK_L_________________,                    _________________ROW_TOP_COLMK_R_________________,KC_BSPC  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            LTN(GRV) ,_________________ROW_MID_COLMK_L_________________,                    _________________ROW_MID_COLMK_R_________________,LTN(ENT) ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_LSFT  ,_________________ROW_BOT_COLMK_L_________________,                    _________________ROW_BOT_COLMK_R_________________,KC_RSFT  ,
        // └─────────┴─────────┴─────────┴─────┬───┴─────┬───┴─────┬───┴─────┐       ┌─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─────────┴─────────┘
                                                __T_L3___,__T_L2___,__T_L1___,        __T_R1___,__T_R2___,__T_R3___
                                            // └─────────┴─────────┴─────────┘       └─────────┴─────────┴─────────┘
    ),

    [_QWERTY] = LAYOUT_wrapper(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                   ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Bkspc ─┐
            KC_TAB   ,_________________ROW_TOP_QWERT_L_________________,                    _________________ROW_TOP_QWERT_R_________________,KC_BSPC  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            LTN(GRV) ,_________________ROW_MID_QWERT_L_________________,                    _________________ROW_MID_QWERT_R_________________,LTN(ENT) ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_LSFT  ,_________________ROW_BOT_QWERT_L_________________,                    _________________ROW_BOT_QWERT_R_________________,KC_RSFT  ,
        // └─────────┴─────────┴─────────┴─────┬───┴─────┬───┴─────┬───┴─────┐       ┌─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─────────┴─────────┘
                                                __T_L3___,__T_L2___,__T_L1___,        __T_R1___,__T_R2___,__T_R3___
                                            // └─────────┴─────────┴─────────┘       └─────────┴─────────┴─────────┘
    ),

    [_NAV] = LAYOUT_wrapper(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                   ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Bkspc ─┐
            _______  ,_________________ROW_TOP_NAV_L___________________,                    _________________ROW_TOP_NAV_R___________________,KC_DEL   ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_NAV_L___________________,                    _________________ROW_MID_NAV_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_NAV_L___________________,                    _________________ROW_BOT_NAV_R___________________,_______  ,
        // └─────────┴─────────┴─────────┴─────┬───┴─────┬───┴─────┬───┴─────┐       ┌─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─────────┴─────────┘
                                                _______  ,_______  ,_______  ,        _______  ,KC_F     ,KC_ENT
                                            // └─────────┴─────────┴─────────┘       └─────────┴─────────┴─────────┘
    ),

    [_SYM] = LAYOUT_wrapper(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                   ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Bkspc ─┐
            _______  ,_________________ROW_TOP_SYM_L___________________,                    _________________ROW_TOP_SYM_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_SYM_L___________________,                    _________________ROW_MID_SYM_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_SYM_L___________________,                    _________________ROW_BOT_SYM_R___________________,_______  ,
        // └─────────┴─────────┴─────────┴─────┬───┴─────┬───┴─────┬───┴─────┐       ┌─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─────────┴─────────┘
                                                _______  ,_______  ,_______  ,        _______  ,_______  ,_______
                                            // └─────────┴─────────┴─────────┘       └─────────┴─────────┴─────────┘
    ),

    [_NUM] = LAYOUT_wrapper(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                   ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Bkspc ─┐
            _______  ,_________________ROW_TOP_NUM_L___________________,                    _________________ROW_TOP_NUM_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_NUM_L___________________,                    _________________ROW_MID_NUM_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_NUM_L___________________,                    _________________ROW_BOT_NUM_R___________________,_______  ,
        // └─────────┴─────────┴─────────┴─────┬───┴─────┬───┴─────┬───┴─────┐       ┌─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─────────┴─────────┘
                                                _______  ,_______  ,_______  ,        _______  ,KC_0     ,KC_DOT
                                            // └─────────┴─────────┴─────────┘       └─────────┴─────────┴─────────┘
    ),

    [_KB] = LAYOUT_wrapper(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                   ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Bkspc ─┐
            _______  ,_________________ROW_TOP_KB_L____________________,                    _________________ROW_TOP_KB_R____________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_KB_L____________________,                    _________________ROW_MID_KB_R____________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_KB_L____________________,                    _________________ROW_BOT_KB_R____________________,_______  ,
        // └─────────┴─────────┴─────────┴─────┬───┴─────┬───┴─────┬───┴─────┐       ┌─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─────────┴─────────┘
                                                _______  ,_______  ,_______  ,        _______  ,_______  ,_______
                                            // └─────────┴─────────┴─────────┘       └─────────┴─────────┴─────────┘
    ),

    [_CUR] = LAYOUT_wrapper(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── F ───┬─── P ───┬─── G ───┐                   ┌─── J ───┬─── L ───┬─── U ───┬─── Y ───┬─── ; ───┬─ Bkspc ─┐
            _______  ,_________________ROW_TOP_CUR_L___________________,                    _________________ROW_TOP_CUR_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_MID_CUR_L___________________,                    _________________ROW_MID_CUR_R___________________,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_BOT_CUR_L___________________,                    _________________ROW_BOT_CUR_R___________________,_______  ,
        // └─────────┴─────────┴─────────┴─────┬───┴─────┬───┴─────┬───┴─────┐       ┌─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─────────┴─────────┘
                                                _______  ,_______  ,_______  ,        _______  ,_______  ,_______
                                            // └─────────┴─────────┴─────────┘       └─────────┴─────────┴─────────┘
    )
};

// int RGB_current_mode;

// // Setting ADJUST layer RGB back to default
// void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
//   if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
//     layer_on(layer3);
//   } else {
//     layer_off(layer3);
//   }
// }

// void matrix_init_user(void) {
//     #ifdef RGBLIGHT_ENABLE
//       RGB_current_mode = rgblight_config.mode;
//     #endif
// }

#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void render_space(void) {
    oled_write_P(PSTR("\n"), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_mod_status_capslock(void) {
    led_t led_state = host_keyboard_led_state();

    oled_write_P(led_state.caps_lock ? PSTR(">CAP<\n") : PSTR(" cap\n\n"), false);
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
}

void render_layer_state(void) {
    if(layer_state_is(_CUR)) {
        oled_write_P(PSTR(" CUR\n"), false);
        oled_write_P(PSTR(" sor\n"), false);
    } else if(layer_state_is(_KB)) {
        oled_write_P(PSTR(" KB\n"), false);
        oled_write_P(PSTR(" act\n"), false);
    } else if(layer_state_is(_NUM)) {
        oled_write_P(PSTR(" NUM\n"), false);
        oled_write_P(PSTR(" 123\n"), false);
    } else if(layer_state_is(_SYM)) {
        oled_write_P(PSTR(" SYM\n"), false);
        oled_write_P(PSTR(" !@#\n"), false);
    } else if(layer_state_is(_NAV)) {
        oled_write_P(PSTR(" NAV\n"), false);
        oled_write_P(PSTR(" mov\n"), false);
    } else if(layer_state_is(_QWERTY)) {
        oled_write_P(PSTR(" QWE\n"), false);
        oled_write_P(PSTR(" sux\n"), false);
    } else {
        oled_write_P(PSTR(" CMK\n"), false);
        oled_write_P(PSTR(" yay\n"), false);
    }
    // static const char PROGMEM default_layer[] = {
    //     // 0x20, 0x9a, 0x9b, 0x9c, 0x20, // abs top, not coloured
    //     // 0x20, 0xba, 0xb8, 0xb9, 0x20, // not coloured top, not coloured bottom
    //     // 0x20, 0xba, 0xbb, 0xbc, 0x20, // not coloured top, coloured bottom
    //     // 0x20, 0xda, 0xdb, 0xdc, 0x20, 0}; // coloured top and bottom
    //     0x20, 0x9a, 0x9b, 0x9c, 0x20, // abs top, not coloured
    //     0x20, 0xb7, 0xbb, 0xb9, 0x20, // 0xd7 : nothing bottom left corner
    //     0x20, 0xba, 0xbb, 0xbc, 0x20, // not coloured top, coloured bottom
    //     0x20, 0xda, 0xdb, 0xdc, 0x20, 0}; // coloured top and bottom
    // static const char PROGMEM sec_layer[] = {
    //     // 0x20, 0x97, 0x98, 0x99, 0x20, // abs top, coloured
    //     // 0x20, 0xb7, 0xb8, 0xb9, 0x20, // coloured top, uncoloured bottom
    //     // 0x20, 0xd7, 0xd8, 0xd9, 0x20, 0}; // empty top and bottom
    //     0x20, 0x94, 0x95, 0x96, 0x20,
    //     0x20, 0xb4, 0xb5, 0xb6, 0x20,
    //     0x20, 0xb7, 0xbb, 0xb9, 0x20, // 0xd7 : nothing bottom left corner
    //     0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    // static const char PROGMEM pri_layer[] = {
    //     // 0x20, 0x9a, 0x9b, 0x9c, 0x20, // abs top, not coloured
    //     // 0x20, 0xba, 0xbb, 0xbc, 0x20, // not coloured top, coloured bottom
    //     // 0x20, 0xda, 0xdb, 0xdc, 0x20, 0}; // coloured top and bottom
    //     0x20, 0x94, 0x95, 0x96, 0x20,
    //     0x20, 0xb7, 0xbb, 0xb9, 0x20, // 0xd7 : nothing bottom left corner
    //     0x20, 0xb4, 0xb5, 0xb6, 0x20,
    //     0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    // static const char PROGMEM ter_layer[] = {
    //     0x20, 0x97, 0x98, 0x99, 0x20,
    //     0x20, 0xb7, 0xb8, 0xb9, 0x20,
    //     0x20, 0xb7, 0xbb, 0xb9, 0x20, // 0xd7 : nothing bottom left corner
    //     0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    // static const char PROGMEM qua_layer[] = {
    //     0x20, 0x9d, 0x9e, 0x9f, 0x20,
    //     0x20, 0xbd, 0xbe, 0xbf, 0x20,
    //     0x20, 0xbd, 0xbe, 0xbf, 0x20,
    //     0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    // if(layer_state_is(_NUM)) {
    //     oled_write_P(ter_layer, false);
    // } else if(layer_state_is(_NAV)) {
    //     oled_write_P(pri_layer, false);
    // } else if(layer_state_is(_SYM)) {
    //     oled_write_P(sec_layer, false);
    // } else if(layer_state_is(_KB)) {
    //     oled_write_P(qua_layer, false);
    // } else {
    //     oled_write_P(default_layer, false);
    // }
}

void render_status_main(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_capslock();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_space();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        oled_timer = timer_read32(); // when you type again, reset the timer to let you know inactivity
    }

    return true;
}

void oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > 60000) { // turn off OLED due to inactivity, to preserve OLED life. also turn off RGB.
        oled_off();
        // rgblight_disable_noeeprom();
        rgb_matrix_disable_noeeprom();
        return;
    } else {
        oled_on();
        // rgblight_enable_noeeprom();
        rgb_matrix_enable_noeeprom();
        if (is_master) {
            render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
        } else {
            render_status_secondary();
        }
    }
}

#endif
//   static uint16_t my_colon_timer;

//   switch (keycode) {
//     case LTN(Q):
//       if (record->event.pressed) {
//         layer_on(_NAV);
//         update_tri_layer_RGB(_NAV, _SYM, _NUM);
//       } else {
//         layer_off(_NAV);
//         update_tri_layer_RGB(_NAV, _SYM, _NUM);
//       }
//       return false;
//     case LTS(W):
//       if (record->event.pressed) {
//         layer_on(_SYM);
//         update_tri_layer_RGB(_NAV, _SYM, _NUM);
//       } else {
//         layer_off(_SYM);
//         update_tri_layer_RGB(_NAV, _SYM, _NUM);
//       }
//       return false;
//     case LT0(X):
//         if (record->event.pressed) {
//           layer_on(_NUM);
//         } else {
//           layer_off(_NUM);
//         }
//         return false;
//     case KC_RACL:
//         if (record->event.pressed) {
//           my_colon_timer = timer_read();
//           register_code(KC_RALT);
//         } else {
//           unregister_code(KC_RALT);
//           if (timer_elapsed(my_colon_timer) < TAPPING_TERM) {
//             SEND_STRING(":"); // Change the character(s) to be sent on tap here
//           }
//         }
//         return false;
//     case RGBRST:
//       #ifdef RGBLIGHT_ENABLE
//         if (record->event.pressed) {
//           eeconfig_update_rgblight_default();
//           rgblight_enable();
//           RGB_current_mode = rgblight_config.mode;
//         }
//       #endif
//       #ifdef RGB_MATRIX_ENABLE
//         if (record->event.pressed) {
//           eeconfig_update_rgb_matrix_default();
//           rgb_matrix_enable();
//         }
//       #endif
//       break;
    // }

// #ifdef RGB_MATRIX_ENABLE

// void suspend_power_down_keymap(void) {
//     rgb_matrix_set_suspend_state(true);
// }

// void suspend_wakeup_init_keymap(void) {
//     rgb_matrix_set_suspend_state(false);
// }

// #endif
