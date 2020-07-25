#pragma once

// Shortcuts to make keymap more readable
// Layer change abbrs
#define LM1 MO(_PRI)
#define LM2 MO(_SEC)
#define LM3 MO(_TER)
#define LM4 MO(_QUA)

// Layer tap abbrs
#define LT1(kc) LT(_PRI, KC_##kc)
#define LT2(kc) LT(_SEC, KC_##kc)
#define LT3(kc) LT(_TER, KC_##kc)
#define LT4(kc) LT(_QUA, KC_##kc)

// Mod abbrs
#define AA(kc) A(KC_##kc)
#define AG(kc) G(KC_##kc)
#define AAG(kc) A(G(KC_##kc))
#define AAS(kc) A(S(KC_##kc))
#define ACG(kc) C(G(KC_##kc))
#define ASG(kc) S(G(KC_##kc))
#define ALL(kc) C(S(G(KC_##kc)))

// Mod tap abbrs
#define MG(kc) LGUI_T(KC_##kc)
#define MA(kc) LALT_T(KC_##kc)
#define MC(kc) LCTL_T(KC_##kc)
#define MS(kc) LSFT_T(KC_##kc)
