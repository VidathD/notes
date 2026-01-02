# C++

General purpose, pre compiled, case-sensitive language. 

**Install Code Runner, C/C++ extensions on VS Code**

`//` is used for comments.

## Header Files

Header files are generally used to introduce features to the program. 
```c++
#include<iostream>
using namespace std;
```

`#include<iostream>` is used to import functions such as `cin` and `cout` used for input and output.
`using namespace std;` means we are using everything in the standard library.

## The `main()` Function

The `main()` function is a special function from where the program starts.
```c++
int main()
{
cout << "Hello, World!";
return 0;
}
```
The `int` before `main()` indicated that the function will return an integer. Then the function is within the `{}`. `Hello World` is being sent to `cout` which will print it. Then `0` is returned, indicating that the program executed successfully.


## Data Types

- Boolean
- Character
- Integer
- Float

## Variables

Variables in C++ are defined using the syntax, `DataType VariableName;`.
```c++
int data;
```

### Strings

Strings are groups of characters. It is used to represent and manipulate text in a program.

Syntax of a string is a collection of characters surrounded by double quotes (`""`).
```c++
string str = "Coffee"
```

There are two ways to create strings.
1. C type strings. — Here, the string is stored as an array of characters.
2. Create string objects. — These are included in the `std` library.

The `push_back` function appends to the string. `pop_back` function removes the character at the end of the string.
```c++
string s="Hello, World"

s.push_back('!');
cout<<s<<endl; // The output is Hello, World!

s.pop_back();
cout<<s<<endl; // The output is Hello, World
```

Note that `endl` ends the line.

We can use `getline(cin, s);` to get a string as input from the user.
```c++
cout<<"Enter a string: ";
getline(cin, s);
cout<<"You entered: " << s << endl; //This will output the string the user entered.
```

## If-Else Conditionals

The basic syntax is as follows

```cpp
if (condition) {
    // code runs if condition is true
} else {
    // code runs if condition is false
}
```

## Loops

There are four main types of loops in C++.
- For loop — Used when we know the number of times the loop needs to run beforehand.
- While loop — Used when we do not know how many times the loop needs to run.
- Do-While loo — Similar to while, but the condition is checked at the end of execution. So loop body will execute at least once.
- Nested loop — When a loop is inside the body of another loop. In C++, there are 256 levels of nesting.

### For Loop

Basic syntax:
```cpp
for (condition)
{
// body
}
```

Example:
```cpp
for (int i=0; i<=10; i++)
{
    cout<<i<<endl;
}
```

### While Loop

