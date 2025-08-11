# Expression Tree Project — Overview

This C++ project implements a flexible expression tree supporting numbers and arithmetic operations (addition, subtraction, multiplication) with both binary and n-ary variants. Using polymorphism and templates, expressions can be nested arbitrarily, evaluated, printed, and deep-copied safely.

Key features:

- **Expression hierarchy:** Abstract base class `Expression` with concrete subclasses `Number`, `Addition`, `Subtraction`, and `Multiplication`.
- **Binary and N-ary operations:** Uses template metaprogramming to distinguish binary vs. n-ary operation implementations.
- **Deep copy via `clone()`:** Polymorphic cloning preserving dynamic types and ownership.
- **Ownership:** Uses `std::unique_ptr` for safe memory management.
- **Construction helpers:** Variadic templates (`make_addition`, `make_subtraction`, `make_multiplication`, `make_number`) for easy expression building.
- **Testing:** Demo in `main.cpp` with various expression tests.
- **Build:** Makefile and CMake; requires C++17.

---

Project Hierarchy:
ExpressionProject/
├── include/
│ ├── Expression.hpp # Declarations of Expression classes and templates
│ └── Expression.tpp # Implementation of templated Expression classes
├── src/
│ ├── Expression.cpp # Implementation of non-templated Expression classes
│ └── main.cpp # Demo and tests for expression evaluation and printing
├── build/ # Build output directory (gitignored)
├── CMakeLists.txt # CMake build configuration
├── Makefile # Makefile for build convenience
└── README.md # This project overview and instructions
---

### Build & Run Instructions

To build and run the project:

```bash
make
./build/express
