/*
 * [The Wiley Finance Series] Daniel J. Duffy - Introduction to C++ for Financial Engineers with CD_ An Object-Oriented Approach (2006, Wiley)
 * Chapter 11 - Introduction to Generic Data Structures and Standard Template Library (STL)
 * Page 179
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

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
    // making a vector with same value n times
    std::vector<double> v1(10,3.14);
    // range based for loop
    for(auto i: v1)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "The first element is :" << v1[0] << std::endl;
    // iterators: are between the vector and the algorithms being used
    for(auto i = v1.begin(); i!=v1.end();i++) // old style of for loops
        std::cout << *i << " "; // i is the iterator pointing to a position on container, and has t be dereferenced to call it
    std::cout << std::endl;
        // or
    for(auto i = begin(v1); i!= end(v1);i++) // old style of for loops
        std::cout << *i << " ";
    std::cout << std::endl;

    v1 = {1,2,3,4,5,6,7,8,9,10};
    std::vector<double> v2(v1.size()); // declaring a vector of size v1
    // copying values from one vector to another
    std::copy(begin(v1)+1, end(v1)-3, begin(v2));
    print("The new copied vector is :");
    print(v2);
    std::copy(begin(v1)+1, end(v1)-3, begin(v2)+3); // changing the location of copying the elements
    print("The new copied vector is :");
    print(v2);

    // rotating or shifting the elements within the container
    print("Rotating the vector by one: ");
    std::rotate(v2.begin(), v2.begin()+3,v2.end()); // moves the first 3 letters to the last
    print(v2);

    // replacing a particular number with another
    print("Replacing 2 with 7: ");
    std::replace(v2.begin(), v2.end(),2,7); // moves the first 3 letters to the last
    print(v2);

    // removing a particular number
    print("Removing the 7s: ");
    v2.erase(std::remove(v2.begin(), v2.end(),7),v2.end()); // to remove the 0s present in the place of removed values
    print(v2);

    // sorting a vector (default)
    print("Sorting the vector :");
    std::stable_sort(v2.begin(),v2.end()); // default is ascending
    print(v2);
    // sorting a vector (using a comparision function)
    print("Sorting the vector :");
    std::stable_sort(v2.begin(),v2.end(),desc); // function to make it asceding
    print(v2);

    // merging two vectors
    std::vector<double> v3(v1.size()+v2.size());
    print("Appending one vector to the other : ");
    std::stable_sort(v1.begin(),v1.end());
    print(v1);
    std::stable_sort(v2.begin(),v2.end());
    print(v2);
    print("Merge results in :");
    std::merge(begin(v1), end(v1), begin(v2), end(v2), v3.begin());
    print(v3);

    // transform
    print("Transforming a vector using lambda :");
    std::transform(v1.begin(), v1.end(), v1.begin(), [](double i){return (i*2);});
    print(v1);
    std::vector<double> v4(v1.size()+v2.size());
    print("Transforming 2 vectors to form a new one :");
    std::transform(v1.begin(), v1.end(), v2.begin(),v4.begin(),[](double i, double j){return i*j;});
    print(v4);



}




/*
3.14 3.14 3.14 3.14 3.14 3.14 3.14 3.14 3.14 3.14
The first element is :3.14
3.14 3.14 3.14 3.14 3.14 3.14 3.14 3.14 3.14 3.14
3.14 3.14 3.14 3.14 3.14 3.14 3.14 3.14 3.14 3.14
The new copied vector is :
2 3 4 5 6 7 0 0 0 0
The new copied vector is :
2 3 4 2 3 4 5 6 7 0
Rotating the vector by one:
2 3 4 5 6 7 0 2 3 4
Replacing 2 with 7:
7 3 4 5 6 7 0 7 3 4
Removing the 7s:
3 4 5 6 0 3 4
Sorting the vector :
0 3 3 4 4 5 6
Sorting the vector :
6 5 4 4 3 3 0
Appending one vector to the other :
1 2 3 4 5 6 7 8 9 10
0 3 3 4 4 5 6
Merge results in :
0 1 2 3 3 3 4 4 4 5 5 6 6 7 8 9 10
Transforming a vector using lambda :
2 4 6 8 10 12 14 16 18 20
Transforming 2 vectors to form a new one :
0 12 18 32 40 60 84 112 54 80 0 0 0 0 0 0 0


 */
