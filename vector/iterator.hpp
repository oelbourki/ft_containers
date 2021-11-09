/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:07:48 by oel-bour          #+#    #+#             */
/*   Updated: 2021/11/07 10:55:14 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

namespace ft{
    template<class T>
    	class iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		private:
			T* z;
		public:
		typedef ptrdiff_t difference_type;
		typedef T value_type;
        typedef typename std::iterator<std::random_access_iterator_tag, T>::reference reference;
        typedef typename std::iterator<std::random_access_iterator_tag, T>::pointer   pointer;
		iterator(T* init):z(init){
		}
		iterator():z(NULL){}
		iterator(iterator &t):z(t.z){}

		~iterator(){}
		operator iterator<const T>() const{ return iterator<const T>(z);}
        iterator(iterator const& rit){ 
            *this = rit;
         }
		iterator base(void) { iterator tmp = z;return tmp; }
		bool 			operator != (const iterator &v){return this->z != v.z;}
		bool 			operator== (const iterator &v){return this->z == v.z;}
					   
		bool 			operator>(const iterator &v){
			return this->z > v.z;}
		bool 			operator>=(const iterator &v){return this->z >= v.z;}
		bool 			operator<(const iterator &v){return this->z < v.z;}
		bool 			operator<=(const iterator &v){return this->z <= v.z;}
		difference_type 		operator-(const iterator &v){
			 return (this->z - v.z);}
		iterator 		operator-(size_t v)const {iterator tmp(*this); tmp.z -= v; return tmp;}
		iterator 		operator+(size_t v) const {iterator tmp(*this); tmp.z += v; return tmp;}
		iterator 		&operator++(){this->z++;return *this;}
		iterator 		&operator--(){(this->z)--;return *this;}
		iterator 		operator--(int){iterator tmp = *this;(this->z)--;return tmp;}
		iterator		operator++(int) {iterator tmp = *this;this->z++;return tmp;}
		iterator& operator+=(const int& rhs){
			this->z += rhs;
			return *this;}
		iterator& operator-=(const int& rhs){
			this->z -= rhs;
			return *this;}
		reference	operator*(){
			return *z;};
		pointer			operator->(){return z;}
		reference operator[] (size_t n){return z[n];}
		friend iterator operator + (size_t l,const iterator& r)
		{
  			return r + l;   
		}
	iterator& operator =(const iterator& a)
        {
            this->z = a.z;
            return *this;
        }
	};

  template< class Iterator >
    class reverse_iterator
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
        reverse_iterator(const reverse_iterator<rit>& it)
        {
            this->z = --it.base();
        }
		reverse_iterator(Iterator init){
			z = --init;};//must work
        // operator
		reverse_iterator(){z = NULL;}
        reverse_iterator(reverse_iterator const& rit){ 
            *this = rit;
         }

        Iterator base(void) const{ Iterator tmp = z;return ++tmp; }
		reverse_iterator operator+ (difference_type n) const { return (reverse_iterator(base() - n)); }
		reverse_iterator operator- (difference_type n) const { return (reverse_iterator(base() + n)); }

        difference_type 		operator-(const reverse_iterator &v){return v.base() - base();}
		reverse_iterator 		&operator++(){this->z = --this->z;return *this;}
		reverse_iterator 		&operator--(){this->z = ++this->z;return *this;}
        reverse_iterator operator--(int) {reverse_iterator temp = *this;--(*this);return temp;}
        reverse_iterator operator++(int) {reverse_iterator temp = *this;++(*this);return temp;}
		reference	operator*(){return *z;};
		pointer			operator->(){return &(*z);}
        reverse_iterator& operator =(const reverse_iterator& a)
        {
            this->z = a.z;
            return *this;
        }
        reverse_iterator& operator+=(const int& rhs){
			this->z -= rhs;
			return *this;}
		reverse_iterator& operator-=(const int& rhs){
			this->z += rhs;
			return *this;}
		reference operator[] (size_t n){return *(z - n);}

	};
   template< class Iterator1, class Iterator2 >
  bool operator== (const reverse_iterator<Iterator1>& lhs,
                   const reverse_iterator<Iterator2>& rhs){
                   return lhs.base() == rhs.base();
                   }
template< class Iterator1, class Iterator2 >
  bool operator!= (const reverse_iterator<Iterator1>& lhs,
                   const reverse_iterator<Iterator2>& rhs){
                   return !(lhs == rhs);
                   }
template< class Iterator1, class Iterator2 >
  bool operator<  (const reverse_iterator<Iterator1>& lhs,
                   const reverse_iterator<Iterator2>& rhs){
                   return rhs.base() < lhs.base();
                   }
template< class Iterator1, class Iterator2 >
  bool operator<= (const reverse_iterator<Iterator1>& lhs,
                   const reverse_iterator<Iterator2>& rhs){
                   return !(rhs < lhs);
                   }
template< class Iterator1, class Iterator2 >
  bool operator>  (const reverse_iterator<Iterator1>& lhs,
                   const reverse_iterator<Iterator2>& rhs){
                   return (rhs < lhs);
                   }
template< class Iterator1, class Iterator2 >
  bool operator>= (const reverse_iterator<Iterator1>& lhs,
                   const reverse_iterator<Iterator2>& rhs){
                   return !(lhs < rhs);
                   }
template< class Iterator>
  typename reverse_iterator<Iterator>::difference_type operator- (
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs){
        return rhs.base() - lhs.base();
    }
    template< class Iterator >
  reverse_iterator<Iterator> operator+ (
             typename reverse_iterator<Iterator>::difference_type n,
             const reverse_iterator<Iterator>& rev_it){
                 return reverse_iterator<Iterator>(rev_it.base() - n);
             }
}