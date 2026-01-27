# C++ Fundamentals by LSEG Technologies

> Vidath Dissanayake | Sri Lanka  
> Links: [UoM](../UoM.md)
> Sources:  

---

## Compilation

There are 4 steps in compiling C++ code.
1. Pre-processing
2. Compilation
3. Assembly
4. Linking

### Pre-processing

- Handles directives beginning with `#`.
- Expands headers (`#include <iostream>`)
- Applied macros (`#define`)
- Removes comments

`g++ -E file.cpp -o file.i`

### Compilation

- Converts pre-processed code into assembly
- Performs syntax analysis
- Performs optimizations
- Translates high level C++ into low level CPU instructions

`g++ -S file.i -o file.s`
`g++ -S file.cpp -o file.s`

### Assembly

- Converts assembly code into machine code

### Linking