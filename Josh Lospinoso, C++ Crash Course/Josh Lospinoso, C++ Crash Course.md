# C++ Crash Course by Josh Lospinoso
## Foreword
* Reptation of being complicated
* Lacks high-quality learning material
* ISO std
* After the use Standard Template library (STL), it was realized, many advanced constructs can be done by doing computation while compiling, write generic codes, and handle abritrarily complex deductions
* C++ committee approved this book
## Introduction
* C++ can produce smaller, more efficient and readable code with the ideal of zero-overhead abstraction mechanism
* Direct mapping to hardware and low-level controls, making it very powerful and flexible language 
* STL provides unrivaled type safety, correctness and efficiency

## An overtune to C Programmers
> (skipped)

---
## Part 1: The C++ core language
> ## 1. Up and running
* New patterns, usage and features for everyone every time
* Main problem : nuances of features are meshed together, hence entry is difficult
```
Source code: human readable code, .cpp file, which is then complied and run 
```
``` cpp
// sample.cpp program
#include <cstudio> // library used to allow usage of printf

int main() // function, entry point for  execution
{ // blocks that takes input , executes instructions and  returns
    printf("Something");
    return 0; // exit code to determines result of the running, 0 means all went well, others indicate problems
}
```
> ### Complier tool chain
* Turns source code into executable file
* Has three elements that run one by one
    1. *Preprocessor* : includes the header files, takes care of directives  (#includes), and produces a single translation unit
    1. *Complier* : generates object file, which has intermediate code consisting of instructions and data
    1. *Linker* : combined all libraries and source code
* *Debugger* : find error in code line by line
* *IDE* :  Interactive development environment is combination of text editor, tool chain, and debugger
* C++ doesn have interpreter
     > (skipping IDE installation as per OS)

> ### Type system
* Objects are abstraction with state and behaviour
* Collection of behaviour and state description is called type of the object
* C++ is strongly typed, means, all objects have pre-defined daattypes
    > (skipping conditionals, functions, printf)
* printf is used, since cout leads to topics like : 
    * stream buffer
    * << operator
    * method
    * flush()
    * setf
    * format flag
* printf can cause mismatch in types between arguments and format strings (%d etc)
* Cout is better
* Comments are ingnored by the complier
* Good tests, descriptive variable names and short functions can reduce the use of comments
    > (skipping debugging)

> ## 2. Types
* Fundamental, primitive or in built types are core part of the language and are always available
* Their features, size, memory layput depends on implementation
* They map relation between constructs ti lower level and provide cross-platform simplified code
* Size depends on the OS
* Int : whole number, both signed (default) and unsigned
    * short
    * int
    * long int
    * long long int
* Float : fractions, approximate valueof decimals
    * Float : for scientific calculations
    * Double : general usage
    * Long double
* Char type
    * narrow 
        * char
        * signed char
        * unsigned char
    * wide
        * char16_t
        * char32_t
        * wchar_t
* std::byte < cstddef>
    * type used to working on raw bytes, bitwise operations
* std::size_t < cstddef> : can store the maximum size of a theoretically possible object of any type
```cpp
// example of a size_t, where is it substituted with int
for(std::size_t i =0; i<10; i++)
    printf("Something");
```
* sizeof : returns the size of a operand and returns a size_t type output
* void : empty set of values, can be used as method type where it doesn return anything
* array : sequence of similar type variables, starting with 0
```cpp
int arr[] = {1,2,3,4,5}; // size is inferred during compile time
printf(arr[2]);
```
* range based for loop
``` cpp
for (a: arr)
    printf(a);
```
* size of array used to be found by dividing sizeof(variable)/sizeof(type)
* std::size can be used instead from < iterator>
    > skipping string
> ### User defined types
* Enumeration : for modelling categorical type (???)
    * Scoped (:: is used to call its variable) and unscoped enum
* Union : size of the maximum variable and dangerous to use due to data corruption
* Classes : has variables (like POD plain old data/struct)
    * Must have variables declared as per decreasing order of size
    * Private used for encapsulation (access control)
    * struct and classes are the same except for the private nature in class
    * some variables are to be initialized and have some restrictions, class invariants, which can be declared via a constructor
    * Constructor has the same name as class and can be multiple if parameters as different in type and number
    * same like class name with "~" in the begining and no arguments
* Initialization has various methods, due to evolution from C.
* Almost always use {} (uniform intializer) for variables and [] for array like structures
* () can cause problems as they lead to __most vexing parser__
    * where this can mean initializing but is taken as a function
    * also, this produces no warning while narrow conversion
    ``` cpp
    float a,b;
    a = 10;
    b = a-3;
    int result (a/b); // while converting to int, it truncates and doesn give warning
    int result2{a/b}; // atleast produces warning
    ```
> ## 3. Reference types 
