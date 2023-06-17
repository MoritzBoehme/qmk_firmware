#include "MoritzBoehme.h"

void keyboard_post_init_user(void) {
#if defined OS_DETECTION_ENABLE && DEFERRED_EXEC_ENABLE
    defer_exec(100, os_specific, NULL);
#endif
};
