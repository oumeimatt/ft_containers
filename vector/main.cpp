#include "Vector.hpp"
#include "random_access_iterator.hpp"
#include <iostream>
#include <vector>
// using namespace std;

int main()
{
    // {
  	//     std::vector<int> v;
    //     std::vector<int> k;
	//     std::vector<int> tmp;
	//     tmp.assign(26000000, 1);
	//     v.assign(42000000, 7);
	//     v.insert(v.begin(), tmp.begin(), tmp.end());
	//     for (size_t i = 0; i < tmp.size(); ++i) {
	//     	k.push_back(v[i]);
	//     }
	//     k.push_back(v.size());
	//     k.push_back(v.capacity());
    // }
    {
  	    ft::Vector<int> v;
        ft::Vector<int> k;
	    ft::Vector<int> tmp;
	    tmp.assign(26000000, 1);
	    v.assign(42000000, 7);
	    v.insert(v.begin(), tmp.begin(), tmp.end());
	    for (size_t i = 0; i < tmp.size(); ++i) {
	    	k.push_back(v[i]);
	    }
	    k.push_back(v.size());
	    k.push_back(v.capacity());
        
    }
}