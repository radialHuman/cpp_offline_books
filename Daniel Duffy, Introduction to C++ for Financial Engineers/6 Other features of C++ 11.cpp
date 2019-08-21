/*
 * Daniel Duffy
 * https://quantnet.com/media/categories/level-1-videos.12/
 *
 * > alias template and compared to typedef
 *      > used to define aliases for both template and non template
 *      > easy to use and apply, readable
 *      > useful for shared pointers
 *      > syntax: "using" <alias> = std::xyz
 *
 * > range based loop
 *      > similar to foreach
 *      > convinience interface
 * > sealed and classes
 *      > words : override, explicit, defaulted, and deleted
 *      > a "final" call cant be derived from and cant be overrided
 *      > syntax : class className final {};
 *      > can be used for functions memebers too
 *      > can be used with const to access since it will be a different function as const was not there while sealing it
 * > Explicit specifier
 *      > to block implicit and copy initializer
 *      > applies to constructor and user defined conversion operators
 *      > for both default and value inintizlization
 * > overrider ???
 *
 * > uniform initializer
 *      > common suntax for initizliation
 *      > 
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <typeinfo>
#include <string_view>
#include <random>

int main()
{
    // range based loop
    std::vector<int> v1{1,2,4,6,2,7,2,8,2,8,3,9,3};
    for(const auto& i:v1)
    {
        std::cout << i << std::endl;
        if(i>5){
            std::cout << "Bigger than 5" << std::endl;
        }
    }

}

/*
 * OUTPUT

 */