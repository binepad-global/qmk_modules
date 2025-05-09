# `bp_encoder_configurable` QMK Community Module

## Description

Library module that replaces QMK's quadrature encoder driver with one that allows for configurable resolution.

## Key Codes

*{None}*

## `rules.mk`

- Sets `ENCODER_DRIVER` to `custom`

## Usage

This driver operates in two modes:

1. If `OS_DETECTION_ENABLE`<sup>1</sup> is set, then you can set:

    | `#define` | Default *(fallback)* value |
    |:--- |:--- |
    | `ENCODER_RESOLUTION_LINUX` | `ENCODER_RESOLUTION`<sup>2</sup> |
    | `ENCODER_RESOLUTION_WINDOWS` | `ENCODER_RESOLUTION` |
    | `ENCODER_RESOLUTION_MACOS` | `ENCODER_RESOLUTION` |
    | `ENCODER_RESOLUTION_IOS` | `ENCODER_RESOLUTION_MACOS` |

    > <sup>1</sup>: One of these must be set for mode 1 to work. If all are omited then falls back to mode 2.  
    > <sup>2</sup>: If `ENCODER_RESOLUTION` is not set then is set to `4`

2. Otherwise, exposes an API that can be used to set the encoder resolution in user keymap code:

    | Function name | Description |
    |:--- |:--- |
    | `uint8_t get_encoder_resolution(void);` | Get the encoder resolution |
    | `void set_encoder_resolution(uint8_t resolution);` | Set the encoder resolution |

    > <sup>3</sup>: Default value of `encoder_resolution` is set to `4`.
