#include "baobaozi.h"

enum combo_events {
    // AS_PRI,
    // SD_SEC,
    // DF_QUA,
    // WE_TAB,
    // ER_GRV,
    CHD_TAB,
    CHD_GRV,
    CHD_ENT,
    CHD_ESC
    // XV_PASTE
};

// const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
// const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM tab_combo[] = {KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
// const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM grv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_C, KC_COMM, COMBO_END};
// const uint16_t PROGMEM paste_combo[] = {KC_X, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    // [AS_PRI] = COMBO_ACTION(as_combo),
    // [SD_SEC] = COMBO_ACTION(sd_combo),
    // [DF_QUA] = COMBO_ACTION(tab_combo),
    // [WE_TAB] = COMBO(we_combo, KC_TAB),
    // [ER_GRV] = COMBO(er_combo, KC_GRV),
    [CHD_TAB] = COMBO(tab_combo, KC_TAB),
    [CHD_GRV] = COMBO(grv_combo, KC_GRV),
    [CHD_ENT] = COMBO(ent_combo, KC_ENT),
    [CHD_ESC] = COMBO(esc_combo, KC_ESC)
    // [XV_PASTE] = COMBO_ACTION(paste_combo),
};

// void process_combo_event(uint8_t combo_index, bool pressed) {
//     switch(combo_index) {
//         case AS_PRI:
//             if (pressed) {
//                 layer_on(_PRI);
//             } else {
//                 layer_off(_PRI);
//             }
//             break;
//         case SD_SEC:
//             if (pressed) {
//                 layer_on(_SEC);
//             } else {
//                 layer_off(_SEC);
//             }
//             break;
//         case DF_QUA:
//             if (pressed) {
//                 layer_on(_QUA);
//             } else {
//                 layer_off(_QUA);
//             }
//             break;
//         // case XV_PASTE:
//         //     if (pressed) {
//         //         tap_code16(LCTL(KC_V));
//         //     }
//         //     break;
//     }
// }
