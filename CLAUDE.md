# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Commands

Build all targets defined in qmk.json:
```bash
qmk userspace-compile
```

Build a specific keyboard/keymap:
```bash
qmk compile -kb <keyboard> -km <keymap>
# Example: qmk compile -kb cannonkeys/atlas -km vnz
```

Flash firmware to a keyboard:
```bash
qmk flash -kb <keyboard> -km vnz
```

**Note:** Requires QMK CLI installed and `user.qmk_home` configured to point to qmk_firmware clone.

## Architecture

This is a **QMK Userspace** repository - an external overlay that manages keyboard configurations independently from the main QMK firmware. Firmware builds happen via GitHub Actions on push, producing .uf2/.bin files in Releases.

### Directory Structure

- **`users/vnz/`** - Shared code included by all vnz keymaps
  - `vnz.h` - Custom keycode macros (Linux shortcuts, tab switching, etc.)
  - `vnz_unicode.h` - French accented character mappings (é, è, ê, à, ç, €, etc.)
  - `config.h` - Global settings (UNICODE_MODE_LINUX, FORCE_NKRO)

- **`keyboards/<vendor>/<model>/keymaps/vnz/`** - Per-keyboard keymaps
  - `keymap.c` - Layer definitions (_BASE, _LOWER, _RAISE, _ADJUST)
  - `rules.mk` - Keyboard-specific feature flags (UNICODEMAP, MOUSEKEY, etc.)
  - `config.h` - Keyboard-specific overrides (audio, split config, etc.)

- **`qmk.json`** - Defines all build targets for `qmk userspace-compile`

### Adding a Keyboard

1. Create keymap directory: `keyboards/<vendor>/<model>/keymaps/vnz/`
2. Add `keymap.c` with `#include "vnz.h"` for shared macros
3. Add entry to `qmk.json` build_targets array

### Custom Keycodes (from vnz.h)

| Keycode   | Action                          |
|-----------|----------------------------------|
| LX_COPY   | Shift+Ctrl+C (terminal copy)    |
| LX_PSTE   | Shift+Ctrl+V (terminal paste)   |
| ST_COPY   | Ctrl+C (standard copy)          |
| LX_APPS   | Alt+Esc (app switcher)          |
| LX_VDUP   | Ctrl+Alt+Up (virtual desktop)   |
| ST_TBLT   | Ctrl+PgUp (tab left)            |
| ST_TBRT   | Ctrl+PgDn (tab right)           |

## Current Build Targets

Atlas, Preonic, GK6, XD75, CU7, Type9S2, Damapad, Lulu (RP2040) - all with `vnz` keymap.
