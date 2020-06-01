#include QMK_KEYBOARD_H

#include "baobaozi.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── E ───┬─── R ───┬─── T ───┬─── Y ───┬─── U ───┬─── I ───┬─── O ───┬─── P ───┬── Bkspc ──┐
            KC_TAB   ,KC_Q     ,KC_W     ,KC_E     ,KC_R     ,KC_T     ,KC_Y     ,KC_U     ,KC_I     ,KC_O     ,KC_P     ,KC_BSPC    ,
        // ├─────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬──────────┤
            LT1(GRV)  ,LT1(A)   ,KC_S     ,KC_D     ,KC_F     ,KC_G     ,KC_H     ,KC_J     ,KC_K     ,KC_L     ,KC_SCLN  ,LT1(ENT)  ,
        // ├──────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬─────────┤
            KC_LSFT    ,MS(Z)    ,KC_X     ,KC_C     ,KC_V     ,KC_B     ,KC_N     ,KC_M     ,MG(COMM) ,MA(DOT)  ,MS(SLSH) ,KC_RSFT  ,
        // ├─────────┬─┴───────┬─┴───────┬─┴───────┬─┴───────┬─┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            LT4(CAPS),MC(ESC)  ,MA(TAB)  ,MG(GRV)  ,LM2      ,LT3(SPC)             ,LM1      ,KC_LEFT  ,KC_UP    ,KC_DOWN  ,KC_RGHT
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_PRI] = LAYOUT(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── E ───┬─── R ───┬─── T ───┬─── Y ───┬─── U ───┬─── I ───┬─── O ───┬─── P ───┬── Bkspc ──┐
            KC_ESC   ,KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5     ,KC_6     ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,KC_DEL     ,
        // ├─────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬──────────┤
            _______   ,_______  ,KC_CAPS  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______   ,
        // ├──────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬─────────┤
            _______    ,_______  ,KC_LSFT  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
        // ├─────────┬─┴───────┬─┴───────┬─┴───────┬─┴───────┬─┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,_______  ,_______              ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_SEC] = LAYOUT(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── E ───┬─── R ───┬─── T ───┬─── Y ───┬─── U ───┬─── I ───┬─── O ───┬─── P ───┬── Bkspc ──┐
            _______  ,KC_EXLM  ,KC_AT    ,KC_HASH  ,KC_DLR   ,KC_PERC  ,KC_CIRC  ,KC_AMPR  ,KC_ASTR  ,KC_LPRN  ,KC_RPRN  ,KC_DEL   ,
        // ├─────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬──────────┤
            _______   ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______   ,
        // ├──────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬─────────┤
            _______    ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
        // ├─────────┬─┴───────┬─┴───────┬─┴───────┬─┴───────┬─┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,_______  ,_______              ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_TER] = LAYOUT(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── E ───┬─── R ───┬─── T ───┬─── Y ───┬─── U ───┬─── I ───┬─── O ───┬─── P ───┬── Bkspc ──┐
            _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,KC_LBRC  ,KC_RBRC  ,KC_MINS  ,KC_EQL   ,KC_DEL     ,
        // ├─────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬──────────┤
            _______   ,_______  ,KC_CAPS  ,_______  ,_______  ,_______  ,_______  ,KC_SCLN  ,_______  ,KC_QUOT  ,KC_BSLS  ,_______   ,
        // ├──────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬─────────┤
            _______    ,_______  ,KC_LSFT  ,_______  ,_______  ,_______  ,AG(F2)   ,KC_F12   ,_______  ,_______  ,_______  ,_______  ,
        // ├─────────┬─┴───────┬─┴───────┬─┴───────┬─┴───────┬─┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,_______  ,_______              ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),

    [_QUA] = LAYOUT(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── E ───┬─── R ───┬─── T ───┬─── Y ───┬─── U ───┬─── I ───┬─── O ───┬─── P ───┬── Bkspc ──┐
            _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,KC_UP    ,_______  ,_______  ,_______    ,
        // ├─────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬──────────┤
            _______   ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,KC_LEFT  ,KC_DOWN  ,KC_RGHT  ,_______  ,_______   ,
        // ├──────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬────────┴┬─────────┤
            _______    ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
        // ├─────────┬─┴───────┬─┴───────┬─┴───────┬─┴───────┬─┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,_______  ,_______              ,_______  ,_______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┴─────────┴─────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
    ),
};
