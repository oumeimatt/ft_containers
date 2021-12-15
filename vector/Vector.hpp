#pragma once

#include <iostream>
#include <string>
#include "random_access_iterator.hpp"

namespace ft {

    template < class T, class Alloc = std::allocator<T> >
    class Vector
    {
        public:
            typedef T value_type;
            typedef  Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef ft::random_access_iterator<T> iterator;
            typedef ft::random_access_iterator<const T> const_iterator;
            typedef ptrdiff_t difference_type;
            typedef  size_t size_type;


            /*-------------------------   CONSTRUCTORS   -----------------------------*/

            explicit Vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), _curr_size(0), _capacity(0){}
            explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc){
                _arr = _alloc.allocate(n);
                for (size_type i= 0; i < n; i++)
                    _alloc.construct(_arr+i, val);
                _curr_size = n;
                _capacity = n;
            }
            // template <class InputIterator>
            // Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :_alloc(alloc){

            // }
            // Vector (const Vector& x){

            // }

            /*---------------------------------------------------------------------------*/

            /*-----------------------   ASSIGNMENT OPERATOR  ----------------------------*/

            // Vector& operator= (const Vector& x){}

            /*---------------------------------------------------------------------------*/

            /*-----------------------------  DESTRUCTOR  --------------------------------*/

            ~Vector(){}

            /*---------------------------------------------------------------------------*/

            /*-----------------------------   ITERATORS  --------------------------------*/

            iterator begin(){
                return iterator(_arr);
            }
            const_iterator begin() const{
                return iterator(_arr);
            }
            iterator end(){
                return iterator(_arr + _curr_size);
            }
            const_iterator end() const{
                return iterator(_arr + _curr_size);
            }
            // reverse_iterator rbegin(){}
            // const_reverse_iterator rbegin() const{}
            // reverse_iterator rend(){}
            // const_reverse_iterator rend() const{}

            /*---------------------------------------------------------------------------*/

            /*-------------------------------  CAPACITY  --------------------------------*/

            size_type size() const{
                return _curr_size;
            }
            size_type max_size() const{
                return _alloc.max_size();
            }
            // void resize (size_type n, value_type val = value_type()){}
            size_type capacity() const{
                return _capacity;
            }
            bool empty() const{
                return _curr_size > 0;
            }
            // void reserve (size_type n){}

            /*---------------------------------------------------------------------------*/

            /*---------------------------  ELEMENT ACCESS  ------------------------------*/

            // reference operator[] (size_type n){}
            // const_reference operator[] (size_type n) const{}
            // reference at (size_type n){}
            // const_reference at (size_type n) const{}
            // reference front(){}
            // const_reference front() const{}
            // reference back(){}
            // const_reference back() const{}

            /*---------------------------------------------------------------------------*/

            /*-----------------------------   MODIFIERS  --------------------------------*/

            // template <class InputIterator>
            // void assign (InputIterator first, InputIterator last){}
            // void assign (size_type n, const value_type& val){}
            // void push_back (const value_type& val){}
            // void pop_back(){}
            // iterator insert (iterator position, const value_type& val){}
            // void insert (iterator position, size_type n, const value_type& val){}
            // template <class InputIterator>
            // void insert (iterator position, InputIterator first, InputIterator last){}
            // iterator erase (iterator position){}
            // iterator erase (iterator first, iterator last){}
            // void swap (Vector& x){}
            // void clear(){}

            /*---------------------------------------------------------------------------*/

            /*-----------------------------   ALLOCATOR  --------------------------------*/

            allocator_type get_allocator() const{
                allocator_type tmp(_alloc);
                return tmp;
            }

            /*---------------------------------------------------------------------------*/
        private:
            T* _arr;
            allocator_type _alloc;
            size_type _curr_size;
            size_type _capacity;

        };
        /*--------------------   NON-MEMBER FUNCTION OVERLOADS -----------------------*/

        // template <class T, class Alloc>
        // bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){}

        // template <class T, class Alloc>
        // bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){}

        // template <class T, class Alloc>
        // bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){}

        // template <class T, class Alloc>
        // bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){}
	
        // template <class T, class Alloc>
        // bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){}

        // template <class T, class Alloc>
        // bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){}

        /*---------------------------------------------------------------------------*/
}
