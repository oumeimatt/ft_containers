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
        Node<T> *_left, *_right;
        bool isThreaded;
        Node(T value) : _value(value){}
    };

    template<typename T>
    bool operator!=(const Node<T> &lhs, const Node<T> &rhs){
        if (lhs._bf == rhs._bf || lhs._height == rhs._bf || lhs.isThreaded == rhs._bf ||
            lhs._value == rhs._value)
            return false;
        return true;
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

            Node<T> *createThreaded(Node<T> *root){
                if (root == NULL)
                    return (NULL);
                if (root->_right == NULL && root->_left == NULL)
                    return (root);
                //find predecessor if exist 
                if (root->_left != NULL){
                    Node<T> *l = createThreaded(root->_left);
                    l->_right = root;
                    l->isThreaded = true;
                }
                if (root->_right == NULL)
                    return (root);
                return(createThreaded(root->_right));
            }


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
                newParent->_left = node;
                update(node);
                update(newParent);
                return newParent;
            }

            Node<T>* rightRotation(Node<T> *node){
                Node<T> *newParent = node->_left;
                node->_left = newParent->_right;
                newParent->_right = node;
                update(node);
                update(newParent);
                return newParent;
            }

            Node<T>* insert(Node<T>* node, T val) {
                if (node == NULL){
                    Node<T> *root;
                    root = _alloc.allocate(1);
                    // root->_value = _alloc2.allocate(1);
                    _alloc2.construct(&root->_value, val);
                    root->_right = NULL;
                    root->_left = NULL;
                    root->_bf = root->_height = 0;
                    return root;
                }
                bool cmp = _compare(val.first, node->_value.first);
                if (cmp == true)
                    node->_left = insert(node->_left, val);
                else
                    node->_right = insert(node->_right, val);
                //update balance factor and height values
                update(node);
                // re-balance tree
                return (balance(node));
            }


             void inorder2(Node<T> *t){
                if (t == NULL)
                    return ;
                inorder2(t->_left);
                std::cout << t->_value.first << " ";
                inorder2(t->_right);
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
            Node<T> * getroot(void)const{
                return _root;
            }
            bool contains(T value){
                return(contains(_root, value));
            }

            bool insert(T val){
                if (!contains(_root, val.first)) {
                    _root = insert(_root, val);
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
                    std::cout << node->_value.first << ":"  << std::endl;

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
            Node<T>* inorder(Node<T> *root){
                root = createThreaded(root);
                if (root == NULL)
                    return NULL;
                if (root->isThreaded){
                    root = root->_right;
                }
                else{
                    root = leftMost(root->_right);
                    // std::cout << "lala" << std::endl;
                }
                return root;
            }
            void inorder2(){
                inorder2(_root);
            }
    };
}
