/*
 * [The Wiley Finance Series] Daniel J. Duffy - Introduction to C++ for Financial Engineers with CD_ An Object-Oriented Approach (2006, Wiley)
 * Chapter 12 - Creating Simpler Interfaces to STL for QF Applications
 * Page 179
 *
 * Contnet:
 * > Maps and sets
 * > interlinked classes Set<T>, AssocArray<V,AI>, AssocMatrix<V, A1, A2>
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

int main()
{
    // maps
    std::map<std::string,double> m1;
    //ways of inserting in map
    m1["pi"] = 3.14;

    auto p1 = std::make_pair("ki",2.12);
    m1.insert(p1);

    print("Key value pair of the dictionary are :");
    for(auto& [i,j] : m1)
        std::cout << i << ":" << j << std::endl;
    print("Removing the ki :");
    m1.erase("ki");
    for(auto& [i,j] : m1)
        std::cout << i << ":" << j << std::endl;
    auto p3 = std::make_pair("ji",8.10);
    m1.insert(p3);
    auto p4 = std::make_pair("di",9.83);
    m1.insert(p4);
    print("Removing between a range :");
    m1.erase(m1.begin(), m1.end());
    // or
    m1.clear();
    for(auto& [i,j] : m1)
        std::cout << i << ":" << j << std::endl;







}




/*



 */