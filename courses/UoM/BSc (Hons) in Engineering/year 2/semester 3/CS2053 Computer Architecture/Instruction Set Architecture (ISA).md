![](assets/documents/02%20-%20Instruction%20Set%20Architecture-RV%20Part%20I%20V_21In_Aug23.pdf)

Software/hardware parallelization?

ISA essentially contain 2 components. 
- What is the available memory, memory map. A way to allocate regions of memory.
- Details about available instructions

ISA extensions are additional instructions that add additional functionality and optimizations. 

Generally, we try to maximize the number of devices a program runs on by reducing the amount of instructions and extensions used. If hardware have extensions, we can use compiler flags to enable them.