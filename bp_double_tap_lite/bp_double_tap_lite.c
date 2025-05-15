// Copyright 2025 Silvino R. (@silvinor)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "bp_double_tap_lite.h"
#include "action.h"
// #ifdef CONSOLE_ENABLE
// #    include "print.h"
// #endif

#ifndef DOUBLE_TAP_TERM
#    ifdef TAPPING_TERM
#        define DOUBLE_TAP_TERM TAPPING_TERM
#    else
#        define DOUBLE_TAP_TERM 250
#    endif
#endif

#ifndef DOUBLE_TAP_KEY_COUNT
#    error "!! Please define DOUBLE_TAP_KEY_COUNT in config.h"
#elif DOUBLE_TAP_KEY_COUNT > 0

/**
 * Automatically called from community module
 */
void keyboard_post_init_bp_double_tap_lite(void) {
    // make doubly sure the struct is zeroed. may not be needed?
    for (uint8_t i = 0; i < DOUBLE_TAP_KEY_COUNT; ++i) {
        dt_keycodes_t *current = &double_tap_keycodes[i];
        current->tap_time      = 0;
        current->active        = false;
    }
}

/**
 * Automatically called from community module
 */
void housekeeping_task_bp_double_tap_lite(void) {
    for (uint8_t i = 0; i < DOUBLE_TAP_KEY_COUNT; ++i) {
        dt_keycodes_t *current = &double_tap_keycodes[i];

        if (current->active && (timer_elapsed(current->tap_time) > DOUBLE_TAP_TERM)) {
            current->active = false;
            switch (current->mode) {
                case DT_MODE_KEYCODE: {
                    tap_code(current->kc1);
                    break;
                }
                case DT_MODE_FUNCTION: {
                    keyrecord_t fake_record = {.event = {.pressed = true}};
                    current->fn1(&fake_record);
                    break;
                }
                default:
                    break;
            }
        }
    }
}

/**
 * Automatically called from community module
 */
bool process_record_bp_double_tap_lite(uint16_t keycode, keyrecord_t *record) {
// #    ifdef CONSOLE_ENABLE
//     if (record->event.pressed) {
//         char buf[8];
//         snprintf(buf, sizeof(buf), "Keycode 0x%04X ", keycode);
//         SEND_STRING(buf);
//     }
// #    endif

    for (uint8_t i = 0; i < DOUBLE_TAP_KEY_COUNT; ++i) {
        dt_keycodes_t *current = &double_tap_keycodes[i];

        // is this the one we're interested in?
        if (keycode == current->kcc) {
            if (record->event.pressed) {
                // first press?
                if (!current->active) {
                    current->active   = true;
                    current->tap_time = timer_read();
                } else {
                    current->active = false;
                    switch (current->mode) {
                        case DT_MODE_KEYCODE: {
                            tap_code(current->kc2);
                            break;
                        }
                        case DT_MODE_FUNCTION: {
                            keyrecord_t fake_record = {.event = {.pressed = true}};
                            current->fn2(&fake_record);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
            return false; // No need to process downstream, as it was handled here.
        }
    }
    return true;
}

#else
#    warning "DOUBLE_TAP_KEY_COUNT is zero and is thus moot"
#endif
