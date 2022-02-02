#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "avl.hpp"
#include "tools.hpp"

// #define pow2(n) (1 << (n))
using namespace std;
int main() {
   ft::AVLtree<ft::pair<int, int> > avl;
   ft::pair<int, int> a(1, 100);
   ft::pair<int, int> b(2, 200);
   ft::pair<int, int> c(3, 300);
   avl.insert(a);
   avl.insert(b);
   avl.insert(c);



    avl.tree_debug();
   // avl.print_tree();


   return 0;
}