// Copyright 2025 Silvino R. (@silvinor)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <stdint.h>

#if defined(OS_DETECTION_ENABLE) && (defined(ENCODER_RESOLUTION_LINUX) || defined(ENCODER_RESOLUTION_WINDOWS) || defined(ENCODER_RESOLUTION_MACOS) || defined(ENCODER_RESOLUTION_IOS))
#    ifndef ENCODER_RESOLUTION
#        define ENCODER_RESOLUTION 4
#    endif
#    ifndef ENCODER_RESOLUTION_LINUX
#        define ENCODER_RESOLUTION_LINUX ENCODER_RESOLUTION
#    endif
#    ifndef ENCODER_RESOLUTION_WINDOWS
#        define ENCODER_RESOLUTION_WINDOWS ENCODER_RESOLUTION
#    endif
#    ifndef ENCODER_RESOLUTION_MACOS
#        define ENCODER_RESOLUTION_MACOS ENCODER_RESOLUTION
#    endif
#    ifndef ENCODER_RESOLUTION_IOS
#        define ENCODER_RESOLUTION_IOS ENCODER_RESOLUTION_MACOS
#    endif
#else

uint8_t get_encoder_resolution(void);

#endif

void set_encoder_resolution(uint8_t resolution);
