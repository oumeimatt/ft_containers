#include <iostream>
#include <map>
#include <unistd.h>
#include <vector>
#include <random>
#include "map.hpp"
// #include "../tools/avl.hpp"
// #include "../tools/tools.hpp"
using namespace std;
int  main()
{
    {
        std::cout << "---------------------- ft::Map ------------------------" <<std::endl;
        bool cond(true);
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::Map<int, std::string> ft_m1;
            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, "string2"));
            }

            // m1.erase(m1.begin(), m1.end());
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
            ft_m1.erase(ft_m1.begin(), ft_m1.end());

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
