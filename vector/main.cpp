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


        // for (int i = 0; i < 15; i++)
        //     a.push_back(i);
        // vector<int> k = a;

        a.assign(49, 777);
        // a.push_back("hello");
        // a.push_back("world");
        // a.push_back("oumixa");
        // a.erase(a.begin()+5);
        //std::cout<<test.value
        for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
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
        // myString test(5);
        // ft::Vector<myString> a(3, test);
        ft::Vector<int> a;
        // for (int i = 0; i < 16; i++)
        //     a.push_back(i);
        a.assign(49, 777);
        // a.erase(a.begin()+5);
        // a.pop_back();
        for (ft::Vector<int>::iterator it = a.begin(); it != a.end(); it++)
            cout << *it << endl;
        cout << "size ======= "<< a.size() << " ||||| capacity ===== " << a.capacity() << endl;
    }
}
