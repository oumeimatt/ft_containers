#include "Vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "================= STL VECTOR ================= " << endl;
    {
        vector<int> a;
        for (int i =0; i < 20; i++)
            a.push_back(i + 200);
        vector<int> b;
        for (int i = 0; i < 20; i++)
            b.push_back(i + 200);
        // cout << "++++++++++ BEFORE ASSIGN ++++++++++" << endl;
        // cout << " b size === " << b.size() << " ||| b capacity === " << b.capacity() << "\n\n\n";
        // b.insert(b.end(), b.begin(), b.end());
        // cout << "++++++++++ AFTER ASSIGN ++++++++++" << endl;
        // cout << " b size === " << b.size() << " ||| b capacity === " << b.capacity() << "\n\n\n";
        // for (vector<int>::iterator it = b.begin(); it != b.end(); it++)
        //     cout << *it  <<  " " ;
        // cout << endl;
        cout << "operator == " << (a == b) << endl;
        cout << "operator != " << (a != b) << endl;
        cout << "operator <= " << (a <= b) << endl;
        cout << "operator => " << (a >= b) << endl;
        cout << "operator < " << (a < b) << endl;
        cout << "operator > " << (a > b) << endl;
        a.push_back(12);
        cout << "operator == " << (a == b) << endl;
        cout << "operator != " << (a != b) << endl;
        cout << "operator <= " << (a <= b) << endl;
        cout << "operator => " << (a >= b) << endl;
        cout << "operator < " << (a < b) << endl;
        cout << "operator > " << (a > b) << endl;

    }
    cout << "\n================= MY VETOR ================="<< endl;
    {
        ft::Vector<int> a;
        for (int i =0; i < 20; i++)
            a.push_back(i + 200);
        ft::Vector<int> b;
        for (int i =0; i < 20; i++)
            b.push_back(i + 200);
        // cout << "++++++++++ BEFORE ASSIGN ++++++++++" << endl;
        // cout << " b size === " << b.size() << " ||| b capacity === " << b.capacity() << "\n\n\n";
        // b.insert(b.end(), b.begin(), b.end());
        // cout << "++++++++++ AFTER ASSIGN ++++++++++" << endl;
        // cout << " b size === " << b.size() << " ||| b capacity === " << b.capacity() << "\n\n\n";
        // for (ft::Vector<int>::iterator it = b.begin(); it != b.end(); it++)
        //     cout << *it  <<  " " ;
        // cout << endl;
        cout << "operator == " << (a == b) << endl;
        cout << "operator != " << (a != b) << endl;
        cout << "operator <= " << (a <= b) << endl;
        cout << "operator => " << (a >= b) << endl;
        cout << "operator < " << (a < b) << endl;
        cout << "operator > " << (a > b) << endl;
        a.push_back(12);
        cout << "operator == " << (a == b) << endl;
        cout << "operator != " << (a != b) << endl;
        cout << "operator <= " << (a <= b) << endl;
        cout << "operator => " << (a >= b) << endl;
        cout << "operator < " << (a < b) << endl;
        cout << "operator > " << (a > b) << endl;
    }
    
}