#pragma once 

#include <iostream>
#include <stack>
#include <memory>
#include <deque>
#include "rbtVD2.hpp"
#include "../utils/pair.hpp"

namespace ft
{
    template < class Key,                                     // map::key_type
            class T,                                       // map::mapped_type
            class Compare = std::less<Key>,                     // map::key_compare
            class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
            >
    class map
    {

        private:
            RBT<ft::pair<const Key,T>,Compare,Alloc> r;
            Compare cmp;
            Alloc _allocator;
        public:
        typedef ft::pair<const Key,T> value_type;
        typedef typename RBT<value_type,Compare,Alloc>::iterator iterator;
        typedef typename RBT<value_type,Compare,Alloc>::const_iterator const_iterator;
        typedef typename RBT<value_type,Compare,Alloc>::reverse_iterator reverse_iterator;
        typedef typename RBT<value_type,Compare,Alloc>::const_reverse_iterator const_reverse_iterator;
        typedef RBT<value_type,Compare,Alloc> tree;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef size_t size_type;
        typedef Key key_type;
        typedef T mapped_type;
        explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()):cmp(comp),_allocator(alloc){}
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()){
                    this->insert(first,last);
                    _allocator = alloc;
                    cmp = comp;
            }
        map (const map& x)
        {
            *this = x;
        }
        map& operator= (const map& x){
            this->clear();
            this->insert(x.begin(),x.end());
            this->cmp = x.cmp;
            this->_allocator = x._allocator;
            return *this;
        }
        ~map(){
            clear();
        }
        //-------------
        const RBT<value_type,Compare,Alloc> &get_tree() const{
            return r;
        }
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
        size_type erase (const key_type& k){return r.erase(k);}
        void erase (iterator first, iterator last){
            // ft::vector<key_type> tmp;
            // for (iterator it=first; it!=last; ++it)
            //     tmp.push_back(it->first);
            // for (typename ft::vector<key_type>::iterator it=tmp.begin(); it!=tmp.end(); ++it)
            //     r.erase(*it);
            std::vector<key_type> tmp;
            for (iterator it=first; it!=last; ++it)
                tmp.push_back(it->first);
            for (typename std::vector<key_type>::iterator it=tmp.begin(); it!=tmp.end(); ++it)
                r.erase(*it);
        }
        //find
        iterator find (const key_type& k){return r.find(k);}
        const_iterator find (const key_type& k) const{return r.find(k);}
        //things
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const{return r.equal_range(k);}
        pair<iterator,iterator>             equal_range (const key_type& k){return r.equal_range(k);}
        key_compare key_comp() const{return this->cmp;}
        iterator lower_bound (const key_type& k){return r.lower_bound(k);}
        const_iterator lower_bound (const key_type& k) const{return r.lower_bound(k);}
        iterator upper_bound (const key_type& k){return r.upper_bound(k);}
        const_iterator upper_bound (const key_type& k) const{return r.upper_bound(k);}
        //others
        void clear()
        { 
            if (size() > 0)
                this->erase(begin(),end());
        }
        size_type count (const key_type& k) const{return r.count(k);}
        bool empty() const{return r.empty();}
        size_type max_size() const{return r.max_size();}
        mapped_type& operator[] (const key_type& k){return this->r[k];}
        size_type size() const{return r.size();}
        void swap (map& x){r.swap(x.r);

        }
        allocator_type get_allocator() const{return this->_allocator;}
        class value_compare
        {   
        friend class map;
        protected:
        Compare comp;
        value_compare (Compare c) : comp(c) {}  
        public:
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;
        bool operator() (const value_type& x, const value_type& y) const
        {
            return comp(x.first, y.first);
        }
        };
    value_compare value_comp() const{
        return value_compare(cmp);
    }

    };
        template< class Key, class T, class Compare, class Alloc >
        bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<ft::pair<const Key,T>,Compare,Alloc>&>(lhs.get_tree()) == const_cast<RBT<ft::pair<const Key,T>,Compare,Alloc>&>(rhs.get_tree());
                        }
        template< class Key, class T, class Compare, class Alloc >
        bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<ft::pair<const Key,T>,Compare,Alloc>&>(lhs.get_tree()) != const_cast<RBT<ft::pair<const Key,T>,Compare,Alloc>&>(rhs.get_tree());
                        }
        template< class Key, class T, class Compare, class Alloc >
        bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<ft::pair<const Key,T>,Compare,Alloc>&>(lhs.get_tree()) < const_cast<RBT<ft::pair<const Key,T>,Compare,Alloc>&>(rhs.get_tree());
                        }
        template< class Key, class T, class Compare, class Alloc >
        bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<ft::pair<const Key,T>,Compare,Alloc>&>(lhs.get_tree()) <= const_cast<RBT<ft::pair<const Key,T>,Compare,Alloc>&>(rhs.get_tree());
                        }
        template< class Key, class T, class Compare, class Alloc >
        bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<ft::pair<const Key,T>,Compare,Alloc>&>(lhs.get_tree()) > const_cast<RBT<ft::pair<const Key,T>,Compare,Alloc>&>(rhs.get_tree());
                        }
        template< class Key, class T, class Compare, class Alloc >
        bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<ft::pair<const Key,T>,Compare,Alloc>&>(lhs.get_tree()) >= const_cast<RBT<ft::pair<const Key,T>,Compare,Alloc>&>(rhs.get_tree());
                        }
                        template <class Key, class T, class Compare, class Alloc>
  void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y){
      x.swap(y);
  }
}
