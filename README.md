# Fatlib, my own multi platforme library

### every bit of criticisme is welcome as i use this project to learn

see the bottom of the file for the copyright

### list of finished features:

- simple readline
- some math function
- some data struct
___

## question

q: how much time will it take ?
a: i don't know maybe 15 years ? maybe i won't finish it 
   i will work on it until i have no inspiration of things to do

q: why do i create a library ?
a: because i want to learn how everything work on a computer 
   and building a library is for me the first step

## note

- The CI action isn't set up, need to start working on the workflow and unitest
- i started working only on the linux part, i didn't make it compile under windows, as i need to change unistd.h and sys/*.h into windows.h an equivalent for each use (exemple with how process and forking work under windows, or write function)
- everything should be in it's seperate part of the library
- you can choose what part you wan't to use(almost like stb header)
- everything need to be minimalistic and have the least line of code
- performance need to come first
- this lib is intended for C and i don't intend to make it for other language

___

## intended features

- some data structures (should be useful for some purpose ex. Parser logic);
- memory allocator (to learn memory mapping);
- syscall and kernel utils (i intend to create a very small bootloader os for a game);
- 3d and 2d graphic utilities (maybe will try cpu render api 
  and maybe gpu render api for arm);
- Linear Algebra function (lerp, dot, transform, etc...)
- Text and string utilities
- data transformation and logic
- optimized math function and algorithm
  (Ex fast inverse square root or msd radix sort)
- networking, database and web capability (back-end and use of wasm)
- lexer, parser, tokenizer stats machine

___

# Copyleft

  This project is under The GPL v3 public License see License file.

___
