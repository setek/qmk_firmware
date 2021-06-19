#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _NUML 1
#define _NUMR 2
#define _NAVL 3
#define _NAVR 4
#define _XTRL 5
#define _XTRR 6

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_3x5_3(
     KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,           KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,
     LGUI_T(KC_A), LSFT_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), KC_G,           KC_H,   RCTL_T(KC_J), LALT_T(KC_K), RSFT_T(KC_L), RGUI_T(KC_SCLN),
     KC_Z,         KC_X,         KC_C,         RALT_T(KC_V), KC_B,           KC_N,   RALT_T(KC_M), KC_COMM,      KC_DOT,       KC_SLSH,
          LT(_NUMR, KC_ESC), LT(_NAVR, KC_SPC), LT(_XTRR, KC_TAB),           LT(_XTRL, KC_DEL), LT(_NAVL, KC_ENT), LT(_NUML, KC_BSPC)
  ),

  [_NUML] = LAYOUT_3x5_3(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            _______, _______, _______, _______, _______,
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,            _______, KC_RCTL, KC_LALT, KC_RSFT, KC_RGUI,
     _______, _______,  KC_GRV, KC_MINS,  KC_EQL,            _______, KC_RALT, _______, _______, _______,
                        KC_ESC,  KC_SPC,  KC_TAB,            _______, _______, _______
  ),

  [_NUMR] = LAYOUT_3x5_3(
     _______, _______, _______, _______, _______,              KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
     KC_LGUI, KC_LSFT, KC_LALT, KC_LCTL, _______,              KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
     _______, _______, _______, KC_RALT, _______,            KC_BSLS, KC_COLN, KC_QUOT,  KC_F11,  KC_F12,
                       _______, _______, _______,             KC_DEL,  KC_ENT, KC_BSPC
  ),

  [_NAVL] = LAYOUT_3x5_3(
     _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______,
     _______, _______, KC_HOME,  KC_END, _______,            _______, KC_RCTL, KC_LALT, KC_RSFT, KC_RGUI,
     _______, _______, _______, _______, _______,            _______, KC_RALT, _______, _______, _______,
                        KC_ESC,  KC_SPC,  KC_TAB,            _______, _______, _______
  ),

  [_NAVR] = LAYOUT_3x5_3(
     _______, _______, _______, _______, _______,            _______, KC_PGDN,   KC_UP, KC_PGUP, _______,
     KC_LGUI, KC_LSFT, KC_LALT, KC_LCTL, _______,            _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
     _______, _______, _______, KC_RALT, _______,            _______, KC_HOME,  KC_END, _______, _______,
                       _______, _______, _______,             KC_DEL,  KC_ENT, KC_BSPC
  ),

  [_XTRL] = LAYOUT_3x5_3(
     _______, _______, KC_QUOT, KC_DQUO, _______,            _______, _______, _______, _______, _______,
     _______, _______, KC_PLUS,  KC_EQL, _______,            _______, KC_RCTL, KC_LALT, KC_RSFT, KC_RGUI,
     _______, _______, _______, _______, _______,            _______, KC_RALT, _______, _______, _______,
                        KC_ESC,  KC_SPC,  KC_TAB,            _______, _______, _______
  ),

  [_XTRR] = LAYOUT_3x5_3(
     _______, _______, _______, _______, _______,            _______, KC_LBRC, KC_RBRC, _______, _______,
     KC_LGUI, KC_LSFT, KC_LALT, KC_LCTL, _______,            _______, KC_LPRN, KC_RPRN, _______, _______,
     _______, _______, _______, KC_RALT, _______,            _______,   KC_LT,   KC_GT, _______, _______,
                       _______, _______, _______,             KC_DEL,  KC_ENT, KC_BSPC
  ),
};
