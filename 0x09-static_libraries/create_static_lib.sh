#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -c *.o
ar -rc liball.a
ranlib liball.a
