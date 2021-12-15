#include "Vector.hpp"
#include "random_access_iterator.hpp"
#include <vector>
// using namespace std;
int main()
{
    // {
      ft::Vector<int> a(4, 2);
        // ft::Vector<int>::iterator it = a.begin();
        // ft::Vector<int>::iterator it2 = a.end();
        // // cout << it[1] << endl;
        // std::ptrdiff_t k=it - it2;
        std::cout << a.end() - a.begin() << std::endl;
        // cout << (a.end() == a.begin()) << endl;
    //     // cout << (it2 == it) << endl;
    //     // cout << a.size() << "         " << a.capacity() << endl;
    // }
    // // {
    //     vector<int> a(2, 2);
    //     // a.push_back(1);
    //     // a.push_back(2);
    //     ptrdiff_t k = a.end() - a.begin();
    //     cout << k << endl;
    //     // for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
    //     cout << k << endl;
    //     // cout << a.size() << "         " << a.capacity() << endl;
    // }
}