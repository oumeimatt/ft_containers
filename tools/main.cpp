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
   ft::pair<int, int> b(26, 200);
   ft::pair<int, int> c(3, 300);
   ft::pair<int, int> d(23, -300);
   ft::pair<int, int> e(44, 1000);
   ft::pair<int, int> f(2, 10200);
   ft::pair<int, int> g(12, 100330);
   ft::pair<int, int> h(90, 10030);
   ft::pair<int, int> m(1, 10030);
   
   avl.insert(b);
   avl.insert(c);
   avl.insert(d);
   avl.insert(e);
   avl.insert(f);
   avl.insert(g);
   avl.insert(h);
   avl.insert(m);
   avl.remove(c);
   // avl.remove(d);

   avl.tree_debug();
   // std::cout << avl.min().first << std::endl;
   // std::cout << avl.max().first << std::endl;
   // avl.inorder();
   // avl.inorder2();

   // avl.print_tree();


   return 0;
}