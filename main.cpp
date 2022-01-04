#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v(5,5);
    std::vector<int>::reverse_iterator it = v.rend();
    std::cout<<it[-8]<<std::endl;

}