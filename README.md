# Simple gravity simulator

Just like that. Feel free to modify the solar.cpp to get different results.

Currently it is drawing massive bodies as dots in 2D space, but nothing prevents
it to be calculated in 3D. The only thing that should be modified in this case is visialization.

## Features

With math_vector / massive_body modules one can create abstract massive bodies, and select
which other massive bodies would affect it's speed.
Massive bodies are able to calculate it's acceleration after summarizing each of gravity forces,
affecting current body.
Then it is up to you to apply velocity change / position change to massive body.

## Folders

`src` contains all sources and Makefile.

`bin` contatins binary executable file.
Currently it has been built at Debian linux only.

## Dependencies

This simulator use SDL2 library and its extension SDL2_image

