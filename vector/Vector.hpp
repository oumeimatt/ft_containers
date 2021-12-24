#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
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

            explicit Vector (const allocator_type& alloc = allocator_type()):_arr(NULL), _alloc(alloc), _curr_size(0), _capacity(0){}
            explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _arr(NULL), _curr_size(0), _capacity(0){
                _arr = _alloc.allocate(n);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_arr + i, val);
                _curr_size = _capacity = n;
            }

            template <class InputIterator>
            Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :_alloc(alloc), _arr(NULL), _curr_size(0), _capacity(0){
                size_type diff = last - first;
                _arr = _alloc.allocate(diff);
                size_type i = 0;
                for (typename ft::Vector<T>::iterator it = first; it != last; it++){
                    _alloc.construct(_arr + i, *it);
                    i++;
                }
                _curr_size = _capacity = diff;
            }

            Vector (const Vector& x){
                *this = x;
            }

            /*---------------------------------------------------------------------------*/

            /*-----------------------   ASSIGNMENT OPERATOR  ----------------------------*/

            Vector& operator=(const Vector& x){
                // 
                for (size_type i =0; i < _curr_size; i++)
                    _alloc.destroy(_arr + i);
                _alloc.deallocate(_arr , _capacity);
                _arr = _alloc.allocate(x._capacity);
                _curr_size = x._curr_size;
                _capacity = x._curr_size;
                for (size_type i =0; i < _curr_size; i++)
                    _alloc.construct(_arr+i, x._arr[i]);
                return *this;
            }

            /*---------------------------------------------------------------------------*/

            /*-----------------------------  DESTRUCTOR  --------------------------------*/

            ~Vector(){
               for (size_type i = 0; i <_curr_size; i++)
                    _alloc.destroy(_arr + i);
                _alloc.deallocate(_arr, _capacity);
                _curr_size = 0;
                _capacity = 0;
            }

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

            void resize (size_type n, value_type val = value_type()){
                if (n > _capacity){
                    if (n > _capacity * 2)
                        reserve(n);
                    else
                        reserve(_capacity * 2);
                }
                if (n > _curr_size){
                    for (size_type i = _curr_size; i < n; i++){
                        _alloc.construct(_arr + i, val);
                    }
                }
                else if (n < _curr_size){
                    for (size_type i = n; i < _curr_size; i++)
                        _alloc.destroy(_arr+i);
                }
                _curr_size = n;
            }

            size_type capacity() const{
                return _capacity;
            }

            bool empty() const{
                if (_curr_size == 0)
                    return(1);
                return(0);
            }

            void reserve (size_type n){
                if (n > max_size())
                    throw std::length_error("length error");
                if (n > _capacity){
                    T* tmp = _alloc.allocate(n);
                    for (size_t i = 0; i < _curr_size; i++){
                        _alloc.construct(tmp+i, _arr[i]);
                        _alloc.destroy(_arr+i);
                    }
                    _alloc.deallocate(_arr, _capacity);
                    _arr = tmp;
                    _capacity = n;
                }
            }

            /*---------------------------------------------------------------------------*/

            /*---------------------------  ELEMENT ACCESS  ------------------------------*/

            reference operator[] (size_type n){
                if (n < 0 || n >= _curr_size)
                    throw std::out_of_range("out of range");
                return _arr[n];
            }

            const_reference operator[] (size_type n) const{
                if (n < 0 || n >= _curr_size)
                    throw std::out_of_range("out of range");
                return _arr[n];
            }

            reference at(size_type n){
                if (n < 0 || n >= _curr_size)
                    throw std::out_of_range("out of range");
                else
                    return (_arr[n]);
            }

            const_reference at (size_type n) const{
                if (n < 0 || n >= _curr_size)
                    throw std::out_of_range("out of range");
                else
                    return (_arr[n]);
            }

            reference front(){
                return _arr[0];
            }

            const_reference front() const{
                return  _arr[0];
            }

            reference back(){
                return _arr[_curr_size - 1];
            }

            const_reference back() const{
                return _arr[_curr_size - 1];
            }

            /*---------------------------------------------------------------------------*/

            /*-----------------------------   MODIFIERS  --------------------------------*/

            // template <class InputIterator>
            // void assign (InputIterator first, InputIterator last){

            // }
            void assign (size_type n, const value_type& val){
                if (n > _capacity)
                    reserve(n);
                _curr_size = n;
                for (size_t i = 0; i < _curr_size; i++){
                    _alloc.destroy(_arr + i);
                    _alloc.construct(_arr + i, val);
                }
            }

            void push_back (const value_type& val){
                if (_capacity == 0){
                    _capacity++;
                    _arr = _alloc.allocate(2);
                    _alloc.construct(_arr, val);
                }
                else if (_curr_size +1 > _capacity)
                    reserve(_capacity * 2);
                _alloc.construct(_arr + _curr_size, val);
                _curr_size++;
            }
            void pop_back(){
                _curr_size--;
                _alloc.destroy(_arr + _curr_size);
            }

            iterator insert (iterator position, const value_type& val){
                long distance = position - begin();
                if (_capacity == _curr_size)
                    reserve(2 * _capacity);
                for (long i = _curr_size; i > distance; i--)
                    _arr[i] = _arr[i - 1];
                _arr[distance] = val;
                _curr_size++;
                return position;
            }

            void insert (iterator position, size_type n, const value_type& val){
                size_type newCap;
                long pos = position - begin();
                if (_curr_size + n > _capacity){
                    newCap = 2 * _capacity;
                    if (_curr_size + n > newCap)
                        newCap = _curr_size + n;
                    reserve(newCap);
                }
                _curr_size+=n;
                for (unsigned long i = _curr_size - 1; i > pos + n - 1;i--)
                    _arr[i] = _arr[i - n];
                for (long i = pos + n -1; i > pos - 1; i--)
                    _arr[i] = val;
            }

            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last){
                size_type diff = last - first;
                size_type pos = position - begin();
                
                if (_curr_size + diff > _capacity){
                    if (_curr_size + diff > _capacity * 2)
                        reserve(_curr_size + diff);
                    else
                        reserve(_capacity * 2);
                }
                _curr_size += diff;
                for (size_type i = _curr_size - 1; i > pos + diff - 1; i--){
                    
                    _arr[i] = _arr[i - diff];
                    std::cout << _arr[i] << std::endl;
                }
                for (size_type i = pos + diff - 1; i > pos -1; i--){
                    _arr[i] = *(last - i -1);
                }
            }
            iterator erase (iterator position){
                unsigned long i = position - begin();
                if (i < _curr_size){
                    _curr_size -= 1;
                    for (; i < _curr_size; i++){
                        _alloc.destroy(_arr+i);
                        _arr[i] = _arr[i + 1];
                    }
                    _alloc.destroy(_arr+i);
                }
                return position;
            }

            iterator erase (iterator first, iterator last){
                size_type oldSize = _curr_size;
                unsigned long i = first - begin();
                ptrdiff_t n = last - first;
                if (i < _curr_size){
                    _curr_size -= n;
                    for (; i < _curr_size; i++){
                        _alloc.destroy(_arr + i);
                        _alloc.construct(_arr + i, _arr[i + n]);
                    }
                    for (; i < oldSize; i++)
                        _alloc.destroy(_arr + i);
                }
                return first;
            }

            void swap (Vector& x){
                std::swap(_capacity, x._capacity);
                std::swap(_curr_size, x._curr_size);
                std::swap(_arr, x._arr);
            }

            void clear(){
                for (size_type i = 0; i <_curr_size ; i++)
                    _alloc.destroy(_arr+i);
                _curr_size = 0;
            }

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

        template <class T, class Alloc>
        void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
            x.swap(y);
        }
}
