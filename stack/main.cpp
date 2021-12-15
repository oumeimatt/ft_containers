#include "Stack.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <stack>
int main ()
{
    std::vector<int> vec (3,100);   
    ft::Stack<int> st1(vec);
    ft::Stack<int> st2;
    std::stack<int,std::vector<int> > s1(vec);
    std::stack<int> s2;

    std::cout << (st1 == st2) << std::endl;
    // std::cout << "size  of st1 : " << st1.size() << std::endl;
    // std::cout << "size  of -s1- : " << s1.size() << std::endl;
    // std::cout << "size  of st2 : " << st2.size() << std::endl;
    // std::cout << "size  of -s2- : " << s2.size() << std::endl;
    // std::cout << "here " << (st1 == st2) << std::endl;
    // std::cout << (st1 != st2) << std::endl;

    // st2.push(12);
    // st1.push(12);
    // std::cout << "top  of st1 : "<< st1.top() << std::endl;
    // std::cout << "top  of st2 : "<< st2.top() << std::endl;
    // std::cout << "size  of st1 : " << st1.size() << std::endl;
    // std::cout << "size  of st2 : " << st2.size() << std::endl;


    // st1.pop();
    // st1.pop();
    // st1.pop();
    // st1.pop();
    // std::cout << st1.empty() << std::endl;

    // std::vector<int> example;

    // example.push_back(1);
    // example.push_back(5);
    // example.push_back(22);

    return 0;
}
