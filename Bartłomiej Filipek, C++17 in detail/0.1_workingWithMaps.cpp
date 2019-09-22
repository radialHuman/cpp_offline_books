/*
 * Creating map by assigning values
 * reassigning it with new values
 */

#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> map1 {{"A",34},{"B",23}};
    // copying ti to another map
    std::map map2{map1};

    // changing one kvp
    if(auto [iter, wasAdded] = map2.insert_or_assign("B",25); !wasAdded)
        std::cout << iter->first << " reassigned ... \n";

    // adding one kvp
    if(auto [iter, wasAdded] = map2.insert_or_assign("C",15); !wasAdded)
        std::cout << iter->first << " reassigned ... \n";

    // printing out the result
    for(const auto& [key, value]:map2)
        std::cout << key << ":" << value << '\n';
}

/*
 * OUTPUT
B reassigned ...
A:34
B:25
C:15
 */