#pragma once

#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>
#include <iterator>

namespace ft{

template < class T, class Alloc = std::allocator<T> >
class vector
{
	private:
		template<class B>
			void	swap(B& a,B& b); 
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

    template<bool Condition, typename TC = void>
    struct enable_if
    {
    };
    template<typename TC>
    struct enable_if<true, TC>
    {
        typedef TC type;
    };
	public:
// 	template<bool Cond, class T = void> struct enable_if {};
// template<class T> struct enable_if<true, T> { typedef T type; };
	//------------------member type---------------------
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef const typename allocator_type::const_reference	 const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef const typename allocator_type::const_pointer const_pointer;
		typedef size_t size_type;//error
	//---------------exceptions--------------------------
		class out_of_range : public std::logic_error {
		public:
		explicit out_of_range (const std::string& what_arg);
		};
	//--------------------iterators-----------------------------
	class iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		private:
			T* z;
		public:
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_refernce;
		typedef T* pointer;
		iterator(T* init){z = init;};
		iterator(){z = NULL;}
		bool 			operator != (const iterator &v){return this->z != v.z;}
		bool 			operator== (const iterator &v){return this->z == v.z;}
		bool 			operator>(const iterator &v){return this->z > v.z;}
		bool 			operator>=(const iterator &v){return this->z >= v.z;}
		bool 			operator<(const iterator &v){return this->z < v.z;}
		bool 			operator<=(const iterator &v){return this->z <= v.z;}
		iterator 		operator+(const iterator &v){iterator tmp;tmp->z+v.z;return *this;}
		iterator 		operator-(const iterator &v){iterator tmp;tmp->z-v.z;return *this;}
		iterator 		operator-(int v){iterator tmp(*this);tmp.z -= v; return tmp;}
		iterator 		operator+(int v){iterator tmp(*this);tmp.z += v; return tmp;}
		iterator 		&operator++(){this->z++;return *this;}
		iterator 		&operator--(){(this->z)--;return *this;}
		iterator 		&operator--(int){iterator tmp = *this;(this->z)--;return *this;}
		iterator		operator++(int) {iterator copy = *this;this->z++;return copy;}
		reference	operator*(){return *z;};
		pointer			operator->(){return z;}
	};
	class reverse_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		private:
			T* z;
		public:
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_refernce;
		typedef T* pointer;
		reverse_iterator(T* init){z = init;};
		reverse_iterator(){z = NULL;}
		bool 			operator != (const reverse_iterator &v){return this->z != v.z;}
		bool 			operator== (const reverse_iterator &v){return this->z == v.z;}
		bool 			operator>(const reverse_iterator &v){return this->z > v.z;}
		bool 			operator>=(const reverse_iterator &v){return this->z >= v.z;}
		bool 			operator<(const reverse_iterator &v){return this->z < v.z;}
		bool 			operator<=(const reverse_iterator &v){return this->z <= v.z;}
		reverse_iterator 		operator+(const reverse_iterator &v){reverse_iterator tmp;tmp->z-v.z;return *this;}
		reverse_iterator 		operator-(const reverse_iterator &v){reverse_iterator tmp;tmp->z+v.z;return *this;}
		reverse_iterator 		operator-(int v){reverse_iterator tmp(*this);tmp.z += v; return tmp;}
		reverse_iterator 		operator+(int v){reverse_iterator tmp(*this);tmp.z -= v; return tmp;}
		reverse_iterator 		&operator++(){this->z--;return *this;}
		reverse_iterator 		&operator--(){(this->z)++;return *this;}
		reverse_iterator 		&operator--(int){reverse_iterator tmp = *this;(this->z)++;return *this;}
		reverse_iterator		operator++(int) {reverse_iterator copy = *this;this->z--;return copy;}
		reference	operator*(){return *z;};
		pointer			operator->(){return z;}
	};
	//--------------Constructors----------------------------------
		explicit vector (const allocator_type& alloc = allocator_type());//default
		explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());//fill
		template <class InputIterator>
				vector (InputIterator first, InputIterator last,
						const allocator_type& alloc = allocator_type());//range
		vector (const vector& x);//copy
	//--------------DeConstructors----------------------------------
		~vector();
	//--------------operator= copy------------------------------
		vector& operator= (const vector& x);
	//---------------Iterators---------------------
		iterator	begin(){return iterator(this->_arr);}
		// const_iterator begin() const;
		iterator	end(){return iterator(this->_arr + this->_size);}
		// const_iterator end() const;
		reverse_iterator rbegin(){return reverse_iterator(this->_arr + this->_size - 1);}
		// const_reverse_iterator rbegin() const;
		reverse_iterator rend(){return reverse_iterator(this->_arr - 1);}
		// const_reverse_iterator rend() const;
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
		void insert (iterator position, size_type n, const value_type& val);
	//range (3)	
	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);
	void clear();
	void swap (vector& x);
	iterator erase (iterator position);
	iterator erase (iterator first, iterator last);

};
///---------------private functions ----------
template < class T, class Alloc >
	template<class B>
		void vector<T,Alloc>::swap(B& a,B& b)
		{
			B tmp = a;
			a = b;
			b = tmp;
		}
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
void	vector<T,Alloc>::copy(T** tmp, T* arr,size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		*tmp[i] = arr[i];
	}
	
}

template < class T, class Alloc >
void	vector<T,Alloc>::expand()
{
	this->_capacity *= 2;
	pointer tmp = this->_allocator.allocate(this->_capacity);
	if (tmp == NULL)
		std::cout << "NULL" << std::endl;
	for (size_t i = 0; i < this->_size; i++)
	{
		tmp[i] = this->_arr[i];
	}
	delete this->_arr;
	this->_arr = tmp;
	this->_index = this->_size;
}
template < class T, class Alloc >
void	vector<T,Alloc>::expand(size_t n)
{
	this->_capacity = n;
	pointer tmp = this->_allocator.allocate(this->_capacity);
	if (tmp == NULL)
		std::cout << "NULL" << std::endl;
	for (size_t i = 0; i < this->_size; i++)
	{
		tmp[i] = this->_arr[i];
	}
	delete this->_arr;
	this->_arr = tmp;
	this->_index = this->_size;
}
//-------------------constructors
template < class T, class Alloc >
vector<T,Alloc>::vector(const allocator_type& alloc)
{
	this->_arr = nullptr;
	this->_size = 0;
	this->_capacity = 0;
	this->_index = 0;
}
template < class T, class Alloc >
vector<T,Alloc>::vector (size_type n, const value_type& val,
						const allocator_type& alloc)//maybe problem size
{
	// this->_arr = new value_type[n];
	this->_arr = this->_allocator.allocate(n);
	this->_size = n;
	this->_capacity = n;
	this->_index = n;
	for (size_t i = 0;i < n;i++)
		this->_arr[i] = val;
}
//-------------------deconstructors
template < class T, class Alloc >
vector<T,Alloc>::~vector()
{
	this->_arr = nullptr;//free pointer
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
	if (this->_capacity < n)
	{
		expand(n);
	}
}
template < class T, class Alloc >
void vector<T,Alloc>::resize (size_type n, value_type val)
{
	if (n < this->_size)
	{
		// std::cout <<"1n:"<<n <<" size: "<< this->_size <<std::endl;
		this->_size = n;
		this->_index = (this->_size == 0) ? 0 : (this->_size - 1);
	}
	else if (n > this->_size && n <= this->_capacity)
	{
		// std::cout <<"2n:"<<n <<" size: "<< this->_size <<std::endl;
		for (size_t i = (this->_size - 1); i < n-1; i++)
		{
			this->push_back(val);
		}
	}
	else if (n > this->_capacity)
	{
		// std::cout <<"n:"<<n <<" capacity: "<< this->_capacity <<std::endl;
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
typename vector<T,Alloc>::reference 	vector<T,Alloc>::at(size_type n)
{
	//check bounds
	try
	{
		std::cout << "n: "<<n <<"capacity: "<<this->_capacity<< std::endl;
		return this->_arr[n];
		// std::cout << "here" << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Out of Range error: "<< e.what() << '\n';
	}
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
	this->_arr[this->_index] = val;
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
			this->_arr[i] = val;
		this->_allocator.deallocate(this->_arr,this->_capacity);
		this->_arr = tmp;
		this->_capacity = n;
		this->_size = n;
		this->_index = n;
	}
	else
	{
		for(size_t i = 0;i < n;i++)
			this->_arr[i] = val;
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
				pointer tmp = this->_allocator.allocate(s);
				for (size_t i=0;i < s;i++){
					this->_allocator.construct(tmp + i,*first);
					first++;
				}
				this->_allocator.deallocate(this->_arr,this->_size);
				this->_arr = tmp;
				this->_size = s;
				this->_index = s;
			}
		}


// template < class T, class Alloc >
// vector<T,Alloc>::iterator vector<T,Alloc>::insert (iterator position, const value_type& val)
// 	{
// 		if ((this->_size + 1) > this->_capacity)
// 		{
// 			expand();
// 			iterator end = this->end();
// 			for(iterator start = position;start < end;start++)
// 			{
// 				if ((start + 1) != end)
// 					*start = *(start + 1);
// 			}
// 			*position = val;
// 		}
		
// 	}

// template < class T, class Alloc >
// void	vector<T,Alloc>::expand(size_t n)

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
}
template < class T, class Alloc >
	typename vector<T,Alloc>::iterator vector<T,Alloc>::erase (iterator position)
	{
		size_t pos = this->diff(this->begin(),position);
		this->_allocator.destroy(this->_arr + pos);
		for(size_t i = pos; i < (this->_size - 1);i++)
			this->_arr[i] = this->_arr[i + 1];
		this->_index--;
		return position;
	}
template < class T, class Alloc >
	typename vector<T,Alloc>::iterator vector<T,Alloc>::erase (iterator first, iterator last)
	{
		size_t pos = this->diff(this->begin(),first);
		size_t size = this->diff(first,last);
		for(size_t i = pos; i < (this->_size - 1);i++)
			this->_arr[i] = this->_arr[i + 1];
		this->_allocator.destroy(this->_arr + pos);
		for(size_t i = pos; i < (this->_size - 1);i++)
			this->_arr[i] = this->_arr[i + 1];
		this->_index--;
		return position;
	}
}
