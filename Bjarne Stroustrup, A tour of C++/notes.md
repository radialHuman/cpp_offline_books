# A tour of C++ by Bjarne Stroustrup

> ## Chapter 1 - The Basic

* _The source file of the program has to be complied to produce an **object file**, which is then combined with __linker__ producing the __executable file__._

* _The executable program is created for specific harware/system combination and is not portable, the only poratble part is the source code_

> Types of entities
1. Core language feature
1. Standard library components

* _Its statically typed and the complier should know the type of the entities before using it_

> Display something
```cpp
#include <iostream>

int main()
{
    std::cout << "Something\n";
}
```

* \# include is to bring in the code from other file and replace it where its called, like importing libraries
* << ("put to") operator is used to write the arugument
* std::is namespace to declare that the next following function belongs to the std library

> Functions
* Piece of code that does an operation
* Used to make the code readable and easy to debug
* *Function overloading* : If more than one fucntions are with the same name and vary in the numbe/type of parameters it can take

> Types and variables
* Each  of variable like int, bool, char, double, unsigned has some size in the memory allocated to it
* sizeof() is used to find the size of variable
    * & is bitwise and
    * && is logical and
    * | is bitwise or
    * || is logical or

> Initialization
``` cpp
// for single numbers
double n1 = 10.3;
double n2{10.3};

// for list of numbers
std::vector<int> l1{1,2,3,4};
```
* "=" can be used as in C.
* but "{ }" will save from conversion loss.
* _Narrowing conversion_ : Conversions that result in loss ex: double to int
* These are used in implicit conversion

> Auto
* _auto_ can be used instead of type declaration if its very edvident
* Here "=" can be used as there is no problem of type conversion
* Almost use auto everywhere
* Used in generic progamming where one might not know the type that will be used

``` cpp
auto a = 10;
auto b = 11.3;
auto c = 'C';
auto d = true;
```
> Scope and lifetime
1. Local scope : A variable inside a function or a lambda, that lives with in "{ }" or a block
1. Class scope: or a memeber name live inside the class, dies with the object
1. Namespace scope: Lives inside the namespace and gets destroyed at the end of the program
1. Gloabal scope: If none of the above
* object created by "new" dies when "delete"ed

> Constant
* There are two types of immutability
1. _const_ : promies not to change the value, used to pass variable without the fear of changing it ex: due to side effect
1. _constexpr_ : to make things evaluated only during complie time. To place data which is const in read-only memory to prevent corruption. 
    * constexpr can take in values that are const (exceptions???)

> Pointers and references
``` cpp
// an array
char v[6]; // creates an array of 6 elements of character type
// a pointer
char* p; // a pointer to a character type data
char* p  =&v[3]; // a pointer to the 4th character element of array v
```
* \* : means pointing to the contents of 
* & : means address of
* if there is nothign being pointed by the pointer then it is nullptr
(??? more explanation)

> for loops
``` cpp
// old style of for loops
int main()
{
    std::vector<int> v1{1,2,3,4,5};
    
    for (int i =0; i<sizeof(v1); i++)
    {
        std::cout << i << " ";
    }
}

// new way of for loops
int main()
{
    std::vector<int> v1{1,2,3,4,5};
    std::vector<int> v2;

    for (auto& i: v1) // & is to avoid making copy, might affect the variable
    {
        std::cout << i << " ";
    }
}
```
* switch statement

> Advice
* use fucntion for single logical operation
* keep the functio short
* use function overloading
* avoid magic constants : constants declared with numbers in claculation
* use = with auto and { } otherwise
* use nullptr than 0 or null
---
> ## User defined types























<br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> 

---
Made possible by [Video](https://www.youtube.com/watch?v=HUBNt18RFbo "Markdown crash course")

___
---
---
---
### Other things that were not used in the notes but taught in the video

~~Something gets striked~~

`<p>This is used to write in html code</p>`

![Image name here]("https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/1200px-ISO_C%2B%2B_Logo.svg.png")

```where you want to execute the code
To type in code here and
distinguish it from other text
```

```python
def func(a,b)
    return a+b
```

| ID    | Name  |
|------ |------ |
|1      |Name 1 |
|2      |Name 2 |
|3      |Name 3 |

* [ ] check list item unselected
* [x] check list item selected

