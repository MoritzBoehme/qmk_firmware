#include QMK_KEYBOARD_H
#include "MoritzBoehme.h"

// clang-format off

enum layers {
    PROGRAMMING = _PROGRAMMING,
    NORMAL = _NORMAL,
    FN0,
    GAME,
};

// Custom Keycodes
enum custom_keycodes {
	SOCD_A = SAFE_RANGE,
	SOCD_D
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define TG_GAME TG(GAME)

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [_BOOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, boot_finished, boot_reset),
    [_LSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lsft_finished, lsft_reset),
    [_LGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lgui_finished, lgui_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [PROGRAMMING] = LAYOUT_ansi_61(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,     KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,     KC_O,    KC_QUOT,          KC_ENT,
        TD_LSFT, KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    KC_K,    KC_H,    KC_COMM, KC_DOT,   KC_SLSH,                   KC_RSFT,
        KC_LALT, KC_LCTL, TD_LGUI,                            KC_SPC,                              TT(FN0), KC_LALT, KC_RCTL, KC_RALT),

    [NORMAL] = LAYOUT_ansi_61(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,                   KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                              TG_GAME, KC_RCTL, TT(FN0), KC_RALT),

    [FN0] = LAYOUT_ansi_61(
        KC_GRV,  RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT,  KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,                   TD_BOOT,
        _______, _______, _______,                            _______,                             _______, _______, _______, _______),

    [GAME] = LAYOUT_ansi_61(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,
        _______, SOCD_A,  _______, SOCD_D,  _______, _______, _______, _______, _______, _______,  _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,                   _______,
        _______, KC_NO,   _______,                            _______,                             TG_GAME, _______, _______, _______)
};

// SOCD (Last Input Wins) Boolean Logic
bool A_KEYSTATE = false;
bool D_KEYSTATE = false;
bool A_PRIORITY = false;
bool D_PRIORITY = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case SOCD_A:
			if (record->event.pressed) {
				A_KEYSTATE = true;
				if (D_KEYSTATE) {
					D_PRIORITY = false;
					A_PRIORITY = true;
					unregister_code(KC_D);
				}
				register_code(KC_A);
			} else {
				A_KEYSTATE = false;
				A_PRIORITY = false;
				unregister_code(KC_A);
				if (D_KEYSTATE && !D_PRIORITY) {
					register_code(KC_D);
				}
			}
			return false;
		case SOCD_D:
			if (record->event.pressed) {
				D_KEYSTATE = true;
				if (A_KEYSTATE) {
					A_PRIORITY = false;
					D_PRIORITY = true;
					unregister_code(KC_A);
				}
				register_code(KC_D);
			} else {
				D_KEYSTATE = false;
				D_PRIORITY = false;
				unregister_code(KC_D);
				if (A_KEYSTATE && !A_PRIORITY) {
					register_code(KC_A);
				}
			}
			return false;
		default:
			return true;
	}
};
