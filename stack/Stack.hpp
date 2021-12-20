#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>
#include <vector>

namespace ft {
    template <class T, class Container = std::vector<T> >
    class Stack
    {
        public:
            typedef Container container_type;
            typedef T value_type;
            typedef size_t size_type;
            typedef typename container_type::iterator iterator;

            explicit Stack (const container_type& ctnr = container_type()) : c(ctnr){};
            ~Stack(){};
            bool empty() const{
                return this->c.empty();
            }
            size_type size() const{
                return this->c.size();
            }
            value_type& top(){
                return this->c[c.size() -1];
            }
            const value_type& top() const{
                return this->c[c.size() -1];
            }
            void push (const value_type& val){
                iterator it = this->c.end();
                this->c.insert(it, val);
            }
            void pop(){
                iterator it = this->c.end() - 1;
                this->c.erase(it);
            }
            template <class U, class Cont>
            friend bool operator==(const Stack<U,Cont>& lhs, const Stack<U,Cont>& rhs);

            template <class U, class Cont>
            friend bool operator!=(const Stack<U,Cont>& lhs, const Stack<U,Cont>& rhs);

            template <class U, class Cont>
            friend bool operator<(const Stack<U,Cont>& lhs, const Stack<U,Cont>& rhs);

            template <class U, class Cont>
            friend bool operator<=(const Stack<U,Cont>& lhs, const Stack<U,Cont>& rhs);

            template <class U, class Cont>
            friend bool operator>(const Stack<U,Cont>& lhs, const Stack<U,Cont>& rhs);

            template <class U, class Cont>
            friend bool operator>=(const Stack<U,Cont>& lhs, const Stack<U,Cont>& rhs);
        protected:
            container_type  c;
    };
    
    template <class T, class Container>
    bool operator==(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
        return (lhs.c == rhs.c);
    }

    template <class T, class Container>
    bool operator!=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
        return (lhs.c != rhs.c);
    }


    template <class T, class Container>
    bool operator<(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
        return (lhs.c < rhs.c);
    }

    template <class T, class Container>
    bool operator<=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
        return (lhs.c <= rhs.c);
    }

    template <class T, class Container>
    bool operator>(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
        return (lhs.c > rhs.c);
    }

    template <class T, class Container>
    bool operator>=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
        return (lhs.c >= rhs.c);
    }
}
#endif