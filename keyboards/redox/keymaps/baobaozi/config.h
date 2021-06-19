/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#undef RGBLED_NUM
#define RGBLED_NUM 14
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// #define RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_EFFECT_TWINKLE // single colour pulse in and out
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD // all same colour, slowwww fade to other colours
// #define RGBLIGHT_EFFECT_SNAKE // single colour rolling wave
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL // different colours, fade to other colours
// #define RGBLIGHT_EFFECT_BREATHING // slowly pulses in a breathing fashion
// #define RGBLIGHT_EFFECT_KNIGHT // blue that flashes back and forth
// #define RGBLIGHT_EFFECT_CHRISTMAS // alternating red and green
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT // whole rainbow but doesn’t actually animate
// #define RGBLIGHT_EFFECT_RGB_TEST // harsh flash between different colours
// #define RGBLIGHT_EFFECT_ALTERNATING // single colour flashing in and out
