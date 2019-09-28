# C++ in detail by Bartłomiej Filipek
```
Lesser number of pages compared to the offical one, missing the following in respective chapters:
4. Capturing [*this] in Lambda Expressions
__has_include Preprocessor Expression
16. Removed And Deprecated Library Features
Removing auto_ptr
Removed std::random_shuffle
“Removing Old functional Stuff”
std::iterator Is Deprecated
Other Smaller Removed or Deprecated Items
Compiler support
20. Tests
```
[@CppCast!](https://www.youtube.com/watch?v=WM6QVOt_Rig)

> ## Contents
* Part One - C++17 Language features:
    * Fixes and Deprecation
    * Language Clarification
    * General Language Features
    * Templates
    * Attributes
* Part Two - C++17 The Standard Library:
    * std::optional
    * std::variant
    * std::any
    * std::string_view
    * String Operations
    * Filesystem
    * Parallel STL
    * Other Changes
* Part Three - More Examples and Use Cases
* Appendix A - Compiler Support
* Appendix B - Resources and Links

> ### Online compliers 
* Coliru
* WandBox
* Compiler Explorer
* CppBench
* C++ Insights

[List of online compliers](https://arnemertz.github.io/online-compilers/)

> ## Part 1 - The language Feature

> ### Quick Start
* Intro to new changes via code 
    * 0.1_workingWithMaps.cpp
        * __*Template augmented deduction*__
        * __*std::insert_or_assign*__
        * __*Structured binding*__
        * __*init if*__
        * __*Structured binging inside range based foor loop*__
    * 0.2_printingStuff.cpp
        * __*Variadic template*__
        * __*constexpr*__
        * __*trait type using "_v"*__
        * __*Fold expression*__
---
> ### 1. Fixes and Deprecation
    * (???)
---
> ### 2. Language clarification
    * (???)
---
> ### 3. General language features

> #### Structural Binding/Decomposition declaration
* Structural biding can be used with 
    * Tuples
    * Pairs
    * Arrays
    * Structs
    * Classes
    as long as the number of static variables are the same on either side
        * Has only read access, for write, class should provide accessor that returns reference to that variable
* 3.1_structuralBinding.cpp
* SYNTAX
    >  * auto [a,b,c, ...] = expression;
    >  * auto [a,b,c, ...]  {expression};
    >  * auto [a,b,c, ...]  (expression);
* This generates psudo code like
```cpp
auto tempTuple = expression;
using a = tempTuple.first;
using b = tempTuple.second;
using c = tempTuple.third;
...
```
* a,b,c are not references, they are aliases
* MODIFIERS
    >  * const auto [a,b,c, ...] = expression;
    >  * auto& [a,b,c, ...] = expression;
    >  * auto&& [a,b,c, ...] = expression;
    >  * [[maybe_unused]] auto [a,b,c, ...] = expression; (???)
* LIMITATION
    >  * In C++17, structural binding is not constexpr-able, can be in C++20
    >  * In C++17, this can be used to access public memebers of class, but not the priivate ones, can be in C++20
    >  * You can only use structured bindings on array types __*where the size is known at compile time*__
        >       * Example std::vector cant be decomposed    

* Examples
    * 3.2_structuralBindingsWithMap.cpp
    * classes example with template and constexpr (???)
> #### Init statement in If and switch
* SYNTAX
    > * if(init, condition);
    > * switch(init, condition);
* To initialize new variable and check its condition
* The scope of that variable will be in the scope of the if/else/switch
* Used to avoid leaks
```cpp
{
    auto val = getVlaue();
    if(condition(val))
        ...
    else
        ...
}

// can now to written as

{
    if(auto  val = getVlaue(); condition(val))
        ...
    else
        ...
}
```
* EXAMPLE
    * 3.3_InitInIf.cpp
> #### Inline variable
* const static variable previously was declared and defined seperately in the same file or in different. In C++17 it can be done using the keyword __*inline*__
> SYNTAX
```cpp
struct something
{
    inline static const std::string s = "Something";
};
```
* Constexpr is not required for these variables as they implicitly constexpr
* More flexible than constexpr since it doesn require const ex: can be initilzied with rand() and the variable will be const through out the unit

> #### constexpr Lambda expressions
* Constexpr and lambda can work together in C++17 if
    * lambda expression follows rules of standard constexpr functions <- making them costexpr implicitly
    * It should not be virtual
    * return type will be literal 
* The lambda function should not invoke code thats not constexpr
    * Like dynamically allocating memory
* SYNTAX : Declaring it explicitly
``` cpp
auto lambda = [] (int n) constexpr {return n;};
```
> #### Nested namespace
* Previously nested namespace would look like for loops
* Since C++17, it can be written in a better manner
* SYNTAX
``` cpp
// previously
namespace std {
    namespace library1 {
        namespace library2 {
            // ...
        }
    }
}

// now
namespace std::library1::library2 {
    // ...
}
```
---
> ### 4. Template
* Auto template deduction, makes make_Type redundant
* But all the parameters have to be either specified or not
* Partial deduction cant be done
``` cpp
// previously 
std::pair <int, std::string> pair1 (31,"Something");

// now
auto pair1  = std::make_pair(31,"Something");

// can be done using
using namespace std::string_literal;
std::pair pair1(42,"Something");

// same for
std::array arr1 {1,2,3};
```
* Exceptions like make_shared since they do something more than just creating shared pointers like control block and pointer memory allocation

> ### Deduction guides
* Used for figuring out template class type 
* Two types:
    * Complier geenrated (implicit type)
    * User defined
* These guides by compliers, will be created for each constructor (also copy/move) of the primary class template
* SYNTAX
``` for user defined
template <typename T>
struct MyType
{
    T str;
};
MyType(const char *) -> MyType<std::string>; // if not for this, the deduction would be for const char *
MyType T{"Soemthing};
```
* Overloading
``` cpp
template<class... Ts>
struct overload : Ts... { using Ts::operator()...; };
template<class... Ts>
overload(Ts...) -> overload<Ts...>; // deduction guide
```
> ### Fold expression
* Even though variadic template reduces code, one has to specify rules if a recursive function has to be implemented
``` cpp
// previously
auto summ(){
    return 0;
}

template<typename T1, typename... T>
auto summ(T1 s, T... ts)
{
    return s+ summ(ts); // recursive
}

// Now
template<typename ...Args> auto summ(Args ...args)
{
    return(args+ ... +0);
}

// or 
template<typename ...Args> auto summ(Args ...args)
{
    return(args+ ... );
}
```
* Available with
    * Unary left/right fold
    * Binary left/right fold
```cpp
template<typename T, typename... Args>
void push_back_vec(std::vector<T>& v, Args&&... args)
{
(v.push_back(std::forward<Args>(args)), ...);
}
std::vector<float> vf;
push_back_vec(vf, 10.5f, 0.7f, 1.1f, 0.89f); // how to show the output(???)
```
> ### If constexpr
* Allows to discard branches of if statement at complie-time based on constant expression condition
* This is different than having just an if
* The code in the discarded branch is not completely *removed*
* Only the expressions that are dependent on the template parameter used in the condition are not instantiated but other things will be complied and can throw an error
* Used as an alternate for SFINAE and tag dispatching

SFINAE : Substitution failure is not an error (???)
Tag dispatching : (???)
std::is_integral_v (???)

> ### auto in template
``` cpp
// before C++17
template <typename Type, type value> constexpr Type TConstant = value;
constexpr auto const SuperConst = TConstant<int, 100>;

// after C++
template <auto value> constexpr auto TConstant = value;
constexpr auto const SuperConst = TConstant<100>;

// heterogeneous complie time list (???)
// before c++17, this would not be possible without a wrapper
temaplte <auto ... vs>
struct heteroValueList{};
using list = heteroValueList<'a',100,'b'>;
```

> ### Other
* "typename" and "class" can be inetrchangably used
* All trait types that yields ::value (???) have a "_v" as suffix ex: std::is_integral_v
* Pack expansion (???)
* ...

> ### 5. Standard Attributes
