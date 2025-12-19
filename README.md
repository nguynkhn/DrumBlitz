# DrumBlitz - A simple drum rhythm game using SDL and C++

## Building

A C++ compiler (with C++23 supported) and CMake must be properly installed.\
Both can be done easily on Windows using this single command:

```console
winget install BrechtSanders.WinLibs.POSIX.UCRT
```

Clone this repository with vendored libraries and build it using CMake.

```console
git clone --recurse-submodules https://github.com/nguynkhn/DrumBlitz.git
cd DrumBlitz
cmake -S . -B build
cmake --build build
```

Once the build process is finished, there should be an executable file named
`drumblitz` (with `.exe` on Windows) inside the `build` folder.
