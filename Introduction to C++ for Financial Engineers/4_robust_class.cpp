/*
 * [The Wiley Finance Series] Daniel J. Duffy - Introduction to C++ for Financial Engineers with CD_ An Object-Oriented Approach (2006, Wiley)
 * Chapter 4 - Creating robust classes
 * Page 49
 *
 * Call by value and reference
 * Call by value, creates a copy and works on it, it might be avoided to make things efficient
 * hence, call by reference, which works on the actual variable itself
 * Call by value can be used for built in types
 * which call by reference for objects
 * this is done by the type followed by & and then the variable name
 * this sends the address on which the action has to be performed
 * but the drawback is it can create side effects by modifying the actual value
 * to sort it out the parameter passed is prefixed with const and then the type with & and the name of the argument
 *
 *
 */

double sum_by_reference (const double& x, const double& y)
{
//    this cant be done as this is modifying a const
//    x+=10;
    return(x+y);
}

double sum_by_value(double x, double y)
{
    x+=10;
    return(x+y);
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <sstream>

#include "common_functions.h" // header file reference


int main()
{
    std::cout <<"Sum is of 24,26 by reference\n";
    std::cout << sum_by_reference(24,26) << std::endl;
    std::cout <<"Sum is of 24,26 by value\n";
    std::cout << sum_by_value(24,26) << std::endl;
}




/*

 Sum is of 24,26 by reference
50
Sum is of 24,26 by value
60

 */