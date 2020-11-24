# Installation

## Supported Platforms:

Windows and Cygwin.

## Prerequisite

GCC Compiler, GNU make. Cygwin for windows.

## Dependent External Libraries
CJSON - https://github.com/DaveGamble/cJSON
Unity - https://github.com/ThrowTheSwitch/Unity

All external libraries are included in the software package.
## Build Project:

Running make will compile tax filing software and tests programs. The test program will test the program functions and display results.

```
make all
```

If you just want the tests program. run:

```
make tests
```

Executable binaries "tax.exe" and "tests.exe"(in windows) files will be placed in bin folder of the project. For cygwin.
```
bin/tax.exe
```
