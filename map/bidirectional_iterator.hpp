#pragma once 

#include <iostream>
#include <string>

namespace ft {
    template <typename T>
    class bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T>{
        public:
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            bidirectional_iterator( void ){}
            bidirectional_iterator(const bidirectional_iterator<T> & src){}
            bidirectional_iterator &operator=(const bidirectional_iterator<T> & rhs){}
            reference operator*()const{}
            
            

    };
}