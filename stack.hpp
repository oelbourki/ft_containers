#pragma once 
#include "vector/vectorV2.hpp"
#include <iostream>
#include <stack>
#include <memory>
#include <deque>
#include <list>

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        private:
        Container c;
        public:
        typedef Container container_type;
        explicit stack (const container_type& ctnr = container_type()){
            c = ctnr;
        }
        typedef T value_type;
        typedef int size_type;
        bool empty() const{return  c.empty();}
        void pop(){c.pop_back();}
        void push (const value_type& val){c.push_back(val);}
        size_type size() const{return c.size();}
        value_type& top(){return c.back();}
        const value_type& top() const{return c.back();}
    
    bool operator== (const stack<T,Container>& rhs){
        return c == rhs.c;
    }
    bool operator!= (const stack<T,Container>& rhs){
        return c != rhs.c;
    }
    bool operator<  (const stack<T,Container>& rhs){
        return c < rhs.c;
    }
    bool operator<= (const stack<T,Container>& rhs){
        return c <= rhs.c;
    }
    bool operator>  (const stack<T,Container>& rhs){
        return c > rhs.c;
    }
    bool operator>= (const stack<T,Container>& rhs){
        return c >= rhs.c;
    }
    };


}