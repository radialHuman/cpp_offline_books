/*
 * [The Wiley Finance Series] Daniel J. Duffy - Introduction to C++ for Financial Engineers with CD_ An Object-Oriented Approach (2006, Wiley)
 * Chapter 11 STL
 * Page 179
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>


int main()
{
    // making a vector with same value n times
    std::vector<double> v1(10,3.14);
    for(auto i: v1)
        std::cout << i << " ";
    std::cout << std::endl;
}




/*



 */
