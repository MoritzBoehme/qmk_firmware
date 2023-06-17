#include "MoritzBoehme.h"
#include "os_specific.h"

os_variant_t os_type;
uint32_t os_specific(uint32_t trigger_time, void *cb_arg) {
    os_type = detected_host_os();
    switch (os_type) {
        case OS_LINUX: set_single_persistent_default_layer(_PROGRAMMING); break;
        case OS_MACOS: SEND_STRING(SS_TAP(AG_LSWP)); break; // swap cmd and alt
        default: break;
    }
    return os_type ? 0 : 500;
};

