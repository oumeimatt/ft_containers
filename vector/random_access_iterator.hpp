#pragma once


#include <iostream>
#include <string>
#include <iterator>
using namespace std;

namespace ft {
    template <typename T>
    class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
        public :
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;



            /*---------------------------   CONSTRUCTORS   ------------------------------*/

            random_access_iterator(pointer arr): p(arr){}
            random_access_iterator( void ): p(NULL){}
            random_access_iterator(const random_access_iterator<T> &src){
                *this = src;
            }
            /*---------------------------------------------------------------------------*/

            /*-----------------------   ASSIGNMENT OPERATOR  ----------------------------*/
            
            random_access_iterator &operator=(const random_access_iterator<T> & rhs){
                this->p = rhs.p;
                return *this;
            }

            /*---------------------------------------------------------------------------*/
            
            /*-----------------------------  DESTRUCTOR  --------------------------------*/

            ~random_access_iterator( void ){}

            /*---------------------------------------------------------------------------*/

            /*-------------------------------  GETTER   ---------------------------------*/

            pointer getP()const{
                return p;
            }

            /*---------------------------------------------------------------------------*/

            reference operator*()const{
                return *p;}

            reference operator->(){
                return (&(*p));}

            random_access_iterator & operator++(){
                p++;
                return *this;}

            random_access_iterator  operator++(int){
                random_access_iterator tmp(*this);
                ++(*this);
                return tmp;} 

            random_access_iterator & operator--(){ 
                p--;
                return *this;}
            
            random_access_iterator  operator--(int){ 
                random_access_iterator tmp(*this);
                --(*this);
                return tmp;}
            
            random_access_iterator operator+(int n){
                p += n;
                return *this;}
            
            random_access_iterator operator-(int n){
                p -= n;
                return *this;}
            
            reference operator[](int offset){
                p+= offset;
                return *p;}
            
            operator random_access_iterator<const T>()const{
                return random_access_iterator<const T>(p);}
            
        private :
            pointer p;
    };
    template<typename U>
    typename random_access_iterator<U>::difference_type operator-(const random_access_iterator<U> &lhs ,const random_access_iterator<U> &rhs){
        return lhs.getP() - rhs.getP();}
    
    template <typename U>
    bool operator==(const random_access_iterator<U> & lhs, const random_access_iterator<U> &rhs){
        return (*(lhs.getP()) == *(rhs.getP()));}

    template <typename U>
    bool operator!=(const random_access_iterator<U> & lhs, const random_access_iterator<U> & rhs){
        return (*(lhs.getP()) != *(rhs.getP()));}

    template <typename U>
    bool operator <(const random_access_iterator<U> & lhs, const random_access_iterator<U> & rhs){
        return (*(lhs.getP()) < *(rhs.getP()));}

    template <typename U>
    bool operator >(const random_access_iterator<U> & lhs, const random_access_iterator<U> & rhs){
        return (*(lhs.getP()) > *(rhs.getP()));}

    template <typename U>
    bool operator <=(const random_access_iterator<U> & lhs, const random_access_iterator<U> & rhs){
        return (*(lhs.getP()) <= *(rhs.getP()));}

    template <typename U>
    bool operator >=(const random_access_iterator<U> & lhs, const random_access_iterator<U> & rhs){
        return (*(lhs.getP()) >= *(rhs.getP()));}

}