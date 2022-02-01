#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "avl.hpp"

#define pow2(n) (1 << (n))
using namespace std;
int main() {
//    int c, i;
   ft::AVLtree<int> avl;

    avl.insert(2);
    avl.insert(3);
    avl.insert(1);
    avl.insert(33);
    avl.insert(4);
    avl.insert(22);
    avl.insert(99);
    avl.postorder();

    avl.tree_debug();
    cout << endl;

   return 0;
}