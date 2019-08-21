# A tour of C++ by Bjarne Stroustrup

> ## Chapter 1 - The Basic
__Chapter 5-6, 9-10, 12 of TC++PL__
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
* if there is nothing being pointed by the pointer then it is nullptr
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
__Chapter 8 of TC++PL__
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
__Chapter 13-15 of TC++PL__
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
* This can be used to avoid the exception usage
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
> ## Chapter 4 - 
__Chapter 16-22 of TC++PL__
* _Abstraction and resource management._
* _Classes help in object oriented programming and templates help in generic._
* _Whenever our design for a program has a useful concept,
idea, entity, etc., we try to represent it as a class._
* _Makes code easier to maintain, more efficient, more elegant, easier to use, easier to read, and easier to reason
about._

> ### Concrete type classes
* They behave ''just like built-in types.''
* They have their own semantics and sets of operations
* The defining characteristic of a concrete type is that its representation is part of its definition.
* If the representation changes in any significant way, a user
must recompile, just like in built-in types
* For types that don’t change often, and where local variables provide much-needed clarity and efficiency, this is acceptable and often ideal.
* For flexibility, major parts of its representation on the free store (dynamic memory, heap) and access them through
the part stored in the class object itself.
>1.  ##### Arithmetic type
* The class definition itself contains only the operations requiring access to the representation
* Simple operations are inline and not a fucntion call
* **Default Constructor** is a constructor with no arguments, and eliminates the possibility of uninitialized variables
* **Const** makes sure the variables passed are not affected while operating on it
* **Operator overloading** has be done cautiously
* Built in types should no tbe affected or altered

> 2. ##### Container type
* Like vectors in std
* New is to create and destructor is to deallocate memory. Using ~ in front of the class name
* **Delete** also can be used to do the same
* The technique of acquiring resources in a constructor and releasing them in a destructor, known as **Resource Acquisition Is Initialization or RAII**, allows us to eliminate ''naked new operations,'' that is, to avoid allocations in general code and keep them buried inside the implementation of well-behaved abstractions. Similarly, ''naked delete operations'' should be avoided. Avoiding naked new and naked delete makes code far less error-prone and far easier to keep free of resource leaks
    * _Initializer list_ : 
    ``` cpp
    std::vector<double> v1{1,2,3,4,5};
    ```
    * _push_back_ : 
    ``` cpp
    std::vector<double> v1;
    v1.push_back(2.0);
    ```
    * _emplace_back_ : 
    ``` cpp
    std::vector<double> v1;
    v1.emplace_back(2.0);
    ```
    * push_back has a move operation involved, while emplace_back has fewer and cheaper operations. So almost always use emplace_back().
    <br /><br />
* __Static_cast__: Type converter, does not check the value it is converting. Judicious use of the type system and well-designed libraries allow us to eliminate unchecked cast in higher-level software.
> ### Abstract Type
* Unlike concrete type where representation is a part of their definition, here, user is insulated from implementation details
* Achieved by having the representation separated from interface and having no genuine local variables
``` cpp
class Container {
public:
    virtual double& operator[](int) = 0; // pure virtual function
    virtual int size() const = 0; // const member function 
    virtual ˜Container() {} // destructor
};
```
* __Virtual__ : may be redefined later in some other class that inherits this class
* If all the members of the class are virtual its a pure virtual class or abstract class and thus it can crete an object as it just serves as an interface
* Since its not clear whats the properties are, they are stored in free space and accessed via & or *.
* __use()__ : is used to access such interface class (polymorphic type)
* They dont have constructors as nothing has to be initialized
* But has a destructor thats virtual 
> ##### Inheritance
``` cpp
class superclass // or base class
{
    public:
    // something
    private:
    //something else
}

class subclass : public superclass // or derived classs
{
    // can use stuff from superclass <- inheritance
}
``` 
* __Override__ : This keyword can be used to override the nature of function from derived class thats virtual in base class
* use() (???)

> ### Virtual Functions
* Virtual functions are mapped via a virtual function table or vtbl to the objects
* Same as the normal function bu the overhead of pointers used in vtbl

> ### Class hierarchy
* Its shows relation between classes, like a tree or a family structure, with them sharing members in a hierarchical manner.
> ##### Explicit overriding 
* Virtual function in the base class can be overridden by the function with the same name and same type in the derived clas by explicitly writing "override" after the fucntion in derived class along with its implementation.
* **Pointers** discussed later.

> ### Copy and Move
* User and built-in types can be copied by default, memberwise
* Copying concrete class is memberwise , for more complex concrete its not and for abstract its almost never.
> #### Copying containers
``` cpp
// not the right way to copy
void function(const std::vector<int>& v1)
{
    std::vector<int> v2 = v1;
    v1[0] = 1; // v2[0] also becomes 1
    v2[2] = 3; // v1[2] also becomes 3
}
```
* Since std::vector had destructor, default memberwise copying is wrong.
* **Copy constructor** : used for deep copying, where a separate memory is allocated along with a pointer to avoid two pointer pointing to one location situation

> #### Moving containers
* (???) more on this by Scott Meyers
* Sometimes copying can be a costly affair. So move constructor, that uses rvalue reference to get the task done.
* Move operator doesn need const as it is going to remove the value from its argument

> #### Essential Operations
``` cpp
class X {
public:
    X(Sometype); // ''ordinar y constr uctor'': create an object
    X(); //default constructor
    X(const X&); // copy constr uctor
    X(X&&); //move constr uctor
    X& operator=(const X&); // copy assignment: clean up target and copy
    X& operator=(X&&); // move assignment: clean up target and move
    ˜X(); //destructor: clean up
// ...
};
```

> #### Resource Management
* Garbage collection is fundamentally a global memory management scheme. Clever implementations can compensate, but as systems are getting more distributed (think multicores, caches, and clusters),locality is more important than ever.
* RAII (???)

> #### Suppressing opertions
* Delete default copy and move constructor
* ...

> ### Advice
* Needs a read again, more in later chapters of T++CPL'13
---
> ## Chapter 5 - Template
__Chapter 20-29 of TC++PL__
* Function overloading with each fucntion for a different type can be avoided by generalizing it as a fucntion that takes in any type
* _Templates_ are functions or classes that represents the concept in a general manner
``` cpp
template <typename T>
// template fucntion
T someFunction(const T& a, const T& b)
{
    // implementation
}
// template class
class someClass
{   
private:
    T v1[2];
public:
    // implementation
}
```
* Apart from these, lists, vectors, maps, unordered maps, can also be templated.
* Since they are compile time mechanism, there is no run time over head.

> ### Function objects
* Also called as functors.
* (???)

> ### Variadic templates
* Templates that take in parameters of variable number.
* Like *args in python.
* Generalizing not only the type but also the number of arguments passed
* Used for recursive actions
``` cpp
template <typename T, typename... tail>
void f (T head, Tail... tail)
{
    g(head); // do something for head
    f(tail...); // do something to tail parameters
}
```

> ### Alias
* To make synonym of type or a template.
* To make long names of functions short
``` cpp
template<typename T>
using v = std::vector<T>
void func(const T& i)
{
    v v1{1,2,3,4};
    // implementation
}
```
> ### Template compilation model
* Uses duck typing during compile time type check for templates
---
> ## Chapter 6 - Library overview
__Chapter 30 of TC++PL__
* Libraries makes writing codes easier than writing in bare language.
* 2/3rd of ISO C++ standard is about library specifications.
* There are other GUI, web interface, db interface libraries too.
* Well structured, thought, and optimized libraries are in the std library.
* Facilities in std libraries:
    1. Run time language support (Allocation and RTTI)
    1. Modified C std library
    1. Strings
    1. regex matching
    1. I/O streams
    1. STL framework for containers
    1. Support for numerical computation
    1. Support concurrent programming i.e. threads, locks
    1. STL style generic programming
    1. Smart pointers and interface to garbage collector
    1. Spl. purpose containers like tuple, array, bitset.
* Every lib has a std header
``` cpp
#include <vector>
#include <string>
```
* namespace is std::
``` cpp
std::vector<int> v1{1,2,3,4,5};
// initializes a vector 
```
* List of header and their functions (Sample)

Headers | Functions |
---| ---
< algorithm> | copy(), find(), sort() |
< array> | array  |
< chrono> | duration, time_point  |
< cmath> | sqrt(), pow()  |
< complex> | complex, sqrt(), pow()  |
< forward_list> | forward_list  |
< fstream> | fstream, ifstream, ofstream  |
< future> | future, promise  |
< ios> | hex,dec,scientific,fixed,defaultfloat  |
< iostream> | istream, ostream, cin, cout |
< map> | map, multimap  |
< memory> | unique_ptr, shared_ptr, allocator  |
< random> | default_random_engine, normal_distribution  |
< regex> | regex, smatch  |
< string> | string, basic_string  |
< set> | set, multiset  |
< sstream> | istrstream, ostrstream  |
< stdexcept> | length_error, out_of_range, runtime_error  |
< thread> | thread  |
< unordered_map> | unordered_map, unordered_multimap  |
< utility> | move(), swap(), pair |
< vector> | vector  |

* C libraries which were like
``` cpp
#include <stdlib.h>
// are now changed to
#include <cstdlib>
```
---
> ## Chapter 7 - String and Regex
__Chapter 36-37 of TC++PL__

* "string" type helps users from avoiding C-type of char*.
* "regex" for string pattern matching.

> ### String
* String concatenation:
``` cpp
#include <iostream>
#include <string>

std::string func(const std::string& firstName,const std::string& lastName)
{
    return firstName +" "+ lastName;
}

int main()
{
    std::string a = "Some";
    std::string b = "Name";
    auto result = func(a,b) ;
    std::cout << result <<'\n';
    
    // another way of adding
    std::string name = "Mr. ";
    name+= "Someone";
    std::cout << name << '\n';
}
/*
* OUTPUT
Some Name
Mr. Someone
*/
```
* Std string has a _move constructor_ so its efficient no matter the size
* += is more concise, efficient, explicit
* String is mutable and characters can be access via name[3].
``` cpp
#include <iostream>
#include <string>

int main()
{
    std::string name = "Somename";
    name[4] = 'N';
    std::cout << name << '\n';
    std::cout << name.substr(0,4) << '\n';
    std::cout << name.replace(0,4,"One") << '\n';
    std::cout << std::toupper(name[6]) << '\n';
    // gives back the ascii value of that character
}
/*
* OUTPUT
SomeName
Some
OneName
69
*/
```
> #### String implementation
* __Short string optimization__ : Short strings are kept in string objects while longer once are in free store.
* String performance depends on run time environment.
* multithreading implementation and memory allocation can be constly.
* Memory fragmentation also can happen if there is variety.
* std::string is an alias for basic_string

> ### Regular Expressions
* Tersely describe a pattern in text
1. regex_match()
1. regex_replace()
1. regex_search()
1. regex_iterator()
1. regex_token_iterator()


> #### Regular expression searching
* "smatch" is a type of container of this library that has a vector of sub strings
* First element of this has the complete match
* Works a bit differently, the pattern representation
* 
``` cpp
#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string var = "first secon123d third for456th";

    const std::regex r("(\\d+)");
    std::smatch sm;

    std::regex_search(var, sm, r);
    for (auto i : sm)
            std:: cout << i << ", ";
}
/*
OUTPUT
123, 456
*/
```
(???) needs more pattern knowledge

> #### Regular expression iterator
* Finds all the patterns in string
``` cpp
#include <iostream>
#include <string>
#include <regex>

void test()
{
    std::string input = "aa as; asd ++eˆasdf asdfg";
    std::regex pat {R"(\s+(\w+))"};
    for (std::sregex_iterator p(input.begin(),input.end(),pat); p!=std::sregex_iterator{}; ++p)
        std::cout << (*p)[1] << '\n';
}

int main()
{
  test();
}

/*
*OUTPUT
as
asd
asdfg
*/
```

---
> ## Chapter 8 - I/O stream
__Chapter 38 of TC++PL__
* __ostream__ : typed objects -> stream of characters (bytes)
* __istream__ : typed objects <- stream of characters (bytes)
* Operations on these are type-sensitive, type-safe, and can be used on user-defined types

> ### Output (ostream)
* std::cout is for output of any type
* std::cerr is for reporting error
* << : "put to"
``` cpp
#include <iostream>
//#include <iterator>
//#include <algorithm>
//#include <vector>

int main()
{
    int p;
    if(p)
        std::cout << p;
    else
    std::cerr << "Not present" << p;
}

/*
* OUTPUT
10
*/
```

> ### Input (istream)
* \>> "get from"
* std::cin is standard input stream
``` cpp
#include <iostream>

int main()
{
    int p;
    std::cout << "Enter a value\n";
    std::cin >> p;
    std::cout << "Entered value is : " << p <<'\n';
}
```
* _getline()_ is to input entire line
> ### I/O state
``` cpp
vector<int> read_ints(istream& is)
{
    vector<int> res;
    int i;
    while (is>>i) // this tests if iostream is true or not and returns a reference to is
        res.push_back(i);
    return res;
}
```
> ### I/O for user defined types
* 
``` cpp
#include <iostream>

class something
{
public:
    int some;
    double thing;
    // overloading <<
    friend std::ostream& operator<< (std::ostream& os, const something& x) // this has to be a friend
    {
        return os<< "{ "<<x.some << ", " << x.thing <<"}";
    }
};

int main()
{
    something st{10,20};
    std::cout << st;
}

/*
* OUTPUT
{ 10, 20}
*/
```
> ### Formatting
* Formatting control and manipulation can be done using the following libraries
1. < ios>
1. < istream>
1. < ostream>
1. < iomanip>

``` cpp
#include <iostream>

int main()
{
    std::cout << 1287 << ',' << std::hex << 1287 << ',' << std::oct << 1287 <<  ',' << std::scientific << 1287 <<  ',' << std::hexfloat << 1287 <<  ',' << std::fixed << 1287;
}

/*
 * OUTPUT
 1287,507,2407,2407,2407,2407
 */
```
> ### File stream <fstream>
1. < ifstream> to read a file
1. < ofstream> to write a file
1. < fstream> to read and write a file

> ## String stream <sstream>
1. < istringstream> to read a string
1. < ostringstream> to write a string
1. < stringstream> to read and write a string
``` cpp
#include <iostream>
#include <sstream>

int main()
{
    std::ostringstream oss;
    oss << "This is something that it reads : " << 1234;
    std::cout << oss.str();
}

/*
 * OUTPUT
This is something that it reads : 1234
 */
```

---
> ## Chapter 9 - Containers
__Chapter 31 of TC++PL__
* Containers hold objects.
* Suitable containers with suitable operations makes a good code.

> ### Vector
* Sequence of elements of same type, stored in contiguous memory. 
* Made of element, last space, last element, allocated space
* ex:
``` cpp
std::vector<Shape*> v1(23);
// creates a size 32 vector with nullptr
std::vector<double> v2(32,9.9);
// creates a size of 32 with initial value 9.9
```
* Vector adding element to the end:
``` cpp
#include <iostream>
#include <string>
#include <vector>


int main()
{
    std::vector<int> v1;
    v1.push_back(10); // appends to the end of vector
    v1.emplace_back(20); // better way to append 
    for(auto i: v1)
    	std::cout << i << ", ";
    std::cout << std::endl;
}

// OUTPUT
// 10, 20, 
```
* v1.reserve() is used by user or other vector members to  make room for more elements
* If not enough contiguous memory is available, it moves the whole container.
* But this happens infrequently.
* Range Checking (???)

> ### List
* It is a doubly-linked list
* Used for inserting and deleting operations
* Unless its required go for vector for better traversal, sorting and searching

> ### Map
* Its a red-black tree or a associative array (~python dictionary)
* Implemented as a balanced binary tree.
* Optimized for lookup

> ### unordered_map
* Big o of map is (log n).
* Can be better with hashed lookup than a ordering fucntion
* std lib has default hash fucntion for built-in types
* Creating a new hash function by combining existing hash functions using exclusive or (ˆ) is simple
and often very effective.

> ### Overview
* Basic operation:
    * size()
    * begin() and end()
    * push_back()
1. vector< T>
1. list< T>
1. forward_list< T>
1. deque< T>
1. set< T>
1. multiset< T>
1. map<K,V>
1. multimap<K,V>
1. unordered_map<K,V>
1. unordered_multimap<K,V>
1. unordered_set< T>
1. unordered_multiset< T>
---
> ## Chapter 10 - Algorithm
__Chapter 32 of TC++PL__
* Containers are just for storing objects, but the main purpose is to operate on them
* Most common operations, on most common containers are in std library
* A std algorithm expresses in terms of half open sequences.
* The sequence is represented by a pair of iterators i.e. first element and one-beyond-the-last element.
``` cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> v1{"something","nothing","anything"};
    std::cout << "Before sorting: ";
    for (auto i: v1)
    	std::cout << i << ", ";

    std::cout << std::endl;

    std::cout << "After sorting: ";
    std::sort(v1.begin(), v1.end());
    
    std::list<std::string> result;
 	// copying the objects to a different vector
    std::unique_copy(v1.begin(), v1.end(),std::back_inserter(result));
    for (auto i: result)
    	std::cout << i << ", ";
}

/*
* OUTPUT
Before sorting: something, nothing, anything, 
After sorting: anything, nothing, something,
*/
```
* back_inserter takes care of the memory allocation, unlike realloc() in C-style.
* list has move constructor that takes care of copying value efficiently.

> ### Use of Iterators
* Algorithm returns many types of iterators
* Used to separate algorithm and container
* ex: find() returns an iterator fo the element found
``` cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> v1{"something","nothing","anything"};
    std::cout << *std::find(v1.begin(), v1.end(),"nothing") << std::endl;

}

/*
* OUTPUT
nothing
*/
```
* To find the location of the occurances of object
``` cpp
(???)
```
> ### Iterators type
* Depending on the contianer, the type of iterator differs.
* Ex: std::vector's is a pointer, as thats enough to refere to the position in a vector
* This iterator can also change its location if added, hence useful in range checking
* Ex: std::list's is a pointer to a link
* Semantic and naming of their operation is common across the Iterators
* ++ will move it to the enxt element, * will give the element it refers to
* Containers take care of their iterator types

> ### Stream Iterator
* Apart from containers, iterators can be used in anythign with a sequence like an output stream of values
* *ostream_iterator* and *istream iterator*
``` cpp
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
// for ostream
int main()
{
    std::vector<int> v1{4,2,5,7,3,5,7,8,9,10};
    std::ostream_iterator<int> oo {std::cout};
    std::copy(v1.begin(),v1.end(),oo );
}

/*
* OUTPUT
42573578910
*/

```
istream_iterator (???)
> ### Predicates
* To make that action a parameter to the algorithm
* Alternatively, a lambda function can be used inside a algorithm
``` cpp
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v1{4,2,5,7,3,5,7,8,9,10};
    auto p = std::count_if(v1.begin(), v1.end(), [](const auto& i){return i>3;});
    // In this case, the action done by the lambda fucntion is the predicate
    std::cout << p << std::endl;
}

/*
* OUTPUT
8
*/

```
---
> ## Chapter 11 - Utilities
__Chapter 33-35 of TC++PL__
> ### Resource Management
* Resource is something that has to be acquired and later, explicitly or implicitly, released ex:
    * Memory
    * Lock
    * socket
    * thread handles
    * file handles
* In a long program, not releasing them in a timely manner can lead to problems or crashes
* Std lib are mot made to handle these leaks
* They rely on constructor destructor pairs, to ensure resources do not outlive an object responsible for it
* Thread, lock and mutex (???)
* _RAII_ : Resource acquisition is initialization is fundamental to the idomatic handling of resources

> ### Smart pointers
* The above mentioned are for managing resources in scope, but for the ones in _free store_, <memory> has:
    * unique_ptr
    * shared_ptr
* The use fo these is to prevent memory leaks
* unique_ptr ensure object is destroyed whicherver way it exits the fucntion either by 
    * Throwing an exception or
    * executing return or
    * falling off the end
* Example:
``` cpp
void f(int i, int j) 
{
    X∗ p = new X; // allocate a new X
    unique_ptr<X> sp {new X}; // allocate a new X and give its pointer to unique_ptr
    // ...
    if (i<99) throw Z{}; // may throw an exception
    if (j<77) return; // may retur n "ear ly"
    // ...
    p−>do_something(); // may throw an exception
    sp−>do_something(); // may throw an exception
    delete p;
}
```
* In this case, for the if comditions, P was not deleted due to a mistake by the programmer
* Apart from using smart pointer, it can also be solved by avoiding "new" entirely
* A smart pointer like unique_ptr can be sued, which is light and no space or time overhead
* These are owners of the objects, like how vector is the handle to a sequence of objects
* Shared_ptr is similar to unique_ptr, except they are copied and not moved
* Since it is shared owner ship, it is destroyed when the last pointer pointing to it is destroyed
* Creating an object in free store and passing a pointer to it to a smart ptr is odd and lenghty, so use make_shared( ) instead
``` cpp
#include <memory>
struct
{
    int i;
    double d;
    char c;
};
// verbose
std::shared_ptr<m> s1{new m{1,2.5,'d'}};
// alternative
auto p2 = std::make_shared<m>(1,2.5,'d');
```
* Theres is no make_unique() like make_shared(), but it can be user defined
* Need to reduce the use of the following (in decreasing order of importance)
    * New
    * pointers
    * references
    * smart pointer
* Contianers and other ways of managing resources are to be prefered
* When we share an object, we need pointers (or references) to refer to the shared object, so a shared_ptr becomes the obvious choice (unless there is an obvious single owner).
* When we refer to a polymorphic object, we need a pointer (or a reference) because we don’t know the exact type of the object referred to (or even its size), so a unique_ptr becomes the obvious choice.
* A shared polymorphic object needs shared_ptr
> ### Specialized COntainers
* They are not exatcly like the once provided by STL
* More like +/- containers

Syntax | Desription |
---| ---
T[N] | Built-in array: a fixed-size continuously allocated sequence of N elements of type T; implicitly converts to a T∗
array<T,N> | A fixed-size continuously allocated sequence of N elements of type T; like the built-in array, but with most problems solved
bitset<N> | A fixed-size sequence of N bits
vector<bool> | A sequence of bits compactly stored in a specialization of vector
pair<T,U>| Tw o elements of types T and U
tuple<T...>| A sequence of an arbitrary number of elements of arbitrary types
basic_string<C>| A sequence of characters of type C; provides string operations
valarray<T>| An array of numeric values of type T; provides numeric operations

* No single container could serve all of these needs because some needs are contradictory,
for example,
    * ''ability to grow'' vs. ''guaranteed to be allocated in a fixed location,'' and
    * ''elements do not move when elements are added'' vs. ''contiguously allocated.''

> #### Array :
* Is a fixed-size sequence of elements of a given type where the 
number of elements is specified at compile time
* Allocated with its elements on the stack, in an object, or in static storage
* Does not follow the ‘‘handle to elements’’ model of STL containers
* Element count must be a constant expression
``` cpp
std::array<int,3> a1 = {1,2,3};
```
* Array vs vector
    * There is a significant performance advantage to be had by directly accessing elements allocated on the stack rather than allocating elements on the free store, accessing them indirectly through the vector (a handle), and then deallocating them
    * On the other hand, the stack is a limited resource (especially on some embedded systems), and stack overflow is nasty
* Array vs built-in array
    * It saves from surprising nasty conversions to pointers
    * It can be copied (using = or initialization)
* Example (???)

> #### Bitset
* C++ supports the notion of small sets of flags efficiently through bitwise operations on integers
* Providing operations on a sequence of N bits [0:N),
where N is known at compile time.
``` cpp
std::bitset<9> bs1 {"110001111"};
std::bitset<9> bs2 {399};
bitset<9> bs3 = ˜bs1; // complement: bs3=="001110000"
bitset<9> bs4 = bs1&bs3; // all zeros
bitset<9> bs5 = bs1<<2; // shift left: bs5 = "111000000" >> is shift right
```
> ####  Pair and tuple
* Pair is collection of two objects
``` cpp
#include <utility>

std::pair p{1,"Something"};
std::cout << p.first << ", " << p.second;
```
* Tuple is more than 2 objects, and heterogeneous
``` cpp
auto t =std::make_tuple(std::string{"Herring"},10, 1.23);
std::string s = get<0>[t];
```

> ### Time
* Time related operations can be performed using <chrono>
``` cpp
#include <iostream>
#include <vector>
#include <chrono>

void do_work()
{
    std::vector<int> v;
    for(int i=0; i<100; i++)
        v.emplace_back(i);
    for(auto i : v)
        std::cout << " ";
}

using namespace std::chrono; // see §3.3
int main()
{
    auto t0 = high_resolution_clock::now();
    do_work();
    auto t1 = high_resolution_clock::now();
    auto x = t1-t0;
    std::cout << x.count();
    // this has to be converted to a known time unit by dynamic_casting
}

/*
 * OUTPUT
                                                                                                     2506300
 */
```
* This is important for meausring the performance of code
> ### Function adaptors
* A function adaptor takes a function as argument and returns a function object that can be used to invoke the original function
    * bind( )
    * mem_fn( )
* Functional programming terms: 
    * Currying or partial evaluation
> #### Bind
* Binders can have arguments and placeholders for the ones we dont have value at the moment, and this can be assigned to a variable
``` cpp
#include <functional>
//placeholders are found in the (sub)namespace std::placeholders that is part of <functional>.

func(int, std::string)
auto g = bind(func,2,std::placeholders::_1); // where _1 is the placeholder for the missing argument
g("something"); // this becomes func(2,"something")

// in caseof binding an overloaded function
int func(int, int);
double func (int , double);

// its is confusing which one has to be binded, so it has to be explicitly mentioned
auto g = bind((double(*)(int,double))func,_1,2);

```
* Return type of bind() varies depending on function return and arugument type

> #### mem_fun()
* Produces a fucntion object that can be a nonmember function
* Used for mapping from oops to functional style
* Often lambdas offer simple and generic alternative
``` cpp
(???)
```
> #### std::function()
* (???)

> ### Type function
* Evaluates at complie time
* Gives better performance, tight type checking, 
* Using them is __metaprogramming__ and template metaprogramming if templates are involved
* Example
``` cpp
#include <limits>
constexpr float min = numeric_limits<float>::min()
// gives smallest positive float
constexpr sz = sizeof(z); 
// gives number bytes in the int
```
> #### iterator_trait
* _sort()_ has iterators with random access while _forward\_list_ has only forward iterators
* To check the type of iterators
* (???)

> #### Type predicates
* Used to show check if some object is of some particular type
``` cpp
template<typename T>
constexpr bool Is_arithmetic()
{
    return std::is_arithmetic<T>::value ;
}
```
---
> ## Chapter 12 - Numerics
__Chapter 40 of TC++PL__
* numeric computation
typically occurs in the context of other work – such as
    * database access
    * networking
    * instrument control
    * graphics
    * simulation
    * financial analysis

> ### < cmath>
Function | Description |
--- | --- |
abs(x) | Absolute value
ceil(x) | Smallest integer >= x
floor(x) | Largest integer <= x
sqrt(x) | Square root; x must be non-negative
cos(x) | Cosine
sin(x) | Sine
tan(x) | Tangent
acos(x) | Arccosine; the result is non-negative
asin(x) | Arcsine; the result nearest to 0 is returned
atan(x) | Arctangent
sinh(x) | Hyperbolic sine
cosh(x) | Hyperbolic cosine
tanh(x) | Hyperbolic tangent
exp(x) | Base e exponential
log(x) | Natural logarithm, base e; x must be positive
log10(x) | Base 10 logarithm

* More mathematical functions are found in < cstdlib>
* Errors are reported by setting errno from < cerrno> to EDOM for a domain error and to ERANGE for a range error.

> ### < numeric>
Function | Description |
--- | ---|
x=accumulate(b,e ,i) | x is the sum of i and the elements of [b:e)
x=accumulate(b,e ,i,f) | accumulate using f instead of +
x=inner_product(b,e ,b2,i) | x is the inner product of [b:e) and [b2:b2+(e−b)), that is, the sum of i and (∗p1)∗(∗p2) for each p1 in [b:e) and the corresponding p2 in [b2:b2+(e−b))
x=inner_product(b,e ,b2,i,f,f2) | inner_product using f and f2 instead of + and ∗
p=partial_sum(b,e,out) | Element i of [out:p) is the sum of elements [b:b+i]
p=partial_sum(b,e,out,f) | partial_sum using f instead of +
p=adjacent_difference(b,e ,out) | Element i of [out:p) is (∗b+i)−∗(b+i−1) for i>0; if e−b>0, then ∗out is ∗b
p=adjacent_difference(b,e ,out,f) | adjacent_difference using f instead of −
iota(b,e ,v) | For each element in [b:e) assign ++v; thus the sequence becomes v+1, v+2, ...

``` cpp
void f()
{
    list<double> lst {1, 2, 3, 4, 5, 9999.99999};
    auto s = accumulate(lst.begin(),lst.end(),0.0); // calculate the sum
    cout << s << '\n'; // pr int 10014.9999
}
```
* _Complex_ numbers can be operated on using < complex> library
* _Random Number_ under < random> can be sued to generator
    * uniform_int_distribution
    * normal_distribution
    * exponential_distribution
* < valarray>, inlike vectors are less general and more amenable to optimization for numerical computation
    * support mathematical vector operations.

---
> ## Chapter 13 - Concurrency
__Chapter 41-42 of TC++PL__




<br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> 

---
Made possible by [Video](https://www.youtube.com/watch?v=HUBNt18RFbo "Markdown crash course")

___

### Other things that were not used in the notes but taught in the video

~~Something gets striked~~

`<p>This is used to write in html code</p>`

![Image name here]("https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/1200px-ISO_C%2B%2B_Logo.svg.png")


```python
def func(a,b)
    return a+b
```

* [ ] check list item unselected
* [x] check list item selected
