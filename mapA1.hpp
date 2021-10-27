#pragma once 

#include <iostream>
#include <stack>
#include <memory>
#include <deque>
#include "rbtV5.hpp"
#include "pair.hpp"

namespace ft
{
    template < class Key,                                     // map::key_type
            class T,                                       // map::mapped_type
            class Compare = std::less<Key>,                     // map::key_compare
            class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
            >
    class map
    {
        private:
            RBT<Key, T,Compare,Alloc> r;
            Compare cmp;
        public:
        typedef typename RBT<Key,T,Compare,Alloc>::iterator iterator;
        typedef typename RBT<Key,T,Compare,Alloc>::const_iterator const_iterator;
        // typedef typename RBT<Key,T,Compare,Alloc>::reverse_iterator reverse_iterator;
        // typedef typename RBT<Key,T,Compare,Alloc>::const_reverse_iterator const_reverse_iterator;
        typedef pair<const Key, T> value_type;
        typedef RBT<Key, T,Compare,Alloc> tree;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef size_t size_type;
        typedef Key key_type;
        typedef T mapped_type;
        explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()){this->cmp = cmp;}
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()){

                    this->insert(first,last);
            }
        map (const map& x)
        {
            this->clear();
            this->root = x.root;
        }
        //-------------
        const RBT<Key, T,Compare,Alloc> &get_tree() const{
            return r;
        }
                 //---
        //iterators
        iterator begin(){return r.begin();}
        const_iterator begin() const{return r.begin();}
        iterator end(){return r.end();}
        const_iterator end() const{return r.end();}
        // reverse_iterator rbegin();
        // const_reverse_iterator rbegin() const;
        // reverse_iterator rend();
        // const_reverse_iterator rend() const;
        //insertion
         pair<iterator,bool> insert (const value_type& val){return r.insert(val);}
        iterator insert (iterator position, const value_type& val){return r.insert(position,val);}
        template <class InputIterator>
            void insert (InputIterator first, InputIterator last){return r.insert(first,last);}
        //erase
        void erase (iterator position){r.erase(position);}
        size_type erase (const key_type& k){return r.erase(k);}
        void erase (iterator first, iterator last){r.erase(first,last);}
        //find
        iterator find (const key_type& k){return r.find(k);}
        const_iterator find (const key_type& k) const{return r.find(k);}
        //things
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
        pair<iterator,iterator>             equal_range (const key_type& k);
        key_compare key_comp() const;
        iterator lower_bound (const key_type& k);
        const_iterator lower_bound (const key_type& k) const;
        iterator upper_bound (const key_type& k);
        const_iterator upper_bound (const key_type& k) const;
        //others
        void clear(){r.clear();}
        size_type count (const key_type& k) const{return r.count(k);}
        bool empty() const{return r.empty();}
        size_type max_size() const{r.max_size();}
        map& operator= (const map& x);
        mapped_type& operator[] (const key_type& k){return this->r[k];}
        size_type size() const{return r.size();}
        void swap (map& x){r.swap(x.get_tree());}
        
    };
        template< class Key, class T, class Compare, class Alloc >
        bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<Key, T,Compare,Alloc>&>(lhs.get_tree()) == const_cast<RBT<Key, T,Compare,Alloc>&>(rhs.get_tree());
                        }
        template< class Key, class T, class Compare, class Alloc >
        bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<Key, T,Compare,Alloc>&>(lhs.get_tree()) != const_cast<RBT<Key, T,Compare,Alloc>&>(rhs.get_tree());
                        }
        template< class Key, class T, class Compare, class Alloc >
        bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<Key, T,Compare,Alloc>&>(lhs.get_tree()) < const_cast<RBT<Key, T,Compare,Alloc>&>(rhs.get_tree());
                        }
        template< class Key, class T, class Compare, class Alloc >
        bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<Key, T,Compare,Alloc>&>(lhs.get_tree()) <= const_cast<RBT<Key, T,Compare,Alloc>&>(rhs.get_tree());
                        }
        template< class Key, class T, class Compare, class Alloc >
        bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<Key, T,Compare,Alloc>&>(lhs.get_tree()) > const_cast<RBT<Key, T,Compare,Alloc>&>(rhs.get_tree());
                        }
        template< class Key, class T, class Compare, class Alloc >
        bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
                        const ft::map<Key,T,Compare,Alloc>& rhs ){
                            return const_cast<RBT<Key, T,Compare,Alloc>&>(lhs.get_tree()) >= const_cast<RBT<Key, T,Compare,Alloc>&>(rhs.get_tree());
                        }
}