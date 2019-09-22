/*
 * Printing using templates
 * constexpr
 * type traits _v
 * fold expression in variadic templates
 * static_cast
 */

#include <iostream>

// type this 3
template<typename T> void linePrinter(const T& x)
{
    if constexpr(std::is_integral_v<T>)
        std::cout << "Number :" << x << '\n';
    else if constexpr (std::is_floating_point_v<T>)
    {
        const auto f = x - static_cast<long>(x);
        std::cout << "Float :" << x << " fraction : " << f <<'\n';
    }
    else if constexpr(std::is_pointer_v<T>)
        {
        std::cout << "Pointer -> ";
        linePrinter(*x); // if pointer, take the value it holding and pass it through this template
        }
    else
        std::cout << x << '\n';
}

// type this 2
template< typename ... Args> void printWithInfo(Args ... args) // variadic template
{
    (linePrinter(args), ...); // fold expression
}

// type this 1
int main()
{
    auto i = 10;
    auto f = 2.56f;
    // function that takes in any number of arguments, and prints out
    printWithInfo(&i, &f, 30); // using pass by reference for the variables
}

/*
 * OUTPUT
Pointer -> Number :10
Pointer -> Float :2.56 fraction : 0.56
Number :30
 */