// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#define __ KC_NO

enum layers { _QWERTY, _NAV, _NUM };
#define AR_L KC_LEFT
#define AR_D KC_DOWN
#define AR_U KC_UP
#define AR_R KC_RIGHT

enum custom_keycodes {
    ARROW_MACRO = SAFE_RANGE, // Custom keycode for "->"
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ARROW_MACRO:
            if (record->event.pressed) {
                SEND_STRING("->"); // Send the string "->"
            }
            return false;
    }
    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
    KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5,                                       KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                                        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                __, ARROW_MACRO,                                                            KC_LBRC, KC_RBRC,
                            KC_SPC, KC_LCTL,                                KC_BSPC, KC_ENTER,
                                KC_ESC, MO(_NUM),                         MO(_NAV), KC_LALT,
                                KC_LSFT, KC_LGUI,                           KC_RGUI, KC_RSFT),
    [_NAV] = LAYOUT(
    __, __, __, __, __, __,                                                   __, __, KC_END, KC_HOME, __, __,
    __, __, __, __, __, __,                                                   C(AR_L), KC_PGDN, KC_PGUP, C(AR_R), __, __,
    __, __, __, __, __, __,                                                   AR_L, AR_D, AR_U, AR_R, __, __,
    __, __, __, __, __, __,                                                   LGUI(AR_L), LGUI(AR_D), LGUI(AR_U), LGUI(AR_R), __, __,
                __, __,                                                               __, __,
                                __, __,                                   __, __,
                                __, __,                                   __, __,
                                QK_CLEAR_EEPROM, QK_BOOT,                 QK_BOOT, QK_CLEAR_EEPROM) ,
    
    [_NUM] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                 KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
    S(KC_TILD), S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                  S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_MINS),
    KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5,                                    KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
    __, __, __, __, __, __,                                                   __, __, __, __, __, __,
    KC_BRMD, KC_BRMU,                                                                      KC_VOLD, KC_VOLU,
                            KC_SPC, KC_LCTL,                                KC_BSPC, KC_ENTER,
                                KC_ESC, __,                                 __, KC_LALT,
                                KC_LSFT, KC_CAPS,                           __, KC_RSFT)
};
