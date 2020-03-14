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
			struct Node *next;
			struct Node *prev;
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
			friend class list<T>;
			private:
				Node* z;
			public:
			typedef T value_type;
			typedef T& reference;
			typedef const T& const_refernce;
			typedef T* pointer;
			iterator(Node* init){z = init;};
			iterator(){z = NULL;}
			bool 			operator != (const iterator &v){return this->z != v.z;}
			bool 			operator== (const iterator &v){return this->z == v.z;}
			bool 			operator>(const iterator &v){return this->z > v.z;}
			bool 			operator>=(const iterator &v){return this->z >= v.z;}
			bool 			operator<(const iterator &v){return this->z < v.z;}
			bool 			operator<=(const iterator &v){return this->z <= v.z;}
			iterator 		&operator++(){z = z->next;;return *this;}
			iterator 		&operator--(){z = z->prev;return *this;}
			iterator 		&operator--(int){iterator tmp = *this;(--this);return *this;}
			iterator		operator++(int) {iterator copy = *this;++(*this);return copy;}
			reference		operator*(){return z->data;};
		};
		typedef std::reverse_iterator<iterator>
			reverse_iterator;
		explicit list (){
			length = 0;
			node = creat_node();
			node->next = node;
			node->prev = node;
		}//default
		explicit list (size_type n, const value_type& val = value_type()){
			length = 0;
			node = creat_node();
			node->next = node;
			node->prev = node;
			insert(begin(),n,val);
		}/// fill
		template <class InputIterator>
		list (InputIterator first, InputIterator last)
		{
			length = 0;
			node = creat_node();
			node->next = node;
			node->prev = node;
			insert(begin(),first,last);
		}// range
		list (const list& x)
		{
			length = 0;
			node = creat_node();
			node->next = node;
			node->prev = node;
			insert(begin(),x.first,x.last);
		}//copy
		~list(){std::cout << "";};
		/*--------------------------------*/
		template <class InputIterator>
			void assign (InputIterator first, InputIterator last);//range
		void assign (size_type n, const value_type& val);//fill
		iterator back() {return node;};//done
		const_iterator back() const{return node;};//done
		iterator begin(){return iterator(node->next);};//done
		const_iterator begin() const{return node->next;};//done
		void clear();
		bool empty() const {return this->length == 0;};//done
		iterator end() {return node;};//done
		const_iterator end() const{return node;};//done
		iterator erase (iterator position);//done
		iterator erase (iterator first, iterator last);//done
		reference front(){return *begin();};//done
		const_reference front() const{return *begin()};//done
		iterator insert (iterator position, const value_type& val);//single element (1)//done
		void insert (iterator position, size_type n, const value_type& val);//fill (2)//done
		template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);//range (3)//done
		size_type max_size() const{return this->length;};
		void merge (list& x);
		template <class Compare>
			void merge (list& x, Compare comp);
		list& operator= (const list& x);//copy (1)
		void pop_back();
		void pop_front();
		void push_back (const value_type& val);
		void push_front (const value_type& val);
		reverse_iterator rbegin(){return reverse_iterator(end())};
		const_reverse_iterator rbegin() const{return const_reverse_iterator(end())};
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
				node = new Node;
				node->next = node;
				node->prev = node;
				return node;
			};

	};
	template<class T>
	typename list<T>::iterator list<T>::insert(iterator position, const value_type& val)
	{
		Node* tmp = creat_node();
		tmp->data = val;
		// new (&(tmp->data)) T(val);
		tmp->next = position.z;
		tmp->prev = (position.z)->prev;
		(position.z)->prev->next = tmp;
		(position.z)->prev = tmp;
		++length;
		return tmp;
	}
	template<class T>
	void list<T>::insert (iterator position, size_type n, const value_type& val)
	{
		while (n--)
			insert(position,val);
	}
	template<class T>
	template <class InputIterator>
		void list<T>::insert (iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
				insert(position,*(first++));			
		}
	template<class T>
	list<T>::iterator list<T>::erase (iterator position)
	{
		position.z->prev->next = position.z->next;
		position.z->next->prev = position.z->prev;
		// delete position.z;
		--length;
	}
	template<class T>
	list<T>::iterator list<T>::erase (iterator first, iterator last)
	{
		while (first != last)
		{
			erase(first++);
		}
		
	}
};