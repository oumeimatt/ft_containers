#include "Vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cout << "--------- STL VECTOR ---------" <<endl;
    {
        vector<string> a;
        // for (int i = 0; i < 16; i++)
        a.push_back("hello");
        a.push_back("world");
        a.push_back("oumixa");
        a.pop_back();
        // cout << a[3] << "papa" << endl;
        for (vector<string>::iterator it = a.begin(); it != a.end(); it++)
            cout << *it << endl;
//         vector<int>::iterator it = a.erase(a.begin(), a.begin()+7);
//         for ( ; it != a.end(); it++)
//             cout << *it << endl;
        cout << "size ======= "<< a.size() << " ||||| capacity ===== " << a.capacity() << endl;
        // a.insert(a.begin() + 2,3, 777);
        // cout << "size ======= "<< a.size() << " ||||| capacity ===== " << a.capacity() << endl;
        // vector<int> b;
        // for (int i = 7; i < 19; i++)
        //     b.push_back(i);
        // a.swap(b);
        // cout << "size ======= "<< a.size() << " ||||| capacity ===== " << a.capacity() << endl;
        // cout << "size ======= "<< b.size() << " ||||| capacity ===== " << b.capacity() << endl;
        // cout << "==========print A==========" << endl;
        // for (vector<int>::iterator it=a.begin(); it != a.end(); it++)
        //     cout << *it <<endl;
        // cout << "\n ==========print B==========" << endl;
        // for (vector<int>::iterator it=b.begin(); it != b.end(); it++)
        //     cout << *it << "   ";
        // cout << endl;
        // a.assign(7,15);
        // cout << "size ======= "<< a.size() << " ||||| capacity ===== " << a.capacity() << endl;
        // for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
        //     cout << *it << endl;


    }
    cout << "--------- MY VECTOR ---------" <<endl;
    {
    //     ft::Vector<int> a;
    //     for (int i = 0; i < 16; i++)
    //         a.push_back(i);
    //     ft::Vector<int>::iterator it = a.erase(a.begin(),a.begin()+7);
    //     for (; it != a.end(); it++)
    //         cout << *it << endl;   
    //     cout << "size ======= "<< a.size() << " ||||| capacity ===== " << a.capacity() << endl;
    // //     a.insert(a.begin()+2,3, 777);
    // //     cout << "size ======= "<< a.size() << " ||||| capacity ===== " << a.capacity() << endl;
    // //     // ft::Vector<int> b;
    // //     // for (int i = 7; i < 19; i++)
    // //     //     b.push_back(i);
    // //     // a.swap(b);

    // //     // cout << "size ======= "<< a.size() << " ||||| capacity ===== " << a.capacity() << endl;
    // //     // cout << "size ======= "<< b.size() << " ||||| capacity ===== " << b.capacity() << endl;
    // //     cout << "==========print A==========" << endl;

    // //     for (ft::Vector<int>::iterator it=a.begin(); it != a.end(); it++)
    // //         cout << *it << endl;
    // //     // cout << "\n ==========print B==========" << endl;
    // //     // for (ft::Vector<int>::iterator it=b.begin(); it != b.end(); it++)
    // //     //     cout << *it << "   ";
    // //     // cout << endl;
        ft::Vector<string> a;
        // for (int i = 0; i < 16; i++)
        //     a.push_back(i);
        a.push_back("hello");
        a.push_back("world");
        a.push_back("oumixa");
        // a.clear();
        a.pop_back();
         cout << a[2] << "papa" << endl;
        for (ft::Vector<string>::iterator it = a.begin(); it != a.end(); it++)
            cout << *it << endl;
        cout << "size ======= "<< a.size() << " ||||| capacity ===== " << a.capacity() << endl;
    }
}
