#pragma once 

#include <iostream>
#include <stack>
#include <memory>
#include <deque>
#include <algorithm>
#include "map_list.hpp"
namespace ft
{
    // template <class Key, class T, class Compare, class Alloc>
// class map<Key,T,Compare,Alloc>::value_compare
// {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
//   friend class map;
// protected:
//   Compare comp;
//   value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
// public:
//   typedef bool result_type;
//   typedef value_type first_argument_type;
//   typedef value_type second_argument_type;
//   bool operator() (const value_type& x, const value_type& y) const
//   {
//     return comp(x.first, y.first);
//   }
// };

    template < class Key,                                     // map::key_type
            class T,                                       // map::mapped_type
            class Compare = std::less<Key>,                     // map::key_compare
            class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
            >
    class map
    {
                typedef std::pair<Key, T> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef size_t size_type;
        typedef Key key_type;
        typedef T mapped_type;
        class value_compare
{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
  friend class map;
protected:
  Compare comp;
  value_compare(){}
  value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
public:
  typedef bool result_type;
  typedef value_type first_argument_type;
  typedef value_type second_argument_type;
  bool operator() (const value_type& x, const value_type& y) const
  {
    return comp(x.first, y.first);
  }
};
        // class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
        // {
        //     friend class map<const Key,T>;
        // };
        // class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
        // {
        //     friend class map<const Key,T>;
        // };
        // typedef std::reverse_iterator<iterator>
		// 	reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>
		// 	const_reverse_iterator;


        // class compare : public Compare
        // {
        //      template<class v>
        //     bool operator() (const v& lhs, const v& rhs) const
        //     {return lhs.first < rhs.first;}
        // };
        private:
        Compare cmp;
        value_compare comp;
        // value_compare (Compare c) : comp(c) {} 
        list<value_type,Compare> n;
        public:
        typedef typename ft::list<value_type,Compare>::iterator iterator;
        typedef typename ft::list<value_type,Compare>::const_iterator const_iterator;
        typedef typename ft::list<value_type,Compare>::reverse_iterator reverse_iterator;
        typedef typename ft::list<value_type,Compare>::const_reverse_iterator const_reverse_iterator;
        typedef typename ft::list<value_type,Compare>::Node Node;
        explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()){this->n.set_cmp(comp);this->cmp = comp;this->comp = value_compare(comp);}
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()){
            this->cmp = comp;
            this->comp = value_compare(comp);
            this->n.set_cmp(comp);
            this->n.insert(first,last);
           
            }
        map (const map& x)
        {
            this->n.clear();
            this->n = x.n;
            this->cmp = x.cmp;
            this->comp = x.comp;
        }
        iterator begin() {
            return this->n.begin();}//done
        const_iterator begin() const{return this->n.begin();}//done
        void clear(){return this->n.clear();}//done
        size_type count (const key_type& k){
            // iterator iter;
            // int c = 0;
            // for (iter = const_cathis->begin(); iter != this->end(); iter++)
            // {
            //    if (iter->first == k)
            //     c++;
            // }
            // return c;
            value_type p(k,mapped_type());
            return this->n.count(p);
            ;}//done
        bool empty() const{return this->n.empty();}//done
        iterator end(){return this->n.end();}//done
        const_iterator end() const{return this->n.end();}//done
        std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const//done
        {
            value_type x(k,mapped_type());
            iterator low = ft::lower_bound(this->begin(),this->end(),x);
             iterator l = low;
             l++;
            iterator up = ft::upper_bound(l,this->end(),x);
            std::pair<iterator,iterator> f(low,up);
            return f;
        }
        std::pair<iterator,iterator>             equal_range (const key_type& k)//done
        {
            value_type x(k,mapped_type());
            // std::pair<char,int> p1(k,mapped_type());
            //  std::cout <<"x>>>>>" <<x.first << std::endl;
            //  iterator iter1;
            //  for (iter1 = this->begin(); iter1 != this->end(); iter1++)
            //  {
            //      std::cout <<">>>" <<iter1->first << std::endl;
            //  }
            //  iterator l;
            std::cout << "+++++++++++++\n";
            iterator low = ft::lower_bound(this->begin(),this->end(),x);
            std::cout << "-*-* "<<x.first <<" "<< low->first << std::endl;
            iterator up = ft::upper_bound(this->begin(),this->end(),x);
             std::cout << "-*-* "<<x.first <<" "<< up->first << std::endl;
            // std::cout <<up->first << std::endl;
            std::pair<iterator,iterator> f(low,up);
            return f;
        }
        void erase (iterator position){this->n.erase(position);}//done
        size_type erase (const key_type& k){this->n.erase(k);}//done
        void erase (iterator first, iterator last){this->n.erase(first,last);}//done
        iterator find (const key_type& k)//done
        {
            std::pair<Key, T>  x(k,mapped_type());
            iterator iter = ft::lower_bound(this->begin(),this->end(),x);
            // iterator iter1 = ft::upper_bound(this->begin(),this->end(),x);
            // std::cout << "first "<< k << " "<< iter1->first << std::endl;
            if (iter->first == k)
                return iter;
            else 
                return this->end();
        }

        std::pair<iterator,bool> insert (const value_type& val){iterator iter = this->n.insert(this->begin(),val);
        std::pair<iterator,bool> x(iter,true);
        return x;}//done
        iterator insert (iterator position, const value_type& val){return this->n.insert(position,val);}//done
        template <class InputIterator>
            void insert (InputIterator first, InputIterator last){this->n.insert(first,last);}//done
        key_compare key_comp() const {return this->cmp;}
        iterator lower_bound (const key_type& k){value_type p(k,mapped_type());return ft::lower_bound(this->begin(),this->end(),p);}
        const_iterator lower_bound (const key_type& k) const{value_type p(k,mapped_type());return ft::lower_bound(this->begin(),this->end(),p);}
        size_type max_size() const{return this->n.max_size();}//done
        map& operator= (const map& x) {
            this->n = x.n;
            this->cmp = x.cmp;
            return *this;
        }//done
       value_type make_pair(key_type k,T m)
        {
            //  iterator iter =  this->find(k);
           value_type x(k,m);
            return x;
        }
        mapped_type& operator[] (const key_type& k)
        {
            // std::cout << mapped_type() << "\n";
            // value_type p(k,mapkeyped_type());
            // this->insert()
            //  puts("*****");
            iterator iter =  this->find(k);
            
            // puts("*****");
            if (iter == this->end())
            {
                // std::cout << "end \n";
                std::pair<iterator,bool> p = (this->insert(make_pair(k,mapped_type())));
                return (*(p).first).second;
            }
            else 
            {
                std::cout << "iter "<< iter->second <<  "\n";
                return iter->second;
            }
            // this->insert()
        }
        reverse_iterator rbegin(){return this->n.rbegin();}//done
        const_reverse_iterator rbegin() const{return this->n.rbegin();}//done
        reverse_iterator rend(){return this->n.rend();}//done
        const_reverse_iterator rend() const{return this->n.rend();}//done
        size_type size() const{return this->n.size();}//done
        void swap (map& x){this->n.swap(x.n);}//done
        iterator upper_bound (const key_type& k){value_type p(k,mapped_type());return ft::upper_bound(this->begin(),this->end(),p);}
        const_iterator upper_bound (const key_type& k) const{value_type p(k,mapped_type());return ft::upper_bound(this->begin(),this->end(),p);}
    value_compare value_comp() const{return this->comp;}

    };

}