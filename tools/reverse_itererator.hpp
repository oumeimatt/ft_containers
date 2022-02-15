#pragma once

#include "tools.hpp"

namespace ft{
    template <class Iterator> 
    class reverse_iterator{


        private:
            Iterator current;

        public :
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iterator>::value_type          value_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::pointer             pointer;
            typedef typename iterator_traits<Iterator>::reference           reference;



            reverse_iterator() : current(){}

            explicit reverse_iterator (iterator_type it){
                --it;
                current = it;

            }

            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it) : current(--rev_it.base()) {}

            iterator_type base() const { 
                iterator_type tmp = current;
                return ++tmp;
            }

            reference operator*() const{
                Iterator tmp = current;
                return (*tmp);
            }

            reverse_iterator operator+ (difference_type n) const{
                iterator_type tmp = current;
                return (reverse_iterator((tmp - (n-1))));
            }

            reverse_iterator& operator++(){
                --current;
                return *this;
            }

            reverse_iterator  operator++(int){
                
                reverse_iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            reverse_iterator& operator+= (difference_type n){
                current -= n;
                return *this;
            }

            reverse_iterator operator- (difference_type n) const{
                iterator_type tmp = current;
                return (reverse_iterator((tmp +( n + 1))));
            }

            reverse_iterator& operator--(){
                ++current;
                return *this;
            }

            reverse_iterator  operator--(int){
                reverse_iterator tmp = *this;
                --(*this);
                return tmp;
            }

            reverse_iterator& operator-= (difference_type n){
                current += n;
                return *this;
            }

            pointer operator->() const{
                return (&(operator*()));
            }

            reference operator[] (difference_type n) const{
                return (base()[-n - 1]);
            }


            template <class Iterator1>
            friend bool operator== (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs);

            template <class Iterator1>
            friend bool operator!= (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs);

            template <class Iterator1>
            friend bool operator<  (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs);


            template <class Iterator1>
            friend bool operator<= (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs);


            template <class Iterator1>
            friend bool operator>  (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs);


            template <class Iterator1>
            friend bool operator>= (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs);     

            template <class Iterator1>
            friend reverse_iterator<Iterator1> operator+ (typename reverse_iterator<Iterator1>::difference_type n,const reverse_iterator<Iterator1>& rev_it);    


            template <class Iterator1>
            friend typename reverse_iterator<Iterator1>::difference_type operator- (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs);

    };

    template <class Iterator1>
    bool operator== (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs){
        return (lhs.base() == rhs.base());
    }


    template <class Iterator1>
    bool operator!= (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs){
        return (lhs.base() != rhs.base());
    }


    template <class Iterator1>
    bool operator<  (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs){
        return (lhs.base() > rhs.base());
    }


    template <class Iterator1>
    bool operator<= (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs){
        return (lhs.base() >= rhs.base());
    }


    template <class Iterator1>
    bool operator>  (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs){
        return (lhs.base() < rhs.base());
    }


    template <class Iterator1>
    bool operator>= (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs){
        return (lhs.base() <= rhs.base());
    }  



    template <class Iterator1>
    reverse_iterator<Iterator1> operator+ (typename reverse_iterator<Iterator1>::difference_type n,const reverse_iterator<Iterator1>& rev_it){
        return (reverse_iterator<Iterator1> (rev_it.base() - n));
    } 


    template <class Iterator1>
    typename reverse_iterator<Iterator1>::difference_type operator- (const reverse_iterator<Iterator1>& lhs,const reverse_iterator<Iterator1>& rhs){
        return (rhs.base() - lhs.base());
    }


}
