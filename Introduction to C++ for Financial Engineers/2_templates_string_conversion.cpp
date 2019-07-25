/*
 * [The Wiley Finance Series] Daniel J. Duffy - Introduction to C++ for Financial Engineers with CD_ An Object-Oriented Approach (2006, Wiley)
 * Chapter 2 - The Mechanics of C++: from Source Code to a Running Program
 * Page 15
 *
 * Structure of c++ program
 * linker header executable file
 * classes and objects
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <sstream>

#include "common_functions.h" // header file reference

// template to convert any type to string
template <class T>
std::string makeString(const T& v)
{
    std::stringstream s;
    s << v;
    return(s.str());
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
    /*
     * In general we create two files, one containing the declaration of all relevant functions and data
while the other file contains the actual code body of each function.
     *
     */
    // classes
    Date dd(12,21,1991);

    // type conversion, using string stream library
    double decimal = 1.0;
    std::stringstream s; // a string stream object
    s << decimal;
    std::string str_decimal = s.str();
    std::cout << str_decimal << std::endl;

    // using a template
    std::cout<< "The number to be converted is : 3.14" << " -> "<< makeString<double>(3.14) << std::endl;
    std::cout<< "The number to be converted is : 3" << " -> "<< makeString<int>(3) << std::endl;


}




/*
** Using template for generic programming
Bigger of 3.14 & 2.13 is : 3.14
Bigger of 3 & 2 is : 3
Bigger of a & b is : b
Bigger of a & b is : b
The date today is :12/21/1991
1
The number to be converted is : 3.14 -> 3.14
The number to be converted is : 3 -> 3

 */