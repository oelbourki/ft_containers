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
		typedef size_t size_type;//error
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
							this->_arr = _allocator.allocate(n);
							for(size_t i = 0;i < n;++i)
							{
								_allocator.construct(this->_arr + i,val);
							}
							this->_size = n;
							this->_index = n;
							this->_capacity = n;
							_allocator = alloc;
						}
		template <class InputIterator>
				vector (InputIterator first, InputIterator last,typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* t = 0,

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
			this->_allocator.deallocate(this->_arr,this->_size);
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
			// this->_arr
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
		void assign (InputIterator first, InputIterator last,typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = InputIterator());//range
		void assign (size_type n, const value_type& val);//fill
	//single element (1)	
		iterator insert (iterator position, const value_type& val);
	//fill (2)	
		void insert (iterator position, size_type n, const value_type& val){
			// std::cout << "insert fill" << std::endl;
			int d = position - begin();
			int tmpc = this->_capacity;
		if (this->_capacity * 2 > this->_size + n)//cap * 2
				tmpc *= 2;
		if ((this->_size + n) > this->_capacity)
		{
			// std::cout << "expand****" << std::endl;
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
				delete this->_arr;
				this->_arr = NULL;
				this->_arr = tmp;
				this->_index = this->_size;
				this->_size += n;
				this->_index += n;
				this->_capacity = tmpc;
				return ;
		}
		// std::cout << "not expand" << std::endl;
		int start = 0;
		for(start = this->_size + n - 1;((start) >= int(this->_size));--start)
					_allocator.construct(this->_arr + start,this->_arr[start - n]);
		for (int i = d; i < int(n+d); i++)
					_allocator.construct(this->_arr + i,val);
		this->_size += n;
		this->_index += n;
		return ;
		}
	//range (3)	
	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){
			int d = position - begin();
			int n = last - first;
			//check values
		int tmpc = this->_capacity;
		if (this->_capacity * 2 > this->_size + n)//cap * 2
				tmpc *= 2;
		if ((this->_size + n) > this->_capacity)
		{
			// std::cout << "expand" << std::endl;
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
				delete this->_arr;
				this->_arr = NULL;
				this->_arr = tmp;
				this->_index = this->_size;
				this->_size += n;
				this->_index += n;
				this->_capacity = tmpc;
				return ;
		}
		// std::cout << "not expand" << std::endl;
		int start = 0;
		for(start = this->_size + n - 1;((start) >= int(this->_size));--start)
					_allocator.construct(this->_arr + start,this->_arr[start - n]);
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
	//   return 0;

  }
template <class T, class Alloc>
  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	//   std::cout << "frem" << std::endl;
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
	for (size_t i = 0; i < this->_size; i++)
	{
		this->_allocator.construct(tmp + i,this->_arr[i]);
	}
	// this->_allocator.deallocate(this->_arr,this->_capacity);
	this->_capacity = n;
	if (this->_arr)
		delete this->_arr;
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
			// std::cout << "here" << std::endl;
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
	//check bounds
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
	// Alloc allocator;
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
	// pointer tmp = this->_allocator.allocate(n);
	if (n > this->_capacity)
	{

		pointer tmp = this->_allocator.allocate(n);
		for(size_t i = 0;i < n;i++)
			this->_allocator.construct(tmp + i,val);
		this->_allocator.deallocate(this->_arr,this->_capacity);
		this->_arr = tmp;
		this->_capacity = n;
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


//class = typename std::enable_if<std::is_integral<T>::value>::type
//,typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()
template < class T, class Alloc >
	template <class InputIterator>
		void vector<T,Alloc>::assign (InputIterator first, InputIterator last,typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type)
		{
			int s = this->diff(first,last);
			if (s > 0)
			{
					// std::cout <<"diff: "<< s << std::endl;
				pointer tmp = this->_allocator.allocate(s);
				for (int i=0;i < s;i++){
					// std::cout << *first << std::endl;
					this->_allocator.construct(tmp + i,*first);
					first++;
				}
				this->_allocator.deallocate(this->_arr,this->_size);
				this->_arr = tmp;
				this->_size = s;
				this->_index = s;
				this->_capacity = s;
			}
		}


template < class T, class Alloc >
typename vector<T,Alloc>::iterator vector<T,Alloc>::insert (iterator position, const value_type& val)
	{
		// std::cout << "insert one " << std::endl;
		int d = position - begin();
		if ((this->_size + 1) > this->_capacity)
		{
			// std::cout << "inside" << std::endl;
				if (this->_capacity == 0)
					this->_capacity = 1;
				else 
					this->_capacity *= 2;
				T* tmp = this->_allocator.allocate(this->_capacity);
				if (tmp == NULL)
					std::cout << "NULL" << std::endl;
				for (int i = 0; i < d; i++)
					this->_allocator.construct(tmp + i,this->_arr[i]);
				this->_allocator.construct(tmp + d,val);
				for (size_t i = d; i < this->_size; i++)
					this->_allocator.construct(tmp + i + 1,this->_arr[i]);
				delete this->_arr;
				this->_arr = NULL;
				this->_arr = tmp;
				this->_index = this->_size;
				this->_size++;
				this->_index++;
				return iterator(this->_arr + d);
		}
		int start = 0;
		for(start = this->_size;(start >= d && (start - 1) >= 0);--start)
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
		size_t pos = this->diff(this->begin(),position);
		// this->_allocator.destroy(this->_arr + pos);
		for(size_t i = pos; i < (this->_size - 1);i++)//size_t - 1
					this->_allocator.construct(this->_arr + i,this->_arr[i + 1]);
		this->_index--;
		this->_size--;
		return position;
	}
template < class T, class Alloc >
	typename vector<T,Alloc>::iterator vector<T,Alloc>::erase (iterator first, iterator last)
	{
		size_t pos = this->diff(this->begin(),first);
		size_t size = this->diff(first,last);
		// for(int i = pos; i < (this->_size - 1);i++){
		// 	this->_allocator.destroy(this->_arr + pos + i);
		// }
		this->_index -= size;
		this->_size -= size;
		return iterator(this->_arr + pos);
	}
}
