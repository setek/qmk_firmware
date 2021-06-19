#include QMK_KEYBOARD_H

#include "baobaozi.h"

/* Re-pass though to allow templates to be used */
#define LAYOUT_wrapper(...) LAYOUT_65_ansi_blocker(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_wrapper(
        // ┌── Esc ──┬─── 1 ───┬─── 2 ───┬─── 3 ───┬─── 4 ───┬─── 5 ───┬─── 6 ───┬─── 7 ───┬─── 8 ───┬─── 9 ───┬─── 0 ───┬─── - ───┬─── = ───┬─ Bkspc ─┬─ Extra ─┐
            KC_ESC   ,_________________ROW_NUMBERS_L___________________,_________________ROW_NUMBERS_R___________________,KC_MINS  ,KC_EQL   ,KC_BSPC  ,KC_MPLY  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_TAB   ,_________________ROW_TOP_COLMK_L_________________,_________________ROW_TOP_COLMK_R_________________,KC_LBRC  ,KC_RBRC  ,KC_BSLS  ,TD(XPST) ,
        // ├─────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴─────────┼─────────┤
            LTN(GRV)    ,_________________ROW_MID_COLMK_L_________________,_________________ROW_MID_COLMK_R_________________,KC_QUOT  ,LTN(ENT)        ,TD(CPST) ,
        // ├────────────┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬─────────┼─────────┤
            KC_LSFT            ,_________________ROW_BOT_COLMK_L_________________,_________________ROW_BOT_COLMK_R_________________,KC_RSFT  ,KC_UP    ,TD(F212) ,
        // ├───────────────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            __T_L3___,__T_L2___,__T_L1___,__T_R1___                                                            ,__T_R3___,__T_R1___,KC_LEFT  ,KC_DOWN  ,KC_RGHT
        // └─────────┴─────────┴─────────┴─────────────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_NAV] = LAYOUT_wrapper(
        // ┌── Esc ──┬─── 1 ───┬─── 2 ───┬─── 3 ───┬─── 4 ───┬─── 5 ───┬─── 6 ───┬─── 7 ───┬─── 8 ───┬─── 9 ───┬─── 0 ───┬─── - ───┬─── = ───┬─ Bkspc ─┬─ Extra ─┐
            _______  ,_________________ROW_5_NOTHING___________________,_________________ROW_5_NOTHING___________________,XXXXXXX  ,XXXXXXX  ,KC_DEL   ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_TOP_NAV_L___________________,_________________ROW_TOP_NAV_R___________________,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,
        // ├─────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴─────────┼─────────┤
            _______     ,_________________ROW_MID_NAV_L___________________,_________________ROW_MID_NAV_R___________________,XXXXXXX  ,_______         ,_______  ,
        // ├────────────┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬─────────┼─────────┤
            _______            ,_________________ROW_BOT_NAV_L___________________,_________________ROW_BOT_NAV_R___________________,_______  ,_______  ,_______  ,
        // ├───────────────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______                                                              ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_SYM] = LAYOUT_wrapper(
        // ┌── Esc ──┬─── 1 ───┬─── 2 ───┬─── 3 ───┬─── 4 ───┬─── 5 ───┬─── 6 ───┬─── 7 ───┬─── 8 ───┬─── 9 ───┬─── 0 ───┬─── - ───┬─── = ───┬─ Bkspc ─┬─ Extra ─┐
            _______  ,_________________ROW_5_NOTHING___________________,_________________ROW_5_NOTHING___________________,XXXXXXX  ,XXXXXXX  ,_______  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_TOP_SYM_L___________________,_________________ROW_TOP_SYM_R___________________,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,
        // ├─────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴─────────┼─────────┤
            _______     ,_________________ROW_MID_SYM_L___________________,_________________ROW_MID_SYM_R___________________,XXXXXXX  ,_______         ,_______  ,
        // ├────────────┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬─────────┼─────────┤
            _______            ,_________________ROW_BOT_SYM_L___________________,_________________ROW_BOT_SYM_R___________________,_______  ,_______  ,_______  ,
        // ├───────────────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______                                                              ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_NUM] = LAYOUT_wrapper(
        // ┌── Esc ──┬─── 1 ───┬─── 2 ───┬─── 3 ───┬─── 4 ───┬─── 5 ───┬─── 6 ───┬─── 7 ───┬─── 8 ───┬─── 9 ───┬─── 0 ───┬─── - ───┬─── = ───┬─ Bkspc ─┬─ Extra ─┐
            _______  ,_________________ROW_5_NOTHING___________________,_________________ROW_5_NOTHING___________________,XXXXXXX  ,XXXXXXX  ,_______  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_TOP_NUM_L___________________,_________________ROW_TOP_NUM_R___________________,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,
        // ├─────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴─────────┼─────────┤
            _______     ,_________________ROW_MID_NUM_L___________________,_________________ROW_MID_NUM_R___________________,XXXXXXX  ,_______         ,_______  ,
        // ├────────────┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬─────────┼─────────┤
            _______            ,_________________ROW_BOT_NUM_L___________________,_________________ROW_BOT_NUM_R___________________,_______  ,_______  ,_______  ,
        // ├───────────────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______                                                              ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_KB] = LAYOUT_wrapper(
        // ┌── Esc ──┬─── 1 ───┬─── 2 ───┬─── 3 ───┬─── 4 ───┬─── 5 ───┬─── 6 ───┬─── 7 ───┬─── 8 ───┬─── 9 ───┬─── 0 ───┬─── - ───┬─── = ───┬─ Bkspc ─┬─ Extra ─┐
            _______  ,_________________ROW_NUM_KB_L____________________,_________________ROW_NUM_KB_R____________________,KC_F11   ,KC_F12   ,_______  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_________________ROW_TOP_KB_L____________________,_________________ROW_TOP_KB_R____________________,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,
        // ├─────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴─────────┼─────────┤
            _______     ,_________________ROW_MID_KB_L____________________,_________________ROW_MID_KB_R____________________,XXXXXXX  ,_______         ,_______  ,
        // ├────────────┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬──┴──────┬─────────┼─────────┤
            _______            ,_________________ROW_BOT_KB_L____________________,_________________ROW_BOT_KB_R____________________,_______  ,_______  ,_______  ,
        // ├───────────────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______                                                              ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),
};
