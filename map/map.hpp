#pragma once

#include <iostream>
#include <string>
#include "../tools/tools.hpp"
#include "../tools/avl.hpp"
#include "bidirectional_iterator.hpp"
#include "../tools/reverse_itererator.hpp"
#include "../vector/Vector.hpp"


namespace ft {

    template < class Key,class T,class Compare = std::less<Key>,class Alloc = std::allocator<ft::pair <const Key, T> > >
    class Map{


        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef typename ft::pair< const Key, T> value_type;
            typedef typename ft::AVLtree<value_type,Compare, Alloc> tree;
            typedef Compare key_compare;
            typedef class value_compare : public std::binary_function <value_type, value_type, bool>  
            {   
                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                        bool operator()(const value_type& left, const value_type& right) const{
                            return comp(left.first, right.first);
                        }
                        value_compare(key_compare c) : comp(c){}
                protected:
                    key_compare comp;   
            } value_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename ft::Node<value_type> node;
            typedef typename ft::bidirectional_iterator<value_type , node,tree, Compare> iterator;
            typedef typename ft::bidirectional_iterator<const value_type, const node ,const tree, Compare> const_iterator;
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
                _avltree = x._avltree;

            }

            /*-------------------------------------------------------------------------*/

            /*---------------------------   DESTRUCTOR   -------------------------------*/

            ~Map(){}

            /*-------------------------------------------------------------------------*/

            /*-----------------------  ASSIGNEMENT OPERATOR   --------------------------*/

            Map& operator= (const Map& x){
                _avltree = x._avltree;
                _compare  = x._compare;
                _alloc = x._alloc;
                return *this;
            }

            /*-------------------------------------------------------------------------*/

            /*----------------------------   ITERATORS   -------------------------------*/

            iterator begin(){
                node *tmp = _avltree.minNode();
                return(iterator( tmp, &_avltree));
            }

            const_iterator begin() const{
                node *tmp = _avltree.minNode();
                return(const_iterator( tmp, &_avltree));
            }

            iterator end(){
                return(iterator(NULL, &_avltree));
            }

            const_iterator end() const{
                return(const_iterator(NULL, &_avltree));
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
                if (_avltree._nodeCount==0)
                    return true;
                return false;
            }
            size_type size() const{
                return (_avltree._nodeCount);
            }
            size_type max_size() const{
                return (_alloc.max_size());
            }

            /*-------------------------------------------------------------------------*/

            /*---------------------------- ELEMENT ACCESS -------------------------------*/

            mapped_type& operator[] (const key_type& k){
                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());
                _avltree.insert(p);
                node *tmp = _avltree.search(_avltree._root, k);
                return (tmp->_value.second);
            }

            /*-------------------------------------------------------------------------*/

            /*----------------------------   MODIFIERS   -------------------------------*/

            ft::pair<iterator,bool> insert (const value_type& val){
                bool second = _avltree.insert(val);
                node *tmp = _avltree.search(_avltree._root, val.first);
                iterator first(tmp, &_avltree);
                ft::pair<iterator,bool> a(first, second);

                return (a);
            }

            
            iterator insert (iterator position, const value_type& val){
                (void)position;
                _avltree.insert(val);
                node *tmp = _avltree.search(_avltree._root, val.first);
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
                    ft::Vector<key_type> tmp;
                    while (first != last){
                        tmp.push_back(first->first);
                        first++;
                    }
                    for (typename ft::Vector<key_type>::iterator it = tmp.begin(); it != tmp.end(); it++){
                        _avltree.remove(*it);
                    }
            }


            void swap (Map& x){
                std::swap(_avltree._root, x._avltree._root);
                std::swap(_avltree._nodeCount, x._avltree._nodeCount);
                std::swap(_alloc,x._alloc);
                std::swap(_compare, x._compare);
            }


            void clear(){
                _avltree.clear();
            }

            /*--------------------------------------------------------------------------*/

            /*----------------------------   OBSERVERS   -------------------------------*/
            
            key_compare key_comp() const{
                return _compare;
            }
            value_compare value_comp() const{
                return (value_compare(_compare));
            }

            /*--------------------------------------------------------------------------*/

            /*----------------------------   OPERATIONS  -------------------------------*/

            iterator find (const key_type& k){
                node *tmp = _avltree.search(_avltree._root, k);
                if (tmp != NULL)
                    return (iterator(tmp, &_avltree));
                return end();
            }


            const_iterator find (const key_type& k) const{
                node *tmp = _avltree.search(_avltree._root, k);
                if (tmp != NULL)
                    return (const_iterator(tmp, &_avltree));
                return end();
            }


            size_type count (const key_type& k) const{
                node *tmp = _avltree.search(_avltree._root, k);
                if (tmp == NULL)
                    return (0);
                return (1);
            }

            
            iterator lower_bound (const key_type& k){
                if (_avltree.contains(k) == true){
                    node *tmp = _avltree.search(_avltree._root, k);
                    return iterator(tmp, &_avltree);
                }
                else 
                    return bound(k);
            }


            const_iterator lower_bound (const key_type& k) const{
                if (_avltree.contains(k) == true){
                    node *tmp = _avltree.search(_avltree._root, k);
                    return const_iterator(tmp, &_avltree);
                }
                else 
                    return (const_bound(k));
            }


            iterator upper_bound (const key_type& k){
                if (_avltree.contains(k) == true){
                    node *tmp = _avltree.search(_avltree._root, k);
                    iterator it(tmp, &_avltree);
                    return (++it);
                }
                else
                    return bound(k);     
            }


            const_iterator upper_bound (const key_type& k) const{
                if (_avltree.contains(k) == true){
                    node *tmp = _avltree.search(_avltree._root, k);
                    const_iterator it(tmp, &_avltree);
                    return (++it);
                }
                else
                    return const_bound(k);
            }


            ft::pair<iterator,iterator> equal_range (const key_type& k){
                ft::pair<iterator, iterator> p = ft::make_pair(lower_bound(k), upper_bound(k));
                return p;
            }
            ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
                const_iterator first = lower_bound(k);
                const_iterator second = upper_bound(k);
                ft::pair<const_iterator,const_iterator> p = ft::make_pair(first, second);
                return p;
            }

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

            iterator bound(const key_type &k){
                if (_compare(k, _avltree.minValue().first) == true){
                    return (iterator(_avltree.minNode(), &_avltree));
                }
                else if (_compare(_avltree.maxValue().first, k) == true)
                    return iterator(NULL, &_avltree);
                else {
                    iterator it = begin();
                    while (it != end()){
                        if (_compare(it->first, k) == true)
                            it++;
                        else
                            break;
                    }
                    return it;
                }
            }

            const_iterator const_bound(const key_type &k)const{
                if (_compare(k, _avltree.minValue().first) == true){
                    return begin();
                }
                else if (_compare(_avltree.maxValue().first, k) == true)
                    return const_iterator(NULL, &_avltree);
                else {
                    const_iterator it = begin();
                    while (it != end()){
                        if (_compare(it->first, k) == true)
                            it++;
                        else
                            break;
                    }
                    return it;
                }
            }
    
    };

    /*---------------------   RELATION OPERATORS  ------------------------------*/

    template <class Key, class T, class Compare, class Alloc>
    bool operator== ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ){
        if (lhs.size() != rhs.size())
                return(false);
        else
            return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator!= ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ){
        return (!(operator==(lhs, rhs)));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<  ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ){
        if (lhs.size() < rhs.size())
                return (true);
        else
            return(ft::lexicographical_compare(lhs.begin(),lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<= ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ){
        return (!(lhs>rhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>  ( const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs ){
        return (rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>= ( const Map<Key,T,Compare,Alloc>& lhs,const Map<Key,T,Compare,Alloc>& rhs ){
        return (!(lhs<rhs));
    }

    /*--------------------------------------------------------------------------*/

    template <class Key, class T, class Compare, class Alloc>
    void swap (Map<Key,T,Compare,Alloc>& x, Map<Key,T,Compare,Alloc>& y){
        x.swap(y);
    }


    
}