# C++

General purpose, pre compiled, case-sensitive language. 

**Install Code Runner, C/C++ extensions on VS Code**


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
The `int` before `main()` indicated that the function will return an integer. Then the function is within the `{}`. `Hello World` is being sent to `cout` which will print it. Then `0` is returned indicating that the program executed successfully.