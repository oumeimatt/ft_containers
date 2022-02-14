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

        ft::Map<char,int> mymap;
        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;      




        // show content:
        ft::Map<char,int>::reverse_iterator rit = mymap.rend();
        --rit;
        // for (; rit!= (mymap.rbegin()) ; rit--)
          std::cout << rit->first << " => " << rit->second << '\n';    
          --rit;
          std::cout << rit->first << " => " << rit->second << '\n';   
            --rit;
            std::cout << rit->first << " => " << rit->second << '\n';   
    }



    // {
    //     std::cout << "---------------------- std::map ------------------------" <<std::endl;

    //     std::map<char,int> mymap;       
    //     mymap['x'] = 100;
    //     mymap['y'] = 200;
    //     mymap['z'] = 300;       



    // //     // show content:
    //     std::map<char,int>::reverse_iterator rit = --mymap.rend();
    // //     for (; rit!= (mymap.rbegin()) ; rit--)
    //       std::cout << rit->first << " => " << rit->second << '\n';      

        
    // }

}
