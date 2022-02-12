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
        ft::Map<int, int> mymap;
        ft::pair<int, int> b(1, 200);
        ft::pair<int, int> c(2, 300);
        ft::pair<int, int> d(3, -300);
        ft::pair<int, int> e(4, 1000);
        ft::pair<int, int> f(5, 10200);
        ft::pair<int, int> g(6, 100330);
        ft::pair<int, int> h(7, 10030);
        ft::pair<int, int> m(8, 10030);
   
        mymap.insert(b);
        mymap.insert(c);
        mymap.insert(d);
        mymap.insert(e);
        mymap.insert(f);
        mymap.insert(g);
        mymap.insert(h);
        mymap.insert(m);
        

        ft::Map<int, int>::iterator it = mymap.end();
        --it;
        --it;
        mymap.erase(it);
        ++it;
        // it--;
        // it--;
        // it--;
        // it--;
        // it--;
        // it++;
        // it++;
        // it++;
        mymap.erase(it);
        mymap.erase(mymap.begin());
        
        for (ft::Map<int, int>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
            // std::cout << (--mymap.end())->first << std::endl;
            std::cout << it->first   << "      ";
            // sleep(1);

        }

        //    ft::pair<int, int> b(1, 200);
        // ft::pair<int, int> c(2, 300);
        // ft::pair<int, int> d(3, -300);
        // ft::pair<int, int> e(4, 1000);
        // ft::pair<int, int> f(5, 10200);
        // ft::pair<int, int> g(6, 100330);
        // ft::pair<int, int> h(7, 10030);
        // ft::pair<int, int> m(8, 10030);
   
        mymap.insert(b);
        mymap.insert(c);
        mymap.insert(d);
        mymap.insert(e);
        mymap.insert(f);
        mymap.insert(g);
        mymap.insert(h);
        mymap.insert(m);

          for (ft::Map<int, int>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
            // std::cout << (--mymap.end())->first << std::endl;
            std::cout << it->first   << "      ";
            // sleep(1);

        }

        std::cout << std::endl;
    }

    // {
    //     std::cout << "---------------------- std::map ------------------------" <<std::endl;

    //     std::map<int, int> mymap;
    //     std::pair<int, int> b(1, 200);
    //     std::pair<int, int> c(2, 300);
    //     std::pair<int, int> d(3, -300);
    //     std::pair<int, int> e(4, 1000);
    //     std::pair<int, int> f(5, 10200);
    //     std::pair<int, int> g(6, 100330);
    //     std::pair<int, int> h(7, 10030);
    //     std::pair<int, int> m(8, 10030);
   
    //     mymap.insert(b);
    //     mymap.insert(c);
    //     mymap.insert(d);
    //     mymap.insert(e);
    //     mymap.insert(f);
    //     mymap.insert(g);
    //     mymap.insert(h);
    //     mymap.insert(m);
        

    //     std::map<int, int>::iterator it = mymap.end();
    //     it--;
    //     it--;
    //     it--;
    //     // it--;
    //     // it--;
    //     // it--;
    //     // it--;
    //     // it--;
    //     // it++;
    //     // it++;
    //     // it++;
    //     mymap.erase(it);
        
    //     for (std::map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++){
    //         // std::cout << (--mymap.end())->first << std::endl;
    //         std::cout << it->first   << "      ";
    //     }
    //     std::cout  << std::endl;
    // }

}
