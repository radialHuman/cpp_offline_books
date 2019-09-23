/*
 * structural binding
 *
 */

#include <iostream>
#include <map>
// type this 1
int main()
{
    std::map<std::string, int> map1 {{"name1",12},{"name2",13},{"name3",14}};
    for(const auto& [key, values] : map1) // makes it more expressive then having to call first, second, etc
        std::cout << key << ":" << values << '\n';
}

/*
 * OUTPUT
name1:12
name2:13
name3:14
 */