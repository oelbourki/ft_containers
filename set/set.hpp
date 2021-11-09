/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:21:57 by oel-bour          #+#    #+#             */
/*   Updated: 2021/11/09 21:17:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <stack>
#include <memory>
#include <deque>
#include "rbtVS1.hpp"
#include "../utils/pair.hpp"

namespace ft
{
    template <                                     // set::T
            class T,                                       // set::T
            class Compare = std::less<T>,                     // set::key_compare
            class Alloc = std::allocator<T >    // set::allocator_type
            >
    class set
    {

        private:
            RBT<T,Compare,Alloc> r;
            Compare cmp;
            Alloc _allocator;
        public:
        typedef T value_type;
        typedef typename RBT<value_type,Compare,Alloc>::iterator iterator;
        typedef typename RBT<value_type,Compare,Alloc>::const_iterator const_iterator;
        typedef typename RBT<value_type,Compare,Alloc>::reverse_iterator reverse_iterator;
        typedef typename RBT<value_type,Compare,Alloc>::const_reverse_iterator const_reverse_iterator;
        typedef RBT<value_type,Compare,Alloc> tree;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef size_t size_type;
        explicit set (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()):cmp(comp),_allocator(alloc){}
        template <class InputIterator>
        set (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()){
                    this->insert(first,last);
                    _allocator = alloc;
                    cmp = comp;
            }
        set (const set& x)
        {
            *this = x;
        }
        set& operator= (const set& x){
            this->clear();
            this->insert(x.begin(),x.end());
            this->cmp = x.cmp;
            this->_allocator = x._allocator;
            return *this;
        }
        ~set(){
            clear();
        }
        //-------------
                 //---
        //iterators
        iterator begin(){return r.begin();}
        const_iterator begin() const{return r.begin();}
        iterator end(){return r.end();}
        const_iterator end() const{return r.end();}
        reverse_iterator rbegin(){return r.rbegin();}
        const_reverse_iterator rbegin() const{return r.rbegin();}
        reverse_iterator rend(){return r.rend();}
        const_reverse_iterator rend() const{return r.rend();}
        //insertion
         pair<iterator,bool> insert (const value_type& val){return r.insert(val);}
        iterator insert (iterator position, const value_type& val){return r.insert(position,val);}
        template <class InputIterator>
            void insert (InputIterator first, InputIterator last){return r.insert(first,last);}
        //erase
        void erase (iterator position){r.erase(position);}
        size_type erase (const T& k){return r.erase(k);}
        void erase (iterator first, iterator last){
            std::vector<T> tmp;
            int d = std::distance(first,last);
            for (iterator it=first; it!=last; ++it)
                 tmp.push_back(*it);
            for (int i = 0; i < d; ++i)
                r.erase(tmp[i]);
        }
        //find
        iterator find (const T& k){return r.find(k);}
        const_iterator find (const T& k) const{return r.find(k);}
        //things
        // pair<const_iterator,const_iterator> equal_range (const T& k) const{return r.equal_range(k);}
        pair<iterator,iterator>             equal_range (const T& k)const{return r.equal_range(k);}
        key_compare key_comp() const{return this->cmp;}
        iterator lower_bound (const T& k)const{return r.lower_bound(k);}
        // const_iterator lower_bound (const T& k) const{return r.lower_bound(k);}
        iterator upper_bound (const T& k)const{return r.upper_bound(k);}
        // const_iterator upper_bound (const T& k) const{return r.upper_bound(k);}
        //others
        void clear()
        { 
            if (size() > 0)
                this->erase(begin(),end());
        }
        size_type count (const T& k) const{return r.count(k);}
        bool empty() const{return r.empty();}
        size_type max_size() const{return r.max_size();}
        T& operator[] (const T& k){return this->r[k];}
        size_type size() const{return r.size();}
        void swap (set& x){r.swap(x.r);

        }
        allocator_type get_allocator() const{return this->_allocator;}
        typedef key_compare value_compare;
        // class value_compare : public std::binary_function<value_type,value_type,bool>
        // {   
        // public:
        // Compare comp;
        // value_compare (Compare c) : comp(c) {}  
        // public:
        // typedef bool result_type;
        // typedef value_type first_argument_type;
        // typedef value_type second_argument_type;
        // bool operator() (const value_type& x, const value_type& y) const
        // {
        //     return comp(x);
        // }
        // };
    value_compare value_comp() const{
        return this->cmp;
    }
 
        friend bool operator==( const ft::set<T,Compare,Alloc>& lhs,
                        const ft::set<T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<T,Compare,Alloc>&>(lhs.r) == const_cast<RBT<T,Compare,Alloc>&>(rhs.r);
                        }
        
        friend bool operator!=( const ft::set<T,Compare,Alloc>& lhs,
                        const ft::set<T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<T,Compare,Alloc>&>(lhs.r) != const_cast<RBT<T,Compare,Alloc>&>(rhs.r);
                        }
        
        friend bool operator<( const ft::set<T,Compare,Alloc>& lhs,
                        const ft::set<T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<T,Compare,Alloc>&>(lhs.r) < const_cast<RBT<T,Compare,Alloc>&>(rhs.r);
                        }
        
        friend bool operator<=( const ft::set<T,Compare,Alloc>& lhs,
                        const ft::set<T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<T,Compare,Alloc>&>(lhs.r) <= const_cast<RBT<T,Compare,Alloc>&>(rhs.r);
                        }
        
        friend bool operator>( const ft::set<T,Compare,Alloc>& lhs,
                        const ft::set<T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<T,Compare,Alloc>&>(lhs.r) > const_cast<RBT<T,Compare,Alloc>&>(rhs.r);
                        }
        
        friend bool operator>=( const ft::set<T,Compare,Alloc>& lhs,
                        const ft::set<T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<T,Compare,Alloc>&>(lhs.r) >= const_cast<RBT<T,Compare,Alloc>&>(rhs.r);
                        }
    };
                        template <class T, class Compare, class Alloc>
  void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y){
      x.swap(y);
  }
}
