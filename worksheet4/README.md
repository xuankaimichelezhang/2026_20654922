# Worksheet 4 — CMake

This worksheet contains two CMake projects demonstrating how to build C++ programs with CMake.

## Folder Structure

```
worksheet4/
├── hello_cmake/          # Project 1: Hello World
│   ├── CMakeLists.txt
│   └── hello.cpp
│
└── Calc/                 # Project 2: Calculator with Maths Library
    ├── CMakeLists.txt
    ├── calc.cpp
    ├── adder.cpp
    └── adder.h
```

## Project 1 — Hello World (`hello_cmake/`)

A simple "Hello World" program built with CMake.

### Build & Run

```bash
cd hello_cmake
mkdir build && cd build
cmake ..
cmake --build .
./Debug/hello        # Windows: .\Debug\hello.exe
```

## Project 2 — Calculator (`Calc/`)

A calculator program that uses a maths library (`adder`) to add two numbers. Supports both **static** and **dynamic** library builds.

### Build Static Library

```bash
cd Calc
mkdir build && cd build
cmake .. -DBUILD_SHARED_LIBS=OFF
cmake --build .
./Debug/calc 3 5      # Output: 8
```

### Build Dynamic Library

```bash
cd Calc
mkdir build && cd build
cmake .. -DBUILD_SHARED_LIBS=ON
cmake --build .
./Debug/calc 3 5      # Output: 8
```
