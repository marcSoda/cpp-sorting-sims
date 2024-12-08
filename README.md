# Build instructions

- populate build dir with:
  - `meson setup build --buildtype=debug --backend=ninja`
- compile with
  - `ninja -C build/ install`
- run with
  - `build/sorter <heap/merge/etc>`
