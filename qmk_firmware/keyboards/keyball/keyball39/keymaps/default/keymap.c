/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Layer 0: Default Layer
  [0] = LAYOUT_universal(
    KC_Q        , KC_W       , KC_E       , KC_R       , KC_T       ,                         KC_Y       , KC_U       , KC_I       , KC_O       , KC_P       ,
    LCTL_T(KC_A), KC_S       , KC_D       , KC_F       , KC_G       ,                         KC_H       , KC_J       , KC_K       , LT(1, KC_L), RCTL_T(KC_ENT),
    LSFT_T(KC_Z), KC_X       , KC_C       , KC_V       , KC_B       ,                         KC_N       , KC_M       , KC_COMM    , KC_DOT     , RSFT_T(KC_SLSH),
    KC_LCTL     , KC_LGUI    , KC_LALT    , LT(1, KC_BSPC), LT(2, KC_SPC), LT(3, KC_LNG2), LT(3, KC_LNG1), LT(2, KC_TAB), KC_NO     , KC_NO      , KC_NO      , KC_ESC
  ),

  [1] = LAYOUT_universal(
    KC_ESC     , KC_F7      , KC_F8      , KC_F9      , KC_F12     ,                          KC_NO      , S(KC_MINS) , S(KC_EQL)  , KC_MINS    , KC_EQL  ,
    KC_TRNS    , A(KC_F4)   , KC_F5      , KC_F6      , KC_F11     ,                          KC_BTN2    , KC_BTN1    , SCRL_MO    , C(KC_SCLN) , KC_TRNS ,
    KC_TRNS    , KC_F1      , KC_F2      , KC_F3      , KC_F10     ,                          G(S(KC_S)) , A(KC_LEFT) , A(KC_RGHT) , KC_BTN3    , KC_TRNS ,
    KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS   , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS   , KC_TRNS
  ),

  [2] = LAYOUT_universal(
    KC_TAB         , KC_7       , KC_8      , KC_9       , KC_EQL     ,                         KC_HOME    , KC_PGDN    , KC_PGUP    , KC_END     , KC_DEL     ,
    LCTL_T(KC_PAST), KC_4       , KC_5      , KC_6       , KC_PPLS    ,                         KC_LEFT    , KC_DOWN    , KC_UP      , KC_RGHT    , KC_TRNS    ,
    LSFT_T(KC_PSLS), KC_1       , KC_2      , KC_3       , KC_PMNS    ,                         KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    ,
    KC_TRNS        , KC_0       , KC_DOT    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS  , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS
  ),

  [3] = LAYOUT_universal(
    S(KC_GRV)      , S(KC_7)    , S(KC_8)    , KC_NO      , KC_NO      ,                         KC_NO      , S(KC_9)       , S(KC_0)       , S(KC_BSLS) , KC_BSLS    ,
    LCTL_T(KC_GRV) , S(KC_4)    , S(KC_5)    , S(KC_6)    , KC_NO      ,                         KC_NO      , KC_LBRC       , KC_RBRC       , S(KC_SCLN) , RCTL_T(KC_SCLN) ,
    KC_TRNS        , S(KC_1)    , S(KC_2)    , S(KC_3)    , KC_NO      ,                         KC_NO      , S(KC_LBRC)    , S(KC_RBRC)    , S(KC_QUOT)  , RSFT_T(KC_QUOT),
    KC_TRNS        , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS  , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
