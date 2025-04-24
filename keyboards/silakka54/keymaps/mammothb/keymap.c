// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define L_DEF 0
#define L_NAV 1
#define L_FUN 2

const uint16_t PROGMEM left_brace[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM right_brace[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM left_bracket[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM right_bracket[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
    COMBO(left_brace, S(KC_LBRC)),
    COMBO(right_brace, S(KC_RBRC)),
    COMBO(left_bracket, KC_LBRC),
    COMBO(right_bracket, KC_RBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_DEF] = LAYOUT(
        KC_GRV,  KC_1, KC_2,         KC_3,         KC_4,         KC_5,                      KC_6,              KC_7,         KC_8,         KC_9,         KC_0,    KC_MINS,
        KC_TAB,  KC_Q, KC_W,         KC_E,         KC_R,         KC_T,                      KC_Y,              KC_U,         KC_I,         KC_O,         KC_P,    KC_BSLS,
        KC_ESC,  KC_A, LCTL_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,                      KC_H,              RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), KC_SCLN, KC_QUOT,
        KC_TRNS, KC_Z, KC_X,         KC_C,         KC_V,         KC_B,                      KC_N,              KC_M,         KC_COMM,      KC_DOT,       KC_SLSH, KC_EQL,
                                     KC_LGUI,      KC_LCTL,      LT(L_NAV, KC_BSPC),        LT(L_FUN, KC_SPC), KC_ENT,       KC_RGUI
    ),
    [L_NAV] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [L_FUN] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,  KC_F12,  KC_TRNS,
        KC_TRNS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),        S(KC_6), S(KC_7), S(KC_8), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
    )
};
