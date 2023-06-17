#pragma once
#include QMK_KEYBOARD_H

#if defined OS_DETECTION_ENABLE && DEFERRED_EXEC_ENABLE
#include "os_specific.h"
#endif

#if defined TAP_DANCE_ENABLE
#include "tap_dances.h"
#endif

void keyboard_post_init_user(void);

enum userspace_layers {
    _NORMAL = 0,
    _PROGRAMMING = 1,
};
