# Binepad's QMK Community Modules

> :bangbang: **NB:** These work on QMK Firmware 0.28.0 or later, merged in 2025q1.

Please follow the instructions at https://docs.qmk.fm/features/community_modules on how to use this.

i.e., set up should be something to the effect of:

```sh
cd /path/to/your/userspace
git submodule add https://github.com/binepad-global/qmk_modules.git modules/binepad
git submodule update --init --recursive
```

To update to the latest commit (of all submodules), use:

```sh
git submodule update --remote --merge
```

Each module is in it's own child folder, and has a README.md file with instructions on how to use it.

| Module | Description |
| --:|:-- |
| [`bp_encoder_configurable`](bp_encoder_configurable/README.md) | Override QMK's quadrature encoder driver with one that allows for configurable resolution|
| [`bp_double_tap_lite`](bp_double_tap_lite/README.md) | Useful for double-tap keys when you can't use tap dance *(i.e., in Vial keymaps)* |

