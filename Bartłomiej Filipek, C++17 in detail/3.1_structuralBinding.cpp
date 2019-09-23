/*
 * structural binding
 *
 */

#include <iostream>
#include <set>

// type this 1
int main()
{
    std::set<int> set1;
    auto [a,b] = set1.insert(19);
    if(b)
        std::cout << "Inserted\n";
}

/*
 * OUTPUT
Inserted
 */