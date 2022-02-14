#pragma once

#include <iostream>
#include <string>
#include "../tools/tools.hpp"
#include "../tools/avl.hpp"
#include "bidirectional_iterator.hpp"
#include "../tools/reverse_itererator.hpp"


namespace ft {

    template < class Key,class T,class Compare = std::less<Key>,class Alloc = std::allocator<ft::pair <const Key, T> > >
    class Map{


        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef typename ft::pair< const Key, T> value_type;
            typedef typename ft::AVLtree<value_type,Compare, Alloc> tree;
            typedef Compare key_compare;
            // typede value_compare
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename ft::Node<value_type> node;
            typedef typename ft::bidirectional_iterator<value_type , node,tree, Compare> iterator;
            typedef typename ft::bidirectional_iterator<const value_type,node ,tree, Compare> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef  size_t size_type;

            /*-------------------------   CONSTRUCTORS   -----------------------------*/

            
            explicit Map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()):_avltree(), _compare(comp), _alloc(alloc){}
            template <class InputIterator>
            Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _avltree(), _compare(comp), _alloc(alloc){
                while(first != last)
                    _avltree.insert(*(first++));
            }
            Map (const Map& x) : _avltree(), _compare(x._compare), _alloc(x._alloc){
                *this = x;

            }

            /*-------------------------------------------------------------------------*/

            /*---------------------------   DESTRUCTOR   -------------------------------*/

            ~Map(){}

            /*-------------------------------------------------------------------------*/

            /*-----------------------  ASSIGNEMENT OPERATOR   --------------------------*/

            Map& operator= (const Map& x){
                _avltree = x._avltree;
                return *this;
            }

            /*-------------------------------------------------------------------------*/

            /*----------------------------   ITERATORS   -------------------------------*/

            iterator begin(){
                node *root = _avltree.minNode();
                return(iterator(root, &_avltree));
            }

            const_iterator begin() const{
                node *root = _avltree.minNode();
                return(iterator(root, &_avltree));
            }

            iterator end(){
                return(iterator(NULL, &_avltree));
            }

            const_iterator end() const{
                return(iterator(NULL, &_avltree));
            }

            reverse_iterator rbegin(){
                reverse_iterator rb(end());
                return (rb);
            }

            const_reverse_iterator rbegin() const{
                const_reverse_iterator rb(end());
                return (rb);
            }

            reverse_iterator rend(){
                reverse_iterator re(begin());
                return (re);
            }

            const_reverse_iterator rend() const{
                const_reverse_iterator re(begin());
                return (re);
            }
 
            /*-------------------------------------------------------------------------*/

            /*----------------------------   CAPACITY   -------------------------------*/

            bool empty() const{
                if (_avltree.getNodeCount()==0)
                    return true;
                return false;
            }
            size_type size() const{
                return (_avltree.getNodeCount());
            }
            size_type max_size() const{
                return (_alloc.max_size());
            }

            /*-------------------------------------------------------------------------*/

            /*---------------------------- ELEMENT ACCESS -------------------------------*/

            mapped_type& operator[] (const key_type& k){
                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());
                _avltree.insert(p);
                node *tmp = _avltree.findNode(_avltree.getRoot(), k);
                return (tmp->_value.second);
            }

            /*-------------------------------------------------------------------------*/

            /*----------------------------   MODIFIERS   -------------------------------*/

            ft::pair<iterator,bool> insert (const value_type& val){
                bool second = _avltree.insert(val);
                node *tmp = _avltree.findNode(_avltree.getRoot(), val.first);
                iterator first(tmp, &_avltree);
                ft::pair<iterator,bool> a(first, second);

                return (a);
            }
            iterator insert (iterator position, const value_type& val){
                (void)position;
                _avltree.insert(val);
                node *tmp = _avltree.findNode(_avltree.getRoot(), val.first);
                iterator first(tmp, &_avltree);
                return first;
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last){
                while(first != last)
                    _avltree.insert(*(first++));
            }
            void erase (iterator position){
                value_type val = *(position);
                _avltree.remove(val.first);
            }
            size_type erase (const key_type& k){
                return (_avltree.remove(k));
            }
            void erase (iterator first, iterator last){
                while (first != last){
                    _avltree.remove(first->first);
                    first++;
                }
            }
            // void swap (Map& x);
            // void clear();

            /*--------------------------------------------------------------------------*/

            /*----------------------------   OBSERVERS   -------------------------------*/
            
            // key_compare key_comp() const;
            // value_compare value_comp() const;

            /*--------------------------------------------------------------------------*/

            /*----------------------------   OPERATIONS  -------------------------------*/

            iterator find (const key_type& k){
                node *tmp = _avltree.findNode(_avltree.getRoot(), k);
                if (tmp != NULL)
                    return (iterator(tmp, &_avltree));
                return end();
            }
            const_iterator find (const key_type& k) const{
                node *tmp = _avltree.findNode(_avltree.getRoot(), k);
                if (tmp != NULL)
                    return (const_iterator(tmp, &_avltree));
                return end();
            }
            size_type count (const key_type& k) const{
                node *tmp = _avltree.findNode(_avltree.getRoot(), k);
                if (tmp == NULL)
                    return (0);
                return (1);
            }
            // iterator lower_bound (const key_type& k);
            // const_iterator lower_bound (const key_type& k) const;
            // iterator upper_bound (const key_type& k);
            // const_iterator upper_bound (const key_type& k) const;
            // ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
            // ft::pair<iterator,iterator>             equal_range (const key_type& k);

            /*--------------------------------------------------------------------------*/

            /*----------------------------   ALLOCATOR   -------------------------------*/

            allocator_type get_allocator() const{
                return (_avltree.get_allocator());
            }

            /*--------------------------------------------------------------------------*/
        private:
            tree _avltree;
            Compare _compare;
            Alloc _alloc;
    
    };

    /*---------------------   RELATION OPERATORS  ------------------------------*/

    // template <class Key, class T, class Compare, class Alloc>
    // bool operator== ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs );

    // template <class Key, class T, class Compare, class Alloc>
    // bool operator!= ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs );

    // template <class Key, class T, class Compare, class Alloc>
    // bool operator<  ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs );

    // template <class Key, class T, class Compare, class Alloc>
    // bool operator<= ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs );

    // template <class Key, class T, class Compare, class Alloc>
    // bool operator>  ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs );

    // template <class Key, class T, class Compare, class Alloc>
    // bool operator>= ( const Map<Key,T,Compare,Alloc>& lhs,const Map<Key,T,Compare,Alloc>& rhs );

    /*--------------------------------------------------------------------------*/

    // template <class Key, class T, class Compare, class Alloc>
    // void swap (Map<Key,T,Compare,Alloc>& x, Map<Key,T,Compare,Alloc>& y);


    
}