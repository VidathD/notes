# Stack

> Vidath Dissanayake | Sri Lanka  
> Links: [Data Structures](Data%20Structures.md)
> Sources: 

---

A **stack** is a linear data structure that operates on the **Last In, First Out (LIFO)** principle, where elements are inserted and removed from a single end known as the **top**. It plays a crucial role in areas such as function call management, expression evaluation, and backtracking algorithms.

In a stack, an ordered collection of elements are inserted and removed, only from the top. A stack grows and shrinks when elements are pushed (added) and popped (removed). 
## Stack Operations

There are three key operations in a stack.
1. `push` (insert an element to top)
2. `pop` (removes an element from the top)
3. `peek` (views the top element without removing it)

Additionally, we can use,
- `isEmpty` to check if the stack has no elements
- `isFull` to check if the stack is full in an array based implementation where size if finite.

`pop` and `peek` returns the value at the top of the stack.

```python
push(i) # Adds the element i to the top of the stack.

i = pop() # Removes the top element and returns it.

i = peek() # Returns the top element without removing it.
# This is equivalent to,
i = pop()
push(i)
```

Removing elements from an empty stack can result in underflow errors. Therefore, we should check with `isEmpty` before running `pop` and `peek`.

## Stack Implementations

### Array Based

A stack can be implemented using an array where elements are stored sequentially. An index is used to keep track of the top of the stack. `push` and `pop` operations update this index. Additional operations are used to check whether the stack if full or empty.

Here is a Python implementation.
```python
class Stack:
    def __init__(self):
        """Implements a stack using a list."""
        self.data = []
    
    def isEmpty(self)
        """Checks if the stack is empty."""
        return len(self.data) == 0:
    
    def push(self, node):
        """Adds a new element to the top of the stack."""
        self.data.append(node)
        
    def pop(self)
        """Removes and returns the top element from the stack."""
        if self.isEmpty():
            return "Stack is empty"
        else:
            self.data.pop()
    
    def peek(self)
        """Returns the top element without removing it."""
        if self.isEmpty():
            return "Stack is empty"
        else:
            return self.data[-1]
```

### Linked List Based

- A new node is created and added to the top of the stack during `push` operations.
- The top pointer is updated to the next during a `pop` operation.
- A counter is used to keep track of the size of the stack.
- Underflow (popping from an empty stack is handled using exception handling).

Here is a Python implementation
```python
class Node:
    """Represents a single node in the linked list."""
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    """Implements a stack using a singly linked list."""
    def __init__(self):
        self.top = None  # Head of the linked list
        self.size = 0

    def isEmpty(self):
        """Checks if the stack is empty."""
        return self.size == 0

    def push(self, value):
        """Adds a new element to the top of the stack."""
        new_node = Node(value)
        if self.top is not None:
            new_node.next = self.top
        self.top = new_node
        self.size += 1

    def pop(self):
        """Removes and returns the top element from the stack."""
        if self.is_empty():
            return "Stack is empty"
        popped_node = self.top
        self.top = self.top.next
        self.size -= 1
        return popped_node.data

    def peek(self):
        """Returns the top element without removing it."""
        if self.is_empty():
            return "Stack is empty"
        return self.top.data
```

## Programming Problems

- [Balanced Brakcets](https://www.hackerrank.com/challenges/balanced-brackets/problem)