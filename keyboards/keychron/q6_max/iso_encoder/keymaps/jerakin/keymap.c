/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    _JK_BASE,
    _JK_NAV,
    _JK_COLEMAK_DH,
};


#define _JK_BASE 4
#define _JK_NAV 5
#define _JK_COLEMAK_DH 6

// Define the mod-tap keys for the home row
#define HOME_A LGUI_T(KC_A)  // A acts as GUI (Cmd/Win) when held
#define HOME_S LALT_T(KC_S)  // S acts as Alt when held
#define HOME_D LCTL_T(KC_D)  // D acts as Ctrl when held
#define HOME_F LSFT_T(KC_F)  // F acts as Shift when held

#define HOME_J RSFT_T(KC_J)  // J acts as Shift when held
#define HOME_K RCTL_T(KC_K)  // K acts as Ctrl when held
#define HOME_L RALT_T(KC_L)  // L acts as Alt when held
#define HOME_SCLN RGUI_T(KC_SCLN)  // ; acts as GUI (Cmd/Win) when held

#define LAYER_NAV LT(_JK_NAV, KC_Q)  // ; acts as GUI (Cmd/Win) when held

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [MAC_BASE] = LAYOUT_iso_110(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  KC_SIRI,  RGB_MOD,  KC_F13,   KC_F14,   KC_F15,   KC_F16,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,                KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),

     [MAC_FN] = LAYOUT_iso_110(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                                  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,  
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),

     [WIN_BASE] = LAYOUT_iso_110(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_CTANA, RGB_MOD,  DF(_JK_BASE), _______,  _______,  _______,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,       KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,                KC_DEL,   KC_END,   KC_PGDN,  KC_P7,        KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,                                   KC_P4,        KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,        KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,                  KC_PDOT,  KC_PENT),

     [WIN_FN] = LAYOUT_iso_110(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,   _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                                  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,  
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),

     [_JK_BASE] = LAYOUT_iso_110(
        KC_ESC,   KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_CTANA, RGB_MOD,  DF(_JK_COLEMAK_DH), _______,  _______,  _______,
        KC_GRV,   KC_1,      KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,             KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   LAYER_NAV, KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_LBRC,  KC_RBRC,                KC_DEL,   KC_END,   KC_PGDN,  KC_P7,              KC_P8,    KC_P9,
        KC_CAPS,  HOME_A,    HOME_S,   HOME_D,   HOME_F,   KC_G,     KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN, KC_QUOT,  KC_NUHS,    KC_ENT,                                   KC_P4,              KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,  KC_NUBS,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,              KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,   KC_LALT,                                KC_SPC,                                 KC_RALT,   KC_RWIN,  MO(WIN_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
        
     [_JK_NAV] = LAYOUT_iso_110(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,  _______,    _______,                                  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,  
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),

    [_JK_COLEMAK_DH] = LAYOUT_iso_110(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_CTANA, RGB_MOD,  DF(WIN_BASE), _______,  _______,  _______,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_EQL,   KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,       KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_LBRC,  KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_SLASH,               KC_DEL,   KC_END,   KC_PGDN,  KC_P7,        KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_RBRC,  KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,    KC_ENT,                                   KC_P4,        KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,     KC_SLSH,  KC_NUHS,  KC_K,     KC_H,     KC_COMM,  KC_DOT,               KC_RSFT,              KC_UP,              KC_P1,        KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,        KC_PDOT,  KC_PENT),
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_JK_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_JK_NAV]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_JK_COLEMAK_DH]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif // ENCODER_MAP_ENABLE


/*
I want the colors as stock. Except that when my layer is pressed a single color is shown
I also want my "base" layer to have a toggle light underneath it, like capslock and numlock
*/

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)){
        case _JK_BASE:
            rgb_matrix_set_color(16, 255, 255, 255);
            break;
        case _JK_NAV:
            rgb_matrix_set_color(16, 0, 255, 0);
            break;
        case _JK_COLEMAK_DH:
            rgb_matrix_set_color(16, 24, 192, 56);
            break;
        case WIN_BASE:
            rgb_matrix_set_color(16, 0, 0, 0);
            break;
        default: // for any other layers, or the default layer
            rgb_matrix_set_color(16, 255, 0, 0);
            break;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}
