#pragma once
//destroy in popback wnd resize**** 
#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>
#include <iterator>

namespace ft{

template <class T>
class vector
{
private:
	void    expand();
	void    expand(size_t n);
	T *_arr;
	int _size;
	int _capacity;
	static const size_t _max_size = 4611686018427387903;
public:

	typedef int size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T* pointer;
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
		const_refernce	operator*(){return *z;};
		pointer			operator->(){return z;}
	};
		class const_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		private:
			T* z;
		public:
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_refernce;
		typedef T* pointer;
		const_iterator(T* init){z = init;};
		const_iterator(){z = NULL;}
		bool 			operator != (const const_iterator &v){return this->z != v.z;}
		bool 			operator== (const const_iterator &v){return this->z == v.z;}
		bool 			operator>(const const_iterator &v){return this->z > v.z;}
		bool 			operator>=(const const_iterator &v){return this->z >= v.z;}
		bool 			operator<(const const_iterator &v){return this->z < v.z;}
		bool 			operator<=(const const_iterator &v){return this->z <= v.z;}
		const_iterator 		operator+(const const_iterator &v){const_iterator tmp;tmp->z+v.z;return *this;}
		const_iterator 		operator-(const const_iterator &v){const_iterator tmp;tmp->z-v.z;return *this;}
		const_iterator 		operator-(int v){const_iterator tmp(*this);tmp.z -= v; return tmp;}
		const_iterator 		operator+(int v){const_iterator tmp(*this);tmp.z += v; return tmp;}
		const_iterator 		&operator++(){this->z++;return *this;}
		const_iterator 		&operator--(){(this->z)--;return *this;}
		const_iterator 		&operator--(int){const_iterator tmp = *this;(this->z)--;return *this;}
		const_iterator		operator++(int) {const_iterator copy = *this;this->z++;return copy;}
		const_refernce	operator*(){return *z;};
		const pointer			operator->(){return z;}
	};
	// class reverse_iterator : public std::iterator<std::random_access_iterator_tag, T>
	// {

	// 	friend class list<T>;
	// 	private:
	// 		T* z;
	// 	public:
	// 	typedef T value_type;
	// 	typedef T& reference;
	// 	typedef const T& const_refernce;
	// 	typedef T* pointer;
	// 	reverse_iterator(T* init){z = init;};
	// 	reverse_iterator(){z = NULL;}
	// 	bool 			operator != (const reverse_iterator &v){return this->z != v.z;}
	// 	bool 			operator== (const reverse_iterator &v){return this->z == v.z;}
	// 	bool 			operator>(const reverse_iterator &v){return this->z > v.z;}
	// 	bool 			operator>=(const reverse_iterator &v){return this->z >= v.z;}
	// 	bool 			operator<(const reverse_iterator &v){return this->z < v.z;}
	// 	bool 			operator<=(const reverse_iterator &v){return this->z <= v.z;}
	// 	reverse_iterator 		operator+(const reverse_iterator &v){reverse_iterator tmp;tmp->z-v.z;return *this;}
	// 	reverse_iterator 		operator-(const reverse_iterator &v){reverse_iterator tmp;tmp->z+v.z;return *this;}
	// 	reverse_iterator 		operator-(int v){reverse_iterator tmp(*this);tmp.z += v; return tmp;}
	// 	reverse_iterator 		operator+(int v){reverse_iterator tmp(*this);tmp.z -= v; return tmp;}
	// 	reverse_iterator 		&operator++(){this->z--;return *this;}
	// 	reverse_iterator 		&operator--(){(this->z)++;return *this;}
	// 	reverse_iterator 		&operator--(int){reverse_iterator tmp = *this;(this->z)++;return *this;}
	// 	reverse_iterator		operator++(int) {reverse_iterator copy = *this;this->z--;return copy;}
	// 	const_refernce	operator*(){return *z;};
	// 	pointer			operator->(){return z;}
	// };
	// 	class const_reverse_iterator : public std::iterator<std::random_access_iterator_tag, T>
	// {
	// 	private:
	// 		T* z;
	// 	public:
	// 	typedef T value_type;
	// 	typedef T& reference;
	// 	typedef const T& const_refernce;
	// 	typedef T* pointer;
	// 	const_reverse_iterator(T* init){z = init;};
	// 	const_reverse_iterator(){z = NULL;}
	// 	bool 			operator != (const const_reverse_iterator &v){return this->z != v.z;}
	// 	bool 			operator== (const const_reverse_iterator &v){return this->z == v.z;}
	// 	bool 			operator>(const const_reverse_iterator &v){return this->z > v.z;}
	// 	bool 			operator>=(const const_reverse_iterator &v){return this->z >= v.z;}
	// 	bool 			operator<(const const_reverse_iterator &v){return this->z < v.z;}
	// 	bool 			operator<=(const const_reverse_iterator &v){return this->z <= v.z;}
	// 	const_reverse_iterator 		operator+(const const_reverse_iterator &v){const_reverse_iterator tmp;tmp->z-v.z;return *this;}
	// 	const_reverse_iterator 		operator-(const const_reverse_iterator &v){const_reverse_iterator tmp;tmp->z+v.z;return *this;}
	// 	const_reverse_iterator 		operator-(int v){const_reverse_iterator tmp(*this);tmp.z += v; return tmp;}
	// 	const_reverse_iterator 		operator+(int v){const_reverse_iterator tmp(*this);tmp.z -= v; return tmp;}
	// 	const_reverse_iterator 		&operator++(){this->z--;return *this;}
	// 	const_reverse_iterator 		&operator--(){(this->z)++;return *this;}
	// 	const_reverse_iterator 		&operator--(int){const_reverse_iterator tmp = *this;(this->z)++;return *this;}
	// 	const_reverse_iterator		operator++(int) {const_reverse_iterator copy = *this;this->z--;return copy;}
	// 	const_refernce	operator*(){return *z;};
	// 	const pointer			operator->(){return z;}
	// };
	vector();
	vector(unsigned int n);
	vector(vector const &arr);
	~vector();

	/*-----------------------------*/
	//template <class InputIterator>
  	//void assign (InputIterator first, InputIterator last);
	void		assign(int n,const T& val);
	reference		at(size_type n);
	const_reference at (size_type n) const;
	reference	back();
	const_reference back() const;
	iterator	begin(){return iterator(this->_arr);}
	const_iterator begin() const{return iterator(this->_arr);}
	size_type	capacity() const;
	void		clear();
	bool        empty() const;
	iterator	end(){return iterator(this->_arr + this->_size);}
	const_iterator end() const{return iterator(this->_arr + this->_size);}
	iterator	erase(iterator position);
	iterator	erase(iterator first, iterator last);
	reference	front();
	const_reference front() const;
	iterator	insert (iterator position, const value_type& val);
	//void insert (iterator position, size_type n, const value_type& val);
	//template <class InputIterator>
    //void insert (iterator position, InputIterator first, InputIterator last);
	size_type	max_size() const;
	/*--------operatorts-----------*/
	vector<T>	&operator=(vector <T>const &arr);
	reference		operator[](size_type i);
	const_reference operator[] (size_type n) const;
	/*--------operatorts-----------*/
	void        pop_back();
	void push_back (const value_type& val); //replace my pushback
	reverse_iterator rbegin(){return reverse_iterator(end());} //must change end() - 1
	const_reverse_iterator rbegin() const {return reverse_iterator(end());}
	reverse_iterator rend(){return reverse_iterator(begin());}
	const_reverse_iterator rend() const{return reverse_iterator(begin());}
	void		reserve(size_t);
	void		resize (size_t n, T val = 0);
	//void resize (size_type n, value_type val = value_type());
	size_type size() const;
	void		swap(vector<T> &);	
};
// template <class T, class Alloc>
//   void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
// template <class T, class Alloc>
//   bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>
//   bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>
//   bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>
//   bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>
//   bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>
//   bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//add typedef
template<class T>
typename vector<T>::iterator	vector<T>::insert(vector<T>::iterator position, const value_type& val)
{
	iterator end = this->at(this->_size - 1);
	iterator begin = this->at(0);
	int span = end - position;
	int b = position - begin;
	if (b == this->_size)
	{
		this->push_back(val);
	}
	else if (b > this->_size)
	{
		
	}
		return 0;
}
template<class T>
T&  vector<T>::at(size_type n)
{
	if (n >= this->_size)
		throw std::out_of_range("out of rang");
	else 
		return this->_arr[n];
}
template<class T>
const T&  vector<T>::at(size_type n) const
{
	if (n >= this->_size)
		throw std::out_of_range("out of rang");
	else 
		return this->_arr[n];
}
template <class T >
typename vector<T>::iterator  vector<T>::erase(vector<T>::iterator first, vector<T>::iterator last)
{
	int copy = this->_size;
	T *new_arr = new T[this->_capacity]();
	vector<T>::iterator i,end,ret;
	int j = 0;
	end = this->end();
	for (i = this->begin(); i != end; i++)
	{
		if (i >= first && i <= last)
		{
			this->_size--;
			continue;
		}
		if ((i - 1) == last)
			ret = &new_arr[j];
		new_arr[j] = *i;
		j++;
	}
	delete this->_arr;
	this->_arr = new_arr;
	return ret;
}
template <class T >
typename vector<T>::iterator  vector<T>::erase(vector<T>::iterator position)
{
	T *new_arr = new T[this->_capacity]();
	vector<T>::iterator i,ret;
	int j = 0;
	for (i = this->begin(); i != this->end(); i++)
	{
		if (i == position)
			continue;
		if ((i - 1) == position)
			ret = &new_arr[j];
		new_arr[j] = *i;
		j++;
	}
	delete this->_arr;
	this->_arr = new_arr;
	this->_size--;
	return ret;
}
template <class T >
void    vector<T>::expand(size_t n)
{
	T *new_arr = new T[n]();
	int i = -1;
	while (++i < this->_size)
	{
		new_arr[i] = this->_arr[i];
	}
	delete this->_arr;
	this->_arr = new_arr;
	this->_capacity = n;
}
template <class T >
void    vector<T>::expand()
{
	std::cout <<"expand\n";
	if (this->_capacity == 0)
		this->_capacity++;
	size_t n = this->_capacity * 2;
	T *new_arr = new T[n]();
	int i = -1;
	while (++i < this->_size)
	{
		new_arr[i] = this->_arr[i];
	}
	delete this->_arr;
	this->_arr = new_arr;
	this->_capacity = n;
	// std::cout << "capaity" <<this->_capacity << std::endl;
	// std::cout << "size" <<this->_size << std::endl;
}

template <class T>
void    vector<T>::resize(size_t n,T val)
{
	if (n < this->size())
	{
		this->_size = n;
		return ;
	}
	int range =  n - this->size();
	for (size_t i = 0;i < range ; i++)
	{
		this->push_back(val);
	}
}
template <class T>
void    vector<T>::reserve(size_t n)
{
	if (n <= this->_capacity)
		return;
	else 
	{
		expand(n);
	}
}
template <class T>
void    vector<T>::swap(vector<T> &v)
{
	vector f(v);
	v = *this;
	*this = f;
}
template <class T>
void    vector<T>::clear()
{
	this->_size = 0;
}
template <class T>
void    vector<T>::assign(int n,const T& val)
{
	this->_size = 0;
	for (size_t i = 0; i < n; i++)
	{
		this->push_back(val);
	}
}
template <class T>
typename vector<T>::size_type    vector<T>::max_size() const
{
	return (this->_max_size);
}
template <class T>
T&    vector<T>::back()
{
	return (this->_arr[this->size() - 1]);
}
template <class T>
const T&    vector<T>::back() const
{
	return (this->_arr[this->size() - 1]);
}
template <class T>
T&    vector<T>::front()
{
	return (this->_arr[0]);
}
template <class T>
const T&    vector<T>::front() const
{
	return (this->_arr[0]);
}
template <class T>
void    vector<T>::pop_back()
{
	if (this->size() <= 0)
		return ;
	else 
	{
		this->_size--;
	}
}
template <class T>
void    vector<T>::push_back(const T& v)
{
	if (this->size() == this->_capacity)
		expand();
		this->_arr[this->size()] = v;
		this->_size++;
	// std::cout << ">>capaity" <<this->_capacity << std::endl;
	// std::cout << ">>>size" <<this->_size << std::endl;
}
template <class T>
vector<T>::vector() :_size(0),_capacity(0)
{
	this->_arr = new T[0]();
}
template <class T>
vector<T>::vector(unsigned int n)
{
	this->_arr = new T[n * 2]();
	this->_size = n;
	this->_capacity = this->_size * 2;
}

template <class T>
vector<T>::~vector()
{
	delete this->_arr;
	this->_size = 0;
}
template <class T>
vector<T> &vector<T>::operator=(vector <T>const &arr)
{
	delete this->_arr;
	this->_capacity = arr._capacity;
	this->_size = arr.size();
	this->_arr = new T[this->_capacity]();
	// if (this->_arr == NULL)
	//     puts("NULL");
	int i = -1;
	while (++i < this->_size)
	{
		this->_arr[i] = arr[i];
	}
	return *this;
}
template <class T>
typename vector<T>::reference vector<T>::operator[](int i)
{
	if (i >= this->_size)
		throw std::out_of_range("out of range");
	else 
		return this->_arr[i];
}
template <class T>
typename vector<T>::const_reference vector<T>::operator[](int i) const
{
	if (i >= this->_size)
		throw std::out_of_range("out of range");
	else 
		return this->_arr[i];
}
template <class T>
typename vector<T>::size_type  vector<T>::size() const
{
	return this->_size;
}
template <class T>
int vector<T>::capacity() const
{
	return this->_capacity;
}
template <class T>
vector<T>::vector(vector const &arr)
{
	this->_size = arr._size;
	this->_arr = new T[this->_size]();
	int i = -1;
	while (++i < this->_size)
	{
		this->_arr[i] = arr[i];
	}
}

template <class T>
bool vector<T>::empty() const
{
	if (this->_size > 0)
		return 0;
	else 
		return 1;
}
}