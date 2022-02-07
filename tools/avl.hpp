#pragma once

#include <iostream>
#include<string>
#include <functional>
#include "tools.hpp"


namespace ft{
    template<class T>
    struct Node{
        int _bf;
        T _value;
        int _height;
        Node<T> *_left, *_right, *_parent;
        Node(T value) : _value(value){}
    };


    template <typename T>
    bool operator!=(const Node<T> &lhs, const Node<T> &rhs){
        return (!(lhs==rhs));
    }


    template <typename T>
    bool operator==(const Node<T> &lhs, const Node<T> &rhs){
        if (lhs._value == NULL && rhs._value == NULL)
            return (true);
        if (lhs._bf == rhs._bf && lhs._height == rhs._height &&
            lhs._value == rhs._value && lhs._left == rhs._left && lhs._right == rhs._right)
            return (true);
        return (false);
    }


    template<class T, class Compare = std::less<typename T::first_type> >
    class AVLtree
    {
        public:
            typedef typename T::first_type Key;
            typedef typename T::second_type value;
        private:
            Node<T> *_root;
            std::allocator< Node<T> > _alloc;
            std::allocator<T> _alloc2;
            int _nodeCount;
            Compare _compare;



            bool contains(Node<T> *node, Key key){
                if (node == NULL)
                    return false;
                bool cmp = _compare(key, node->_value.first);
                if (cmp == true)
                    return (contains(node->_left,  key));
                else
                    return(contains(node->_right, key));
                return (true);
            }
            void update_height(Node<T> *root){
                if (root != NULL) {
                          
                    // Store the height of the
                    // current node
                    int val = 1;

                    // Store the height of the left
                    // and right substree
                    if (root->_left != NULL)
                        val = root->_left->_height + 1;

                    if (root->_right != NULL)
                        val = std::max(
                            val, root->_right->_height + 1);

                    // Update the _height of the
                    // current node
                    root->_height = val;
                }
            }

            void update(Node<T> *node) {
                int leftNodeHeight = (node->_left == NULL) ? -1 : node->_left->_height;
                int rightNodeHeight = (node->_right == NULL) ? -1 : node->_right->_height;

                // update this node's height
                node->_height = 1 + std::max(leftNodeHeight, rightNodeHeight);
                // update balance factor
                node->_bf = rightNodeHeight - leftNodeHeight;
            }


            Node<T> *balance(Node<T> *node){
                // left heavy subtree
                // std::cout << "     " <<node->_bf << "     "  << std::endl;
                if (node->_bf == -2){
                    //left-left case 
                    // std::cout << "     " <<node->_bf << "     "  << std::endl;
                    if (node->_left->_bf <= 0)
                        return leftLeftCase(node);
                    //left-right case
                    else
                        return leftRightCase(node);
                }
                // right heavy subtree
                else if (node->_bf == 2){
                    //right-right case
                    if (node->_right->_bf >= 0)
                        return rightRightCase(node);
                    //right-left case
                    else
                        return rightLeftCase(node);
                }

                // node either has a balance factor of 0 , 1 or -1 which is fine
                return node;
            }


            Node<T>* leftLeftCase(Node<T>* node){
                return rightRotation(node);
            }


            Node<T>* leftRightCase(Node<T>* node) {
                node->_left = leftRotation(node->_left);
                return leftLeftCase(node);
            }


            Node<T>* rightRightCase(Node<T>* node) {
                return leftRotation(node);
            }


            Node<T>* rightLeftCase(Node<T>* node) {
                node->_right = rightRotation(node->_right);
                return rightRightCase(node);
            }


            Node<T>* leftRotation(Node<T>* node) {
                Node<T> *newParent = node->_right;
                node->_right = newParent->_left;
                if (newParent->_left != NULL)
                    newParent->_left->_parent = node;

                // Update the _left child of the
                // newParent to node
                newParent->_left = node;

                // Update parent pointer of
                // the newParent
                newParent->_parent = node->_parent;

                // Update the parent pointer
                // of the node
                node->_parent = newParent;

                // Update newParent as the _left or
                // the right child of its parent
                // pointer according to its key value
                if (newParent->_parent != NULL
                    && _compare(node->_value.first ,newParent->_parent->_value.first) == true) {
                    newParent->_parent->_left = newParent;
                }
                else {
                    if (newParent->_parent != NULL)
                        newParent->_parent->_right = newParent;
                }

                // Make newParent as the new node
                node = newParent;

                // Update the heights
                update_height(node->_left);
                update_height(node->_right);
                std::cout << "*/*/ herree */*/ " << std::endl;
                update_height(node->_parent);
                update(node);

                // Return the root node
                // return root;
                // newParent->_left = node;
                // update(node);
                // update(newParent);
                return node;
            }


            Node<T>* rightRotation(Node<T> *node){
                Node<T> *newParent = node->_left;
                node->_left = newParent->_right;
                //
                if (newParent->_right != NULL)
                    newParent->_right->_parent = node;
                //
                newParent->_right = node;
                //
                newParent->_parent = node->_parent;
                node->_parent = newParent;
                if (newParent->_parent != NULL && _compare(node->_value.first, newParent->_parent->_value.first) == true)
                    newParent->_parent->_left = newParent;
                else{
                    if (newParent->_parent != NULL)
                        newParent->_parent->_right = newParent;
                }
                node = newParent;
                //

                update_height(node->_left);
                update_height(node->_right);
                update_height(node->_parent);
                update(node);
                return node;
            }


            Node<T>* insert(Node<T>* node, Node<T> *parent, T val) {
                if (node == NULL){
                    Node<T> *root;
                    root = _alloc.allocate(1);
                    // root->_value = _alloc2.allocate(1);
                    _alloc2.construct(&root->_value, val);
                    root->_right = NULL;
                    root->_left = NULL;
                    root->_parent = parent;
                    root->_bf = root->_height = 0;
                    return root;
                }
                bool cmp = _compare(val.first, node->_value.first);
                if (cmp == true)
                    node->_left = insert(node->_left,node, val);
                else
                    node->_right = insert(node->_right, node, val);
                //update balance factor and height values
                update(node);
                // re-balance tree
                return (balance(node));
            }


            Node<T> *leftMost(Node<T> *root){
                while (root != NULL && root->_left != NULL)
                    root = root->_left;
                return root;
            }


            Node<T> *rightMost(Node<T> *root){
                while (root != NULL && root->_right != NULL)
                    root = root->_right;
                return root;
            }


        public:
            AVLtree(): _root(NULL), _nodeCount(0){}
            
            ~AVLtree(){}
            Node<T> * getRoot()const{
                return _root;
            }


            int height(){
                if (_root == NULL)
                    return (0);
                return (_root->_height);
            }


            int size(){
                return (_nodeCount);
            }


            bool isEmpty(){
                return (size() == 0);
            }


            bool contains(T value){
                return(contains(_root, value));
            }


            bool insert(T val){
                if (!contains(_root, val.first)) {
                    _root = insert(_root, NULL, val);
                    _nodeCount++;
                    return true;
                }
                return false;
            }


            T min(){
                return leftMost(_root)->_value;
            }

            
            Node<T> *minNode(){
                
                return leftMost(_root);
            }


            Node<T> *maxNode(){
                return rightMost(_root);
            }


            T max(){
                return rightMost(_root)->_value;
            }


            void	tree_debug(const std::string &prefix,
                    const Node<T>* node, bool isLeft){
                if(node != NULL)
                {
                    std::cout << prefix;
                    std::cout << (isLeft?"├──" : "└──");
                    std::cout << node->_value.first;
                    if (node->_parent != NULL)
                        std::cout << ":parent:" << node->_parent->_value.first;
                    std::cout << ":"  << std::endl;

                    tree_debug(prefix+(isLeft?"│   "
                                : "    "),
                            node->_left, true);
                    tree_debug(prefix+(isLeft?"│   "
                                : "    "),
                            node->_right, false);
                }
            }


            void	tree_debug(void){
                std::cout << std::endl;
                tree_debug("$", _root, false);
            }


    };
}
