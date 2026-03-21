> Vidath Dissanayake  
> Links: [CS1040 Program Construction](CS1040%20Program%20Construction.md)  
> Sources:  

![Lecture 2](assets/documents/CS1040-L02.pdf)

---

# Memory Management

Memory management is controlled by the operating system and the programming language used. Languages provide mechanisms for memory management via their libraries and run-time execution environments.

- Run time environment requests a large block of memory at the start of the program execution. 
- It then provides an allocation engine that handles memory allocation within that block. 
- It also provides garbage collection functionality.
- JIT optimizations (Escape Analysis and stack optimizations for objects on heap).

Key activities of memory management are:
- Memory allocation 
- Memory deallocation
- Garbage collection (Releasing memory if not manually done)
- Use of pointers for memory access
- Ensuring memory safety (Not allowing two programs to access same memory unless they are sharing)

**Note:** The OS allocates a block of memory for the program when requested at the start of the execution. After that, it is up to the language and run-time environment to use it according to the needs of the program.


## Memory Allocation Techniques

Memory can be allocated statically, at compile time (look at program and allocate memory) or dynamically, at runtime (program asks for memory).