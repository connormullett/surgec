
# SurgeC - a C compiler from scratch written in C++

Support x86_64 and only x86_64

This is not a good compiler. I wanted to experiment
with compiler theory and implement one from scratch.
This compiler has barely any features which can be
_deciphered_ from the enum `LexemTypes` in `headers/types.hpp`

## Requirements 
 - *nix environment (installs to `/usr/bin`)
 - CMake
 - root priviliges for installation

## Installation
 - Clone repository
 - cd into repository
 - `cmake .`
 - `sudo make install`
 - `surge {C source file}`

## Progress

 - [X] Lexical Analysis
 - [ ] Syntax Analysis
 - [ ] Semantic Analysis
 - [ ] Code Generation