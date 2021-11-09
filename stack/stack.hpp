/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:22:07 by oel-bour          #+#    #+#             */
/*   Updated: 2021/11/09 21:52:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include "../vector/vector.hpp"
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
        protected:
        Container c;
        public:
        typedef size_t size_type;
        typedef Container container_type;
        explicit stack (const container_type& ctnr = container_type()){
            c = ctnr;
        }
        typedef T value_type;
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