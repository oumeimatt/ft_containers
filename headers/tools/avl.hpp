#pragma once

#include <iostream>
#include<string>
#include <functional>
#include "tools.hpp"


namespace ft{

    /*------------------------- NODE STRUCT ----------------------------------*/

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

    /*-------------------------------------------------------------------------*/


    /*-------------------------    AVLTREEE CLASS   ---------------------------*/

    template<class T, class Compare = std::less<typename T::first_type>, class Alloc = std::allocator<T> >
    class AVLtree
    {
        public:
            typedef typename T::first_type Key;
            typedef typename T::second_type value;
            typedef size_t size_type;
            typedef Alloc alloc_value;
            typedef typename Alloc::template rebind<Node<T> >::other alloc_node;


            Node<T> *_root;
            alloc_node _alloc;
            alloc_value _alloc2;
            size_type _nodeCount;
            Compare _compare;



            AVLtree(): _root(NULL), _nodeCount(0){}
            

            AVLtree(const AVLtree &x):_root(), _nodeCount(x._nodeCount){
                *this = x;
            }


            AVLtree & operator=(const AVLtree& x){
                clear();
                Node<T> *tmp = x._root;
                insertData(tmp);
                return *this;
            }



            ~AVLtree(){
                clear();
            }


            void clear(){
                destroyTree(_root);
                _nodeCount = 0;
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


            bool contains(Key k) const{
                return(contains(_root, k));
            }


            bool insert(T val){
                if (!contains(_root, val.first)) {
                    _root = insert(_root, NULL, val);
                    _nodeCount++;
                    return true;
                }
                return false;
            }


            bool remove(Key k){
                if (contains(_root, k) ){
                    _root = remove(_root, k);
                    _nodeCount--;
                    return true;
                }
                return false;
            }

    
            T minValue()const{
                return leftMost(_root)->_value;
            }

            
            Node<T> *minNode()const{
                return leftMost(_root);
            }


            T maxValue()const{
                return rightMost(_root)->_value;
            }


            Node<T> *maxNode()const{
                Node<T> * tmp = rightMost(_root);
                return (tmp);
            }


            Node<T> *search(Node<T> * root, Key key) const{
                if (root ==NULL){
                    return NULL;
                }
                if (root->_value.first == key)
                    return (root);
                else{
                    if (_compare(key, root->_value.first) == true)
                        return(search(root->_left, key));
                    else
                        return(search(root->_right, key));
                }

            }

            alloc_value get_allocator()const{
                return _alloc2;
            }

        private:

            bool contains(Node<T> *node, Key key) const{
                if (node == NULL)
                    return false;
                if (key == node->_value.first)
                    return true;
                if (_compare(key, node->_value.first) == true)
                    return (contains(node->_left,  key));
                else
                    return(contains(node->_right, key));
                return (true);
            }


            void update(Node<T> *root){
                if (root != NULL) {
                    int leftNodeHeight = (root->_left == NULL) ? -1 : root->_left->_height;
                    int rightNodeHeight = (root->_right == NULL) ? -1 : root->_right->_height;
                    root->_height = 1 + std::max(leftNodeHeight, rightNodeHeight);
                    root->_bf = rightNodeHeight - leftNodeHeight;
                }
            }


            Node<T> *balance(Node<T> *node){
                // left heavy subtree
                if (node->_bf == -2){
                    //left-left case 
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
                update(node->_left);
                update(node->_right);
                update(node->_parent);
                update(node);
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

                update(node->_left);
                update(node->_right);
                update(node->_parent);
                update(node);
                return node;
            }


            Node<T>* insert(Node<T>* node, Node<T> *parent, T val) {
                if (node == NULL){
                    Node<T> *root;
                    root = _alloc.allocate(1);
                    _alloc2.construct(&(root->_value), val);
                    root->_right = root->_left = NULL;
                    root->_bf = root->_height = 0;
                    root->_parent = parent;
                    return root;
                }
                bool cmp = _compare(val.first, node->_value.first);
                if (cmp == true)
                    node->_left = insert(node->_left, node, val);
                else
                    node->_right = insert(node->_right, node, val);
                //update balance factor and height values
                update(node);
                // re-balance tree
                return (balance(node));
            }


            Node<T> *remove(Node <T> * node, Key k){
                bool cmp = _compare(k, node->_value.first);
                if (k == node->_value.first){
                    if (node->_left == NULL && node->_right != NULL) {
                        if (node->_parent != NULL) {
                            if (_compare(node->_parent->_value.first, node->_value.first) == true)
                                node->_parent->_right = node->_right;
                            else
                                node->_parent->_left = node->_right;

                            // Update the height
                            // of the root's parent
                            update(node->_parent);
                        }
                        node->_right->_parent = node->_parent;

                        _alloc2.destroy(&(node->_value));
                        _alloc2.construct(&(node->_value),(node->_right->_value));
                        _alloc2.destroy(&(node->_right->_value));
                        _alloc.deallocate(node->_right, 1);
                        node->_right = NULL;
                    }

                    else if (node->_right == NULL && node->_left != NULL) {
                        if (node->_parent != NULL) {
                            if (_compare(node->_parent->_value.first, node->_value.first) ==true )
                                node->_parent->_right = node->_left;
                            else
                                node->_parent->_left = node->_left;
  
                            // Update the height
                            // of node's parent
                            update(node->_parent);
                        }
  
                        node->_left->_parent = node->_parent;
  
                        _alloc2.destroy(&(node->_value));
                        _alloc2.construct(&(node->_value),(node->_left->_value));
                        _alloc2.destroy(&(node->_left->_value));
                        _alloc.deallocate(node->_left, 1);
                        node->_left = NULL;
                    }

                    else if (node->_left == NULL && node->_right == NULL) {
                        if (node->_parent != NULL){
                            if (_compare(node->_parent->_value.first ,node->_value.first) == true) {
                                node->_parent->_right = NULL;
                            }
                            else {
                                node->_parent->_left = NULL;
                            }

                            update(node->_parent);
                        }
                        _alloc2.destroy(&(node->_value));
                        _alloc.deallocate(node, 1);
                        node = NULL;
                        return NULL;
                    }
                    else {
                            // swap the value of the successor into the node
                            T successorVal = rightMost(node->_left)->_value;
                            _alloc2.destroy(&node->_value);
                            _alloc2.construct(&(node->_value), successorVal);
                            // find the largest node inthe left subtree
                            node->_left = remove(node->_left, successorVal.first);
                    }
                }

                else if (cmp == true){
                    node->_left = remove(node->_left, k);
                }
                else{
                    node->_right = remove(node->_right, k);
                }
                update(node);
                return (balance(node));
                
            }


            Node<T> *leftMost(Node<T> *root)const{
                while (root != NULL && root->_left != NULL)
                    root = root->_left;
                return root;
            }


            Node<T> *rightMost(Node<T> *root)const{
                while (root != NULL && root->_right != NULL)
                    root = root->_right;
                return root;
            }


            void insertData(Node<T> *x){
                if (x != NULL){
                    insert(x->_value);
                    insertData(x->_left);
                    insertData(x->_right);
                }
            }


            void destroyTree(Node<T> * &node){
                if (node && node != NULL){
                    destroyTree(node->_right);
                    destroyTree(node->_left);
                    _alloc2.destroy(&node->_value);
                    _alloc.deallocate(node, 1);
                }
                node = NULL;
            }

    };

    /*-------------------------------------------------------------------------*/
}
