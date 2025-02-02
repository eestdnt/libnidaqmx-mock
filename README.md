# libnidaqmx-mock

Mocking/Stubbing of libnidaqmx for unit testing of code using the library.

## Tools

- GCC
- GNU Make
- [Unity](https://github.com/ThrowTheSwitch/Unity)
- mingw-w64 (if compling for Windows)

## Test

```
make test
```

## Build

```
make
```

## Installation

```
su
make install
```

## Build for Windows

```
TARGET_NAME=libnidaqmx.dll CC=x86_64-w64-mingw32-gcc make
```
