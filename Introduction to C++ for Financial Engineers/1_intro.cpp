/*
 * [The Wiley Finance Series] Daniel J. Duffy - Introduction to C++ for Financial Engineers with CD_ An Object-Oriented Approach (2006, Wiley)
 * Chapter 1 - Introduction to C++ and Quantitative FInance
 * Page 10
 *
 * Generic programming: Template
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

// function to show vector values
template <class T>
void print(std::vector<T> v)
{
    for(auto i: v)
        std::cout << i << " ";
    std::cout << std::endl;
}

// printing out anything made easy
void print(std::string s)
{
    std::cout << s << std::endl;
}

// comparision function for descending sort
bool desc(double x, double y)
{
    return x>y;
}

template <class T>
T max(const T& x, const T& y)
{
    if(x>y)
        return(x);
    else
        return(y);
}

int main()
{

    /* Generic programming
     * > difference with normal programming practice in this case is that we need to give the compiler a hint that we are working with generic data types and not with specific ones
     *
    */
    print("** Using template for generic programming");
    std::cout << "Bigger of 3.14 & 2.13 is : " << max<double>(3.14,2.13) << std::endl;
    std::cout << "Bigger of 3 & 2 is : " << max<int>(3,2) << std::endl;
    std::cout << "Bigger of a & b is : " << max<std::string>("a","b") << std::endl;
    std::cout << "Bigger of a & b is : " << max<char>('a','b') << std::endl;

    // a module is a function thats not in the class, provides outptu for the input
    // this does not need object to be created



}




/*

Bigger of 3.14 & 2.13 is : 3.14
Bigger of 3 & 2 is : 3
Bigger of a & b is : b
Bigger of a & b is : b

 */