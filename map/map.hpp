#pragma once

#include <iostream>
#include <string>
#include "../tools/tools.hpp"
#include "../tools/avl.hpp"

namespace ft {

    template < class Key,class T,class Compare = std::less<Key>,class Alloc = std::allocator<ft::pair <const Key, T> > >
    class Map{
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef ft::pair<const Key, T> value_type;
            typedef Compare key_compare;
            // typede value_compare
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef ft::bidirectional_iterator<value_type> iterator;
            typedef ft::bidirectional_iterator<const value_type> const_iterator;
            typedef ptrdiff_t difference_type;
            typedef  size_t size_type;

            /*-------------------------   CONSTRUCTORS   -----------------------------*/

            explicit Map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()){}
            template <class InputIterator>
            Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){}
            Map (const Map& x){}

            /*-------------------------------------------------------------------------*/

            /*---------------------------   DESTRUCTOR   -------------------------------*/

            ~Map();

            /*-------------------------------------------------------------------------*/

            /*-----------------------  ASSIGNEMENT OPERATOR   --------------------------*/

            Map& operator= (const Map& x);

            /*-------------------------------------------------------------------------*/

            /*----------------------------   ITERATORS   -------------------------------*/

            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            // reverse_iterator rbegin();
            // const_reverse_iterator rbegin() const;
            // reverse_iterator rend();
            // const_reverse_iterator rend() const;

            /*-------------------------------------------------------------------------*/

            /*----------------------------   CAPACITY   -------------------------------*/

            bool empty() const;
            size_type size() const;
            size_type max_size() const;

            /*-------------------------------------------------------------------------*/

            /*---------------------------- ELEMENT ACCESS -------------------------------*/

            mapped_type& operator[] (const key_type& k);

            /*-------------------------------------------------------------------------*/

            /*----------------------------   MODIFIERS   -------------------------------*/

            ft::pair<iterator,bool> insert (const value_type& val);
            iterator insert (iterator position, const value_type& val);
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last);
            void erase (iterator position);
            size_type erase (const key_type& k);
            void erase (iterator first, iterator last);
            void swap (Map& x);
            void clear();

            /*--------------------------------------------------------------------------*/

            /*----------------------------   OBSERVERS   -------------------------------*/
            
            key_compare key_comp() const;
            // value_compare value_comp() const;

            /*--------------------------------------------------------------------------*/

            /*----------------------------   OPERATIONS  -------------------------------*/

            iterator find (const key_type& k);
            const_iterator find (const key_type& k) const;
            size_type count (const key_type& k) const;
            iterator lower_bound (const key_type& k);
            const_iterator lower_bound (const key_type& k) const;
            iterator upper_bound (const key_type& k);
            const_iterator upper_bound (const key_type& k) const;
            ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
            ft::pair<iterator,iterator>             equal_range (const key_type& k);

            /*--------------------------------------------------------------------------*/

            /*----------------------------   ALLOCATOR   -------------------------------*/

            allocator_type get_allocator() const;

            /*--------------------------------------------------------------------------*/
    };

    /*---------------------   RELATION OPERATORS  ------------------------------*/

    template <class Key, class T, class Compare, class Alloc>
    bool operator== ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs );

    template <class Key, class T, class Compare, class Alloc>
    bool operator!= ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs );

    template <class Key, class T, class Compare, class Alloc>
    bool operator<  ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs );

    template <class Key, class T, class Compare, class Alloc>
    bool operator<= ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs );

    template <class Key, class T, class Compare, class Alloc>
    bool operator>  ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs );

    template <class Key, class T, class Compare, class Alloc>
    bool operator>= ( const Map<Key,T,Compare,Alloc>& lhs,const Map<Key,T,Compare,Alloc>& rhs );

    /*--------------------------------------------------------------------------*/

    template <class Key, class T, class Compare, class Alloc>
    void swap (Map<Key,T,Compare,Alloc>& x, Map<Key,T,Compare,Alloc>& y);

    
}