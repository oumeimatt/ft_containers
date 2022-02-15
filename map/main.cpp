#include <iostream>
#include <map>
#include <unistd.h>
// #include <vector>
#include "map.hpp"
// #include "../tools/avl.hpp"
// #include "../tools/tools.hpp"
using namespace std;
int  main()
{
    {
        std::cout << "---------------------- ft::Map ------------------------" <<std::endl;

        ft::Map<int, int> aaa;
        ft::pair<int, int> a(1,1);
        ft::pair<int, int> b(2,2);
        ft::pair<int, int> c(3,3);


        aaa.insert(a);
        aaa.insert(b);
        aaa.insert(c);

        ft::Map<int, int>::const_iterator it = aaa.begin();
        std::cout << it->first << std::endl;
    }



    {
        std::cout << "---------------------- std::map ------------------------" <<std::endl;


        std::map<int, int> aaa;
        std::pair<int, int> a(1,1);
        std::pair<int, int> b(2,2);
        std::pair<int, int> c(3,3);


        aaa.insert(a);
        aaa.insert(b);
        aaa.insert(c);

        std::map<int, int>::const_iterator it = aaa.begin();
        std::cout << it->first << std::endl;
        
    }

}
