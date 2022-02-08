#include <iostream>
#include <map>
// #include <vector>
#include "map.hpp"
// #include "../tools/avl.hpp"
// #include "../tools/tools.hpp"

int main()
{
    {
        std::cout << "---------------------- ft::Map ------------------------" <<std::endl;
        ft::Map<int,int> mymap;
        ft::pair<int,int> a(1,122);
        mymap.insert(a);

        // mymap[1]=123;
        mymap[2]=456;
    
        std::cout << "mymap[1] is " << mymap[1] << '\n';
        std::cout << "mymap[2] is " << mymap[2] << '\n';
    }

    {
        std::cout << "---------------------- std::map ------------------------" <<std::endl;
        std::map<int,int> mymap;
        std::pair<int,int> a(1,122);
        mymap.insert(a);
        // mymap[1]=123;
        mymap[2]=456;
    
        std::cout << "mymap[1] is " << mymap[1] << '\n';
        std::cout << "mymap[2] is " << mymap[2] << '\n';
    }

}