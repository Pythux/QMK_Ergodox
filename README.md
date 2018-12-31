#!/bin/sh

cd $HOME/ErgoDox_EZ/qmk_firmware/
# build the .C file
util/docker_build.sh ergodox_ez:pythux && \
\
echo "Press the RESET signal" && \
# load the .hex file builded from the .C one in the ergodox Ez
teensy-loader-cli -mmcu=atmega32u4 -w .build/ergodox_ez_pythux.hex

# now, it's waiting to recev the RESET signal

sleep .8s
# and now, fr keymap
setxkbmap -layout fr
