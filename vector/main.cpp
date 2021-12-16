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
        cout << "is empty :"<< a.empty() << endl;
        // cout << a.size() << endl;
        // cout << a.capacity() << endl;
        for (int i = 0; i < 17; i++)
            a.push_back(i);
        // cout << "is empty :"<< a.empty() << endl;
        cout << "size == " << a.size() << " |||| capacity=== " << a.capacity() << endl;
        // a.resize(5);
        // cout << "size == " << a.size() << " |||| capacity=== " << a.capacity() << endl;
        // cout << a.size() << endl;
        // cout << a.capacity() << endl;
        // for (std::vector<int>::iterator it =a.begin(); it != a.end(); it++)
        //     cout << *it << endl;
        a.pop_back();
        cout << "size == " << a.size() << " |||| capacity=== " << a.capacity() << endl;
        for (std::vector<int>::iterator it =a.begin(); it != a.end(); it++)
            cout << *it << endl;
        a.clear();
        cout << "size == " << a.size() << " |||| capacity=== " << a.capacity() << endl;

    }
    cout << "--------- MY VECTOR ---------" <<endl;
    {
        ft::Vector<int> a;
    //     cout << "is empty :"<< a.empty() << endl;
    //     // cout << a.size() << endl;
    //     // cout << a.capacity() << endl;
        for (int i = 0; i < 17; i++)
            a.push_back(i);
    //     cout << "is empty :"<< a.empty() << endl;
        cout << "size == " << a.size() << " |||| capacity=== " << a.capacity() << endl;
        a.pop_back();
        cout << "size == " << a.size() << " |||| capacity=== " << a.capacity() << endl;
        for (ft::Vector<int>::iterator it =a.begin(); it != a.end(); it++)
            cout << *it << endl;
        a.clear();
        cout << "size == " << a.size() << " |||| capacity=== " << a.capacity() << endl;
    //     a.resize(19, 100);
    //     cout << "size == " << a.size() << " |||| capacity=== " << a.capacity() << endl;
    //     // cout << a.size() << endl;
    //     // cout << a.capacity() << endl;
    //     for (ft::Vector<int>::iterator it =a.begin(); it != a.end(); it++)
    //         cout << *it <<endl;
    }
}