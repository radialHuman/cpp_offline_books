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
(skipped)

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
* 
