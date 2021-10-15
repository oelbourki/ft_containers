#pragma once 

#include <iostream>
#include <stack>
#include <memory>
#include <deque>
#include "rbtV2.hpp"
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
        class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
        {
            friend class map<const Key,T>;
        };
        class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
        {
            friend class map<const Key,T>;
        };
        typedef std::reverse_iterator<iterator>
			reverse_iterator;
		typedef std::reverse_iterator<const_iterator>
			const_reverse_iterator;
        typedef ft::pair<const Key, T> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef size_t size_type;
        typedef Key key_type;
        typedef T mapped_type;
        private:
        avl<const Key, T,Compare> n;
        Compare cmp;
        public:
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
        iterator begin();//done
        const_iterator begin() const;
        void clear();
        size_type count (const key_type& k) const;
        bool empty() const;//done
        iterator end();//done
        const_iterator end() const;
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
        pair<iterator,iterator>             equal_range (const key_type& k);
        void erase (iterator position);
        size_type erase (const key_type& k);
        void erase (iterator first, iterator last);
        iterator find (const key_type& k);//done
        const_iterator find (const key_type& k) const;
        ft::pair<iterator,bool> insert (const value_type& val);
        iterator insert (iterator position, const value_type& val);
        template <class InputIterator>
            void insert (InputIterator first, InputIterator last);
        key_compare key_comp() const;
        iterator lower_bound (const key_type& k);
        const_iterator lower_bound (const key_type& k) const;
        size_type max_size() const;
        map& operator= (const map& x);
        mapped_type& operator[] (const key_type& k);
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;
        size_type size() const;//done
        void swap (map& x);
        iterator upper_bound (const key_type& k);
        const_iterator upper_bound (const key_type& k) const;
    };

}