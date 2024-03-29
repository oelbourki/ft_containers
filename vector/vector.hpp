/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:07:45 by oel-bour          #+#    #+#             */
/*   Updated: 2021/11/14 10:58:11 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>
#include <iterator>
#include "../utils/pair.hpp"
#include "iterator.hpp"

namespace ft{

template < class T, class Alloc = std::allocator<T> >
class vector
{
	private:
		Alloc _allocator;
		void    expand();
		void    expand(size_t n);
		void	copy(T* *tmp, T* arr,size_t size);
		template <class InputIterator>
		int diff (InputIterator first, InputIterator last);//range
		T *_arr;
		size_t _size;
		size_t _index;
		size_t _capacity;

	public:
		template<class B>
			void	swap(B& a,B& b){
			B tmp = a;
			a = b;
			b = tmp;
		}
	//------------------member type---------------------
	typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef const typename allocator_type::const_reference	 const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef const typename allocator_type::const_pointer const_pointer;
		typedef size_t size_type;
		typedef ft::iterator<value_type> iterator; 
		typedef ft::iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator>
        reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>
			const_reverse_iterator;
	//---------------exceptions--------------------------
		class out_of_range : public std::logic_error {
		public:
		explicit out_of_range (const std::string& what_arg);
		};
	//--------------------iterators-----------------------------

	//--------------Constructors----------------------------------
		explicit vector (const allocator_type& alloc = allocator_type()):_allocator(alloc),_arr(0),_size(0),_index(0),_capacity(0)
		{
		}
		explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()){
							_allocator = alloc;
							this->_arr = _allocator.allocate(n);
							for(size_t i = 0;i < n;++i)
							{
								_allocator.construct(this->_arr + i,val);
							}
							this->_size = n;
							this->_index = n;
							this->_capacity = n;
						}
		template <class InputIterator>
				vector (InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* t = 0,

						const allocator_type& alloc = allocator_type()){
							int d = diff(first,last);
							if (d <= 0)
								return;
							this->_arr = _allocator.allocate(d);
							for(int i = 0;i < d;++i)
							{
								_allocator.construct(this->_arr + i,*(first + i));
							}
							this->_size = d;
							this->_index = d;
							this->_capacity = d;
							_allocator = alloc;
							t = 0;
						}
		vector (const vector& x):_allocator(x._allocator),_size(x._size),_index(x._index),_capacity(x._capacity)
		{
			this->_arr = _allocator.allocate(this->_size);
			for(size_t i = 0;i < this->_size;++i)
			{
				this->_allocator.construct(this->_arr + i,x._arr[i]);
			}
		}
	//--------------DeConstructors----------------------------------
		~vector(){
			for(size_t i = 0; i < this->_size;++i)
				this->_allocator.destroy(this->_arr + i);
			this->_allocator.deallocate(this->_arr,this->_capacity);
		}
	//--------------operator= copy------------------------------
		vector& operator= (const vector& x){
			this->_allocator.deallocate(this->_arr,this->_capacity);
			this->_capacity = x.capacity();
			this->_size = x.size();
			if (this->_capacity)
			{
			this->_index = 	this->_size;
			this->_arr = this->_allocator.allocate(this->_capacity);
			size_t i = 0;
			for (i = 0; i < x.size();++i)
				_allocator.construct(this->_arr + i,x[i]);
			}
			else 
				this->_arr = NULL;
			return *this;
		}
	//---------------Iterators---------------------
		iterator	begin(){return iterator(this->_arr);}
		const_iterator begin() const{return const_iterator(this->_arr);}
		iterator	end(){return iterator(this->_arr + this->_size);}
		const_iterator end() const{return const_iterator(this->_arr + this->_size);}
		reverse_iterator rbegin(){return reverse_iterator(end());}
		const_reverse_iterator rbegin() const{return const_reverse_iterator(end());}
		reverse_iterator rend(){return reverse_iterator(begin());}
		const_reverse_iterator rend() const{return const_reverse_iterator(begin());}
	//---------------ConstIterators---------------------
	//
	//
	//----------capacity------------------
		size_type size() const;
		size_type max_size() const;
		void resize (size_type n, value_type val = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve (size_type n);
	//-------------Element access-------------
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		reference at (size_type n);
		const_reference at (size_type n) const;
	//------------modifiers
		void push_back (const value_type& val);
		void pop_back();
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator());//range
		void assign (size_type n, const value_type& val);//fill
	//single element (1)	
		iterator insert (iterator position, const value_type& val);
	//fill (2)	
		void insert (iterator position, size_type n, const value_type& val){
			if (n == 1)
			{
				insert(position,val);
				return;
			}
			int d = position - begin();
			int tmpc = this->_capacity;
		if (this->_capacity * 2 > this->_size + n)//cap * 2
				tmpc *= 2;
		if ((this->_size + n) > this->_capacity)
		{
				if (this->_capacity == 0)
					tmpc = n;
				else if (this->_capacity * 2 < this->_size + n)
					tmpc = n + this->_size;
				T* tmp = this->_allocator.allocate(tmpc);
				if (tmp == NULL)
					std::cout << "NULL" << std::endl;
				for (int i = 0; i < d; i++)
					_allocator.construct(tmp + i,this->_arr[i]);
				for (size_t i = d; i < (n+d); i++)
					_allocator.construct(tmp + i,val);
				for (size_t i = d;i < this->_size; i++)
					_allocator.construct(tmp + i + n,this->_arr[i]);
				for(size_t i = 0; i < this->_size;i++)
						this->_allocator.destroy(this->_arr + i);
				this->_allocator.deallocate(this->_arr,this->_capacity);
				this->_arr = NULL;
				this->_arr = tmp;
				this->_size += n;
				this->_index += n;
				this->_capacity = tmpc;
				return ;
		}
		int start = 0;
		int size = this->_size;
		int nm = n;
		for(start = size + nm - 1;((start) >= size) && (start - nm) >= 0;--start)
		{
			_allocator.construct(this->_arr + start,this->_arr[start - nm]);
		}
		for (int i = d; i < int(n+d); i++)
					_allocator.construct(this->_arr + i,val);
		this->_size += n;
		this->_index += n;
		return ;
		}
	//range (3)	
	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){
 			int d = position - begin();
			int n = last - first;
			if ( n <= 0 || d < 0)
				return ;
		if (n == 1)
			{
				insert(position,*first);
				return;
			}
		int tmpc = this->_capacity;
		if (this->_capacity * 2 > this->_size + n)
				tmpc *= 2;
		if ((this->_size + n) > this->_capacity)
		{
				if (this->_capacity == 0)
					tmpc = n;
				else if (this->_capacity * 2 < this->_size + n)
					tmpc = n + this->_size;
				T* tmp = this->_allocator.allocate(tmpc);
				if (tmp == NULL)
					std::cout << "NULL" << std::endl;
				for (int i = 0; i < d; i++)
					_allocator.construct(tmp + i,this->_arr[i]);
				for (int i = d; i < (n+d); i++)
					_allocator.construct(tmp + i,*(first++));
				for (size_t i = d;i < this->_size; i++)
					_allocator.construct(tmp + i + n,this->_arr[i]);
					for(size_t i = 0; i < this->_size;i++)
						this->_allocator.destroy(this->_arr + i);
				this->_allocator.deallocate(this->_arr,this->_capacity);
				this->_arr = tmp;
				this->_size += n;
				this->_index += n;
				this->_capacity = tmpc;
				return ;
		}
		int start = 0;
		int size = this->_size;
		int nm = n;
				for(start = size + nm - 1;((start) >= size) && (start - nm) >= 0;--start)
				{
					_allocator.construct(this->_arr + start,this->_arr[start - nm]);
				}
		for (int i = d; i < (n+d); i++)
			_allocator.construct(this->_arr + i,*(first++));
		this->_size += n;
		this->_index += n;
		return ;
		}
	void clear();
	void swap (vector& x);
	iterator erase (iterator position);
	iterator erase (iterator first, iterator last);
	//-----
	allocator_type get_allocator() const{
		return this->_allocator;
	}
};
//--------
template <class T, class Alloc>
  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	  return (lhs.size() == rhs.size()) && ft::equal(lhs.begin(),lhs.end(),rhs.begin());
  }
template <class T, class Alloc>
  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	  return !(lhs == rhs);
  }
template <class T, class Alloc>
  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	  return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
  }
template <class T, class Alloc>
  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	  return (lhs < rhs) || (lhs == rhs);
  }
template <class T, class Alloc>
  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	  return !(lhs < rhs) && (lhs != rhs);
  }
template <class T, class Alloc>
  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	  return !(lhs < rhs);
  }

  template <class T, class Alloc>
  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
	  x.swap(y);
  }
///---------------private functions ----------
template < class T, class Alloc >
template <class InputIterator>
		int vector<T,Alloc>::diff (InputIterator first, InputIterator last)
		{
			int i = 0;
			while (first != last)
			{
				first++;
				i++;
			}
			return i;
		}
template < class T, class Alloc >
void	vector<T,Alloc>::expand()
{
	size_t t = this->_capacity ;
	if (this->_capacity == 0)
		this->_capacity = 1;
	this->_capacity *= 2;
	T* tmp = this->_allocator.allocate(this->_capacity);
	if (tmp == NULL)
		std::cout << "NULL" << std::endl;
	for (size_t i = 0; i < this->_size; i++)
	{
		this->_allocator.construct(tmp + i,this->_arr[i]);
	}
	this->_allocator.deallocate(this->_arr,t);
	this->_arr = tmp;
	this->_index = this->_size;
}
template < class T, class Alloc >
void	vector<T,Alloc>::expand(size_t n)
{
	pointer tmp = this->_allocator.allocate(n);
	if (tmp == NULL)
		std::cout << "NULL" << std::endl;
	for (size_t i = 0; i < this->_size && i < n; i++)
	{
		this->_allocator.construct(tmp + i,this->_arr[i]);
	}
	this->_allocator.deallocate(this->_arr,this->_capacity);
	this->_capacity = n;
	this->_arr = tmp;
}
///---------------Capacity---------------------
template < class T, class Alloc >
typename vector<T,Alloc>::size_type vector<T,Alloc>::size() const
{
	return this->_size;
}
template < class T, class Alloc >
typename vector<T,Alloc>::size_type vector<T,Alloc>::capacity() const
{
	return this->_capacity;
}
template < class T, class Alloc >
typename vector<T,Alloc>::size_type vector<T,Alloc>::max_size() const
{
	return this->_allocator.max_size();
}
template < class T, class Alloc >
bool vector<T,Alloc>::empty() const
{
	return (this->_size == 0);
}
template < class T, class Alloc >
void vector<T,Alloc>::reserve (size_type n)
{
	if (n > this->_capacity)
	{
		expand(n);
		this->_capacity = n;
	}
}
template < class T, class Alloc >
void vector<T,Alloc>::resize (size_type n, value_type val)
{
	if (n < this->_size)
	{
		for(size_t i = n; i < this->_size;++i)
			this->_allocator.destroy(this->_arr + i);
		this->_size = n;
		this->_index = n;
	}
	else if (n > this->_size && n <= this->_capacity)
	{
		for (int i = (int(this->_size) - 1); i < int(n) - 1; i++)
		{
			this->push_back(val);
		}
	}
	else if (n > this->_capacity)
	{
		if ((this->_capacity * 2) >= n)
		{
			expand();
			for (size_t i = this->_index; i < n; i++)
			{
				this->push_back(val);
			}
		}
		else
		{
			expand(n);
			for (size_t i = this->_index; i < n; i++)
			{
				this->push_back(val);
			}
		}
	}
}
//------------------Element access-------------//does refence work
template < class T, class Alloc >
typename vector<T,Alloc>::reference 	vector<T,Alloc>::operator[] (size_type n)
{
	return this->_arr[n];
}
template < class T, class Alloc >
typename vector<T,Alloc>::const_reference	vector<T,Alloc>::operator[] (size_type n) const
{
	return this->_arr[n];
}
template < class T, class Alloc >
typename vector<T,Alloc>::reference 	vector<T,Alloc>::front()
{
	return this->_arr[0];
}
template < class T, class Alloc >
typename vector<T,Alloc>::reference 	vector<T,Alloc>::back()
{
	return this->_arr[this->_size - 1];
}
template < class T, class Alloc >
typename vector<T,Alloc>::const_reference 	vector<T,Alloc>::front() const
{
	return this->_arr[0];
}
template < class T, class Alloc >
typename vector<T,Alloc>::const_reference 	vector<T,Alloc>::back() const
{
	return this->_arr[this->_size - 1];
}
template < class T, class Alloc >
typename vector<T,Alloc>::reference 	vector<T,Alloc>::at(size_type n)
{
	if ((n >= this->_size))
		throw std::out_of_range("out of range");
	return this->_arr[n];
}
template < class T, class Alloc >
typename vector<T,Alloc>::const_reference 	vector<T,Alloc>::at(size_type n) const
{
	if ((n >= this->_size))
		throw std::out_of_range("out of range");
	return this->_arr[n];
}
//-----------------------modifires------------------

template < class T, class Alloc >
void	vector<T,Alloc>::push_back (const value_type& val)
{
	if (this->_size == 0)
	{
		this->_capacity = 1;
		this->_arr = this->_allocator.allocate(this->_capacity);
	}
	else if ((this->_size + 1) > this->_capacity)
	{
		expand();
	}
	this->_allocator.construct(this->_arr + this->_size,val);
	this->_index++;
	this->_size++;

}

template < class T, class Alloc >
void	vector<T,Alloc>::pop_back()
{
	if (this->_size)
	{
		this->_size--;
		this->_index--;
		this->_allocator.destroy(this->_arr + this->_index);
	}
}
template < class T, class Alloc >
void vector<T,Alloc>::assign (size_type n, const value_type& val)
{

	if (n > this->_capacity)
	{
		int tmpc = this->_capacity;
		if (this->_capacity * 2 > n)//cap * 2
				tmpc *= 2;
		else 
			tmpc = n;
		pointer tmp = this->_allocator.allocate(tmpc);
		for(size_t i = 0;i < n;i++)
			this->_allocator.construct(tmp + i,val);
		this->_allocator.deallocate(this->_arr,this->_capacity);
		this->_arr = tmp;
		this->_capacity = tmpc;
		this->_size = n;
		this->_index = n;
	}
	else
	{
		for(size_t i = 0;i < n;i++)
			this->_allocator.construct(this->_arr + i,val);
		this->_index = n;
		this->_size = n;
	}

}

template < class T, class Alloc >
	template <class InputIterator>
		void vector<T,Alloc>::assign (InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type)
		{
	int n = this->diff(first,last);
	if (n > int(this->_capacity))
	{
		int tmpc = this->_capacity;
		if (int(this->_capacity * 2) > n)//cap * 2
				tmpc *= 2;
		else 
			tmpc = n;
		pointer tmp = this->_allocator.allocate(tmpc);
		for(int i = 0;i < n;i++)
			this->_allocator.construct(tmp + i,*(first++));
		
		this->_allocator.deallocate(this->_arr,this->_capacity);
		this->_arr = tmp;
		this->_capacity = tmpc;
		this->_size = n;
		this->_index = n;
	}
	else
	{
		for(int i = 0;i < n;i++)
			this->_allocator.construct(this->_arr + i,*(first++));
		this->_index = n;
		this->_size = n;
	}			
}


template < class T, class Alloc >
typename vector<T,Alloc>::iterator vector<T,Alloc>::insert (iterator position, const value_type& val)
	{
		int d = position - begin();
		if ((this->_size + 1) > this->_capacity)
		{
			int t = this->_capacity;
				if (this->_capacity == 0)
					t = 1;
				else 
					t *= 2;
				T* tmp = this->_allocator.allocate(t);
				if (tmp == NULL)
					std::cout << "NULL" << std::endl;
				for (int i = 0; i < d; i++)
					this->_allocator.construct(tmp + i,this->_arr[i]);
				this->_allocator.construct(tmp + d,val);
				for (size_t i = d; i < this->_size; i++)
					this->_allocator.construct(tmp + i + 1,this->_arr[i]);
					for(size_t i = 0; i < this->_size;i++)
						this->_allocator.destroy(this->_arr + i);
				this->_allocator.deallocate(this->_arr,this->_capacity);
				this->_arr = NULL;
				this->_arr = tmp;
				this->_index = this->_size;
				this->_size++;
				this->_index++;
				this->_capacity = t;
				return iterator(this->_arr + d);
		}
		int start = 0;
		for(start = this->_size;(start >= d);--start)
			this->_allocator.construct(this->_arr + start,this->_arr[start - 1]);
		this->_allocator.construct(this->_arr + d,val);
		this->_size++;
		this->_index++;
		return iterator(this->_arr + d);
	}
template < class T, class Alloc >
void vector<T,Alloc>::clear()
{
	for(size_t i = 0; i < this->_size;i++)
		this->_allocator.destroy(this->_arr + i);
	this->_allocator.deallocate(this->_arr,this->_capacity);
	this->_arr = NULL;
	this->_size = 0;
	this->_index = 0;
}
template < class T, class Alloc >
void vector<T,Alloc>::swap (vector& x)
{
	this->swap(this->_arr,x._arr);
	this->swap(this->_size,x._size);
	this->swap(this->_capacity,x._capacity);
	this->swap(this->_index,x._index);
	this->swap(this->_allocator,x._allocator);

}
template < class T, class Alloc >
	typename vector<T,Alloc>::iterator vector<T,Alloc>::erase (iterator position)
	{
		int pos = position - this->begin();//destroy
		if (pos >= int(this->_size))
			return position;
		this->_allocator.destroy(this->_arr + pos);
		for(int i = pos; i < (int(this->_size) - 1);i++)//size_t - 1
					this->_allocator.construct(this->_arr + i,this->_arr[i + 1]);
		this->_index--;
		this->_size--;
		return position;
	}
template < class T, class Alloc >
	typename vector<T,Alloc>::iterator vector<T,Alloc>::erase (iterator first, iterator last)
	{
		int pos = first - begin();
		int size = last - first;
		if (pos < 0 || size < 0 || size > int(this->_size) || last > this->end()){
			return  iterator(this->_arr);
		}
		for (int i = pos; i < size + pos && i + size < int(this->_size); i++)
		{
			this->_allocator.destroy(this->_arr + i);
			this->_allocator.construct(this->_arr + i,this->_arr[i + size]);
		}
		for (int i = pos + size - 1; i < int(this->_size) && i + size < int(this->_size); i++)
		{
			this->_allocator.construct(this->_arr + i,this->_arr[i + size]);
		}
		this->_index -= size;
		this->_size -= size;
		return iterator(this->_arr + pos);
	}
}
