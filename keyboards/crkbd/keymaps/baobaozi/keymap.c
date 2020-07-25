#include QMK_KEYBOARD_H

#include "baobaozi.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer = 0;
#endif

extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── E ───┬─── R ───┬─── T ───┐                   ┌─── Y ───┬─── U ───┬─── I ───┬─── O ───┬─── P ───┬─ Bkspc ─┐
            KC_TAB   ,LT1(Q)   ,LT2(W)   ,KC_E     ,KC_R     ,KC_T     ,                    KC_Y     ,KC_U     ,KC_I     ,KC_O     ,KC_P     ,KC_BSPC  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            LT1(GRV) ,KC_A     ,KC_S     ,KC_D     ,KC_F     ,KC_G     ,                    KC_H     ,KC_J     ,KC_K     ,KC_L     ,LT1(SCLN),LT1(ENT) ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_LSFT  ,MS(Z)    ,LT3(X)   ,KC_C     ,KC_V     ,KC_B     ,                    KC_N     ,KC_M     ,KC_COMM  ,KC_DOT   ,MS(SLSH) ,KC_RSPC  ,
        // └─────────┴─────────┴─────────┴─────┬───┴─────┬───┴─────┬───┴─────┐       ┌─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─────────┴─────────┘
                                                MC(ESC)  ,MA(GRV)  ,MG(ENT)  ,        MG(TAB)  ,MA(SPC)  ,LT4(ENT)
                                            // └─────────┴─────────┴─────────┘       └─────────┴─────────┴─────────┘
    ),

    [_PRI] = LAYOUT(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── E ───┬─── R ───┬─── T ───┐                   ┌─── Y ───┬─── U ───┬─── I ───┬─── O ───┬─── P ───┬─ Bkspc ─┐
            ACG(Q)   ,_______  ,KC_LSFT  ,XXXXXXX  ,KC_VOLU  ,XXXXXXX  ,                    KC_DEL   ,KC_SCLN  ,KC_UP    ,KC_QUOT  ,KC_BSLS  ,KC_DEL   ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,_______  ,KC_CAPS  ,KC_MPRV  ,KC_MPLY  ,KC_MNXT  ,                    KC_BSPC  ,KC_LEFT  ,KC_DOWN  ,KC_RIGHT ,_______  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,KC_LSFT  ,XXXXXXX  ,XXXXXXX  ,KC_VOLD  ,XXXXXXX  ,                    XXXXXXX  ,KC_LBRC  ,KC_RBRC  ,KC_MINS  ,KC_EQL   ,_______  ,
        // └─────────┴─────────┴─────────┴─────┬───┴─────┬───┴─────┬───┴─────┐       ┌─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─────────┴─────────┘
                                                _______  ,_______  ,_______  ,        _______  ,_______  ,_______
                                            // └─────────┴─────────┴─────────┘       └─────────┴─────────┴─────────┘
    ),

    [_SEC] = LAYOUT(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── E ───┬─── R ───┬─── T ───┐                   ┌─── Y ───┬─── U ───┬─── I ───┬─── O ───┬─── P ───┬─ Bkspc ─┐
            ACG(Q)   ,XXXXXXX  ,_______  ,KC_LSFT  ,ASG(R)   ,XXXXXXX  ,                    KC_DEL   ,AA(SCLN) ,KC_PGUP  ,XXXXXXX  ,XXXXXXX  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,XXXXXXX  ,XXXXXXX  ,AAG(LEFT),AG(R)    ,AAG(RGHT),                    KC_BSPC  ,AG(LEFT) ,KC_PGDN  ,AG(RGHT) ,AA(SCLN) ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,KC_LSFT  ,XXXXXXX  ,AG(LEFT) ,XXXXXXX  ,AG(RGHT) ,                    XXXXXXX  ,TD(DQUO) ,TD(SQUO) ,TD(ENEM) ,XXXXXXX  ,_______  ,
        // └─────────┴─────────┴─────────┴─────┬───┴─────┬───┴─────┬───┴─────┐       ┌─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─────────┴─────────┘
                                                _______  ,_______  ,_______  ,        _______  ,_______  ,_______
                                            // └─────────┴─────────┴─────────┘       └─────────┴─────────┴─────────┘
    ),

    [_TER] = LAYOUT(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── E ───┬─── R ───┬─── T ───┐                   ┌─── Y ───┬─── U ───┬─── I ───┬─── O ───┬─── P ───┬─ Bkspc ─┐
            ACG(Q)   ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                    KC_DEL   ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                    KC_BSPC  ,KC_4     ,KC_5     ,KC_6     ,KC_DOT   ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,KC_LSFT  ,_______  ,KC_LSFT  ,XXXXXXX  ,XXXXXXX  ,                    KC_0     ,KC_1     ,KC_2     ,KC_3     ,XXXXXXX  ,_______  ,
        // └─────────┴─────────┴─────────┴─────┬───┴─────┬───┴─────┬───┴─────┐       ┌─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─────────┴─────────┘
                                                _______  ,_______  ,_______  ,        _______  ,_______  ,_______
                                            // └─────────┴─────────┴─────────┘       └─────────┴─────────┴─────────┘
    ),

    [_QUA] = LAYOUT(
        // ┌── Tab ──┬─── Q ───┬─── W ───┬─── E ───┬─── R ───┬─── T ───┐                   ┌─── Y ───┬─── U ───┬─── I ───┬─── O ───┬─── P ───┬─ Bkspc ─┐
            TD(SEEP) ,TD(SRST) ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                    XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                    XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,
        // ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            _______  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,                    TD(F212) ,AAG(DOT) ,ASG(SPC) ,AG(SPC)  ,KC_RSFT  ,_______  ,
        // └─────────┴─────────┴─────────┴─────┬───┴─────┬───┴─────┬───┴─────┐       ┌─────┴───┬─────┴───┬─────┴───┬─────┴─────────┴─────────┴─────────┘
                                                _______  ,_______  ,_______  ,        DEBUG    ,_______  ,_______
                                            // └─────────┴─────────┴─────────┘       └─────────┴─────────┴─────────┘
    )
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

// void matrix_init_user(void) {
//     #ifdef RGBLIGHT_ENABLE
//       RGB_current_mode = rgblight_config.mode;
//     #endif
// }

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void render_space(void) {
    oled_write_P(PSTR("     "), false);
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

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_TER)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_PRI)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_SEC)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void render_status_main(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > 30000) {
        oled_off();
        return;
    }
#ifndef SPLIT_KEYBOARD
    else { oled_on(); }
#endif

    if (is_master) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}

#endif
bool try_handle_macro(uint16_t keycode, keyrecord_t *record) {
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#       ifdef OLED_DRIVER_ENABLE
            oled_timer = timer_read32();
#       endif
    // set_timelog();
  }
//   static uint16_t my_colon_timer;

  switch (keycode) {
    case LT1(Q):
      if (record->event.pressed) {
        layer_on(_PRI);
        update_tri_layer_RGB(_PRI, _SEC, _TER);
      } else {
        layer_off(_PRI);
        update_tri_layer_RGB(_PRI, _SEC, _TER);
      }
      return false;
    case LT2(W):
      if (record->event.pressed) {
        layer_on(_SEC);
        update_tri_layer_RGB(_PRI, _SEC, _TER);
      } else {
        layer_off(_SEC);
        update_tri_layer_RGB(_PRI, _SEC, _TER);
      }
      return false;
    case LT3(X):
        if (record->event.pressed) {
          layer_on(_TER);
        } else {
          layer_off(_TER);
        }
        return false;
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
    }
    return true;
}

// #ifdef RGB_MATRIX_ENABLE

// void suspend_power_down_keymap(void) {
//     rgb_matrix_set_suspend_state(true);
// }

// void suspend_wakeup_init_keymap(void) {
//     rgb_matrix_set_suspend_state(false);
// }

// #endif
