#include "baobaozi.h"
#include "eeprom.h"

void rgblight_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode) {
    rgblight_sethsv_noeeprom(hue, sat, val);
    wait_us(175);  // Add a slight delay between color and mode to ensure it's processed correctly
    rgblight_mode_noeeprom(mode);
}

void keyboard_post_init_rgb_light(void) {
    layer_state_set_rgb_light(layer_state);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return layer_state_set_rgb_light(state);
}

layer_state_t layer_state_set_rgb_light(layer_state_t state) {
    uint8_t mode = RGBLIGHT_MODE_STATIC_LIGHT;

    switch (get_highest_layer(state)) {
        case _FUNCTIONS:
            rgblight_set_hsv_and_mode(HSV_MAGENTA, mode);
            break;
        case _SETTINGS:
            rgblight_set_hsv_and_mode(HSV_RED, mode);
            break;
        case _MACROS:
            rgblight_set_hsv_and_mode(HSV_GOLD, mode);
            break;
        case _VIM:
            rgblight_set_hsv_and_mode(HSV_PINK, mode);
            break;
        default:  //  for any other layers, or the default layer
        {
            switch (get_highest_layer(default_layer_state)) {
                case _UNIX:
                    rgblight_set_hsv_and_mode(HSV_CYAN, mode);
                    break;
                case _WINDOWS:
                    rgblight_set_hsv_and_mode(HSV_GREEN, mode);
                    break;
                default:
                    rgblight_set_hsv_and_mode(HSV_CYAN, mode);
                    break;
            }
            break;
        }
    }
  return state;
}
