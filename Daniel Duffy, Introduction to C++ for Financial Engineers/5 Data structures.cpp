/*
 Daniel Duffy
 * https://quantnet.com/media/categories/level-1-videos.12/
 * DATA STRUCTURES
 * > Union, tuple, structures for threading and concurrancy,regex
 * > Universal function wrappers std::function<>
 * > Unordered conatiners : fucntional hash, heap, unordered
 * > Unified Modelling Language
 * > Boost, design application
 * > cons of c++
 *  > lack of data structures, like for matrices, trees, graphs,
 *  > long developement time
 *  > boiler plate code
 *  > STL doesn support design by contract
 *
 *  Unordered MAP
 *  template<
 *  class Key,
 *  class T,
 *  class hash = std::hash<Key>;
 *  class equal_to = std::equal_to<Key>,
 *  class allocator = std::allocator<std::pair<const Key,T>>
 *  >
 *  class unordered_map;
 *
 *  UNION ???
 *  Template Template parameter ???
 *
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
    // shuffle randomly
    // creating an engine
    std::default_random_engine eng;
    std::vector<int> v1{1,2,3,4,5,6,7,8,9,10};
    std::shuffle(v1.begin(),v1.end(),eng);
    std::for_each(v1.begin(),v1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;

    // modify the numebrs with randomly geenrated numbers
    std::for_each(v1.begin(),v1.end(),[&](int& i){i = eng();});
    std::for_each(v1.begin(),v1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;

    // randomly generating using tuple for testing
    std::uniform_int_distribution<int> uid_i(10,20);
    std::uniform_real_distribution<double> uid_d(0.10,0.20);
    std::cout << uid_d(eng) <<std::endl;
    std::cout << uid_i(eng) <<std::endl;

    // break at 31:56



}

/*
 * OUTPUT
3 8 2 7 9 1 5 10 6 4
470211272 101027544 1457850878 1458777923 2007237709 823564440 1115438165 1784484492 74243042 114807987
0.167115
10
 */