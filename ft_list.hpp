#pragma once

#include <iostream>
#include <list>
#include <memory>
namespace ft
{
	template < class T >
	class list
	{
		public:
		struct Node
		{
			T data;
			struct s_Node *next;
			struct s_Node *prev;
		};
		typedef int size_type;
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef Node* link_type;	
		class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
		{
		};
		class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
		{
		};
		class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
		{
		};
		class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
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
			// iterator 		operator+(const iterator &v){iterator tmp;tmp->z+v.z;return *this;}
			// iterator 		operator-(const iterator &v){iterator tmp;tmp->z-v.z;return *this;}
			// iterator 		operator-(int v){iterator tmp(*this);tmp.z -= v; return tmp;}
			// iterator 		operator+(int v){iterator tmp(*this);tmp.z += v; return tmp;}
			// iterator 		&operator++(){this->z++;return *this;}
			// iterator 		&operator--(){(this->z)--;return *this;}
			// iterator 		&operator--(int){iterator tmp = *this;(this->z)--;return *this;}
			// iterator		operator++(int) {iterator copy = *this;this->z++;return copy;}
			const_refernce	operator*(){return *z;};
			pointer			operator->(){return z;}
		};
		explicit list (){
			node = creat_node();
			node->next = node;
			node->prev = node;
		}//default
		explicit list (size_type n, const value_type& val = value_type()){
			
		}/// fill
		template <class InputIterator>
		list (InputIterator first, InputIterator last);// range
		list (const list& x);//copy
		~list(){std::cout << "";};
		/*--------------------------------*/
		template <class InputIterator>
			void assign (InputIterator first, InputIterator last);//range
		void assign (size_type n, const value_type& val);//fill
		iterator back() {return this->tail;};
		const_iterator back() const{return this->tail;};
		iterator begin(){return this->head;};
		const_iterator begin() const{return this->head;};
		void clear();
		bool empty() const {return this->length == 0;};
		iterator end() {return iterator(this->tail);};
		const_iterator end() const{return iterator(this->tail);};
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		reference front(){return this->head->data;};
		const_reference front() const{return this->head->data;};
		iterator insert (iterator position, const value_type& val);//single element (1)
		void insert (iterator position, size_type n, const value_type& val);//fill (2)
		template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);//range (3)
		size_type max_size() const{return this->length;};
		void merge (list& x);
		template <class Compare>
			void merge (list& x, Compare comp);
		list& operator= (const list& x);//copy (1)
		void pop_back();
		void pop_front();
		void push_back (const value_type& val);
		void push_front (const value_type& val);
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		void remove (const value_type& val);
		template <class Predicate>
			void remove_if (Predicate pred);
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		void resize (size_type n, value_type val = value_type());
		void reverse();
		size_type size() const{return this->length;};
		void sort();
		template <class Compare>
			void sort (Compare comp);
		void splice (iterator position, list& x);//entire list (1)	
		void splice (iterator position, list& x, iterator i);//single element (2)	
		void splice (iterator position, list& x, iterator first, iterator last);//element range (3)	
		void swap (list& x);
		void unique();
		template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred);
		// template <class T>
		// 	bool operator== (const list<T>& lhs, const list<T>& rhs);
		// template <class T>
		// 	bool operator!= (const list<T>& lhs, const list<T>& rhs);
		// template <class T>
		// 	bool operator<  (const list<T>& lhs, const list<T>& rhs);
		// template <class T>
		// 	bool operator<= (const list<T>& lhs, const list<T>& rhs);
		// template <class T>
		// 	bool operator>  (const list<T>& lhs, const list<T>& rhs);
		// template <class T>
		// 	bool operator>= (const list<T>& lhs, const list<T>& rhs);
		// template <class T>
		// 	void swap (list<T>& x, list<T>& y);
		/*----------------------------*/
		private:
			size_t length;
			link_type node;
			link_type creat_node()
			{
				node = new typename list<T>::link_type[1];
				node->next = node;
				node->prev = node;
				return node;
			};

	};
	template<class T>
	typename list<T>::iterator list<T>::insert(iterator position, const value_type& val)
	{
		// T* tmp = creat_node();
		// tmp->data = 5;
		// // new (&(tmp->data)) T(val);
		// tmp->next = position.z;
		// tmp->prev = (position.z)->prev;
		// (position.z)->prev->next = tmp;
		// (position.z)->prev = tmp;
		// ++length;
		// return iterator(tmp);
	}



};