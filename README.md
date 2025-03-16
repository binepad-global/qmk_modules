# Binepad's QMK Community Modules

> :bangbang: **NB:** These work on QMK Firmware 0.28.0 or later, merged in 2025q1.

Please follow the instructions at https://docs.qmk.fm/features/community_modules on how to use this.

i.e., set up should be something to the effect of:

```sh
cd /path/to/your/userspace
git submodule add https://github.com/binepad-global/qmk_modules.git modules/binepad
git submodule update --init --recursive
```

Each module is in it's own child folder, and has a README.md file with instructions on how to use it.

| Module | Description |
| --:|:-- |
| Caffeine | Adds a screen saver blocker / keep alive key |
| Mac Globe | Adds a simplified version of the macOS Globe key |
