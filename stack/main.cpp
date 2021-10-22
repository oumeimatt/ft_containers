#include "Stack.hpp"

int main ()
{
    std::vector<int> vec (3,100);   
    ft::Stack<int> st1(vec);
    ft::Stack<int> st2;

    std::cout << "size  of st1 : " << st1.size() << std::endl;
    std::cout << "size  of st2 : " << st2.size() << std::endl;
    std::cout << (st1 == st2) << std::endl;
    std::cout << (st1 != st2) << std::endl;

    st2.push(12);
    st1.push(12);
    std::cout << "top  of st1 : "<< st1.top() << std::endl;
    std::cout << "top  of st2 : "<< st2.top() << std::endl;
    std::cout << "size  of st1 : " << st1.size() << std::endl;
    std::cout << "size  of st2 : " << st2.size() << std::endl;

    st1.pop();
    st1.pop();
    st1.pop();
    st1.pop();
    std::cout << st1.empty() << std::endl;
    return 0;
}
