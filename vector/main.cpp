#include "Vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    {
        vector<int> a;
        for (int i =0; i < 10; i++)
            a.push_back(i+100);
        vector<int> b;
        for (int i =0; i < 10; i++)
            b.push_back(i+200);
        vector<int> c(b.begin(), b.end());
        // vector<int> c;
        c.insert(c.begin(), a.begin(), a.begin() + 7);
        // cout  << "size of c  == " << c.size() << " || capacity of c == " << c.capacity() << endl;
        // for (vector<int>::iterator it = c.begin(); it != c.end() ; it++)
        //     cout << *it << endl;
        // c.insert(c.begin(), b.begin(), b.begin() + 5);
        cout  << "size of c  == " << c.size() << " || capacity of c == " << c.capacity() << endl;
        for (vector<int>::iterator it = c.begin(); it != c.end() ; it++)
            cout << *it << endl;
    }

    // {
    //     ft::Vector<int> a;
    //     for (int i =0; i < 10; i++)
    //         a.push_back(i);
    //     ft::Vector<int> b;
    //     for (int i =0; i < 10; i++)
    //         b.push_back(i+5);
    //     ft::Vector<int> c(b.begin(), b.end());
    //     // vector<int> c;
    //     // c.insert(c.begin(), a.begin(), a.begin() + 7);
    //     // cout  << "size of c  == " << c.size() << " || capacity of c == " << c.capacity() << endl;
    //     // for (vector<int>::iterator it = c.begin(); it != c.end() ; it++)
    //     //     cout << *it << endl;
    //     // c.insert(c.begin(), b.begin(), b.begin() + 5);
    //     cout  << "size of c  == " << c.size() << " || capacity of c == " << c.capacity() << endl;
    //     for (ft::Vector<int>::iterator it = c.begin(); it != c.end() ; it++)
    //         cout << *it << endl;
    // }
    
}
