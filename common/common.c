// Copyright 2023 Silvino Rodrigues (@silvinor)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "common.h"

bool process_record_common(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef RGB_MATRIX_ENABLE
        case QK_CLEAR_EEPROM:
            if (record->event.pressed) {
                if (!rgb_matrix_is_enabled()) {
                    rgb_matrix_enable();
                }
                rgb_matrix_set_color_all(RGB_YELLOW);
                rgb_matrix_update_pwm_buffers();
                wait_ms(500); // 1/2 sec
            }
            return true; // let QMK do the rest
            break;

        case QK_BOOT:
            if (record->event.pressed) {
                if (!rgb_matrix_is_enabled()) {
                    rgb_matrix_enable();
                }
                rgb_matrix_set_color_all(RGB_RED);
                rgb_matrix_update_pwm_buffers();
                wait_ms(500); // 1/2 sec
            }
            return true; // let QMK do the rest
            break;
#endif
    }
    return true;
}
