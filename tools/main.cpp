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
   ft::pair<int, int> a(100, 100);
   ft::pair<int, int> b(26, 200);
   ft::pair<int, int> c(3, 300);
   ft::pair<int, int> d(23, -300);
   ft::pair<int, int> e(44, 1000);
   ft::pair<int, int> f(99, 1100);
   ft::pair<int, int> g(11, 1200);
   ft::pair<int, int> h(5, 1300);
   ft::pair<int, int> i(17, 1500);
   ft::pair<int, int> j(13, 1200);
   
   avl.insert(a);
   avl.insert(b);
   avl.insert(c);
   avl.insert(d);
   avl.insert(e);
   avl.insert(f);
   avl.insert(g);
   avl.insert(h);
   avl.insert(i);
   avl.insert(j);



   avl.tree_debug();
   // std::cout << avl.min().first << std::endl;
   // std::cout << avl.max().first << std::endl;
   avl.inorder();

   // avl.print_tree();


   return 0;
}