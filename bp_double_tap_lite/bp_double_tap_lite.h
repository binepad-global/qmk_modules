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

void matrix_init_double_tap_lite(void); // !! Must be manually called from matrix_init_user
void matrix_scan_double_tap_lite(void); // !! Must be manually called from matrix_scan_user
bool process_record_bp_double_tap_lite(uint16_t keycode, keyrecord_t *record); // Community Modules will handle this
