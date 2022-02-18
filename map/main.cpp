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


        ft::Map<int, int> bbb;
        ft::pair<int, int> d(4,1);
        ft::pair<int, int> e(5,2);
        ft::pair<int, int> f(6,3);
        bbb.insert(d);
        bbb.insert(e);
        bbb.insert(f);
        
        aaa.swap(bbb);

        for (ft::Map<int, int>::iterator it = bbb.begin(); it != bbb.end(); it++)
            std::cout << it->first << std::endl;
        std::cout << std::endl;
        for (ft::Map<int, int>::iterator it = aaa.begin(); it != aaa.end(); it++)
            std::cout << it->first << std::endl;
    }



    // {
    //     std::cout << "---------------------- std::map ------------------------" <<std::endl;


    //     std::map<int, int> aaa;
    //     std::pair<int, int> a(1,1);
    //     std::pair<int, int> b(2,2);
    //     std::pair<int, int> c(3,3);


    //     aaa.insert(a);
    //     aaa.insert(b);
    //     aaa.insert(c);

    //     std::map<int, int>::const_iterator it = aaa.upper_bound();
    //     // std::cout << it->first << std::endl;
        
    // }

}
