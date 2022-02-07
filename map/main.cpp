#include <iostream>
#include <map>
// #include <vector>
#include "map.hpp"
// #include "../tools/avl.hpp"
// #include "../tools/tools.hpp"

int main()
{
    {
        ft::Map<int,int> a;
        ft::pair<int, int> b(26, 200);
        ft::pair<int, int> c(3, 300);
        ft::pair<int, int> d(23, -300);
        ft::pair<int, int> e(44, 1000);
        ft::pair<int, int> f(2, 10200);
        ft::pair<int, int> g(12, 100330);
        ft::pair<int, int> h(90, 10030);

        a.insert(b);
        a.insert(c);
        a.insert(d);
        a.insert(e);
        a.insert(f);
        a.insert(g);
        a.insert(h);
        ft::Map<int, int>::iterator it = a.begin();
        it--;
        // std::cout << it->first << std::endl;
        // it--;
        // std::cout << it->first << std::endl;
        // it--;
        // std::cout << it->first << std::endl;
        // it--;
        // std::cout << it->first << std::endl;
        // it--;
        // std::cout << it->first << std::endl;
        // it--;
        // std::cout << it->first << std::endl;
        // it--;
        // std::cout << it->first << std::endl;
        // it--;

    //     for (ft::Map<int, int>::iterator it = a.begin(); it != a.end(); it++)
            std::cout << it->first << std::endl;
    }
    // {
    //     std::map<int,int> a;
    //     std::pair<int, int> b(26, 200);
    // //     // std::pair<int, int> c(3, 300);
    // //     // std::pair<int, int> d(23, -300);
    // //     // std::pair<int, int> e(44, 1000);

    //     a.insert(b);
    // //     // a.insert(c);
    // //     // a.insert(d);
    // //     // a.insert(e);

    //     std::map<int,int>::iterator it = a.begin();

    //     it--;
    //     it--;
    //     std::cout<< it->first <<std::endl;
    // //     // std::cout << it->first << std::endl;
    // }

}