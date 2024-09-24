# How to build

1. cd to the `src` folder. This folder should include .c files, .h files, and a CMakeLists.txt. 

		src % ls
		CMakeLists.txt  main.c     term.c     term.h     tictactoe.c     tictactoe.h     typedefs.h
    

2. Type a command to your compiler.

**Apple Clang** (This is the compiler I use)  
`src % gcc -o tictactoe main.c tictactoe.c term.c -O2`  

**GCC** (I also have this)  

`src $ gcc -o tictactoe main.c tictactoe.c term.c -O2`  

**"I'm on a mac with Apple Clang installed, and I REALLY want to use GCC."**  

`src % gfortran -o tictactoe main.c tictactoe.c term.c -O2` 

**Clang**  (I have zero idea if this works, feel free to make a pull request with the proper command.)

`src $ clang main.c tictactoe.c term.c -o tictactoe -O2`

**MSVC**  

Something about visual studio...


# Misc

I originally planned on having the build instructions be in regards to CMake, but due to this repo only having  three implementation files (main.c, tictactoe.c, term.c), it was overkill.  

I have decided to commit CMakeLists.txt and CMakePresets.json as files that helped me build for debugging/release.

