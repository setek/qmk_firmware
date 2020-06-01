
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
#define L_PRI (1 << 2)
#define L_SEC (1 << 3)
#define L_TER (1 << 4)
#define L_QUA (1 << 5)
// #define L_TER_TRI (L_TER | L_SEC | L_PRI)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Colemak");
    break;
  case L_QUA:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Actions");
    break;
  case L_TER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Numbers");
    break;
  case L_SEC:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Symbols");
    break;
  case L_PRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Nav");
    break;
//   case L_TER:
//   case L_TER_TRI:
//     snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
//     break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
