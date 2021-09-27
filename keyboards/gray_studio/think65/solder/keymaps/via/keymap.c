/* Copyright 2019 Rys Sommefeldt
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

/*
* LED ranges for Think6.5v2 2U
* These values were derived from manual testing. Derived from keymaps/rys.
* ┌───────┬───────┬─────────────┬───────────────────────────────────────────┐
* │ 00 01 │ 02 03 │ 04 05 06 07 │ 08 09 10 11 12 13 14 15 16 17 18 19 20 21 │
* │ badge │ badge │    (?)      │              underglow (?)                │
* │  bar  │ icon  │             │                                           │
* └───────┴───────┴─────────────┴───────────────────────────────────────────┘
*/

// Define the LED ranges    start, count
#define T65_CAPS                0, 2
#define T65_BADGE               2, 2
#define T65_UNDERGLOW           4, 18
#define T65_ALL                 0, 22

const rgblight_segment_t PROGMEM mk5_rgb_caps[] = RGBLIGHT_LAYER_SEGMENTS(
    {T65_CAPS, HSV_WHITE}
);

const rgblight_segment_t PROGMEM mk5_rgb_layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {T65_BADGE, HSV_CYAN}
);

const rgblight_segment_t PROGMEM mk5_rgb_layer2[] = RGBLIGHT_LAYER_SEGMENTS(
    {T65_BADGE, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM mk5_rgb_layer3[] = RGBLIGHT_LAYER_SEGMENTS(
    {T65_BADGE, HSV_RED}
);

const rgblight_segment_t* const PROGMEM mk5_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    mk5_rgb_caps,
    mk5_rgb_layer1,
    mk5_rgb_layer2,
    mk5_rgb_layer3
);

void keyboard_post_init_user(void) {
    rgblight_layers = mk5_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    for (int i = 1; i <= 3; i++) {
        rgblight_set_layer_state(i, layer_state_cmp(state, i));
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_DEL,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
        KC_CAPS,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                      KC_SPC,                          KC_RALT, MO(1),                     KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_all(
        QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,
        _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                      _______,                         _______, _______,                   _______, _______, _______
    ),
    [2] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                      _______,                         _______, _______,                   _______, _______, _______
    ),
    [3] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                      _______,                         _______, _______,                   _______, _______, _______
    ),
};
