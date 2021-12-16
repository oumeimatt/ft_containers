#include "Vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cout << "--------- STL VECTOR ---------" <<endl;
    {
        vector<int> a;
        for (int i = 0; i < 20; i++)
            a.push_back(i);
        cout << a.size() << endl;
        cout << "front ==== " <<  a.front() << " |||  back ==== " << a.back() << endl;
        

    }
    // cout << "--------- MY VECTOR ---------" <<endl;
    // {
    //     ft::Vector<int> a;
    //     for (int i = 0; i < 20; i++)
    //         a.push_back(i);
    //     cout << a.size() << endl;
    //     cout << "front ==== " <<  a.front() << " |||  back ==== " << a.back() << endl;
    // }
}