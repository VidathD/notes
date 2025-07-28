# Lecture 1

> Vidath Dissanayake | Sri Lanka  
> Tags: 
> Links: [CS1033 Programming Fundamentals](CS1033%20Programming%20Fundamentals.md)
> Sources:

---

## Program

A program is,
- an ordered sequence of instructions that hardware can execute.
- performs a computation task step-by-step.

A computer program is expressed using a programming language.

{{Complete}}


## Algorithm

An algorithm is a sequence of a finite number of well-defined steps for solving a problem.

### Developing an algorithm

Algorithm should be a precise, clear and finite sequence of steps to solve the problem. 

A problem could have more than one algorithm.

**Developing an algorithm is the most important part of creating a program and can be the most challenging part, specially for complex problems.**

### Expressing Algorithms

#### Pseudocode

Pseudocode is a structured form of English.
{{Complete}}
#### Flow Charts

{{Add table}}

## Program Development

There are several steps in developing a program.
1. Define the problem.
2. Outline the solution.
3. Develop an algorithm to solve the problem.
4. Test the algorithm for correctness.
5. Convert the [algorithm](#Algorithm) into a program using a suitable language.
6. Ensure the program has no syntax errors.
7. Compile if necessary.
8. Execute the program.
9. Test the debug.
10. Repeat if necessary.

## Program Translation

### Compilation

- Compilation: source code program → machine code (object code) program
- Linking: object code with other object code → 
{{Complete}}

### Interpretation

For each source code statement, 
- First, translate into machine code
- Next, execute the machine code

**In interpretation, translation is done for every execution.**
- Machine code of the full source code is neither produced, nor saved.
- Therefore, execution is generally slower than complied code.

Interpreted languages:
- BASIC
- Perl
- Python
- Ruby


## Errors in Programs

### Syntax Errors

Syntax errors occur due to violation of syntax (grammar) rules of the source language.
- Compiler/Interpreter will complain. Fix by editing source code.
- A program with syntax errors **cannot be executed.**

Syntactically correct program may still have bugs (other errors and faults).
- Unexpected terminations due to **exceptions** or **runtime errors.**
- Giving wrong output {{Complete}}