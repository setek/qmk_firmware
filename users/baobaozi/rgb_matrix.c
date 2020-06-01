#include "baobaozi.h"

const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_CYAN}
);
const rgblight_segment_t PROGMEM pri_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_GOLD}
);
const rgblight_segment_t PROGMEM sec_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM ter_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_PINK}
);
const rgblight_segment_t PROGMEM qua_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_WHITE}
);
// as later layers take precedence, we want capslock layer to override
// but for some reason, capslock colour layer doesn’t work anyway. shrug.
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_RED},
    {9, 2, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
// const rgblight_segment_t *const PROGMEM rgb_light_layers[] = {
const rgblight_segment_t *const PROGMEM rgb_light_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    pri_layer,
    sec_layer,
    ter_layer,
    qua_layer,
    capslock_layer
);

layer_state_t layer_state_set_user(layer_state_t state) {
    dprintf("in layer_state_set_user: %u\n", state);
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(2, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(4, layer_state_cmp(state, _KB));

    // if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    //     rgblight_sethsv_range(HSV_RED, 0, RGBLED_NUM);
    // }

    return state;
}

// bool led_update_user_rgb(led_t led_state) { // this one doesn’t run at all lol
bool led_update_user(led_t led_state) {
    dprintf("in led_update_user: cap=%u\n", led_state.caps_lock);
    rgblight_set_layer_state(5, led_state.caps_lock);
    // if (led_state.caps_lock) {
    //     rgblight_sethsv(HSV_RED);
    // }

    return true;
}

void keyboard_post_init_user(void) {
    // set initial animation type (in that I don’t want it)
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    // set the default colour
    // rgblight_sethsv_range(HSV_CYAN, 0, RGBLED_NUM);
    // Enable the LED layers
    rgblight_layers = rgb_light_layers;
}
