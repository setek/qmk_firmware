#include QMK_KEYBOARD_H

#include "baobaozi.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        // ┌── Esc ──┬─── 1 ───┬─── 2 ───┬─── 3 ───┬─── 4 ───┬─── 5 ───┐  Thumbs                          Thumbs  ┌─── 6 ───┬─── 7 ───┬─── 8 ───┬─── 9 ───┬─── 0 ───┬─ Extra ─┐
            KC_ESC   ,KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5     ,                                           KC_6     ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,KC_MPLY  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_TAB   ,LT1(Q)   ,LT2(W)   ,KC_E     ,KC_R     ,KC_T     ,ASG(3)   ,                       MCSG3    ,KC_Y     ,KC_U     ,KC_I     ,KC_O     ,KC_P     ,KC_BSPC  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            LT1(GRV) ,KC_A     ,KC_S     ,KC_D     ,KC_F     ,KC_G     ,ASG(4)   ,                       MCSG4    ,KC_H     ,KC_J     ,KC_K     ,KC_L     ,LT1(SCLN),LT1(ENT) ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐  ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_LSFT  ,MS(Z)    ,LT3(X)   ,KC_C     ,KC_V     ,KC_B     ,KC_DEL   ,KC_ESC   ,   TD(XPST) ,TD(CPST) ,KC_N     ,KC_M     ,KC_COMM  ,KC_DOT   ,MS(SLSH) ,KC_RSFT  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────┬───┴─────┬───┼─────────┼─────────┤  ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
            LT4(CAPS),KC_LCTL  ,KC_LALT  ,AAG(NO)  ,      KC_LGUI  ,    KC_BSPC  ,ASG(K)   ,   LT2(ENT) ,KC_SPC   ,     MG(SPC)  ,     KC_LEFT  ,KC_UP    ,KC_DOWN  ,KC_RGHT
        // └─────────┴─────────┴─────────┴─────────┘     └─────────┘   └─────────┴─────────┘  └─────────┴─────────┘    └─────────┘    └─────────┴─────────┴─────────┴─────────┘
    ),

    [_PRI] = LAYOUT(
        // ┌── Esc ──┬─── 1 ───┬─── 2 ───┬─── 3 ───┬─── 4 ───┬─── 5 ───┐  Thumbs                          Thumbs  ┌─── 6 ───┬─── 7 ───┬─── 8 ───┬─── 9 ───┬─── 0 ───┬─ Extra ─┐
            ACG(Q)   ,ASG(3)   ,ASG(4)   ,MCSG3    ,MCSG4    ,XXXXXXX  ,                                           XXXXXXX  ,KC_LBRC  ,KC_RBRC  ,KC_MINS  ,KC_EQL   ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,KC_LSFT  ,XXXXXXX  ,KC_VOLU  ,XXXXXXX  ,_______  ,                       _______  ,KC_DEL   ,KC_SCLN  ,KC_UP    ,KC_QUOT  ,KC_BSLS  ,KC_DEL   ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,XXXXXXX  ,KC_CAPS  ,KC_MPRV  ,KC_MPLY  ,KC_MNXT  ,_______  ,                       _______  ,KC_BSPC  ,KC_LEFT  ,KC_DOWN  ,KC_RIGHT ,_______  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐  ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,KC_LSFT  ,XXXXXXX  ,XXXXXXX  ,KC_VOLD  ,XXXXXXX  ,_______  ,_______  ,   _______  ,_______  ,TD(F212) ,AAG(DOT) ,ASG(SPC) ,AG(SPC)  ,KC_RSFT  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────┬───┴─────┬───┼─────────┼─────────┤  ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,      _______  ,    KC_DEL   ,_______  ,   _______  ,_______  ,     _______  ,     _______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┘     └─────────┘   └─────────┴─────────┘  └─────────┴─────────┘    └─────────┘    └─────────┴─────────┴─────────┴─────────┘
    ),

    [_SEC] = LAYOUT(
        // ┌── Esc ──┬─── 1 ───┬─── 2 ───┬─── 3 ───┬─── 4 ───┬─── 5 ───┐  Thumbs                          Thumbs  ┌─── 6 ───┬─── 7 ───┬─── 8 ───┬─── 9 ───┬─── 0 ───┬─ Extra ─┐
            ACG(Q)   ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                                           XXXXXXX  ,TD(DQUO) ,TD(SQUO) ,TD(ENEM) ,XXXXXXX  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,XXXXXXX  ,_______  ,KC_LSFT  ,ASG(R)   ,XXXXXXX  ,_______  ,                       _______  ,KC_DEL   ,AA(SCLN) ,KC_PGUP  ,XXXXXXX  ,XXXXXXX  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,XXXXXXX  ,XXXXXXX  ,AAG(LEFT),AG(R)    ,AAG(RGHT),_______  ,                       _______  ,KC_BSPC  ,AG(LEFT) ,KC_PGDN  ,AG(RGHT) ,AA(SCLN) ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐  ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,KC_LSFT  ,XXXXXXX  ,AG(LEFT) ,XXXXXXX  ,AG(RGHT) ,_______  ,_______  ,   _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,KC_RSFT  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────┬───┴─────┬───┼─────────┼─────────┤  ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,      _______  ,    _______  ,_______  ,   _______  ,_______  ,     _______  ,     _______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┘     └─────────┘   └─────────┴─────────┘  └─────────┴─────────┘    └─────────┘    └─────────┴─────────┴─────────┴─────────┘
    ),

    [_TER] = LAYOUT(
        // ┌── Esc ──┬─── 1 ───┬─── 2 ───┬─── 3 ───┬─── 4 ───┬─── 5 ───┐  Thumbs                          Thumbs  ┌─── 6 ───┬─── 7 ───┬─── 8 ───┬─── 9 ───┬─── 0 ───┬─ Extra ─┐
            ACG(Q)   ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                                           XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,                       _______  ,KC_DEL   ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,                       _______  ,KC_BSPC  ,KC_4     ,KC_5     ,KC_6     ,KC_DOT   ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐  ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,XXXXXXX  ,_______  ,KC_LSFT  ,XXXXXXX  ,XXXXXXX  ,_______  ,_______  ,   _______  ,_______  ,KC_0     ,KC_1     ,KC_2     ,KC_3     ,XXXXXXX  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────┬───┴─────┬───┼─────────┼─────────┤  ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,      _______  ,    _______  ,_______  ,   _______  ,_______  ,     _______  ,     _______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┘     └─────────┘   └─────────┴─────────┘  └─────────┴─────────┘    └─────────┘    └─────────┴─────────┴─────────┴─────────┘
    ),

    [_QUA] = LAYOUT(
        // ┌── Esc ──┬─── 1 ───┬─── 2 ───┬─── 3 ───┬─── 4 ───┬─── 5 ───┐  Thumbs                          Thumbs  ┌─── 6 ───┬─── 7 ───┬─── 8 ───┬─── 9 ───┬─── 0 ───┬─ Extra ─┐
            TD(SEEP) ,KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5    ,                                           KC_F6    ,KC_F7    ,KC_F8    ,KC_F9    ,KC_F10   ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,TD(SRST) ,RGB_MOD  ,RGB_HUI  ,RGB_SAI  ,RGB_VAI  ,_______  ,                       _______  ,KC_F11   ,KC_F12   ,KC_PAUS  ,XXXXXXX  ,XXXXXXX  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,RGB_M_P  ,RGB_TOG  ,RGB_HUD  ,RGB_SAD  ,RGB_VAD  ,_______  ,                       _______  ,XXXXXXX  ,XXXXXXX  ,KC_SLCK  ,XXXXXXX  ,XXXXXXX  ,DEBUG    ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐  ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,_______  ,   _______  ,_______  ,XXXXXXX  ,XXXXXXX  ,_______  ,_______  ,_______  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────┬───┴─────┬───┼─────────┼─────────┤  ├─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,_______  ,_______  ,      _______  ,    _______  ,_______  ,   DEBUG    ,_______  ,     _______  ,     _______  ,_______  ,_______  ,_______
        // └─────────┴─────────┴─────────┴─────────┘     └─────────┘   └─────────┴─────────┘  └─────────┴─────────┘    └─────────┘    └─────────┴─────────┴─────────┴─────────┘
    )
};
