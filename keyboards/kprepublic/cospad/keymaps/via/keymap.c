/* Copyright 2020 Team Mechlovin
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

#define COSPAD_UNDERGLOW 0, 4

const rgblight_segment_t PROGMEM mk5_rgb_blank[] = RGBLIGHT_LAYER_SEGMENTS(
    {COSPAD_UNDERGLOW, HSV_WHITE}
);

const rgblight_segment_t PROGMEM mk5_rgb_layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {COSPAD_UNDERGLOW, HSV_CYAN}
);

const rgblight_segment_t PROGMEM mk5_rgb_layer2[] = RGBLIGHT_LAYER_SEGMENTS(
    {COSPAD_UNDERGLOW, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM mk5_rgb_layer3[] = RGBLIGHT_LAYER_SEGMENTS(
    {COSPAD_UNDERGLOW, HSV_RED}
);

const rgblight_segment_t* const PROGMEM mk5_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    mk5_rgb_blank,
    mk5_rgb_layer1,
    mk5_rgb_layer2,
    mk5_rgb_layer3
);

void keyboard_post_init_user(void) {
    rgblight_layers = mk5_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    for (int i = 1; i <= 3; i++) {
        rgblight_set_layer_state(i, layer_state_cmp(state, i));
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _BL: (Base Layer) Default Layer
     * ,-------------------.
     * |Esc |TAB | FN | BS |
     * |----|----|----|----|
     * | NL | /  | *  | -  |
     * |----|----|----|----|
     * | 7  | 8  | 9  |    |
     * |----|----|----| +  |
     * | 4  | 5  | 6  |    |
     * |----|----|----|----|
     * | 1  | 2  | 3  |    |
     * |----|----|----| En |
     * |   0     | .  |    |
     * `-------------------'
     */
    [0] = LAYOUT_numpad_6x4(
        KC_ESC,  KC_TAB,  MO(1),   KC_BSPC,
        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,            KC_PDOT, KC_PENT
    ),

    /* Keymap _FL: Function Layer
     * ,-------------------.
     * |RGBT|    |    |    |
     * |----|----|----|----|
     * |RGBM|RGBP|BTOG|    |
     * |----|----|----|----|
     * |HUD |HUI |BON |    |
     * |----|----|----|    |
     * |SAD |SAI |BOFF|    |
     * |----|----|----|----|
     * |VAD |VAS |BSTP|    |
     * |----|----|----|    |
     * |         |RST |    |
     * `-------------------'
    */
    [1] = LAYOUT_numpad_6x4(
        RGB_TOG, _______, _______, _______,
        RGB_MOD, RGB_M_P, BL_TOGG, _______,
        RGB_HUD, RGB_HUI, BL_ON,
        RGB_SAD, RGB_SAI, BL_OFF,  _______,
        RGB_VAD, RGB_VAI, BL_STEP,
        _______,          QK_BOOT,   _______
    ),

    [2] = LAYOUT_numpad_6x4(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS
    ),
    
    [3] = LAYOUT_numpad_6x4(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS
    )
};
