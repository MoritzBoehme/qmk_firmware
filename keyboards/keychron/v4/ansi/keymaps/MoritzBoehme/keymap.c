#include QMK_KEYBOARD_H
#include "MoritzBoehme.h"

// clang-format off

enum layers {
    PROGRAMMING = _PROGRAMMING,
    NORMAL = _NORMAL,
    FN0,
    FN1
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [PROGRAMMING] = LAYOUT_ansi_61(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_J,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_M,    KC_N,    KC_E,    KC_L,     KC_SCLN, KC_QUOT,          KC_ENT,
        TD_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_H,    KC_COMM, KC_DOT,   KC_SLSH,                   KC_RSFT,
        KC_LALT, KC_LCTL, TD_LGUI,                            KC_SPC,                              TT(FN0), TT(FN1), KC_RCTL, KC_RALT),

    [NORMAL] = LAYOUT_ansi_61(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,                   KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                              KC_RALT, KC_RCTL, TT(FN0), TT(FN1)),

    [FN0] = LAYOUT_ansi_61(
        KC_GRV,  RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT,  KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,                   _______,
        _______, _______, _______,                            _______,                             _______, _______, _______, _______),

    [FN1] = LAYOUT_ansi_61(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,                   TD_BOOT,
        _______, _______, _______,                            _______,                             _______, _______, _______, _______)
};
