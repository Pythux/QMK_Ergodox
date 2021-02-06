#!/usr/bin/env zsh


# qmk compile -kb <keyboard> -km <keymap>
qmk compile -kb ergodox_ez -km pythux && \
\
qmk flash -kb ergodox_ez -km pythux
# qmk flash use teensy loader

# now, it's waiting to recev the RESET signal
