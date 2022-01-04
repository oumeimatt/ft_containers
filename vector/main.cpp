#include "Vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>
// using namespace std;

int main()
{

        /*-------------------------------------- time limit test -----------------------------------*/
           {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            /*------------------ std::vectors ---------------------*/
            // std::vector<std::string> v(1e6, "string");
            // std::vector<std::string> v1(1e6, "string2");
            // swap(v, v1);
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<int> ft_v(16, 12);
            ft::Vector<int> ft_v1(16, 12);
            // cout << "im here " << endl;
            // ft::swap(ft_v, ft_v1);
            swap(ft_v, ft_v1);
            
        }
        /*
         * strings to store the resutls
         */
        // std::string str, ft_str;
        // /*
        //  * var to store the size and the capacity
        //  */
        // ft::Vector<std::string>::size_type s, ft_s;
        // ft::Vector<std::string>::size_type c, ft_c;
        // ft::Vector<std::string>::iterator b1, b2;
        // /*
        //  * bool to store the comparison
        //  */
        // bool cond;

        // /*---------------------------------- test 1: equal size vectors ----------------------*/
        // {
        //     std::vector<std::string> v(200, "hello");
        //     std::vector<std::string> v1(200, "string");
        //     ft::Vector<std::string> ft_v(200, "hello");
        //     ft::Vector<std::string> ft_v1(200, "string");

        //     b1 = ft_v.begin();
        //     b2 = ft_v1.begin();

        //     swap(v, v1);
        //     swap(ft_v, ft_v1);

        //     s = v.size();
        //     ft_s = ft_v.size();
        //     c = v.capacity();
        //     ft_c = ft_v.capacity();
        //     for (size_t i = 0; i < v.size(); ++i)
        //         str += v[i];
        //     for (size_t i = 0; i < ft_v.size(); ++i)
        //         ft_str += ft_v[i];

        //     cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
        //     cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
        //     cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        // }
        /*--------------------------------------------------------------------------------------------*/
        /*---------------------------------- test 2: lhs > rhs ----------------------*/
        // {
        //     std::vector<std::string> v(200, "hello");
        //     std::vector<std::string> v1(50, "string");
        //     ft::Vector<std::string> ft_v(200, "hello");
        //     ft::Vector<std::string> ft_v1(50, "string");

        //     b1 = ft_v.begin();
        //     b2 = ft_v1.begin();

        //     swap(v, v1);
        //     swap(ft_v, ft_v1);

        //     s = v.size();
        //     ft_s = ft_v.size();
        //     c = v.capacity();
        //     ft_c = ft_v.capacity();
        //     for (size_t i = 0; i < v.size(); ++i)
        //         str += v[i];
        //     for (size_t i = 0; i < ft_v.size(); ++i)
        //         ft_str += ft_v[i];

        //     cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        //     cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
        //     cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        // }
        /*--------------------------------------------------------------------------------------------*/
        /*---------------------------------- test 2: lhs < rhs ----------------------*/
        // {
        //     std::vector<std::string> v(50, "hello");
        //     std::vector<std::string> v1(200, "string");
        //     ft::Vector<std::string> ft_v(50, "hello");
        //     ft::Vector<std::string> ft_v1(200, "string");

        //     b1 = ft_v.begin();
        //     b2 = ft_v1.begin();

        //     swap(v, v1);
        //     swap(ft_v, ft_v1);

        //     s = v.size();
        //     ft_s = ft_v.size();
        //     c = v.capacity();
        //     ft_c = ft_v.capacity();
        //     for (size_t i = 0; i < v.size(); ++i)
        //         str += v[i];
        //     for (size_t i = 0; i < ft_v.size(); ++i)
        //         ft_str += ft_v[i];

        //     cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        //     cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
        //     cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
        // }
        /*--------------------------------------------------------------------------------------------*/
    }
    
}