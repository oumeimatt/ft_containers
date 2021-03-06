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
            typedef typename T::first_type key_type;

            

            bidirectional_iterator( void ):_node(), _avltree(){}
            bidirectional_iterator( Node  *node, tree *avltree):_node(node), _avltree(avltree){}
            

            operator bidirectional_iterator<const T, const Node, const tree,Compare>()const{
                return (bidirectional_iterator<const T, const Node, const tree, Compare>(_node, _avltree));
            }


            bidirectional_iterator(const bidirectional_iterator<T, Node, tree, Compare> &src){
                *this = src;
            }


            ~bidirectional_iterator(){}

            bidirectional_iterator & operator=(const bidirectional_iterator<T, Node, tree, Compare> &rhs){
                this->_node = rhs._node;
                this->_compare = rhs._compare;
                this->_avltree = rhs._avltree;
                return *this;
            }

            T* operator->()const{
                return (&_node->_value);
            }

            T& operator*()const{
                return (_node->_value);
            }

            bidirectional_iterator &operator++(){
                
                if (_node == NULL)
                    _node = _avltree->minNode();
                else{
                    if (_node->_right != NULL){
                        _node = _node->_right;
                        while (_node->_left != NULL)
                            _node = _node->_left;
                    }
                    else {

                        Node * p = _node->_parent;
                        while(p != NULL && _node == p->_right){
                            _node = p;
                            p = p->_parent;
                        }
                        _node = p;
                    }
                }
                return *this;
            }

            bidirectional_iterator operator++(int){
                bidirectional_iterator tmp(*this);
                ++(*this);
                return tmp;
            }


            bidirectional_iterator &operator--(){
                if (_node == NULL)
                    _node = _avltree->maxNode();
                else if (_node->_left != NULL){
                    _node = _node->_left;
                    while (_node->_right != NULL)
                        _node = _node->_right;
                }
                else{
                    Node *p = _node->_parent;
                    while(p != NULL && _node == p->_left){
                        _node = p;
                        p = p->_parent;
                    }
                    _node = p;
                }
                return *this;
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
            friend bool operator==(const bidirectional_iterator<U, Node1, tree1, Compare1> & lhs, const bidirectional_iterator<U, Node1, tree1, Compare1>  &rhs);

            template <typename U, class Node1, class tree1, class Compare1>
            friend bool operator!=(const bidirectional_iterator<U, Node1, tree1, Compare1>  & lhs, const bidirectional_iterator<U, Node1, tree1, Compare1>  & rhs);
        private:
            Node *_node;
            tree const *_avltree;
            Compare _compare;

    };

    template <typename U, class Node1, class tree1, class Compare1>
    bool operator!=(const bidirectional_iterator<U, Node1, tree1, Compare1>  & lhs, const bidirectional_iterator<U, Node1, tree1, Compare1>  &rhs){
        return lhs._node != rhs._node;}

    template <typename U, class Node1, class tree1, class Compare1>
    bool operator==(const bidirectional_iterator<U, Node1, tree1, Compare1> & lhs, const bidirectional_iterator<U, Node1, tree1, Compare1>  &rhs){
        return (!(lhs._node != rhs._node));}
}
