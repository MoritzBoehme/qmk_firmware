#pragma once

#include "MoritzBoehme.h"

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap Dance enum
enum {
    _BOOT,
    _LSFT,
    _LGUI,
};

#define TD_BOOT TD(_BOOT)
#define TD_LSFT TD(_LSFT)
#define TD_LGUI TD(_LGUI)

td_state_t cur_dance(tap_dance_state_t *state);

void lsft_finished(tap_dance_state_t *state, void *user_data);
void lsft_reset(tap_dance_state_t *state, void *user_data);

void boot_finished(tap_dance_state_t *state, void *user_data);
void boot_reset(tap_dance_state_t *state, void *user_data);

void lgui_finished(tap_dance_state_t *state, void *user_data);
void lgui_reset(tap_dance_state_t *state, void *user_data);
