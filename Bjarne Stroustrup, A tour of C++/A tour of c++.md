# A tour of C++ by Bjarne Stroustrup

> ## Chapter 1 - The Basic

* _The source file of the program has to be complied to produce an **object file**, which is then combined with __linker__ producing the __executable file__._

* _The executable program is created for specific harware/system combination and is not portable, the only poratble part is the source code_

> ### Types of entities
1. Core language feature
1. Standard library components

* _Its statically typed and the complier should know the type of the entities before using it_

> ### Display something
```cpp
#include <iostream>

int main()
{
    std::cout << "Something\n";
}
```

* \# include is to bring in the code from other file and replace it where its called, like importing libraries
* << ("put to") operator is used to write the argument
* std::is namespace to declare that the next following function belongs to the std library

> ### Functions
* Piece of code that does an operation
* Used to make the code readable and easy to debug
* *Function overloading* (polymorphism): If more than one functions are with the same name and vary in the number/type of parameters it can take

> ### Types and variables
* Each  of variable like int, bool, char, double, unsigned has some size in the memory allocated to it
* sizeof() is used to find the size of variable
    * & is bitwise and
    * && is logical and
    * | is bitwise or
    * || is logical or

> ### Initialization
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

> ### Auto
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
> ### Scope and lifetime
1. Local scope : A variable inside a function or a lambda, that lives with in "{ }" or a block
1. Class scope: or a memeber name live inside the class, dies with the object
1. Namespace scope: Lives inside the namespace and gets destroyed at the end of the program
1. Gloabal scope: If none of the above
* object created by "new" dies when "delete"ed

> ### Constant
* There are two types of immutability
1. _const_ : promies not to change the value, used to pass variable without the fear of changing it ex: due to side effect
1. _constexpr_ : to make things evaluated only during complie time. To place data which is const in read-only memory to prevent corruption. 
    * constexpr can take in values that are const (exceptions???)

> ### Pointers and references
``` cpp
// an array
char v[6]; // creates an array of 6 elements of character type
// a pointer
char* p; // a pointer to a character type data
char* p  =&v[3]; // a pointer to the 4th character element of array v
```
* \* : means pointing to the contents of and it is a type
* & : means address of
* if there is nothign being pointed by the pointer then it is nullptr
(??? more explanation)

> ### for loops
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

> ### Advice
* use fucntion for single logical operation
* keep the functio short
* use function overloading
* avoid magic constants : constants declared with numbers in claculation
* use = with auto and { } otherwise
* use nullptr than 0 or null
---
> ## Chapter 2 - User defined types
* _In c++, the built-in types and their operations are rich but low level delibrately._
* _Types built using built-in types for high level abstraction are user defined types._
* Ex: Classes, Structs, enums ets.

> ### Structures
* It is a collection of variables, all public.
``` cpp
struct user
{
    std::string name;
    std::string address;
    int id;
    double age;
    int* friends;
}

// function that uses this type
void func(Vector& v) // passing the original structure type, which is not const so can be altered by this function
{
    std::cout << v.age <<'\n';
}

int main()
{
    user user1;
    user1.name = "Someone";
    user1.address = "Somewhere";
    user1.id = 123;
    user1.age = 22.5;
    user1.friends = 5;

    // this can further be sent as a parameter to a function
    func(user1);
}
```
* struct member name is access using "." and "->" is used for accessing it through a pointer

> ### Class
* This not only acts like struct, but helps in encapsulation and abstraction.
* It provides private mode to store not only variables but also the fucntions.
``` cpp
class user
{
    public:
    double& double_the_age(double age) {return age*2;}
    
    private:
    double age;
    int id;
    std::string name;
}
```

* In classes, the function with the same name as class is called a constructor
* Unlike, ordinary functions, constructors are guaranteed to initialize the objects of the class

> ### Union
* Union is a struct, that has all the members are allocated at the same address, ie. it occupies only as much space as the largest member.
* It can hold value for only one member at a time.
``` cpp
union user_defined_union
{
    int x;
    double y; // this is the biggest of all the members so only 8 bytes will be allocated
    char c;
    // no constructors or destructors
    // all the members will point to the 8 bytes allocated for this union
    // saves a lot of space and structural padding size too
};
```
* Use case
    * Only one member is being used at a time
    * Used for polymorphism

* _At application level, tagged unions are helpful, otherwise, its usage should be minimum._

> ### Enumerations
* This enumerates, or indexes the varible
* There are two types of enums
    * Plain enum
    * Enum class
* Emum class helps removing confusion while declaring variables with same name by having scope resolution operator
* Not just variables, even enum variables cant be declared in plain enum
* If plain enum was created, the enum type and int type can be passed into the same function which should not happen.
* If two plain enums are created and the same position value is compared, the result will be true, but thats not acceptable
* Hence enum classes makes sure that elements of different enum classes are not comparable
``` cpp
int main()
{
     // plain enum
	enum color2 {red, blue, yellow};
	color2 d2 = red;
	std::cout << d2 <<'\n';


    // class enum
	enum class color1 {red, blue, yellow}; // red is 0, blues is 1 ...
	color1 d1 = color1::red; // scope resolution to get value
    int red = 10; // this wont be possible in plain enum
    enum class color3 {red, blue, blue};
    color3 d3 = color3::red; // this wont be possible in plain enum
	std::cout << d1 <<'\n';
}
```
> ### Advice
* Use enumerations to represent sets of named constants
* Define operations on enumerations for safe and simple use;
---
> ## Chapter 3 - Modularity
* Parts of a program (source code)
    * Functions
    * User-defined types
    * Class hierarchies
    * Templates
* _Creating a clear difference between interface and its implementation._
* _Interface_ : is declaration part
* User code sees only declarations of the types
and functions used. The definitions of those types and functions are in separate source files and compiled separately.
* _Header file_ : Contains class information and other parts which were usually placed before int main()
* To access the header files, 
``` cpp
// in header.h
class user
{
public:
    // fucntions
private:
    // members
}

// in main.cpp
#include <iostream>
#include <"header.h">

int main()
{
    // the source implementation
}
```

> ### Namespace
* To express some names belong together in one group and to avoid confusion if the same name is repeated in another group, similar to that as in enum class

``` cpp
namespace group{
    class class1
        {
            // implementation
        }
}

class class1
{
    // different implementation
}

int main()
{
    group::class1 obj1; // scope operator avoids conflict
    class1 obj2;
}
```
> ### Error Handeling
* This is a huge and complex topic which goes into programming techniques and tools
    * Type system 

> ##### Exceptions
* If met with an error while run time, the throw function will transfer the control to handler for the specific type of error 
* Which will exit the scope and invoke the destructor
``` cpp
#include <stdexept>
#include <vector>

void f( const std::vector<int>& v)
    {
        try
            {
                v[v.size()] = 7;
            }
        catch(out_of_range)
            {
                std::cout << "Went out of bound, reverting to original form\n"; 
            }
    }
```
* A function that does not entertain exceptions can be declared as
``` cpp
void f (const std::vector<int> v) noexcept
{
    // implementation
}
```
> ##### Invariants (class invariant)
* A pre-defined condition (assumptions) that a class must hold when its member function is called
* This can be sued to avoid the exception usage
(???)

> ##### Static assertion
* Its check for some condition which has to be true in order to proceed, in the code, for checking, compline time error
* Useful for type checking in generic programming

``` cpp
# include <iostream>

int main()
{
    constexpr double pi = 3.14;
    static_assert(pi==3.14,"Entered value is correct");
}
```
> ### Advice
* "using" not to be used in header file 
---
> ## Chapter 4 - Classes























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
