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
- Garbage collection
- Use of pointers for memory access
- Ensuring memory safety