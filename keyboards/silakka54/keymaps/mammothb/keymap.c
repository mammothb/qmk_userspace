// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    L_BASE,
    L_NAV,
    L_FUN,
};

// Aliases
#define HRM_S LALT_T(KC_S)
#define HRM_D LCTL_T(KC_D)
#define HRM_F LSFT_T(KC_F)

#define HRM_J RSFT_T(KC_J)
#define HRM_K RCTL_T(KC_K)
#define HRM_L RALT_T(KC_L)

#define NAV_BS LT(L_NAV, KC_BSPC)
#define FUN_SPC LT(L_FUN, KC_SPC)

const char PROGMEM chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] =
     LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
                       'L', 'L', 'L', 'R', 'R', 'R'
    );


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
        KC_ESC , KC_A   , HRM_S  , HRM_D  , HRM_F  , KC_G   ,        KC_H   , HRM_J  , HRM_K  , HRM_L  , KC_SCLN, KC_QUOT,
        _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,        KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_EQL ,
                                   KC_LGUI, KC_LCTL, NAV_BS ,        FUN_SPC, KC_ENT , KC_RGUI
    ),
    [L_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, KC_PSCR,
        _______, _______, _______, _______, _______, _______,        KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
        _______, _______, _______, _______, _______, _______,        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______,        _______, _______, _______
    ),
    [L_FUN] = LAYOUT(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, KC_F11 , KC_F12 , _______,
        _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),        S(KC_6), S(KC_7), S(KC_8), _______, _______, _______,
        _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______,        _______, _______, _______
    )
};

///////////////////////////////////////////////////////////////////////////////
// Combos
///////////////////////////////////////////////////////////////////////////////
const uint16_t PROGMEM l_brace[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM r_brace[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM l_bracket[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM r_bracket[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM caps_word[] = {HRM_F, HRM_J, COMBO_END};

combo_t key_combos[] = {
    COMBO(l_brace, S(KC_LBRC)),  // W and E => {
    COMBO(r_brace, S(KC_RBRC)),  // E and R => }
    COMBO(l_bracket, KC_LBRC),   // U and I => [
    COMBO(r_bracket, KC_RBRC),   // I and O => ]
    COMBO(caps_word, CW_TOGG),   // F and J => Caps Word
};

///////////////////////////////////////////////////////////////////////////////
// Tap-hold configuration
///////////////////////////////////////////////////////////////////////////////
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case HRM_F:
        case HRM_J:
            return TAPPING_TERM - 45;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    // If you quickly hold a tap-hold key after tapping it, the tap action is
    // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
    // lead to missed triggers in fast typing. Here, returning 0 means we
    // instead want to "force hold" and disable key repeating.
    switch (keycode) {
        case HRM_J:
        case HRM_K:
        case HRM_L:
            return QUICK_TAP_TERM;  // Enable key repeating
        default:
            return 0;  // Otherwise, force hold and disable key repeating.
    }
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, uint16_t prev_keycode) {
    // Only apply Flow Tap when following a letter key.
    if (get_tap_keycode(prev_keycode) <= KC_Z) {
        switch (keycode) {
            case HRM_S:
            case HRM_L:
            case HRM_D:
            case HRM_K:
                return FLOW_TAP_TERM;
        }
    }
    return 0;
}
