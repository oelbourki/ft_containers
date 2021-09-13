#pragma once 

#include <iostream>
#include <stack>
#include <memory>
#include <deque>
namespace ft
{
    template <class T, class Container = std::deque<T> >
    class queue
    {
        private:
        Container c;
        public:
        typedef T value_type;
        typedef int size_type;
        bool empty() const{return  c.empty();}
        void pop(){c.pop_front();}
        void push (const value_type& val){c.push_back(val);}
        size_type size() const{return c.size();}
        value_type& top(){return c.front();}
        const value_type& top() const{return c.front();}
    };
}