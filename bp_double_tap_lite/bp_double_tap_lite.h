// Copyright 2025 Silvino R. (@silvinor)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "quantum.h"
#include "keycodes.h"

// clang-format off

typedef enum {
    DT_MODE_UNSET,   // 0
    DT_MODE_KEYCODE, // 1
    DT_MODE_FUNCTION // 2
} dt_mode_t;

typedef bool (*dt_func_t)(keyrecord_t *record);

typedef struct {
    uint16_t kcc;
    dt_mode_t mode;
    uint8_t tap_count;
    timer_t tap_time;
    union {
        uint8_t flags;
        struct {
            bool active : 1;
        };
    };
    union {
        struct {
            uint16_t kc1;
            uint16_t kc2;
        };
        struct {
            dt_func_t fn1;
            dt_func_t fn2;
        };
    };
} dt_keycodes_t;

// clang-format on

extern dt_keycodes_t double_tap_keycodes[];

#if defined(DOUBLE_TAP_KEY_COUNT) && (DOUBLE_TAP_KEY_COUNT > 0)

void keyboard_post_init_bp_double_tap_lite(void);
void housekeeping_task_bp_double_tap_lite(void);
bool process_record_bp_double_tap_lite(uint16_t keycode, keyrecord_t *record);

#endif
