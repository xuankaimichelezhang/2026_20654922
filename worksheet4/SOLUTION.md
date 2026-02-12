# Worksheet 4 Solution

Student: Xuankai Zhang (20654922)

This document outlines the solutions for the three main tasks in Worksheet 4, covering the use of CMake for project management, static libraries, and dynamic libraries.

## Task 1: Basic CMake Project (Hello World)
**Objective:** Create a simple executable using CMake.

### Implementation
*   **Source File:** `hello.cpp` (Standard "Hello World" code)
*   **CMake Configuration:**
    The `CMakeLists.txt` defines an executable target:
    ```cmake
    add_executable(hello hello.cpp)
    ```
    This instructs CMake to compile `hello.cpp` and link it into an executable named `hello.exe` (on Windows).

---

## Task 2: Static Library
**Objective:** Create a maths library that is statically linked to a calculator application.

### Implementation
1.  **Defining the Library (`maths/CMakeLists.txt`):**
    We use the `STATIC` keyword to create a static archive (`.lib`).
    ```cmake
    add_library(maths_static STATIC adder.cpp adder.h)
    ```
    This creates `maths_static.lib`. The code from this library is copied directly into the final executable.

2.  **Linking (`CMakeLists.txt`):**
    ```cmake
    add_executable(calc_static calc.cpp)
    target_link_libraries(calc_static PUBLIC maths_static)
    ```

3.  **Result:** `calc_static.exe` is a standalone executable that contains the `add` function logic inside it.

---

## Task 3: Dynamic (Shared) Library
**Objective:** Create a maths library that is dynamically linked (DLL) and loaded at runtime.

### Implementation
1.  **Defining the Library:**
    We use the `SHARED` keyword.
    ```cmake
    add_library(maths_shared SHARED adder.cpp adder.h)
    target_compile_definitions(maths_shared PRIVATE maths_EXPORTS)
    ```

2.  **Handling Windows Exports (`adder.h`):**
    Windows requires explicit export/import of symbols. We use preprocessor macros to handle this:
    *   When building the library (`maths_EXPORTS` is defined), `MATHSLIB_API` becomes `__declspec(dllexport)`.
    *   When using the library (compiler sees header), `MATHSLIB_API` becomes `__declspec(dllimport)`.

3.  **Linking:**
    ```cmake
    add_executable(calc_dynamic calc.cpp)
    target_link_libraries(calc_dynamic PUBLIC maths_shared)
    ```

4.  **Result:** `calc_dynamic.exe` relies on `maths_shared.dll`. The DLL must be in the same folder (or in the system PATH) for the program to run.

---

## Deployment (Bonus / Final Requirements)
The `install` commands in CMake were used to automatically organize the output into a standard release structure:
*   `bin/`: Contains executables (`.exe`) and dynamic libraries (`.dll`).
*   `lib/`: Contains static archives (`.lib`) and import libraries.
*   `include/`: Contains public headers (`.h`).
