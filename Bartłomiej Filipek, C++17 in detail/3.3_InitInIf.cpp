/*
 * Init in if
 *
 */

#include <iostream>
#include <string>
#include <array>

int main() {
    std::string s = "Something that means nothing"; // const auto did not work (???) auto assumed to be const char* which is a type whiel std::String is no
    { // scoped so that "found" can be reused in a better manner
    // find a word in string
    const auto found = s.find("that"); // initializaing here
    if(found != std::string::npos)
        std::cout << found << " has it\n";
    }
    // found now has a seperate scope, so can leak
    // if the same has to be done again for a different word, found has to be renamed or has to be scoped

    // new way of doing the , so that scope fo found is controlled only to the if statement
    if(auto found = s.find("thats");found != std::string::npos)
        std::cout << found << " has it\n";
    // by doing so, even the else can access it
    else
        std::cout << "Cant find " << found << '\n';

    // this can also be integrated with previously discussed structural binding
    std::array<int,3> x = {6,2,3}; // cant use auto, as that will take in list instead of a vector ro array
    if(const auto [a,b,c] = x ; a-b-c>0) // cant use decomposition on vector
        std::cout << "Difference positive\n";
}
/*
 * OUTPUT
10 has it
Cant find 4294967295
Difference positive
 */