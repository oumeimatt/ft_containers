#include "Vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // cout << "================= STL VECTOR ================= " << endl;
    // {
    //     vector<int> a;
    //     for (int i =0; i < 22; i++)
    //         a.push_back(i+100);
    //     // cout  << "size of c  == " << a.size() << " || capacity of c == " << a.capacity() << endl;
    //     vector<int> b;
    //     for (int i =0; i < 10; i++)
    //         b.push_back(i+200);
    //     vector<int> c(a);
    //     cout << " ---- BEFORE INSERT ----" << endl;
    //     cout  << "size of c  == " << c.size() << " || capacity of c == " << c.capacity() << endl;
    //     // vector<int> c;
    //    c.insert(c.end(), (c.begin()), c.end());
    //     // cout  << "size of c  == " << c.size() << " || capacity of c == " << c.capacity() << endl;
    //     // for (vector<int>::iterator it = c.begin(); it != c.end() ; it++)
    //     //     cout << *it << endl;
    //     // c.insert(c.begin(), b.begin(), b.begin() + 5);
    //     cout << " ---- AFTER INSERT ----" << endl;
    //     cout  << "size of c  == " << c.size() << " || capacity of c == " << c.capacity() << endl;
    //     for (vector<int>::iterator it = c.begin(); it != c.end() ; it++)
    //         cout << *it << " ";
    // }
    cout << "\n================= MY VETOR ================="<< endl;
    {
        ft::Vector<int> a;
        for (int i =0; i < 22; i++)
            a.push_back(i);
        ft::Vector<int> b;
        for (int i =0; i < 10; i++)
            b.push_back(i+200);
        cout << " ---- BEFORE INSERT ----" << endl;
        cout  << "size of c  == " << b.size() << " || capacity of c == " << b.capacity() << endl;
        // vector<int> c;
        // c.insert(c.begin(), a.begin(), a.begin() + 7);
        // cout  << "size of c  == " << c.size() << " || capacity of c == " << c.capacity() << endl;
        // for (vector<int>::iterator it = c.begin(); it != c.end() ; it++)
        //     cout << *it << endl;
        // c.insert(c.begin(), b.begin(), b.begin() + 5);
        b.insert(b.end(), (a.begin()), a.begin() + 2);
        // c.insert(c.end()-6, 4, 11111);
        cout << " ---- AFTER INSERT ----" << endl;
        cout  << "size of c  == " << b.size() << " || capacity of c == " << b.capacity() << endl;
        // for (ft::Vector<int>::iterator it = c.begin(); it != c.end() ; it++)
        //     cout << *it << " ";
    }
    
}
