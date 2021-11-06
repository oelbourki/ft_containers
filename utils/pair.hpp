/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:07:52 by oel-bour          #+#    #+#             */
/*   Updated: 2021/11/06 14:21:19 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
namespace ft
{
    template <class T1, class T2> struct pair
{
    public:
    typedef T1    key_type;
    typedef T2    mapped_type;
    key_type first;
    mapped_type second;

    pair():first(),second()
    {};
    template<class U, class V> 
    pair (const pair<U,V>& pr):first(pr.first),second(pr.second)
    {};
    pair (const key_type& a, const mapped_type& b):first(a),second(b)
    {};
    pair& operator= (const pair& pr)
    {
        if(this == &pr)
            return *this;
        this->first = pr.first;
        this->second = pr.second;
        return *this;
    }
};
template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }

template <class T1,class T2>
  ft::pair< T1,T2> make_pair (T1 x, T2 y)
  {
    return ( ft::pair< T1,T2>(x,y) );
  }

  template<class A>
  void swap(A& a,A& b){
      A tmp = a;
      a = b;
      b = tmp;
      }
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, BinaryPredicate pred){
                while (first1!=last1) {
    if (!pred(*first1,*first2))   // or: if (!pred(*first1,*first2)), for version 2
      return false;
    ++first1; ++first2;
  }
  return true;
              }
    template <class InputIterator1, class InputIterator2>
  bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
  while (first1!=last1) {
    if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
      return false;
    ++first1; ++first2;
  }
  return true;
}
template <class InputIterator1, class InputIterator2, class Compare>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                Compare comp){
                   while (first1!=last1)
                  {
                      if (first2==last2 || comp(*first2,*first1)) return false;
                      else if (comp(*first1,*first2)) return true;
                      ++first1; ++first2;
                  }
                  return (first2!=last2);
                                }
    template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
    {
    while (first1!=last1)
    {
        if (first2==last2 || *first2<*first1) return false;
        else if (*first1<*first2) return true;
        ++first1; ++first2;
    }
    return (first2!=last2);
    }

        template <class Iterator>
    class iterator_traits{
        public:
        	typedef typename Iterator::difference_type       difference_type;
        	typedef typename Iterator::value_type	        value_type;
        	typedef typename Iterator::pointer               pointer;
        	typedef typename Iterator::reference             reference;
        	typedef typename Iterator::iterator_category	    iterator_category;
    };
    template <class T>
    class iterator_traits<T*>{
         public:
        	typedef ptrdiff_t                           difference_type;
        	typedef T	                                value_type;
        	typedef T*                                  pointer;
        	typedef T&                                  reference;
        	typedef std::random_access_iterator_tag	    iterator_category;
    };
    template <class T>
    class iterator_traits<const T*>{
           public:
        	typedef ptrdiff_t                           difference_type;
        	typedef T	                                value_type;
        	typedef const T*                            pointer;
        	typedef const T&                            reference;
        	typedef std::random_access_iterator_tag	    iterator_category;
    };
  template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };
  template<typename>    struct is_integral {static const bool value = false;};
    template<>             struct is_integral<bool> {static const bool value = true;};
    template<>             struct is_integral<char> {static const bool value = true;};
    template<>             struct is_integral<signed char> {static const bool value = true;};
    template<>             struct is_integral<short int> {static const bool value = true;};
    template<>             struct is_integral<int> {static const bool value = true;};
    template<>             struct is_integral<long int> {static const bool value = true;};
    template<>             struct is_integral<long long int> {static const bool value = true;};
    template<>             struct is_integral<unsigned char> {static const bool value = true;};
    template<>             struct is_integral<unsigned short int> {static const bool value = true;};
    template<>             struct is_integral<unsigned int> {static const bool value = true;};
    template<>             struct is_integral<unsigned long int> {static const bool value = true;};
    template<>             struct is_integral<unsigned long long int> {static const bool value = true;};
  template< class Iterator >
    class reverse_iterator_tree
	{
		private:
			Iterator z;
		public:
        typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type	 value_type	;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;
        template<typename rit>
        reverse_iterator_tree(const reverse_iterator_tree<rit>& it)
        {
          this->z = --it.base();
        }
		reverse_iterator_tree(Iterator init){
      z = --init;};//must work
		reverse_iterator_tree(){z = NULL;}
        reverse_iterator_tree(reverse_iterator_tree const& rit){ 
            *this = rit;
         }

        Iterator base(void) const { 
          Iterator tmp = z;return ++tmp; }
        difference_type 		operator-(const reverse_iterator_tree &v){ return (z - v.z);}
		reverse_iterator_tree 		&operator++(){this->z = --this->z;return *this;}
		reverse_iterator_tree 		&operator--(){this->z = ++this->z;return *this;}
        reverse_iterator_tree operator--(int) {reverse_iterator_tree temp = *this;--(*this);return temp;}
        reverse_iterator_tree operator++(int) {reverse_iterator_tree temp = *this;++(*this);return temp;}
        reverse_iterator_tree 		operator-(int v){return reverse_iterator_tree (z + v);}
		reverse_iterator_tree 		operator+(int v){return reverse_iterator_tree (z - v);}
		reference	operator*() const {return *z;};
		pointer			operator->() const {return &(operator*());}
        reverse_iterator_tree& operator =(const reverse_iterator_tree& a)
        {
            this->z = a.z;
            return *this;
        }
        reverse_iterator_tree& operator+=(const int& rhs){
			this->z -= rhs;
			return *this;}
		reverse_iterator_tree& operator-=(const int& rhs){
			this->z += rhs;
			return *this;}
		reference operator[] (size_t n){return z[n];}

	};
    template <class Iterator>
  bool operator== (const reverse_iterator_tree<Iterator>& lhs,
                   const reverse_iterator_tree<Iterator>& rhs){
                   return lhs.base() == rhs.base();
                   }
template <class Iterator>
  bool operator!= (const reverse_iterator_tree<Iterator>& lhs,
                   const reverse_iterator_tree<Iterator>& rhs){
                   return !(lhs == rhs);
                   }
template <class Iterator>
  bool operator<  (const reverse_iterator_tree<Iterator>& lhs,
                   const reverse_iterator_tree<Iterator>& rhs){
                   return rhs.base() < lhs.base();
                   }
template <class Iterator>
  bool operator<= (const reverse_iterator_tree<Iterator>& lhs,
                   const reverse_iterator_tree<Iterator>& rhs){
                   return !(rhs < lhs);;
                   }
template <class Iterator>
  bool operator>  (const reverse_iterator_tree<Iterator>& lhs,
                   const reverse_iterator_tree<Iterator>& rhs){
                   return (rhs < lhs);
                   }
template <class Iterator>
  bool operator>= (const reverse_iterator_tree<Iterator>& lhs,
                   const reverse_iterator_tree<Iterator>& rhs){
                   return !(lhs < rhs);
                   }
template <class Iterator>
  typename reverse_iterator_tree<Iterator>::difference_type operator- (
    const reverse_iterator_tree<Iterator>& lhs,
    const reverse_iterator_tree<Iterator>& rhs){
        return rhs.base() - lhs.base();
    }
    template <class Iterator>
  reverse_iterator_tree<Iterator> operator+ (
             typename reverse_iterator_tree<Iterator>::difference_type n,
             const reverse_iterator_tree<Iterator>& rev_it){
                 return reverse_iterator_tree<Iterator>(rev_it.base() - n);
             }
}