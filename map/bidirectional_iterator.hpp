#pragma once 

#include <iostream>
#include <string>
#include "../tools/avl.hpp"

namespace ft {
    template <typename T, class Node, class tree, class Compare>
    class bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T>{
        public:
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            

            bidirectional_iterator( void ):_node(), _avltree(){}
            bidirectional_iterator(Node  *node, tree *avltree):_node(node), _avltree(avltree){}
            

            operator bidirectional_iterator<const T, Node, tree,Compare>()const{
                return bidirectional_iterator<const T, Node, tree, Compare>(_node, _avltree);
            }
            bidirectional_iterator(const bidirectional_iterator<T, Node, tree, Compare> &src){
                *this = src;
            }

            ~bidirectional_iterator(){}

            bidirectional_iterator & operator=(const bidirectional_iterator<T, Node, tree, Compare> &rhs){
                this->_node = rhs._node;
                this->_compare = rhs._compare;
                return *this;
            }

            T* operator->()const{
                return (&_node->_value);
            }

            T& operator*()const{
                return (*_node->_value);
            }

            bidirectional_iterator &operator++(){
                // _avltree->inorder(_node);
                _node = _avltree->inorder(_node);
                
                return *this;
            }

            bidirectional_iterator operator++(int){
                bidirectional_iterator tmp(*this);
                ++(*this);
                return tmp;
            }

            bidirectional_iterator &operator--(){

            }

            bidirectional_iterator operator--(int){
                bidirectional_iterator tmp(*this);
                --(*this);
                return tmp;
            }
            bidirectional_iterator begin(){
                bidirectional_iterator tmp(_avltree->minNode(), _avltree);
                return tmp;
            }
            template <typename U, class Node1, class tree1, class Compare1>
            friend bool operator==(const bidirectional_iterator<U, Node1, tree1, Compare1> & lhs, const bidirectional_iterator<U, Node, tree, Compare>  &rhs);

            template <typename U, class Node1, class tree1, class Compare1>
            friend bool operator!=(const bidirectional_iterator<U, Node1, tree1, Compare1>  & lhs, const bidirectional_iterator<U, Node, tree, Compare>  & rhs);
        private:
            Node  *_node;
            tree *_avltree;
            Compare _compare;

    };

    template <typename U, class Node1, class tree1, class Compare1>
    bool operator!=(const bidirectional_iterator<U, Node1, tree1, Compare1>  & lhs, const bidirectional_iterator<U, Node1, tree1, Compare1>  &rhs){
        return lhs._avltree != rhs._avltree;}

    template <typename U, class Node1, class tree1, class Compare1>
    bool operator==(const bidirectional_iterator<U, Node1, tree1, Compare1>  & lhs, const bidirectional_iterator<U, Node1, tree1, Compare1>  & rhs){
        return (!(lhs._node != rhs._node));}
}
