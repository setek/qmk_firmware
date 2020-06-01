#include "baobaozi.h"

const rgblight_segment_t PROGMEM colemak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, 170, 255, 255}
);
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM/2, 170, 255, 150},
    {RGBLED_NUM/2, RGBLED_NUM, 0, 0, 100}
);
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_GOLD}
);
const rgblight_segment_t PROGMEM sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_CYAN}
);
const rgblight_segment_t PROGMEM kb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM/2, 115, 250, 175}, // between springgreen and turquoise
    {RGBLED_NUM/2, RGBLED_NUM, 70, 255, 150} // between springgreen and turquoise
);
const rgblight_segment_t PROGMEM cur_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_WHITE}
);
// as later layers take precedence, we want capslock layer to override
// but for some reason, capslock colour layer doesn’t work anyway. shrug.
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, 0, 255, 200}
    // {7, 2, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
// const rgblight_segment_t *const PROGMEM rgb_light_layers[] = {
const rgblight_segment_t *const PROGMEM rgb_light_layers[] = RGBLIGHT_LAYERS_LIST(
    colemak_layer,
    qwerty_layer,
    nav_layer,
    sym_layer,
    num_layer,
    kb_layer,
    cur_layer,
    capslock_layer
);

layer_state_t layer_state_set_user(layer_state_t state) {
    // uint8_t layer = biton32(state);
    dprintf("in layer_state_set_user: %u\n", state);
    // Both layers will light up if both kb layers are active
    // rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK));
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(5, layer_state_cmp(state, _KB));
    rgblight_set_layer_state(6, layer_state_cmp(state, _CUR));

    // RGB Modes
    // 1 = Static
    // 2-5 = Breathing
    // 6-8 = Rainbow
    // 9-14 = Swirl
    // 15-20 = Snake
    // 21-24 = Nightrider
    // 25 = Christmas
    // 26-30 = Static Gradient

    // switch (layer) {
    //     case _QWERTY:
    //         rgblight_mode(desired);
    //         break;

    //     case _LOWER: // If we're in swirl mode, then speed up the swirls, otherwise breathe
    //         check = rgblight_get_mode();
    //         if (check > 8 && check < 15) {
    //             rgblight_mode(14);
    //         } else {
    //             rgblight_mode(5);
    //         }
    //         break;
    // }

    // if (layer_state_cmp(state, _COLEMAK)) {
    //     dprintf("HIHIHI in layer_state_is(0): %u\n", layer_state_cmp(state, _COLEMAK));
    //     rgblight_sethsv_noeeprom(170, 255, 255);
    //     wait_us(175);  // Add a slight delay between color and mode to ensure it's processed correctly
    //     rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
    // }
    // wish this worked …
    // if (layer_state_cmp(state, _QWERTY)) {
    //     dprintf("HIHIHI in layer_state_is(0): %u\n", layer_state_cmp(state, _QWERTY) == 1);
    //     rgblight_mode(RGBLIGHT_MODE_BREATHING);
    // } else {
    //     rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    // }

    // if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    //     rgblight_sethsv_range(HSV_RED, 0, RGBLED_NUM);
    // }

    return state;
}

// bool led_update_user_rgb(led_t led_state) { // this one doesn’t run at all lol
bool led_update_user(led_t led_state) {
    dprintf("in led_update_user: cap=%u\n", led_state.caps_lock);
    rgblight_set_layer_state(7, led_state.caps_lock);
    // if (led_state.caps_lock) {
    //     rgblight_sethsv(HSV_RED);
    // }

    return true;
}

void keyboard_post_init_user(void) {
    // // set initial animation type (in that I don’t want it)
    // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    // // set the default colour
    // rgblight_sethsv_range(HSV_CYAN, 0, RGBLED_NUM);
    // Enable the LED layers
    rgblight_layers = rgb_light_layers;
    // drashna’s fix for weird lights
    rgblight_enable_noeeprom();
    layer_state_set_user(0);
    // rgblight_mode(RGBLIGHT_MODE_KNIGHT);
}
