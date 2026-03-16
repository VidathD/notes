> Vidath Dissanayake  
> Links: [CS1040 Program Construction](CS1040%20Program%20Construction.md)  
> Sources: [7 Missing Basics of Engineering](https://www.youtube.com/watch?v=Rp9PfqUQ8a4) [Multics GFG](https://www.geeksforgeeks.org/operating-systems/what-is-multics/), [Multics Wikipedia](https://en.wikipedia.org/wiki/Multics) [PL/I](https://en.wikipedia.org/wiki/PL/I "PL/I") [Unix GFG](https://www.geeksforgeeks.org/linux-unix/introduction-to-unix-system/), [Unix Wikipedia](https://en.wikipedia.org/wiki/Unix), [Response time limits](https://www.nngroup.com/articles/response-times-3-important-limits/)

![Lecture 1](assets/documents/CS1040-L01.pdf)

---

# Random Info

## 7 Missing Basics of Engineering

[According to David E. Goldberg](https://www.youtube.com/watch?v=Rp9PfqUQ8a4), the following are the missing basics of engineering.
1. Asking questions (Socrates 101)
2. Labelling patterns in data (Aristotle 101)
3. Modelling conceptually (Hume 101)
4. Decomposing (Descartes 101)
5. Experimenting (Locke 101)
6. Visualizing/ideating (Da Vinci 101)
7. Communicating (Newman 101)

**Note: 101 is the introductory course to a subject in USA universities.**


## Historical OSes

- Multics ([GFG](https://www.geeksforgeeks.org/operating-systems/what-is-multics/), [Wikipedia](https://en.wikipedia.org/wiki/Multics)) — One of the first OSes written partly with a high-level language (Multics [PL/I](https://en.wikipedia.org/wiki/PL/I "PL/I")). Had many innovative ideas.
- Unix ([GFG](https://www.geeksforgeeks.org/linux-unix/introduction-to-unix-system/), [Wikipedia](https://en.wikipedia.org/wiki/Unix)) — Multi-user, multitasking, portable OS. Linux, macOS took heavy inspiration from it.

---

# Program Construction

**Program construction (PC)** is a methodological process to start from a user’s requirements and end with a working program as the final product.

This is different from **programming** which is coding an algorithm to a program using a programming language.

There are two levels to PC methodology.
1. [System level](#System%20Level%20PC%20Methodology)
2. [Software level](#Software%20Level%20PC%20Methodology)

## System Level PC Methodology

Covers the overall system including hardware, software, users, operating environment, rules and regulations, etc.

This has four steps.
1. System requirements analysis (What is needed and why)
    - Finding, understanding, and analysing what a system must do.
2. System requirements specification (What exactly must be built)
    - A formal, written, document that precisely describes all functional and non-functional requirements.
3. System architecture design (How will the system be structured)
    - Define the high-level structure of the system. No programming is done.
4. System validation (Are we building the right system)
    - Checking whether the final system meets the user's needs and requirements.

## Software Level PC Methodology

This is more software focussed.
1. Software requirements analysis
2. Software requirements specification
3. Software architecture design
4. Software component/module design
5. Program coding and testing
6. Software deployment and maintenance
7. Software verification

---

# Requirements

Requirements is the foundation of program constructions. We must strive to fulfil as many requirements as possible to the best of our ability.

The more accurately the requirements are obtained, recorded, and used, the more satisfying the product is for the user.

There are two main types of requirements.
1. [Functional requirements](#Functional%20Requirements)
2. [Non-functional requirements](#Non-Functional%20Requirements)

## Functional Requirements

A functional requirement is a piece of required functionality or a behaviour that
a system will exhibit under specific conditions.

In other words, functional requirements describe what the system is supposed to do and how it should respond to events. 

Functional requirements can be defined based on functionality and behaviour.
- A functional requirement in this sense describes what the system must do. These requirements are rigid.
- A behavioural requirement describes how the system should respond to certain events or stimuli. These can be flexible. 

## Non-Functional Requirements

Non-functional requirements are generally based on soft criteria that are subjective and can be ambiguous (unclear) 
and conflicting.

The software architecture is selected to accommodate the non-functional requirements as well. When doing a project, we will have to give priority to some non-functional requirements over others.

See following slides for a list of non-functional requirements. [CS1040-L01, page 11](courses/UoM/BSc%20(Hons)%20in%20Engineering/year%201/semester%202/CS1040%20Program%20Construction/assets/documents/CS1040-L01.pdf#page=11), [CS1040-L01, page 12](courses/UoM/BSc%20(Hons)%20in%20Engineering/year%201/semester%202/CS1040%20Program%20Construction/assets/documents/CS1040-L01.pdf#page=12), [CS1040-L01, page 13](courses/UoM/BSc%20(Hons)%20in%20Engineering/year%201/semester%202/CS1040%20Program%20Construction/assets/documents/CS1040-L01.pdf#page=13), [CS1040-L01, page 14](courses/UoM/BSc%20(Hons)%20in%20Engineering/year%201/semester%202/CS1040%20Program%20Construction/assets/documents/CS1040-L01.pdf#page=14) + profitability (Non-engineering but non-functional requirement).

### Some Important Non-Functional Requirements

#### Performance

Critical for both interactive and non-interactive systems.
- In interactive, the time to respond to a user action.
- In non-interactive, the time taken to complete a task.

Performance is dependent on external factors that is out of control of engineers. Therefore, it should be defined with the context of execution environment.
- Hardware resources (CPU, RAM, GPU, storage, accelerators, etc…)
- System resources (OS type, libraries, system parameters, etc…)
- Run-time environment (no. of active users, background tasks, etc…)

There are [three metrics](https://www.nngroup.com/articles/response-times-3-important-limits/) that define performance and usability of a system.
1. **0.1 second** — the limit after which the system reaction does not seem instantaneous
2. **1 second** — when user will notice the delay, but without interrupted flow of thought
3. **10 seconds** — when user attention is completely lost

#### Security

We have to protect data and services from unauthorized access and malware attacks. 

In PC, most of the security is mapped to some functional requirement. 
- Identification and authentication is mapped to a login process.
- Authorized access is mapped to an access control.
- Confidentiality is mapped to an encryption process.

|               | Functional Requirements    | Non-Functional Requirements      |
| ------------- | -------------------------- | -------------------------------- |
| **Objective**     | Describe what product does | Describe how product works       |
| **End Result**    | Define product features    | Define product properties        |
| **Focus**         | User requirements          | User expectations                |
| **Documentation** | Captured in use cases      | Captured as quality attributes   |
| **Origin**        | Defined mostly by user     | Defined by developers/experts    |
| **Testing**       | Component, Module, API, UI | Performance, Usability, Security |
